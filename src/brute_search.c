#include <stdio.h>
#define ARR_LEN 100

void print_array(int *arr, int len);
int  brute_search(int *arr, int len, int num);
int  main() {
    int arr[ARR_LEN];

    for (int i = 0; i < ARR_LEN; i++) {
        arr[i] = i + 1;
    }

    print_array(arr, ARR_LEN);
    printf("What value would you like to search for? ");

    int num;
    scanf("%d", &num);

    int index = brute_search(arr, ARR_LEN, num);

    if (index == -1)
        printf("%d isn't in the array!\n", num);
    else
        printf("arr[%d] = %d\n", index, num);

    return 0;
}

int brute_search(int *arr, int len, int num) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == num) {
            return i;
        }
    }

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
