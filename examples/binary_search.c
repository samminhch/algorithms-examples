#include <stdio.h>
#include <unistd.h>
#include "../utils/arr_utils.h"
#define RAND_RANGE 15

int binary_search(int *, int, int); 
int binary_search_estimate(int *, int, int);
int main() {
    int len = 5;
    int arr[len];

    fill_random(arr, len, RAND_RANGE);

    printf("Here is the array: ");
    print_array(arr, len);

    printf("What value would you like to search for? If it's not in "
           "the array, I can tell you what index it would belong in :)\n");

    int num;
    scanf("%d", &num);
    
    int index = binary_search_estimate(arr, len, num);
    printf("%d should be located at index %d\n", num, index);
}

int binary_search(int *arr, int len, int num) {
    int left  = 0;
    int right = len;
    int mid_prev = -1;
    int mid = (left + right) / 2;

    while (left < right) {
        if (mid_prev == mid)
            return -1; // the number isn't in the array!
        else if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            left = mid;
        else
            right = mid;

        sleep(1);

        mid_prev = mid;
        mid = (left + right) / 2;
    }
    return mid;
}

int binary_search_estimate(int *arr, int len, int num) {
    int left  = 0;
    int right = len;
    int mid_prev = -1;
    int mid = (left + right) / 2;

    while (left < right) {
        printf("left: %d, right: %d, mid: %d\n", left, right, mid);

        if (mid_prev == mid)
            return arr[mid] > num ? mid + 2 : mid + 1;
        else if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            left = mid;
        else
            right = mid;

        sleep(1);

        mid_prev = mid;
        mid = (left + right) / 2;
    }
    printf("\nleft: %d, right: %d\n", left, right);
    return mid;
}
