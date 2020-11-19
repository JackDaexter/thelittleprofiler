/**
 * \file Option.h
 * \brief Done some action in function of the option choose by the user
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 20-12-2018
 */

#ifndef __OPTION__
#define __OPTION__
#include "../include/Graphic.h"

/**
 * \param *quit take a pointer toward a value to know if the user want to quit or not
 * \param **text Take a pointer to register a text who's the name o file enter by the user
 * \param *navigate Pointer towards int. About displaying function
 * \return Nothing
 * */
int choice_menu_user(int *quit,char **text,int *navigate);

/**
 * \brief We give differents number who correspond at options choose by the user 
 * \param *navigate Pointer towards int. About displaying function
 * \param *option Pointer towards int. About option click by the user
 * \return nothing
 * */
void choose_sorts_function(int *navigation,int *option);

/**
 *\param *back Pointer towards int. About if we want go back in general menu or not.
 *\return Nothing 
 **/
void get_back(int *back);

#endif
