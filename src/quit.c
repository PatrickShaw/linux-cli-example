/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "quit.h"
#include "validation.h"
int cmdQuit(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 0, 0, commandArgs[0])) {
        return 1;
    }
    exit(0);
    return 0;
}