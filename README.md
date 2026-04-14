_This project has been created as part of the 42 curriculum by akhalfou._

---

# Description:
pushswap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (a and b) and a limited set of operations, while producing the minimum number of instructions possible.
The program reads a list of integers as arguments and outputs to stdout the sequence of operations needed to sort them in ascending order on stack a. 

# Instructions:
This will compile the project and produce the pushswap binary:
## Compilation:
make
make clean
make fclean
make re

## Usage:
./pushswap 3 1 4 1 5 9 2 6
./pushswap "3 1 4 5 9 2 6"
The program outputs the list of operations to sort the stack, one per line. If the input is already sorted, nothing is output.

## Error handling
The program prints Error to stderr and exits if:
- An argument is not a valid integer
- A value is out of the int range (< -2147483648 or > 2147483647)
- There are duplicate values

#Algorithm Explanation

- Indexing
Before sorting, each value is replaced by its rank (index from 0 to n-1) using index of stack(). This simplifies comparisons and allows the radix sort to work on indices instead of raw values.

-Sorting strategy
The algorithm adapts based on input size:
SizeStrategy: 
1 :Already sorted
2: one (sa) if needed
3: sortthree — brute-force with at most 2 operations
4–5 : sortfive — push minimums to b, sort3 on (a), push back
6: radixbig — bitwise radix sort

- Radix sort (for 6+ elements)
The radix sort works bit by bit, from the least significant to the most significant bit of each element's index:

For each bit position i:
Iterate through all elements in a.
If bit i of the current element's index is 0 → push to b (pb)
If bit i is 1 → rotate a (ra)
After processing all elements, push everything back from b to a (pa)

# Ressources:

## documentation: 
- pushswap — The least amount of moves with two stacks
- radix Sort — Wikipedia
- visualizer for pushswap
- openclassroom
- gitbook 

---

**AI Usage: README structure and algorithm explanation. AI was only for purpose comprehension**
