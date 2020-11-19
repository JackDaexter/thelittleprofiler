/**
 * \file Profiler.h
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 29-12-2018
 */
 
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <sys/time.h>   
#include <sys/resource.h> 
#include "../include/Profiler.h"
#include "../include/Macro_Profiler2.h"

FILE *F;

struct timespec start, finish;

/* Verify if a function already exist if Profiler array */
static int in_profiler(Profiler p[],char *name,int taille){
	PROFILE

    int i;
    
    for(i = 0; i < taille; i++){
        if(!strcmp(p[i].name_function,name)){
            return 1;
        }
    }
    return 0;
}


int number_function(Tree a, Profiler p[],int index) {
	PROFILE
	
	int x;
    int size;
    if(a == NULL){
        return 0;
	}
        
    if(in_profiler(p,a->function,index)){
        size = number_function(a->fg,p,index);
    }
    
    else{
        strcpy(p[index].name_function,a->function);
        size = 1 + number_function(a->fg,p,index+1);
    }
    x = size + number_function(a->frd,p,index+size);
	
	return x;
}

int number_call(Tree a,Profiler *p) {
	PROFILE
	
    int call = 1;
    
    if(a == NULL){
		return 0;
    }
    
    if(strcmp(a->function,p->name_function)){
		 
        call = 0;
    }
    
    
    p->number_call = call + number_call(a->fg,p) + number_call(a->frd,p);
	
	
	return p->number_call;
}

/*Calculation time duration for each function */
double time_per_function(Tree a ,Profiler *p){
	PROFILE
	
    double time=0;
    
    if(a == NULL){
        return 0;
    }
    
    if(!strcmp(a->function,p->name_function)){
        time=duree_function(a->time_function,a->time_end_function);
    }
    
    p->time_functions= time + time_per_function(a->fg,p)+time_per_function(a->frd,p);
	
	return p->time_functions;
}

/* Calculation time duration for each function (combine for function who have same name)*/
double time_per_call(Tree a ,Profiler *p,double *average_time){
    PROFILE
    
    p->average_time = time_per_function(a,p)/number_call(a,p);
    if(p->average_time > (*average_time))
		(*average_time) = p->average_time ;
		
    return p->average_time;
}

int create_profiler(Tree a,Profiler P[],double *average_time){
	PROFILE
	
    int size,i;
    size = number_function(a,P,0);
    
    for(i= 0; i < size; i++){
        number_call(a,&P[i]);
        time_per_function(a,&P[i]);
        
        time_per_call(a,&P[i],average_time);
    }
    
    return size;
}

/**
 *\fn static compareNumberCall1(const void * tab1,const void *tab2)
 * \brief function compare number_call of function 
 * 		  
 * \param tab1 number_call of first function
 * \param tab2 number_call of second function
 * 
 * \return 1 if second if bigger
 * \return -1 if it's the reverse
 * \return 0 if they are equals
 * */
static int compareNumberCall1(const void * tab1,const void *tab2){
	PROFILE
	
	Profiler *valeur1 = (Profiler *)tab1;
    Profiler *valeur2 = (Profiler *)tab2;
    
   
    if (valeur1->number_call < valeur2->number_call){
		return 1;
	}
	
	else if (valeur1->number_call > valeur2->number_call){
		return -1;
	}
	
	return 0;
}

/**
 *\fn static compareNumberCall2(const void * tab1,const void *tab2)
 * \brief function compare number_call of function 
 * 		  
 * \param tab1 number_call of first function
 * \param tab2 number_call of second function
 * 
 * \return 1 if first if bigger
 * \return -1 if it's the reverse
 * \return 0 if they are equals
 * */
static int compareNumberCall2(const void * tab1,const void *tab2){
	PROFILE
	
	Profiler *valeur1 = (Profiler *)tab1;
    Profiler *valeur2 = (Profiler *)tab2;
    
   
    if (valeur1->number_call > valeur2->number_call){
		return 1;
	}
	
	else if (valeur1->number_call < valeur2->number_call){
		return -1;
	}
	
	return 0;
}

/**
 *\fn static compareTime(const void * tab1,const void *tab2)
 * \brief function compare number_call of function 
 * 		  
 * \param tab1 time_functions of first function
 * \param tab2 time_functions of second function
 * 
 * \return 1 if second if bigger
 * \return -1 if it's the reverse
 * \return 0 if they are equals
 * */
static int compareTime(const void * tab1,const void *tab2){
	PROFILE
	
	Profiler *valeur1 = (Profiler *)tab1;
    Profiler *valeur2 = (Profiler *)tab2;
    
   
    if (valeur1->time_functions < valeur2->time_functions){
		return 1;
	}
	
	else if (valeur1->time_functions > valeur2->time_functions){
		return -1;
	}
	
	return 0;
}

/**
 *\fn static compareAverageTime(const void * tab1,const void *tab2)
 * \brief function compare average_time of functions
 * 		  
 * \param tab1 average_time of first function
 * \param tab2 average_time of second function
 * 
 * \return 1 if second if bigger
 * \return -1 if it's the reverse
 * \return 0 if they are equals
 * */
static int compareAverageTime(const void * tab1,const void *tab2){
	PROFILE
	
	Profiler *valeur1 = (Profiler *)tab1;
    Profiler *valeur2 = (Profiler *)tab2;
    
   
    if (valeur1->average_time < valeur2->average_time){
		return 1;
	}
	
	else if (valeur1->average_time > valeur2->average_time){
		return -1;
	}
	
	return 0;
}


void profiler_course(Profiler p[],int *navigation,int height,int width,int option,int number_of_function){
	PROFILE
	
	int i = 0;
	
	while(*navigation == 2){
		display_option_function(width,height);
		display_function_interface();
		
		if(option == 1){
			qsort(p,number_of_function,sizeof(Profiler),compareNumberCall2);
		}
		else if(option == 2){
			qsort(p,number_of_function,sizeof(Profiler),compareNumberCall1);
		}
		else if (option == 3){
			qsort(p,number_of_function,sizeof(Profiler),compareTime);
		}
		else if (option == 4){
			qsort(p,number_of_function,sizeof(Profiler),compareAverageTime);
		}
		
		for(i = 0; i < number_of_function;i++){
			display_function_informations(p[i].name_function,p[i].number_call,p[i].time_functions,p[i].average_time,i);
		}
		
		
		choose_sorts_function(navigation,&option);
	}
	return ;
}


void choose_file(Profiler **profile,FILE *in,char **text,Tree *a,int *number_of_function,double *average_time){
	PROFILE
	
	int nb_function = 0;
    in = fopen(*text,"r");
    (*a) = NULL;
	(*profile) = NULL;
	
	if(in != NULL){
		add_function(a,in,&nb_function);
		
		(*profile) = (Profiler *) malloc(nb_function * sizeof(Profiler));
		
		if(profile == NULL)
			exit(0);
			
		fclose(in);
		
		(*number_of_function) = create_profiler(*a,*profile,average_time);
		print_profiler(*profile,(*number_of_function));
	}
	else if ( in == NULL){
		*text = NULL; 
		display_error_message();
	}
	
	return ;
}

void print_profiler(Profiler P[],int size){
	PROFILE
	
    int i;
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("                       											total average \n");
    printf("name        	        |          calls   	     |             time             |          ms/calls \n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    
    for(i = 0; i < size; i++){
		printf("%s	    	        |",P[i].name_function);
		printf("   %4d 		     |",P[i].number_call);
		printf("   %2fs			    |",P[i].time_functions);
		printf("   %2fs		       |\n",P[i].average_time);
    }
    
    return ;
}
