/*
 * Main file
 * author: Vitor Carvalho <vitor.carvalho@ppgcc.ifce.edu.br>
 * date: 06/10/2015
 * filename: main.c
 */

#include <stdio.h>
#include <mpi.h>

#define BUFSIZE 100

int main(int argc, char *argv[]) {
  int rank, size;
  int length;
  char name[BUFSIZ];

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Get_processor_name(name, &length);

  printf("Hello from: %s! I am %d of %d\n", name, rank, size);

  MPI_Finalize();
  return 0;
}
