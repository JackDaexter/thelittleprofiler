/**
 * \file Macro_profiler.h
 * \author NGOUNOU KOTCHAP Franck & CURIER DUARTE Nelson
 * \version 1.0
 * \date : 30-12-2018
 */

#ifndef __MACRO_PROFILAGE__
#define __MACRO_PROFILAGE__

#define PROFILE F = fopen("profile_profiler.log","a+");\
    clock_gettime(CLOCK_REALTIME,&start);\
    fprintf(F,"%s -- time : %.6fs \n",__FUNCTION__,start.tv_sec/1.0 + start.tv_nsec/1000000000.0);\
    fclose(F);

#define return F = fopen("profile_profiler.log","a+");\
    clock_gettime(CLOCK_REALTIME,&finish);\
    fprintf(F,"END -- time : %.6fs \n",finish.tv_sec/1.0 + finish.tv_nsec/1000000000.0);\
    fclose(F); return


#endif

