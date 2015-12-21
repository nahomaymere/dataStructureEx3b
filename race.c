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
    
    Trunner runnerA,runnerB;
    readName(&runnerA, "Enter runner 1 Name: ");
    readName(&runnerB, "Enter runner 2 Name: ");
    read_runnerTime(&runnerA,"Enter runner 1 Time: " );
    read_runnerTime(&runnerB,"Enter runner 2 Time: ");
    switch (  betterRunner(&runnerA, &runnerB)) {
       case 0:
            printf("No actual winner\n");
            displayRunner(&runnerA);
            printf("\n");
            displayRunner(&runnerB);
            break;
        case 1:
            printf("Winner is: ");
            displayRunner(&runnerA);
            break;
        case 2:
            printf("Winner is: ");
            displayRunner(&runnerB);
            break;

    }
    

  
    

    return 0;
}
