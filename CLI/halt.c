/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "halt.h"
#include "validation.h"
int cmdHalt(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 1, 1, commandArgs[0])) {
        return 1;
    }
    
    // Max directory path length is 4096 theoretically + killall (8 characters)
    char killCommand[4011];
    strcpy(killCommand, "killall ");
    strcat(killCommand, commandArgs[1]);


    char* killArgs[3];
    killArgs[0] = "/usr/bin/killall";
    killArgs[1] = lessCommand;
    killArgs[2] = NULL;

    execv(killArgs[0], passArgs);
    return 0;
}
