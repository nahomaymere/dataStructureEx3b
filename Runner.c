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

    printf("%s ",prompt);

    fgets(runner->Name, 30, stdin);
    for (int i = 0; i < 30 ; i++) {
        if (runner->Name[i] == '\n') {
            runner->Name[i] = '\0';
        }
    }
    
}
void read_runnerTime(Trunner *runner, const char *prompt){
    read_time(&runner->runnertime, prompt);
}
void displayRunner(Trunner runner){
    printf("%-30s%s",runner.Name,print_time(runner.runnertime));

    // i want to leave 30 charachters before printing runner's time however i cant do that because the counting of the 30 charachters is begining with the last charachter of the name which defies the whole purpose of counting the charachters

    //printing blank space after runners name
    //printing runner's time
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




void print_result_list(Trunner runners[], int runnersList_size){
    
    int winner = find_winner_runner(runners, runnersList_size);
    printf("Winner is : %s ",runners[winner].Name);
    printf("%s",print_time(runners[winner].runnertime));
    printf("\n\n");
    
    printf("The result list:\n");
    int count = 0;
    Ttime compared_time = 0;
   

    for (int i = 0; i < runnersList_size; i++) {
      
        count = i + 1;
        
        printf("%d: ",count);
        displayRunner(runners[i]);
        printf(" +");
        compared_time = compare_time(&runners[i].runnertime, &runners[winner].runnertime);
        printf("%s",print_time(compared_time));
        printf("\n");
    }
    
}


