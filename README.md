# CalcPi
Experiments on OpenMP

This three programs are independ and do the same thing: calculate a approximation of pi using an statistical approach of the Archimedes' method. You can use theses three programs as an use case on how to parallelize a program using OpenMP. 

The file 'calcpi.c' is the serial version of the program. To compile it, use (on linx): $ gcc calcpi calcpi.c 

The file 'calc_pi_openMP.c' is a parallel version of the program that have performance issues. To compile it, use (on linx): $ gcc -fopenmp -o calc_pi_openMP calc_pi_openMP.c

The file 'calc_pi_openMP_better.c' is an efficient parallel version of the program that runs on shorter times than the other two versions. To compile it, use (on linx): $ gcc -fopenmp -o calc_pi_openMP_better calc_pi_openMP_better.c
