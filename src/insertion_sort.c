#include <stdio.h>

#ifdef DEBUG
#include <unistd.h>
#endif

void print_array(int *, int);
void insertion_sort(int *, int);
int  main()
{
    int len = 6;
    int arr[] = {52, 76, 40, 18, 24, 100};

    printf("Original array:\n\t");
    print_array(arr, len);
    printf("\n");

    insertion_sort(arr, len);

    printf("Sorted array:\n\t");
    print_array(arr, len);
    printf("\n");
    return 0;
}

void insertion_sort(int *arr, int len)
{
    int key, j;
    for (int i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
#ifdef DEBUG
        printf("\t");
        print_array(arr, len);
        fflush(stdout);
        sleep(2);
        printf("\r");
#endif
        arr[j + 1] = key;
    }

#ifdef DEBUG
    printf("\n");
#endif
}

void print_array(int *arr, int len)
{
    if (len < 1)
        return;

    printf("[%d, ", arr[0]);
    for (int i = 1; i < len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[len - 1]);
}
