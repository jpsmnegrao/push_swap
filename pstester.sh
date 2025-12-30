#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
YELLOW='\033[0;33m'
RESET='\033[0m'

if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap not found.${RESET}"
    exit 1
fi

run_test() {
    # Capture raw output (stdout and stderr)
    RAW_OUT=$(./push_swap $1 2>&1)
    
    # Count valid instructions
    MOVES_COUNT=$(echo "$RAW_OUT" | grep -E '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$' | wc -l)
    
    # Valgrind check
    valgrind --leak-check=full --error-exitcode=42 ./push_swap $1 > /dev/null 2>&1
    LEAK=$?

    # Prepare the output string (removing newlines) for error reporting
    CLEAN_OUT=$(echo "$RAW_OUT" | tr '\n' ' ' | sed 's/  */ /g')

    printf "Testing: [%s] " "$1"
    
    if [ $LEAK -eq 42 ]; then
        echo -e "${RED}[LEAK]${RESET} Output: [${YELLOW}$CLEAN_OUT${RESET}]"
    elif [ "$2" == "error" ]; then
        if [[ "$RAW_OUT" == "Error"* ]] && [ $MOVES_COUNT -eq 0 ]; then
            # Still showing output here so you can confirm "Error" was printed
            echo -e "${GREEN}[OK]${RESET} Output: [${YELLOW}$CLEAN_OUT${RESET}]"
        else
            echo -e "${RED}[FAIL]${RESET} (Expected 'Error') Output: [${YELLOW}$CLEAN_OUT${RESET}]"
        fi
    elif [ "$2" == "sorted" ]; then
        if [ $MOVES_COUNT -eq 0 ]; then
            echo -e "${GREEN}[OK]${RESET} (Sorted: 0 moves)"
        else
            echo -e "${RED}[FAIL]${RESET} Output: [${YELLOW}$CLEAN_OUT${RESET}]"
        fi
    else
        # Success check for 3, 4, and 5 moves - Now stays silent on the output
        COLOR=$CYAN
        if [[ "$3" == "3" && $MOVES_COUNT -gt 3 ]] || [[ "$3" == "5" && $MOVES_COUNT -gt 12 ]]; then
            COLOR=$RED
            echo -e "${GREEN}[OK]${RESET} Moves: ${COLOR}$MOVES_COUNT${RESET} ${RED}(LIMIT EXCEEDED)${RESET} Output: [${YELLOW}$CLEAN_OUT${RESET}]"
        else
            echo -e "${GREEN}[OK]${RESET} Moves: ${COLOR}$MOVES_COUNT${RESET}"
        fi
    fi
}

echo -e "${YELLOW}--- INITIAL VALIDATION (Error Handling & Sorted) ---${RESET}"
run_test '""' "error"
run_test "1 2 2" "error"
run_test "2147483648" "error"
run_test "1 2 3 4 5" "sorted"

echo -e "\n${YELLOW}--- STACK OF 3 ---${RESET}"
echo -e "${CYAN}Max moves allowed: 3${RESET}"
run_test "1 3 2" "valid" "3"
run_test "2 1 3" "valid" "3"
run_test "2 3 1" "valid" "3"
run_test "3 1 2" "valid" "3"
run_test "3 2 1" "valid" "3"

echo -e "\n${YELLOW}--- STACK OF 4 ---${RESET}"
echo -e "${CYAN}Max moves allowed: n/a (targeting < 12)${RESET}"
run_test "4 3 2 1" "valid" "12"
run_test "1 3 2 4" "valid" "12"
run_test "4 1 2 3" "valid" "12"
run_test "2 4 3 1" "valid" "12"

echo -e "\n${YELLOW}--- STACK OF 5 ---${RESET}"
echo -e "${CYAN}Max moves allowed: 12${RESET}"
run_test "5 4 3 2 1" "valid" "5"
run_test "1 5 2 4 3" "valid" "5"
run_test "2 3 4 5 1" "valid" "5"
run_test "5 1 2 3 4" "valid" "5"
run_test "1 2 3 5 4" "valid" "5"