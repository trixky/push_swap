# push_swap

A simple fast stack sorter, with a limited set of instructions.

![Recordit GIF](https://i.ibb.co/RgGT3Ss/ezgif-com-crop.gif)

## Rules

- Numbers in stack can be moved only with limited instruction set.
- You have only two stacks (A and B) to manipulate numbers.
- The stack to be sorted is received in stack A.
- At the end, all the numbers must be sorted in stack A and stack B must be empty.

![Image description](https://i.ibb.co/92mNwRL/iii-2.png)

# Instruction set

- SA : intervertir les deux premiers éléments au sommet de la pile A.
- SB : intervertir les deux premiers éléments au sommet de la pile B.
- SS : SA and SB at the same time.

- PA : take the first element at the top of B and put it on A.
- PB : take the first element at the top of A and put it on B.

- RA : shifts all the elements of stack A up one position.
- RB : shifts all the elements of stack B up one position.
- RR : RA and RB at the same time.

- RRA : shifts all the elements of stack A down one position.
- RRB : shifts all the elements of stack B down one position.
- RRR : RRA and RRB at the same time.


## Usage

```bash
make
```

> find the best instruction sequence :

```bash
./push_swap 2 9 8 1 4
```

> check the instruction sequence :

```bash
./push_swap 2 9 8 1 4
```

> generate a random stack :

```bash
ARG=(./generator 10); echo ARG
```

> check the instruction sequence with the random stack :
```bash
ARG=(./generator 10); echo ARG
```

### Options

- -v (show stack A and B during sorting)
- -c (add some colors)
- -n (print the instruction number)
- -h (help section)
- -f (read numbers from file)

```bash
ARG=$(./generator 10); echo -n $ARG > file.txt; ./push_swap -v -c -n -f file.txt
```