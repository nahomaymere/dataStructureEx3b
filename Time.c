//
//  Time.c
//  C datastructure exercise
//
//  Created by Nahom Hailu on 25/11/15.
//  Copyright (c) 2015 Nahom. All rights reserved.
//

#include "Time.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

Ttime read_time(Ttime *mytime, const char *prompt){
    int hours, minutes;
    char str[10];
    char *token2;
    char token[6];
    char *strOcuur;
    int size_token;
    enum boo {y, n};
    enum boo allowlooping = y;
    hours = minutes = 0;
    
    while (allowlooping == y) {
        
        printf("%s", prompt);
        fgets(str, 10, stdin);
        int str_size = sizeof(str) / sizeof(char);
        
        for (int i = 0; i< str_size; i++) {
            
            if (i > 4 && (int)str[i] > 31 && (int)str[i] < 127) {
                printf("Incorrect Format\n");
                token[0] = '\0';
                allowlooping = y;
                break;
            }
            if(str[2] !=  ' ' && str[2] != ':'){
                printf("Incorrect Format\n");
                token[0] = '\0';
                allowlooping = y;
                break;
            }
            if (i<5) {
                token[i] = str[i];
                if ( i != 2 &&( (int)str[i] < 48 || (int)str[i] > 57)) {
                    printf("Incorrect input type \n");
                    token[0] = '\0';
                    allowlooping = y;
                    break;
                }
            }
            else
                allowlooping = n;
            
        }

        // spliting string into two strings
        token[5] = '\0';
        size_token = sizeof(token) / sizeof(char);
        strOcuur = strchr(token, ' ');
        
        if( strOcuur != NULL ){
            
            token2 = strtok(token, " :");
            hours = atoi(token2);
            token2 = strtok(NULL, " :");
            minutes = atoi(token2);
        }
        if ((hours > 23 || minutes > 59) && allowlooping == n) {
            printf("Invalid time\n");
            allowlooping = y;
        }
    
    }
    *mytime = (hours * 60) + minutes;

    return *mytime;
}
Ttime find_winner_time(Ttime *timeList, int timeList_size){
    
    Ttime winner_time = timeList[0];
    for (int i = 0; i < timeList_size; i++) {
        if (winner_time > timeList[i]) {
            winner_time = timeList[i];
        }
    }
    
    return winner_time;
}
Ttime compare_time(const Ttime *myTime, const Ttime *winner){
    
    Ttime time_diff = *myTime - *winner;
    return time_diff;
}
void print_time_list(Ttime *time_list, int time_list_size){
    
    Ttime winner = find_winner_time(time_list, time_list_size);
    
    for (int i = 0; i < time_list_size; i++) {
        printf("%d: ", i+1);
        print_time(time_list[i]);
        print_time(compare_time(&time_list[i], &winner));
        printf("\n");
    }
}
int get_numberof_runners(const char *prompt){
    
    int num_of_runners = 0;
    char input[3];
    char inp;
    while (1) {
        printf("%s\n", prompt);
        fgets(input, 3, stdin);
        num_of_runners = atoi(input);
        while ((inp = getchar()) != '\n' && inp != EOF );
        if (num_of_runners > 0 && num_of_runners < 11) {
            break;
        }
        
    }
    return num_of_runners;
}
void print_time(const Ttime myTime){
    
    int hours, minutes;
    hours = myTime / 60;
    minutes = myTime % 60;
    if (hours<10 && minutes <10) 
        printf("0%d:0%d ", hours, minutes);
 
    else if (hours < 10)
        printf("0%d:%d ", hours, minutes);
 
    else if (minutes < 10)
         printf("%3d:0%d ", hours, minutes);
    else
        printf("%3d:%d ", hours, minutes);
}
