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
    # $1 = input, $2 = expected type, $3 = description, $4 = move limit (optional)
    RAW_OUT=$(./push_swap $1 2>&1)
    MOVES_COUNT=$(echo "$RAW_OUT" | grep -E '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$' | wc -l)
    
    valgrind --leak-check=full --error-exitcode=42 ./push_swap $1 > /dev/null 2>&1
    LEAK=$?

    # Clean the output for display (removes extra newlines and trims)
    CLEAN_OUT=$(echo "$RAW_OUT" | tr '\n' ' ' | xargs)

    printf "Testing %-30s : [%s] " "($3)" "$1"
    
    if [ $LEAK -eq 42 ]; then
        echo -e "${RED}[LEAK]${RESET} Output: [${YELLOW}$CLEAN_OUT${RESET}]"
    elif [ "$2" == "error" ]; then
        if [[ "$RAW_OUT" == "Error"* ]] && [ $MOVES_COUNT -eq 0 ]; then
            # Re-added the Output display here for confirmation
            echo -e "${GREEN}[OK]${RESET} Output: [${YELLOW}$CLEAN_OUT${RESET}]"
        else
            echo -e "${RED}[FAIL]${RESET} (Expected 'Error') Output: [${YELLOW}$CLEAN_OUT${RESET}]"
        fi
    elif [ "$2" == "sorted" ]; then
        if [ $MOVES_COUNT -eq 0 ] && [[ "$RAW_OUT" != "Error"* ]]; then
            echo -e "${GREEN}[OK]${RESET} (Sorted: 0 moves)"
        else
            echo -e "${RED}[FAIL]${RESET} (Should be 0 moves) Output: [${YELLOW}$CLEAN_OUT${RESET}]"
        fi
    else
        # Success cases (valid input)
        COLOR=$CYAN
        if [[ -n "$4" ]]; then
            if [[ "$4" == "3" && $MOVES_COUNT -gt 3 ]] || [[ "$4" == "12" && $MOVES_COUNT -gt 12 ]]; then
                COLOR=$RED
                echo -e "${RED}[FAIL]${RESET} Moves: $MOVES_COUNT (Limit $4) Output: [${YELLOW}$CLEAN_OUT${RESET}]"
                return
            fi
        fi
        echo -e "${GREEN}[OK]${RESET} Moves: ${COLOR}$MOVES_COUNT${RESET}"
    fi
}

echo -e "${YELLOW}--- INITIAL VALIDATION (Error Handling & Sorted) ---${RESET}"
run_test '""' "error" "Empty string"
run_test "1 2 2" "error" "Duplicate values"
run_test "2147483648" "error" "Greater than INT_MAX"
run_test "1 2 3 4 5" "sorted" "Already sorted"

echo -e "\n${YELLOW}--- INT EXTREMES & OVERFLOW ---${RESET}"
run_test "2147483647" "success" "Exact INT_MAX"
run_test "-2147483648" "success" "Exact INT_MIN"
run_test "-2147483649" "error" "Less than INT_MIN"
run_test "9999999999999999" "error" "Long long overflow"

echo -e "\n${YELLOW}--- STRING & FORMAT EDGE CASES ---${RESET}"
run_test "0 000" "error" "Numerical duplicate (0)"
run_test "++123" "error" "Multiple signs"
run_test "123-" "error" "Trailing sign"
run_test "1 2 3" "success" "Standard valid input"

echo -e "\n${YELLOW}--- STACK OF 3 ---${RESET}"
echo -e "${CYAN}Max moves allowed: 3${RESET}"
run_test "1 3 2" "valid" "Stack of 3 case 1" "3"
run_test "2 1 3" "valid" "Stack of 3 case 2" "3"
run_test "2 3 1" "valid" "Stack of 3 case 3" "3"
run_test "3 1 2" "valid" "Stack of 3 case 4" "3"
run_test "3 2 1" "valid" "Stack of 3 case 5" "3"

echo -e "\n${YELLOW}--- STACK OF 4 ---${RESET}"
echo -e "${CYAN}Max moves allowed: n/a (targeting < 12)${RESET}"
run_test "4 3 2 1" "valid" "Stack of 4 reverse" "12"
run_test "1 3 2 4" "valid" "Stack of 4 mixed" "12"
run_test "4 1 2 3" "valid" "Stack of 4 shift" "12"
run_test "2 4 3 1" "valid" "Stack of 4 random" "12"

echo -e "\n${YELLOW}--- STACK OF 5 ---${RESET}"
echo -e "${CYAN}Max moves allowed: 12${RESET}"
run_test "5 4 3 2 1" "valid" "Stack of 5 reverse" "12"
run_test "1 5 2 4 3" "valid" "Stack of 5 mixed" "12"
run_test "2 3 4 5 1" "valid" "Stack of 5 shift" "12"
run_test "5 1 2 3 4" "valid" "Stack of 5 random" "12"
run_test "1 2 3 5 4" "valid" "Stack of 5 small swap" "12"