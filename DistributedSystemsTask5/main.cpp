#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {


    int myrank, size;
    MPI_Init(&argc, &argv);
    MPI_Status stat;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 100;
    int start = n * myrank / size+1;
    int end = ((n * (myrank + 1)) / size);
    int sum = 0;
    int i = 0;

    printf("Start > %d , End > %d \n", start, end);

    for (i = start; i <= end; i++) {

        sum += i;
    }


    if (myrank != 0) {
        MPI_Send(&sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    } else {
        int sumOfThreadSums = 0;
        int fin = sum;
        for (int k = 1; k < size; k++) {
            MPI_Recv(&sumOfThreadSums, 1, MPI_INT, k, 1, MPI_COMM_WORLD, &stat);
            fin = fin + sumOfThreadSums;
        }
        printf("Sum is %d\n", fin);
    }


    MPI_Finalize();


    return 0;
}