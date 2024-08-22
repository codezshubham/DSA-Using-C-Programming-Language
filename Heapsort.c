#include <stdio.h>

// To heapify a subtree rooted with node i.
// which is an index in arr[].
// n is size of heap.
void heapify(int arr[], int N, int i) {
    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--) // Leaf node itself max heap
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N) {
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, N);

    printf("Sorted array is \n");
    printArray(arr, N);

    return 0;
}
