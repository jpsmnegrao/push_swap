#!/bin/bash

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
YELLOW='\033[0;33m'
RESET='\033[0m'

if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap executable not found. Run 'make' first!${RESET}"
    exit 1
fi

run_test() {
    # 1. Run and capture all output (moves + debug info)
    ./push_swap $1 > /tmp/ps_raw_out 2> /dev/null
    RET=$?

    # 2. Extract ONLY valid instructions and count them
    # This ignores your "STACK A" labels and visualized numbers
    MOVES_COUNT=$(grep -E '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$' /tmp/ps_raw_out | wc -l)

    # 3. Run with Valgrind to check for leaks (exit 42 on error)
    valgrind --leak-check=full --error-exitcode=42 ./push_swap $1 > /dev/null 2>&1
    LEAK=$?

    # Formatting the output
    printf "Testing: [%-12s] " "$1"
    
    if [ $LEAK -eq 42 ]; then
        echo -e "${RED}[LEAK]${RESET}"
    elif [ $RET -ne 0 ] && [ "$2" != "error" ]; then
        echo -e "${RED}[CRASH]${RESET}"
    else
        # Color coding the move counts based on project efficiency limits
        if [ "$3" == "3" ] && [ $MOVES_COUNT -gt 3 ]; then
            echo -e "${GREEN}[OK]${RESET} Moves: ${RED}$MOVES_COUNT (Limit 3!)${RESET}"
        elif [ "$3" == "5" ] && [ $MOVES_COUNT -gt 12 ]; then
            echo -e "${GREEN}[OK]${RESET} Moves: ${RED}$MOVES_COUNT (Limit 12!)${RESET}"
        else
            echo -e "${GREEN}[OK]${RESET} Moves: ${CYAN}$MOVES_COUNT${RESET}"
        fi
    fi
}

echo -e "${YELLOW}--- ERROR HANDLING ---${RESET}"
run_test '""' "error"
run_test "1 2 2" "error"
run_test "2147483648" "error"

echo -e "\n${YELLOW}--- STACK OF 3 (Limit: 3 moves) ---${RESET}"
run_test "2 1 0" "valid" "3"
run_test "1 3 2" "valid" "3"
run_test "3 1 2" "valid" "3"

echo -e "\n${YELLOW}--- STACK OF 5 (Limit: 12 moves) ---${RESET}"
run_test "1 5 2 4 3" "valid" "5"
run_test "5 4 3 2 1" "valid" "5"
run_test "2 3 5 1 4" "valid" "5"

echo -e "\n${YELLOW}--- ALREADY SORTED ---${RESET}"
run_test "1 2 3 4 5" "valid"