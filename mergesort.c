#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int n = high - low + 1;
    int i, j, k;
    i = low;
    j = mid + 1;
    k = 0;
    int* b = (int*)malloc(n * sizeof(int));

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < n; x++) {
        arr[low + x] = b[x];
    }

    free(b);
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {7, 20, 4, 11, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
