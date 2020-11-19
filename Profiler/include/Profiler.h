/**
 * \file Profiler.h
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 29-12-2018
 */


#ifndef __PROFILER__
#define __PROFILER__
#include "../include/Graphic.h"
#include "../include/Option.h"
#include "../include/Tree.h"


/**
 * \struct Profiler
 * \brief Objects about stockage differents information about functions
 * 
 * Profiler is a structure whopermit us to stock information of function here and 
 * find us more easily and sorts them more easily too
 * */
typedef struct {
    char name_function[200];
    int number_call;
    double time_functions;
    double average_time;
}Profiler;


/** 
 * \brief Calcul the number of differents function in the Tree a
 * \param *a Pointer toward the Tree a
 * \param p[] Pointer towards the structure Profiler
 * \return Nothing
 * */
int number_function(Tree a, Profiler p[],int index);
/**
 * \brief Send back the total call number of each function in the Tree
 * \param *p Profiler array
 * \param a Is the Tree a
 * */
int number_call(Tree a, Profiler *p);

/**
 * \brief Send back the total time of function execution
 * \param *p Profiler array
 * \param a Is the Tree a
 * */
double time_per_function(Tree a ,Profiler *p);
/**
 *\brief Send back the average time for each function about  
 *       all the call
 * \param *p Profiler array
 * \param a take maximum time between all function  
 * */
double time_per_call(Tree a,Profiler *p,double *average_time);

/**
 *\brief Create simply a profiler with element present in array a
 * \param p[] Profiler array
 * \param a Is the Tree a
 * \param *average_time take maximum time between all function 
 * */
int create_profiler(Tree a,Profiler P[],double *average_time);
/**
 *\brief Write the profiler and other details in a file
 * \param p[] Profiler array
 * */
void print_profiler(Profiler P[],int size);

/**
 *\brief Sort all differents function present in Profiler structure
 *       in function of the user choice and display them
 *       on the screen
 * \param *p Profiler array
 * \param *navigation this pointer virify if the user click or not on back button
 * \param height Height of the window
 * \param width WIDTH of the window
 * \param option is value aboutthe about click by the user
 * \param number_of_function is the numder of function present 
 * */
void profiler_course(Profiler p[],int *navigation,int height,int width,int option,int number_of_function);

/**
 * \brief This function course the file *in,add the differents function  in it in a Tree
 * 		   allocate the place necessary for the Profiler array and put 
 *         necessary informations in it
 * \param **profile pointer of pointer of Profiler array
 * \param *in Pointer to a file where is the program profiler
 * \param **text Pointer of the file name give by the user
 * \param *a Pointeur towards node tree
 * \param *number_of_function was loaded
 * \param *average_time take maximum time between all function  
 * \return Nothing
 * */
void choose_file(Profiler **profile,FILE *in,char **text,Tree *a,int *number_of_function,double *average_time);


#endif
