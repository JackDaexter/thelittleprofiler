#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>   
#include <sys/resource.h> 


#include "../include/Macro_profiler.h"

FILE *F;

struct timespec start, finish;

int fact(int n){
    PROFILE
    int prod;
    if (n <= 1){
        return 1;
    }
    prod = n * fact(n-1);
    return prod;
}

int main(int argc, char **argv){
    PROFILE
    if(argc<2){
        fprintf(stderr,"Pas d'entier donnée!\n");
        return 0;
    }
	printf("%s! = %d\n",argv[1],fact(atoi(argv[1])));
	return 0;
}

