/**
 * \file Option.c
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 20-12-2018
 */
 
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>   
#include <sys/resource.h> 
#include "../include/Option.h"
#include "../include/Macro_Profiler2.h"
FILE *F;

struct timespec start, finish;



int choice_menu_user(int *quit,char **text,int *navigation){
	PROFILE
	
	int x,y;
	
	int height = MLV_get_desktop_height(), width = MLV_get_desktop_width();
	
	MLV_wait_mouse(&x,&y);

	if((x >= width/2 - 100 && x <= width/2 + 120) && (y >= height/2 - 300  && y <= height/2 - 245)){
		MLV_wait_input_box(width/2 -100,height/2 - 370,300,50, MLV_COLOR_BLACK, MLV_COLOR_BLACK,MLV_COLOR_WHITE,"File link : ",text);
		
		if(*text != NULL)
			return 1;
	}
	
	else if((x >= width/2 - 100 && x <= width/2 + 120) && (y >= height/2 - 220  && y <= height/2 - 165)){
		if( *text != NULL ){
			*navigation = 1;
		}
	}
	
	else if((x >= width/2 - 100 && x <= width/2 + 120) && (y >= height/2 -140  && y <= height/2 - 85 )){

		if( *text != NULL ){
			*navigation = 2;
		}
	}
	
	else if((x >= width/2 - 100 && x <= width/2 + 120) && (y >= height/2 - 70  && y <= height/2 -15)){
		*quit = 1;
	}
	
	return 0;
}

void choose_sorts_function(int *navigation,int *option){
	PROFILE
	
	int x,y;
	int height = MLV_get_desktop_height(), width = MLV_get_desktop_width();
	
	display_back_button(height,width);
	
	MLV_wait_mouse(&x,&y);
	
	
	if ((y >= (height/2) + 70 && y <= (height/2) + 125) && (x >=(width/2) - 320 && x <= (width/2) - 182)){
		
		if(*option == 1 || *option == 0 || *option == 3 || *option == 4){
			(*option) = 2;
		}
		else if (*option == 2){
			(*option) = 1;
		}
	}
	
	else if((y >= (height/2) + 70 && y <= (height/2) + 125) && (x >= (width/2) - 140 &&  x <= (width/2))){
		*option = 3;
	}
	
	else if(( y >= (height/2) + 70 && y <= (height/2) + 125) && (x >= (width/2) + 40 &&  x <= (width/2)  + 250)){
		*option = 4;
	}
	
	
	if((x >= width - 90 && x <= width - 30) && (y>= height - 100 && y<= height - 80))
		(*navigation) = 0;
	
	return ;
}


void get_back(int *navigation){
	
	PROFILE
	
	int height = MLV_get_desktop_height();
    int width = MLV_get_desktop_width();
	int x,y;
	
	display_back_button(height,width);
	MLV_wait_mouse(&x,&y);
	
	if((x >= width -90 && x <= width - 30) && (y>= height - 100 && y<= height - 80))
		(*navigation) = 0;
	
	return ;
}
