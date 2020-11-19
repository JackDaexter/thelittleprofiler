/**
 * \file Graphic.h
 * \brief Take all function about screen displaying
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 20-12-2018
 */

#ifndef __GRAPHIC__
#define __GRAPHIC__
#include "MLV/MLV_all.h"

/** 
 * \brief Display all the differents function on the home screen and the loaded file
 * \param *link Take char* who will be use when the user choose the file
 * \return Nothing
 * */
void display_home_screen(char *link,int ordo,int abs);

/** 
 * \brief Display error message if the file enter by the user doesn't exist
 * \return Nothing
 * */
void display_error_message();

/**
 * \brief Display a function,his name, his size and his colour
 * \param abscissa abscissa position of the square
 * \param ordely ordely position of the square
 * \param width width of the square
 * \param height height of the square
 * \param *function_name name of the function
 * \param time duration function
 * */
void display_function(int abscissa,int ordely,int width,int height,char *function_name,double time,double average_time);

/**
 * \brief Display the differents button usefull for the option page
 * \param width width of the screen
 * \param height height of the screen
 * */
void display_option_function(int width,int height);

/**
 * \brief Display the back button usefull to go back on menu
 * \param width width of the screen
 * \param height height of the screen
 * */
void display_back_button(int height,int width);

/**
 * \brief Display all available information for each function:
 * 		  time execution,name,number call .
 * \param *function_name function name of function
 * \param number_call int about number_call for each function
 * \param time_function is the time function duree
 * \param average_time is average time function
 * \param  pos
 * */
void display_function_informations(char *function_name,int number_call,double time_functions,double average_time,int pos);

/**
 * \brief Display all other graphic information necessary : titles and design
 * */
void display_function_interface();

/**
 * \brief Display a function,his name, his size and his colour
 * \param abscissa abscissa position of the 3 points
 * \param ordely ordely position of the 3 points
 * \param width width of the screen
 * \param height height of the screen
 * */
void display_point(int abscissa,int ordely,int width,int height);
#endif


