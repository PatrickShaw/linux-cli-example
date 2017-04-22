/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "pause.h"
#include "validation.h"
int cmdPause(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 1, 1, commandArgs[0])) {
        return 1;
    }
    // Print
    printf("Press the ENTER key to continue...\n");
    int c;
    // Loop until they press the enter key
    while ((c = getchar()) != '\n' && c != EOF);
    return 0;
}