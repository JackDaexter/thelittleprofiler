/**
 * \file Tree.c
 * \brief All function about tree
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 20-12-2018
 */
 
#define _POSIX_C_SOURCE 199309L
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <sys/time.h>   
#include <sys/resource.h> 
#include "../include/Tree.h"
#include "../include/Macro_Profiler2.h"
FILE *F;

struct timespec start, finish;


Tree alloue_noeud(char *function_name,double time){
    PROFILE
    
    Tree tmp=NULL;
    
    tmp = (Node*)malloc(sizeof(Node));
    
    if(tmp==NULL){
        return NULL;
    }
    
    tmp->function=(char*)malloc(sizeof(char));
    strcpy(tmp->function,function_name);
    tmp->time_function = time;
    tmp->time_end_function=0;
	tmp->fg = NULL;
	tmp->frd = NULL;
	
    return tmp;
}


double add_function(Tree *a,FILE* f,int *nb_function){
	PROFILE
	
	double x;
	char *nom_f;
    double temps_f;
	nom_f=(char*)malloc(sizeof(char));
    
	if (fscanf(f,"%s -- time : %lfs ",nom_f,&temps_f) == EOF){
		return 0;
	}
    if((*a) == NULL){
		
        if (!strcmp(nom_f, "END")){
			return temps_f;
		}
		(*nb_function) += 1;
        (*a)=alloue_noeud(nom_f,temps_f);
      
    }
    
    temps_f = add_function(&(*a)->fg, f, nb_function);
	
	if (temps_f) {
        (*a)->time_end_function=temps_f;
		x = add_function(&(*a)->frd, f,nb_function);
		return x;
	}
	return 0;
}

double duree_function(double begin, double end) {
	PROFILE
	return end - begin;
}

/**
 *\fn static int nb_function(Tree a,int *i)
 * \brief Return brother number of the node a
 * 		  
 * \param a Node of the Tree a
 * \param *i Is the number of brother
 * 
 * \return 0
 * */
 
 static int nb_function(Tree a,int *i){
		PROFILE
		
		if(a == NULL){
			return 0;
		}
		
		if(a->frd != NULL){
			
			(*i) = (*i) + 1;
		    nb_function(a->frd,i);
			return 0;
		}
		(*i)  = (*i) + 1;
			
		return 0;
}


/**
 *\fn static void course_son(Tree a,int nb_brother,int which_bro,int nb_son,int height,int width,int pos_x,int pos_y,int father_posx,int father_height)
 * \brief Course the node of the Tree a , display all the different function who can be
 * 		  
 * \param a Node of the Tree a
 * \param nb_brother Is the number of brother of a node in precedent recursivity
 * \param which_bro how many brother has already be analyse
 * \param nb_son Is how many son has already be course, and our position in the Tree
 * \param height height of the function
 * \param width  width of the function
 * \param pos_x postion x of the function on the window
 * \param pos_y postion y of the function on the window
 * \param father_posx position x of the father node
 * \param father height height of the father node
 * 
 * 
 * \return Nothing
 * */
 
static void course_son(Tree a,int nb_brother,int which_bro,int nb_son,int height,int width,int pos_x,int pos_y,int father_posx,int father_height,double average_time){
	PROFILE
	
	
	if( a == NULL){
		return ;
	}
	
	double time = duree_function(a->time_function,a->time_end_function);
	
	
	/*the size of square depend of the number of brother he have */
	if(nb_brother == 0){
		
		nb_function(a,&nb_brother);
		
		if(nb_brother > 1){
			if(nb_brother > 6)
				nb_brother = 6;
				
			height /= (nb_brother);
			width  /= (nb_brother);
		}
	}
	
	
	/* If the representation ofthe sonof the precedent functionis represent
	 * out of him, wedisplay 3 points*/
	
	 
	if(father_height+ 10 < (pos_y + height) || width < 86){
		display_point(pos_x - 10,pos_y - 10,width,height);
		return ;
	}
	else if(width >= 86){
		display_function(pos_x,pos_y,width,height,a->function,time,average_time);
		
	}
	
	
	course_son(a->fg, 0,0,nb_son + 1, height-50, width-90, pos_x + 7,pos_y + 30,pos_x,(height + pos_y),average_time);
	
	/*If there is 4 function display on the same line, we go on the under line to have more place*/
	if(which_bro % 4 == 0 && which_bro > 0){
		which_bro = 0;
		pos_x = father_posx + 7;
		pos_y += (width + 50 ) / 2;
		
		course_son(a->frd,nb_brother,which_bro,nb_son,height,width, pos_x ,pos_y,father_posx,father_height,average_time);
	}
	else
		course_son(a->frd,nb_brother,which_bro + 1,nb_son,height,width,pos_x + width + (father_height / 27),pos_y,father_posx,father_height, average_time);
	
	return ;
}

void destroy_tree(Tree *a){
	PROFILE
	
	if( (*a) == NULL){
		return ;
	}
	
	destroy_tree(&(*a)->fg);
	destroy_tree(&(*a)->frd);
	
	free(*a);
	(*a) = NULL;
	return ;
}

void tree_course(Tree a,int width,int height,double average_time){
	PROFILE
	
	int pos_x= 5, pos_y = 5;
	
	MLV_clear_window(MLV_COLOR_DARK_SALMON);
	
	course_son(a,0,0,0,height - 10,width -10,pos_x,pos_y,pos_x,(pos_y + height - 10),average_time);
	
	MLV_actualise_window();
	
	
	return ;
}


