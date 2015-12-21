//
//  Runner.c
//  new
//
//  Created by Nahom Hailu on 10/12/15.
//  Copyright (c) 2015 Nahom. All rights reserved.
//

#include "Runner.h"
#include "Time.h"
#include <stdio.h>
#include <stdlib.h>

void readName(Trunner *runner, const char *prompt){
    int size = sizeof(runner->Name)/sizeof(char);
    printf("%s ",prompt);
    fgets(runner->Name, size, stdin);
    
}
void read_runnerTime(Trunner *runner, const char *prompt){
    read_time(&runner->runnertime, prompt);
}
void displayRunner(const Trunner *runner){
    printf("%s ",runner->Name);
    Ttime runTime = runner -> runnertime;
    print_time(runTime);
}
int betterRunner(const Trunner *runner1, const Trunner *runner2){
    
    if (compare_time(runner1->runnertime, runner2->runnertime) == 0) {
       // runners have equal time;
        return 0;
    }
    else if (compare_time(runner1->runnertime, runner2->runnertime) < 0) {
        //runner1 is better
        return 1;
    }
    else
        //runner2 is better
        return 2;
    
}