/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "run.h"
#include "validation.h"
int cmdRun(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 1, 1, commandArgs[0])) {
        return 1;
    }
    
    // Max directory path length is 4096 theoretically + run (4 characters)
    char runCommand[4100];
    strcpy(runCommand, "");


    char* killArgs[3];
    killArgs[0] = commandArgs[1]; // Directory
    killArgs[1] = runCommand;
    killArgs[2] = NULL;

    execv(killArgs[0], passArgs);
    return 0;
}
