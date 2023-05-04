#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int maxSubArray(int arr[], int n) {
    int max_so_far = arr[0];
    int curr_max = arr[0];
    #pragma omp parallel for reduction(max: max_so_far) private(curr_max)
    for (int i = 1; i < n; i++) {
        curr_max = (arr[i] > curr_max + arr[i]) ? arr[i] : curr_max + arr[i];
        if (curr_max > max_so_far) {
            max_so_far = curr_max;
        }
    }
    return max_so_far;
}

int main() {
    int n = 10000000;
    int* arr = (int*)malloc(sizeof(int) * n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 2001 - 1000;
    }
    clock_t start_time = clock();
    int max_sum = maxSubArray(arr, n);
    clock_t end_time = clock();
    printf("Maximum subarray sum is %d\n", max_sum);
    printf("Execution time: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    free(arr);
    return 0;
}
