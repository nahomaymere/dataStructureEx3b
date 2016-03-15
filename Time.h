//
//  Time.h
//  C datastructure exercise
//
//  Created by Nahom Hailu on 25/11/15.
//  Copyright (c) 2015 Nahom. All rights reserved.
//

#ifndef __C_datastructure_exercise__Time__
#define __C_datastructure_exercise__Time__

#include <stdio.h>

typedef int Ttime;//the time in minutes

Ttime read_time(Ttime *mytime, const char *prompt);
char* print_time(const Ttime myTime);
Ttime find_winner_time(Ttime *timeList,int timeList_size);
Ttime compare_time(const Ttime *myTime, const Ttime *winner);
void print_time_list(Ttime *time_list,int time_list_size);
int get_numberof_runners(const char *prompt);

#endif /* defined(__C_datastructure_exercise__Time__) */
