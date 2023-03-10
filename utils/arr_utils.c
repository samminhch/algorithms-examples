#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void fill_random(int *arr, int len, int range) {
    time_t current_time;
    time(&current_time);
    srand(current_time);
    // Fill array with random numbers
    for (int i = 0; i < len; i++) {
      arr[i] = ( rand() % range ) + range * i;
    }
}

void print_array(int *arr, int len) {
    printf("[");
    for (int i = 0; i < len - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d]\n", arr[len - 1]);
}
