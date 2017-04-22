/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)

*/
#include "clear.h"
#include "validation.h"
#include "<stdio.h>"
int cmdClear(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 0, 0, commandArgs[0])) {
         return 1;
    }
    printf("\033[2J\033[1;1H");
    return 0;
}