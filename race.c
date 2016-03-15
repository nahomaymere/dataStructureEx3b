//
//  race.c
//  new
//
//  Created by Nahom Hailu on 10/12/15.
//  Copyright (c) 2015 Nahom. All rights reserved.
//

#include <stdio.h>
#include "Runner.h"
#include "Time.h"
#include <stdlib.h>

int main(){
    
    int i;
    int num_of_runners = get_numberof_runners("How many runners do you have?");
    Trunner runner[num_of_runners];
    
    for ( i = 0; i < num_of_runners; i++ ){
        printf("Enter runner %d Name: ",i + 1);
        readName(&runner[i], "");
    }
    for (i = 0; i < num_of_runners; i++) {
        printf("Enter runner %d Time: ",i + 1);
        read_runnerTime(&runner[i],"");
    }   print_result_list(runner, num_of_runners);
    

    

    return 0;
}
