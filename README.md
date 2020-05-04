# push_swap

A fast stack sorter, with a limited instruction set.

![Recordit GIF](https://i.ibb.co/RgGT3Ss/ezgif-com-crop.gif)

## Rules

- Numbers in stack can be moved only with a limited instruction set.
- You have only two stacks (A and B) to manipulate numbers.
- The unsorted stack is received in stack A.
- At the end, all numbers must be sorted in stack A, and stack B must be empty.
- Find the shortest possible instruction sequence.

![Image description](https://i.ibb.co/WFhBhQ2/iii-3-1.png)

# Instruction Set

- SA : Swap the first two elements at the top of stack A.
- SB : Swap the first two elements at the top of stack B.
- SS : SA and SB at the same time.

- PA : Take the first element at the top of B and put it on A.
- PB : Take the first element at the top of A and put it on B.

- RA : Shifts all elements of stack A up one position.
- RB : Shifts all elements of stack B up one position.
- RR : RA and RB at the same time.

- RRA : Shifts all elements of stack A down one position.
- RRB : Shifts all elements of stack B down one position.
- RRR : RRA and RRB at the same time.

## Usage

```bash
make

# find the best instruction sequence
./push_swap 2 9 8 1 4

# check the instruction sequence
./push_swap 2 9 8 1 4 | ./checker 2 9 8 1 4

# generate a random stack
ARG=$(./generator 10); echo $ARG

# check the instruction sequence with the random stack
ARG=$(./generator 200); ./push_swap $ARG | ./checker $ARG
```

### Options

- -v : Show stack A and B during sorting.
- -c : Add some colors.
- -n : Print the instruction number.
- -h : Help section.
- -f : Read numbers from file.

```bash
ARG=$(./generator 10); echo -n $ARG > file.txt; ./push_swap -v -c -n -f file.txt
```