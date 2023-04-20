#include <stdio.h>
#define ARR_LEN 10

#ifdef DEBUG
#include <unistd.h>
#endif

void print_array(int *arr, int len);
void selection_sort(int *arr, int len);
int  main() {
    int arr[ARR_LEN] = {23, 353, 6, -2, 0, 8, 678, -176, 3, 69};

    printf("Original array: ");
    print_array(arr, ARR_LEN);

    selection_sort(arr, ARR_LEN);

    printf("Sorted array: ");
    print_array(arr, ARR_LEN);

    return 0;
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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {

        int min_idx = i;
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[i], &arr[min_idx]);
#ifdef DEBUG
        printf("swap(&arr[%d], &arr[%d]) | ", i, min_idx);
        print_array(arr, ARR_LEN);
        sleep(1.5);
#endif
    }
}
