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
void displayRunner(const Trunner *runner);
int betterRunner(const Trunner *runner1, const Trunner *runner2);
#endif /* defined(__new__Runner__) */
