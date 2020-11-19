/**
 * \file Main.c
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 20-12-2018
 */
 
#define _POSIX_C_SOURCE 199309L
#define HEIGHT MLV_get_desktop_height()
#define WIDTH MLV_get_desktop_width()
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>   
#include <sys/resource.h> 
#include "../include/Tree.h"
#include "../include/Option.h"
#include "../include/Graphic.h"
#include "../include/Profiler.h"

#include "../include/Macro_Profiler2.h"

FILE *F;

struct timespec start, finish;

/**
 * \fn int main (int argc, char **argv)
 * \brief Entry of the program.
 *
 * \return EXIT_SUCCESS - normal stoppage of the program.
 */
 
int main(int argc, char **argv){
	PROFILE
	
	FILE* in = NULL;
    Tree a = NULL;
   
    Profiler *profile;
   
    int quit = 0,navigation = 0,number_of_function = 0,can_be_open = 0;
    double average_time = 0.0; /* Maximum time function to help width graphic display */
    
    /* We generate the profile file automatically*/
    system("gcc profilable_example/Fact.c ");
    system("./a.out 10");
    
    char *text = NULL;
    
    
    MLV_create_window( "myprofiler", "Profiler", WIDTH, HEIGHT);
    
    
    while(quit == 0){
		
		display_home_screen(text,HEIGHT,WIDTH);
		
		can_be_open = choice_menu_user(&quit,&text,&navigation);
		
		/*If the filename enter exist, we can open him and exploit the data*/
		if(can_be_open == 1){
			choose_file(&profile,in,&text,&a,&number_of_function,&average_time);
			can_be_open = 0; /*Permit to avoid enter angain in function in the other loop*/
		}
			
		while(navigation == 1){
			tree_course(a,WIDTH,HEIGHT,average_time);
			get_back(&navigation);
		}
		
		if(navigation == 2){
			profiler_course(profile,&navigation,WIDTH,HEIGHT,0,number_of_function);
		}		
	}
	
	destroy_tree(&a);
		
    MLV_wait_seconds(0);
    MLV_free_window();
	
	return 0;
}
