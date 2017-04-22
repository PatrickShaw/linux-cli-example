/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "find.h"
#include "validation.h"
int cmdFind(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 2, 2, commandArgs[0])) {
        return 1;
    }
    char* fileDirectory = commandArgs[2];
    if(!validateFileExistence(fileDirectory)) {
        return 1;
    }
    char* targetCharacter = commandArgs[1];
    if(strlen(targetCharacter) != 1) {
        fprintf(stderr, "%s only supports finding a single character\n", commandArgs[0]);
        return 1;
    }
    FILE *file = fopen(fileDirectory, "r");
    int occurrences = 0;
    char comparedCharacter;
    while (comparedCharacter != EOF) {
        comparedCharacter = fgetc(file);
        int result = strncmp(&ch, &character, 1);
        if (result == 0) {
            occurrences++;
        }
    }
    fclose(file);
    printf("%s occurs %d times in %s\n", comparedCharacter, occurrences, fileName);
    return 0;
}