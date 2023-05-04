#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int maxSubArray(int arr[], int n) {
    int max_so_far = arr[0];
    int curr_max = arr[0];
    for (int i = 1; i < n; i++) {
        curr_max = (arr[i] > curr_max + arr[i]) ? arr[i] : curr_max + arr[i];
        max_so_far = (curr_max > max_so_far) ? curr_max : max_so_far;
    }
    return max_so_far;
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int n = 100000000;
    int* arr = (int*)malloc(sizeof(int) * n);
    if (rank == 0) {
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 2001 - 1000;
        }
    }
    int local_n = n / size;
    int* local_arr = (int*)malloc(sizeof(int) * local_n);
    MPI_Scatter(arr, local_n, MPI_INT, local_arr, local_n, MPI_INT, 0, MPI_COMM_WORLD);
    clock_t start_time = clock();
    int local_max_sum = maxSubArray(local_arr, local_n);
    int global_max_sum;
    MPI_Reduce(&local_max_sum, &global_max_sum, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    clock_t end_time = clock();
    if (rank == 0) {
        printf("Maximum subarray sum is %d\n", global_max_sum);
        printf("Execution time: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    }
    free(arr);
    free(local_arr);
    MPI_Finalize();
    return 0;
}
