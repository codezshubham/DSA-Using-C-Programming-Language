#include <stdio.h>

void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (!flag) {
            return;
        }
    }
}

int main() {
    int arr[] = {5, 7, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
