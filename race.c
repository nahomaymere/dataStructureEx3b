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
    read_runnersData(runner,num_of_runners);
    print_result_list(runner, num_of_runners);
    
    return 0;
}
