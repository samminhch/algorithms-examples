#include <stdio.h>
#define ARR_LEN 100

#ifdef DEBUG
#include <unistd.h>
#endif

void print_array(int *arr, int len);
int  binary_search(int *, int, int);
int  main() {
    int arr[ARR_LEN];

    for (int i = 0; i < ARR_LEN; i++) {
        arr[i] = i + 1;
    }

    printf("Here is the array: ");
    print_array(arr, ARR_LEN);

    printf("What value would you like to search for? ");

    int num;
    scanf("%d", &num);

    int index = binary_search(arr, ARR_LEN, num);

    if (index == -1)
        printf("%d isn't in the array!\n", num);
    else
        printf("arr[%d] = %d\n", index, num);

    return 0;
}

int binary_search(int *arr, int len, int num) {
    int left = 0;
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

        mid_prev = mid;
        mid = (left + right) / 2;

#ifdef DEBUG
        printf("left = %d | right = %d | mid = %d | mid_prev = %d\n", left,
               right, mid, mid_prev);
        sleep(1);
#endif
    }

    // nothing was found, return -1
    return -1;
}

void print_array(int *arr, int len) {
    if (len < 1)
        return;

    printf("[%d, ", arr[0]);
    for (int i = 1; i < len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[len - 1]);
}
