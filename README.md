# push_swap

## Description

The project's goal is to write an algorithm that takes an unsorted list of numbers and prints the actions needed to sort them by using 2 stacks (stack a and stack b) in the least(ish) amount of moves. The avaliable actions are :

- sa, swap a : swaps the first 2 items of stack a
- sb, swap b : same with b
- ss : swap a and swap b

- ra, rotate a : delete the 1st (topmost) number of a and put it at the bottom of a
- rb, rotate b : same with b
- rr : rotate a and b

- rra, reverse rotate a : delete the last number of a and put it at the top of a
- rrb, reverse rotate b : same with b
- rrr : reverse rotate a and b

- pb, push a : delete the first number of a and put it on top of b
- pa, push b : delete the first number of b and put it on top of a

## My approach

I use 2 linked lists to manage the actions and some helper functions that find values, value indexes and whether it's faster to r or rr to get to a given index. I use a few different algorithms for different list sizes.

- 3 numbers are sorted with a function that checks for every possible arrangement of 3 numebrs and sorts it in the least actions possible.
- 6 numbers are sorted by splitting the list in 2 and then using the 3 number function (or the inverse of it for stack b) and then combining them again
- 7 - 120 numbers are sorted by repeatedly splitting stack a along a value (pushing the smaller elements than that value to stack b). The splitting value is initially set as 1/4th of its the set's median. Then, it is being recalculated at each iteration in order to waste the least amount of pb, until whatever is left in stack a is sorted. Then the algo becomes a version of selection sort that repeatedly pushes the biggest element of b back to a, until b is empty
- more than 120 numbers are sorted by repeatedly splitting stack a along the current median until a is sorted or empty, marking that split, then calculating the median between the marked splits in b and pushing the largest elements to a until b is empty. Then, a is split into even smaller pieces, pb until it is empty or sorted. Finally, a sort of selection sort is used to repeatedly push the biggest element of b back to a, until b is empty.

This is kind of using elements of quicksort for the largest set, except it's iterative. There's a problem with my split markings, wchich can make a rogue set of close values appear where it doesn't belong, making selection sort waste a lot of rotations to put them back in order, but the number of actions outputted is under the project's requirements. It's worth noting that because the algo does so many operations, like calculating the set's median for each split, it is terribly inneficient at actually sorting the numbers.

## Example

Here's a visualisaton of my algorithm sorting a random set of 500 numbers, made with [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer).

[![sort](https://i3.ytimg.com/vi/od3ST5zWNL4/hqdefault.jpg)](https://youtu.be/od3ST5zWNL4)