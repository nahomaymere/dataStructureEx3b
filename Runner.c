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

void read_runnersData(Trunner *runner, int num_of_runners){
    int i;
    for ( i = 0; i < num_of_runners; i++ ){
        printf("Enter runner %d Name: ",i + 1);
        readName(&runner[i], "");
    }
    for (i = 0; i < num_of_runners; i++) {
        printf("Enter runner %d Time: ",i + 1);
        read_runnerTime(&runner[i],"");
    }
}
void readName(Trunner *runner, const char *prompt){
    int size = sizeof(runner->Name)/sizeof(char);
    printf("%s ",prompt);
    fgets(runner->Name, size, stdin);
    for (int i = 0; i < size; i++) {
        if (runner->Name[i] == '\n') {
            runner->Name[i] = '\0';
        }
    }
    
}
void read_runnerTime(Trunner *runner, const char *prompt){
    read_time(&runner->runnertime, prompt);
}
void displayRunner(const Trunner *runner, int longestNamelength){
    int this_nameLength = getNameLength(runner->Name);
    int amountOfblankspaceNeeded = longestNamelength - this_nameLength;
    printf("%s",runner->Name);
   
    //printing blank space after runners name
    for (int i = 0; i <= amountOfblankspaceNeeded ; i++) {
        printf(" ");
    }
    //printing runner's time
    Ttime runTime = runner->runnertime;
    print_time(runTime);
}
int betterRunner(const Trunner *runner1, const Trunner *runner2){
    
    if (compare_time(&runner1->runnertime, &runner2->runnertime) == 0) {
       // runners have equal time;
        return 0;
    }
    else if (compare_time(&runner1->runnertime, &runner2->runnertime) < 0) {
        //runner1 is better
        return 1;
    }
    else
        //runner2 is better
        return 2;
    
}
int find_winner_runner(Trunner *runners_list, int runnersList_size){
    
    Ttime winner_time = runners_list[0].runnertime;
    int winner = 0;
    
    for (int i = 0; i < runnersList_size; i++) {
        if (winner_time > runners_list[i].runnertime) {
            winner_time = runners_list[i].runnertime;
            winner = i;
        }
    }
    return winner;
   
}
int getNameLength(const char *name){
    
    int nameLength = 0;
    int counter = 0;
    while (name[counter] != '\0'){
        
        nameLength++;
        counter++;
    }
    
    return nameLength;
}
int find_longest_name(Trunner *runners, int runnersList_size){
    
    int longest = 0;

    for (int i = 0;  i < runnersList_size; i++) {
        if (longest < getNameLength(runners[i].Name)) {
            longest = getNameLength(runners[i].Name);
        }
    }
    
    return longest;
}

void print_winner(Trunner *runners_list, int winner_runner){
    
    printf("The Winner is :%s ",runners_list[winner_runner].Name);
    print_time(runners_list[winner_runner].runnertime);
    printf("\n");
}
void print_result_list(Trunner *runners, int runnersList_size){
    
    int winner = find_winner_runner(runners, runnersList_size);
    printf("Winner is : %s ",runners[winner].Name);
    print_time(runners[winner].runnertime);
    printf("\n\n");
    
    printf("The result list:\n");
    int count = 0;
    Ttime compared_time = 0;
   

    for (int i = 0; i < runnersList_size; i++) {
      
        count = i + 1;
        
        printf("%d: ",count);
        displayRunner(&runners[i], find_longest_name(runners,runnersList_size));
        printf(" +");
        compared_time = compare_time(&runners[i].runnertime, &runners[winner].runnertime);
        print_time(compared_time);
        printf("\n");
    }
    
}


