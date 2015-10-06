/*
 * Main file
 * author: http://beige.ucs.indiana.edu/B673/node123.html
 * date: 06/10/2015
 * filename: master.c
 */

#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define TRUE 1
#define FALSE 0
#define MASTER_RANK 0

main(argc, argv)
int argc;
char *argv[];
{
   int count, pool_size, my_rank, my_name_length, i_am_the_master = FALSE;
   char my_name[BUFSIZ], master_name[BUFSIZ], send_buffer[BUFSIZ],
        recv_buffer[BUFSIZ];
   MPI_Status status;

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &pool_size);
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
   MPI_Get_processor_name(my_name, &my_name_length);

   if (my_rank == MASTER_RANK) {
      i_am_the_master = TRUE;
      strcpy (master_name, my_name);
   }

   MPI_Bcast(master_name, BUFSIZ, MPI_CHAR, MASTER_RANK, MPI_COMM_WORLD);

   sprintf(send_buffer, "hello %s, greetings from %s, rank = %d",
           master_name, my_name, my_rank);
   MPI_Send (send_buffer, strlen(send_buffer) + 1, MPI_CHAR,
             MASTER_RANK, 0, MPI_COMM_WORLD);

   if (i_am_the_master) {
      for (count = 1; count <= pool_size; count++) {
         MPI_Recv (recv_buffer, BUFSIZ, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG,
                   MPI_COMM_WORLD, &status);
         printf ("%s\n", recv_buffer);
      }
   }
   MPI_Finalize();
}
