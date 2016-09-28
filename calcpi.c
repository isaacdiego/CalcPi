#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
	int n = 0;
	int h = 0;
	double r1, r2;
	int nmax = atoi(argv[1]);
	struct timeval t1,t2;	
	srand48(time(NULL));
	gettimeofday(&t1,NULL);	
	while(n<=nmax){
		r1 = drand48();
		r2 = drand48();
		if(((r1*r1)+(r2*r2)) <= 1)
			h++;
		n++;
	}
	double pi = (4.0*h)/n;
	gettimeofday(&t2,NULL);
	printf("Valor aproximado de pi por %d iterações:%e\n", nmax, pi);
	float time = (t2.tv_sec + t2.tv_usec*0.000001) - (t1.tv_sec + t1.tv_usec*0.000001);
	printf("Tempo de execução: %e\n", time);
	return 0;
}
