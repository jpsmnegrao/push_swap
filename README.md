# push_swap

## Description

`push_swap` is a 42 School project that sorts a stack of integers using a
limited set of stack operations. The program outputs a sequence of instructions
that can sort the input in ascending order, aiming to minimize the number of
moves.

This implementation uses array-based stacks, coordinate compression,
specialized sorting for small inputs, and a chunk-based algorithm with a
dynamic window for larger inputs.

## Algorithm

- **Indexing:** Input values are converted to their ranks in sorted order, from
  `0` to `n - 1`.
- **Small inputs:** Dedicated logic handles 2 and 3 elements. For 4–5 elements,
  the minimum values are pushed to stack B while the remaining three are
  sorted, then the saved values are pushed back.
- **Larger inputs:** A dynamic chunk window determines which indexed values
  are pushed from stack A to B. Rotations help position values during this
  phase. The algorithm then repeatedly brings the maximum value in B to the top
  and pushes it back to A.
- **Input validation:** Rejects invalid integers, values outside the `int`
  range, and duplicates.

## Instructions

### Compile

Build the program using the Makefile:

```bash
make
```

This creates the `push_swap` executable.

Other Makefile commands:

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Rebuild everything
```

### Run

Pass integers as separate arguments:

```bash
./push_swap 4 2 1 3
```

Or provide them as a single space-separated argument:

```bash
./push_swap "4 2 1 3"
```

The program prints the operations needed to sort the stack. If the input is
already sorted, it prints nothing.

Invalid input, including duplicate values or integers outside the valid `int`
range, produces an `Error` message.

### Check the result

If you have a compatible checker available, pipe the generated instructions
into it. For example, with the included Linux checker:

```bash
ARG="4 2 1 3"
./push_swap $ARG | ./checker_linux $ARG
```

A successful sort should return `OK`.

## Stack Operations

| Operation | Description |
|---|---|
| `sa`, `sb` | Swap the top two elements of A or B |
| `ss` | Swap the top two elements of both stacks |
| `pa`, `pb` | Push the top element from one stack to the other |
| `ra`, `rb` | Rotate a stack upwards |
| `rr` | Rotate both stacks upwards |
| `rra`, `rrb` | Reverse-rotate a stack |
| `rrr` | Reverse-rotate both stacks |

## Testing

The repository includes pstester.sh, an optional development script that tests
input validation, integer boundaries, edge cases, move counts, and randomized
inputs. It also uses Valgrind to check for memory errors.

To run the tester:

```bash
chmod +x pstester.sh
./pstester.sh
```

Requirements for the tester: Bash, Valgrind, and standard command-line
utilities such as seq, shuf, grep, wc, and tr.

Note that the script checks several correctness-related conditions and move
limits, but does not independently verify that every generated sequence sorts
correctly. Use checker_linux for that verification.

## Project Structure

- `push_swap.c` — program entry point and sorting dispatch.
- `push_swap.h` — data structures and function declarations.
- `ft_parse_input.c` and `ft_*.c` — input parsing, validation, and utility
  functions.
- `op_*.c` — stack operations.
- `sorting_utils.c` — indexing and sorting helpers.
- `sort_small.c` — specialized sorting for small stacks.
- `sort_large.c` — chunk-based sorting for larger stacks.
- `pstester.sh` — development test script.
- `checker_linux` — included checker executable.

## Requirements

- C compiler (`cc`)
- Make
- Bash and Valgrind for the optional tester
  