/**
 * \file Tree.h
 * \brief Take care of the Tree create with all call functions
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 20-12-2018
 */

#ifndef __TREE__
#define __TREE__
#include <stdio.h>
#include "../include/Graphic.h"

/**
 * \struct Tree
 * \brief Register the name,time execution,and son of the execution program
 * 
 * */
typedef struct tree{
    char *function;
    double time_function;
    double time_end_function;
    struct tree *fg,*frd;
}Node,*Tree;

/** 
 * \param function_name take the name of the function in the file
 * \param time Take the time execution of the function
 * \return Link to Tree, NULL is there is allocation problem
 * */
Tree alloue_noeud(char *function_name, double time);

/** 
 * \param begin take the time of the start of the function
 * \param end Take the time of the end of the function
 * \return Double value who represent the duration function
 * */
double duree_function(double begin, double end);

/** 
 * \brief This recursive function ,course the file and add all the function
 * 		  declared in the file and add them in the tree
 * \param *a Take a pointer toward a node of Tree structure
 * \param f Pointer to a link file
 * \param nb_function  return how many differents function has been loaded
 * \return Double value
 * */
double add_function(Tree *a, FILE* f,int *nb_function);

/** 
 * \brief Use like initializer towards another recursive file
 * 		  who course recursively the tree to display all
 * 		  function who can be display without size problem
 *  
 * \param *a Take a pointer toward a node of Tree structure
 * \param height Height of the window
 * \param width Width of the window
 * \param average_time value of the maximum time execution function
 * \return Nothing
 * */
void tree_course(Tree a,int height,int width,double average_time);

/**
 * \brief Freeing of the allocate tree properly
 * \param *a pointer of the root tree
 * */
void destroy_tree(Tree *a);


#endif
