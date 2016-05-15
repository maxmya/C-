#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {


    int myrank, sizex;
    MPI_Init(&argc, &argv);
    MPI_Status stat;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &sizex);
    int part[25];
    int singleSum = 0;
    int allSum = 0;
    int TotalSum = 0;

    int size = sizex - 1;

    int n = 100;
    int start = n * myrank / (size) + 1;
    int end = ((n * (myrank + 1)) / (size));

    if (myrank == 0) {

        int sum[100];
        for (int j = 0; j < 100; j++) {
            sum[j] = j + 1;
        }
        for (int i = 1; i < sizex; i++) {
            MPI_Send(&sum, 100, MPI_INT, i, 1, MPI_COMM_WORLD);
        }

    } else {

        MPI_Recv(&part, 100, MPI_INT, 0, 1, MPI_COMM_WORLD, &stat);
        printf("Start > %d , End > %d\n", start, end);
        for (int i = start; i < end; ++i) {
            singleSum += part[i];
        }
        printf("i am %d i send %d\n", myrank, singleSum);
        MPI_Send(&singleSum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);

    }

    if (myrank == 0) {

        for (int i = 1; i < sizex; i++) {
            MPI_Recv(&allSum, 1, MPI_INT, i, 2, MPI_COMM_WORLD, &stat);
            TotalSum += allSum;
        }

    }


//    for (int k = start; k < end; ++k) {
//        printf("I am %d received %d \n", myrank, part[k]);
//    }

    MPI_Finalize();


    return 0;
}