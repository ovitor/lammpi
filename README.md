## lammpi
---

Trying to understand LAM and [open mpi](http://www.open-mpi.org/) programming.

## set enviroment and compiling
This program was tested in `Ubuntu vivid` and `Debian jessie`. You can run `env.sh`
file to install all dependencies.

To compile, run the following command:
```
$ mpicc.lam src/main.c -o bin/main.o
```

## references
* [Instalando o LAM-MPI no Debian (pt-br)](http://www.dct.ufms.br/~marco/paralelos2006/lammpi-debian.pdf)
* [Message Passing Interface (en-us)](http://beige.ucs.indiana.edu/B673/node113.html)
