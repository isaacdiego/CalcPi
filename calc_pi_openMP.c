#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>

int main(int argc, char *argv[]){
	double pi[omp_get_max_threads()];
	int nmax, n, h;
	double r1, r2, pi_final;
	struct timeval t1,t2;
	gettimeofday(&t1,NULL);

	# pragma omp parallel private(n, h, r1, r2, nmax)
	{
		h = 0;
		nmax = atoi(argv[1])/(omp_get_max_threads());
		srand48((int) time(NULL) ^ omp_get_thread_num());
		for (n=0; n<=nmax; n++){
			r1 = drand48();
			r2 = drand48();
			if(((r1*r1)+(r2*r2)) <= 1)
				h++;
		}
		pi[omp_get_thread_num()] = (4.0*h)/(n);
	}
	pi_final = 0;
	for (n=0; n<omp_get_max_threads(); n++)
		pi_final += (float) pi[n]/omp_get_max_threads(); 
	gettimeofday(&t2,NULL);
	printf("Valor aproximado de pi:%e\n", pi_final);
	float time = (t2.tv_sec + t2.tv_usec*0.000001) - (t1.tv_sec + t1.tv_usec*0.000001);
	printf("Tempo de execução: %e\n", time);
	return 0;
}
