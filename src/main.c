/*
 * Main file
 * author: Vitor Carvalho <vitor.carvalho@ppgcc.ifce.edu.br>
 * date: 06/10/2015
 * filename: main.c
 */

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int rank, size;

  MPI_Init(&argc, &argv);
  MPI_Common_rank(MPI_COMM_WORLD, &rank);
  MPI_Common_size(MPI_COMM_WORLD, &size);

  printf("Hello, world! I am %d of %d\n", rank, size);

  MPI_Finalize();
  return 0;
}
