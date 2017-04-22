/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "help.h"
#include "validation.h"
#include <stdio.h>
#include <string.h>
/**
    @
*/
int cmdHelp(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if (!validateRangeParams(commandArgC, 0, 0, commandArgs[0])) {
        return 1;
    }
    // Max directory path length is 4096 theoretically + less (5 characters)
    char lessCommand[4011];
    strcpy(lessCommand, "less ");
    strcat(lessCommand, "./user_manual.txt");


    char* lessArgs[3];
    lessArgs[0] = "/usr/bin/less";
    lessArgs[1] = lessCommand;
    lessArgs[2] = NULL;

    execv(lessArgs[0], passArgs);
    return 1;
}
