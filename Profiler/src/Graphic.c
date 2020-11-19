/**
 * \file Graphic.c
 * \brief Have to display the all differents graphic element
 * \version 1.0
 * \date : 20-12-2018
 * 
 */
#define _POSIX_C_SOURCE 199309L
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>   
#include <sys/resource.h> 
#include "../include/Graphic.h"
#include "../include/Macro_Profiler2.h"

FILE *F;

struct timespec start, finish;

void display_home_screen(char *link,int ordo,int abs){
	
	PROFILE
	
	MLV_clear_window(MLV_COLOR_DARK_SALMON);
	MLV_draw_text(10,10,"File analised :",MLV_COLOR_WHITE);
	
	if(link != NULL)	
		MLV_draw_text(120,10,"%s ",MLV_COLOR_DARK_GREEN,link);
	
	MLV_draw_adapted_text_box(abs/2 -100,ordo/2 - 300,"         Choose one file          ",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
	
	/*While the file name enter by ther user is not available or ok, these options are not available*/
	
	if(link == NULL)
		MLV_draw_adapted_text_box(abs/2 -100,ordo/2 -220," Show inclusion functions ",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_DARK_GREY,MLV_TEXT_CENTER);
	else
		MLV_draw_adapted_text_box(abs/2-100,ordo/2 -220," Show inclusion functions ",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
	if(link == NULL)	
		MLV_draw_adapted_text_box(abs/2-100,ordo/2 - 140,"          MORE DETAILS         ",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_DARK_GREY,MLV_TEXT_CENTER);
	else
		MLV_draw_adapted_text_box(abs/2-100,ordo/2 -140,"          MORE DETAILS         ",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);

	MLV_draw_adapted_text_box(abs/2-100,ordo/2 -70,"                   QUIT                 ",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
	MLV_actualise_window();
	
	return;
}

void display_option_function(int ordo,int abs){
	PROFILE
	
	MLV_clear_window(MLV_COLOR_DARK_SALMON);
	MLV_draw_adapted_text_box((abs/2) - 320 ,(ordo/2) + 70,"SORT BY CALL",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
	MLV_draw_adapted_text_box((abs/2) - 140 ,(ordo/2) + 70,"SORT BY TIME",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
	MLV_draw_adapted_text_box((abs/2) + 40 ,(ordo/2) + 70,"SORT BY AVERAGE TIME",20,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
	
	return ;
}


void display_point(int abscissa,int ordely,int width,int height){
	PROFILE
	
	MLV_draw_adapted_text_box(abscissa + 50,ordely,". . .",3,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_DARK_ORANGE,MLV_TEXT_CENTER);
	
	return;
}


void display_back_button(int height,int width){
	PROFILE
	
	MLV_draw_adapted_text_box(width-90,height - 100,"<- Back",5,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_DARK_ORANGE,MLV_TEXT_CENTER);
	MLV_actualise_window();
	return;
}

void display_function_interface(){
	PROFILE
	
	int x = MLV_get_desktop_height();
    int y = MLV_get_desktop_width();
    
	MLV_draw_filled_rectangle((y/3)-80,x/10,(x/2)+250,y/4,MLV_COLOR_PINK);
	
	MLV_draw_text((y/2)+200,x/10,"TOTAL",MLV_COLOR_BLACK);
	MLV_draw_text(y - 650,x/10,"AVERAGE",MLV_COLOR_BLACK);
	
	MLV_draw_line(y - 1330,x-920,y - 600,x-920,MLV_COLOR_BLACK);
	
	MLV_draw_text(y - 1330,x-940,"name",MLV_COLOR_BLACK);
	MLV_draw_text(y - 1110,x-940,"calls",MLV_COLOR_BLACK);
	MLV_draw_text(y - 850,x-940,"time",MLV_COLOR_BLACK);
	MLV_draw_text(y - 650,x-940,"ms/calls",MLV_COLOR_BLACK);
	return ;
	
}

void display_function_informations(char *function_name,int number_call,double time_functions,double average_time,int pos){
	PROFILE
	
	int x = MLV_get_desktop_height();
    int y = MLV_get_desktop_width();
    
	MLV_draw_text(y - 1320,(x - 900)+ (pos * 15),"%s",20,function_name,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
    MLV_draw_text(y - 1120,(x - 900)+ (pos * 15),"%4d",20,number_call,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
	MLV_draw_text(y - 850,(x - 900)+ (pos * 15),"%2f",20,time_functions,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);
	MLV_draw_text(y - 650,(x - 900)+ (pos * 15),"%2f",20,average_time,MLV_COLOR_BLACK,MLV_COLOR_PURPLE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);

	MLV_actualise_window();

	return;
}


void display_error_message(){
	PROFILE
	MLV_draw_text(120,10,"THIS FILE DON'T EXIST ",MLV_COLOR_DARK_RED);
	MLV_actualise_window();
	MLV_wait_seconds(1);
	
	return;
}

/**
 *\fn static int calculus_pourcentage(double time) 
 * \brief return percentage of the value "average_time"
 * 		  
 * \param time time execution of a function
 * 
 * \return (100 * time)/0.000330 
 * */
 
static int calculus_percentage(double time,double average_time){
	PROFILE
	
	return ((100 * time)/average_time);
}

/**
 *\fn static void calculus_color (int *red,int *green, double time)
 * \brief return value of green colour and red
 * 		  
 * \param time time execution of a function
 * \param red red colour for RGB
 * \param green green colour for RGB
 * 
 * \return Nothind
 * */
 
static void calculus_color (int *red,int *green, double time,double average_time){
	PROFILE
	
	int x = 0;
	
	int value  = calculus_percentage(time,average_time);
	
	
	if(value <= 0){
		(*red) = 0;
		(*green) = 255;
	}
	else if(value >= 100){
		(*red) = 255;
		(*green) = 0;
	}
	else{
		 /*calculus of percentage */
		 x = ((value * (*red)) /100);
	     
		(*green) = (*red) - x; 
		
		(*red) -= (*green);
	}
	
	return;
}

void display_function(int abscissa,int ordely,int width,int height,char *function_name,double time,double average_time){
	PROFILE
	
	int red = 255,green = 0;
	
	calculus_color(&red,&green,time,average_time);
    
    MLV_draw_filled_rectangle(abscissa,ordely,width,height,MLV_rgba(red,green,0,255));
	MLV_draw_text(abscissa+10,ordely,function_name,MLV_COLOR_BLACK);
	
    
    /* black line to do square shape */
    MLV_draw_line(abscissa,ordely,abscissa,height+ordely,MLV_COLOR_BLACK);
	
	MLV_draw_line(abscissa,ordely,width + abscissa,ordely,MLV_COLOR_BLACK);
	
	MLV_draw_line(width+abscissa,ordely,width+abscissa,height+ordely,MLV_COLOR_BLACK);
	
	MLV_draw_line(abscissa,height+ordely,abscissa + width,height+ordely,MLV_COLOR_BLACK);
	
	return;
}
