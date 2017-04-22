/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "new_file.h"
#include "validation.h"
int cmdNewFile(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 1, 1, commandArgs[0])) {
        return 1;
    }
    char* directory = commandArgs[1];
    if(!validateFileNonExistence(directory)) {
        return 1;
    }
    FILE* newFile;
    newFile = fopen(directory);
    fclose(newFile);
    if(validateCreatedNewFile(directory)) {
        return 1;
    }
    return 0;
}