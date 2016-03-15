//
//  Runner.h
//  new
//
//  Created by Nahom Hailu on 10/12/15.
//  Copyright (c) 2015 Nahom. All rights reserved.
//

#ifndef __new__Runner__
#define __new__Runner__

#include <stdio.h>
#include "TIme.h"


typedef struct {
    char Name[30];
    Ttime runnertime;
}Trunner;
void readName(Trunner *runner, const char *prompt);
void read_runnerTime(Trunner *runner, const char *prompt);
void displayRunner(Trunner runner);
int betterRunner(const Trunner *runner1, const Trunner *runner2);
int find_winner_runner(Trunner *runners_list, int runnersList_size);
void print_winner(Trunner *runners_list, int winner_runner);
void print_result_list(Trunner *runners, int runnersList_size);
int find_longest_name(Trunner *runners, int runnersList_size);
int getNameLength(const char *name);

#endif /* defined(__new__Runner__) */
