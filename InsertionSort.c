#include <stdio.h>

void insertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;

        while (j > 0 && arr[j] < arr[j - 1]){
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

int main() {
    int arr[] = {8, 3, 6, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}