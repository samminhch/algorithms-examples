#include <stdio.h>
#define ARR_LEN 10

#ifdef DEBUG
#include <unistd.h>
#endif

void print_array(int *arr, int len);
void quick_sort(int *arr, int low, int high);
int  main() {
    int arr[ARR_LEN] = {23, 353, 6, -2, 0, 8, 678, -176, 3, 69};

    printf("Original array: ");
    print_array(arr, ARR_LEN);

    quick_sort(arr, 0, ARR_LEN - 1);

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

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);

    swap(&arr[i + 1], &arr[high]);
    #ifdef DEBUG
    printf("pivot: arr[%d]=%-4d | ", high, arr[high]);
    print_array(arr, ARR_LEN);
    sleep(1.5);
    #endif
    return i + 1;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int part_idx = partition(arr, low, high);
        quick_sort(arr, low, part_idx - 1);
        quick_sort(arr, part_idx + 1, high);
    }        
}
