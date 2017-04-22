/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "copy.h"
#include "validation.h"
int cmdCopy(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 2, 2, commandArgs[0])) {
        return 1;
    }
    // Make sure they we're not overwriting existing files & reading from non existing files
    char* oldDirectory = commandArgs[0];
    if(!validateFileExistence(oldDirectory)) {
        return 1;
    }
    char* newDirectory = commandArgs[1];
    if(!validateFileNonExistence(newDirectory)) {
        return 1;
    }
    // Open file connections
    FILE* oldFile = fopen(oldFile, "r");
    FILE* newFile = fopen(newFile, "w");
    char c = fgetc(c, oldFile);
    // Start copying bytes until we hit the EOF
    while(c != EOF) {
        fputc(c, newFile);
        c = fgetc(oldFile);
    }
    // Close file connections
    fclose(oldFile);
    fclose(newFile);
    printf("Copied %s to %s\n", oldDirectory, newDirectory);
    return 0;
}