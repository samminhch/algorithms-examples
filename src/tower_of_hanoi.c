#include <stdio.h>
#define SIZE 3

void hanoi(int, char, char, char);
int  main()
{
    int  numDisks = SIZE;
    char tower[SIZE] = {'A', 'B', 'C'};
    hanoi(numDisks, tower[0], tower[2], tower[1]);
}

void hanoi(int numDisks, char start, char end, char pivot)
{
    if (numDisks <= 0)
        return;

    hanoi(numDisks - 1, start, pivot, end);
    printf("Moved disk %d from '%c' to '%c'\n", numDisks, start, end);
    hanoi(numDisks - 1, pivot, end, start);
}

