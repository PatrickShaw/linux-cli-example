/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "change_directory.h"
#include "validation.h"
int cmdChangeDirectory(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 0, 1, commandArgs[0])) {
        return 1;
    }
    char* changeDirectoryResult;
    if (commandArgC == 0) {
        // 0 parameters
        // cd to home
        changeDirectoryResult = chdir(getEnv("HOME"));
    } else {
        // cd to whatever the user specified
        char* newDir = commandArgs[0];
        changeDirectoryResult = chdir(newDir);
    }
    if(changeDirectoryResult != 0) {
        // Error! Something bad happened when we tried to change directories
        printf("Was unable to change directories.\n");
    }
    return 0;
}