#include <stdio.h>

void findMaxMin(int arr[], int l, int r, int *max, int *min) {
    if (l == r) {
        *max = *min = arr[l];
    } else if (l == r - 1) {
        if (arr[l] < arr[r]) {
            *min = arr[l];
            *max = arr[r];
        } else {
            *min = arr[r];
            *max = arr[l];
        }
    } else {
        int mid = (l + r) / 2;
        int max1, min1, max2, min2;
        findMaxMin(arr, l, mid, &max1, &min1);
        findMaxMin(arr, mid + 1, r, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}

int main() {
    int arr[] = {2, 3, 1, 7, 9, 5, 11, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    return 0;
}

