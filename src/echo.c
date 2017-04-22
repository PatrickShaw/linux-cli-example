/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "echo.h"
#include "validation.h"
#include "<string.h>"
#include "<stdio.h>"
int cmdEcho(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateMinParams(commandArgC, 1, commandArgs[0])) {
         return 1;
    }
    char* echoedString = commandArgs[0];
    const char* quotationError = "%s must start and end with \"";
    if(strlen(echoedString) < 1) {
        printf(quotationError, command);
        return 1;
    }
    int quotationCount = 0;
    char* echoResult = "";
    // Go find the first two quotations, add everything in between them to a string and print that string out
    for(char* i = echoedString; *i; i++) {
        char* character = &i[0];
        if(character == '\"') {
            quotationCount++;
            if(quotationCount >= 2) {
                break;
            }
            continue;
        }
        if(quotationCount == 1) {
            echoedResult = strcat(echoedResult, character);
        }
    }
    if(quotationCount < 2) {
        printf(quotationError, command);
    } else {
        printf(echoResult);
    }
    return 0;
}