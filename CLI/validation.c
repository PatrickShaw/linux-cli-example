/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "validation.h"
#include <stdio.h>
int validateMaxParams(int argc, int maxParams, char *command) {
    if(argc > maxParams) {
        fprintf(stderr, "%s takes at most %d arguments\n", command, maxParams);
        return 0;
    }
    return 1;
}

int validateMinParams(int argc, int minParams, char *command) {
    if(argc < minParams) {
        fprintf(stderr, "%s needs at least %d arguments\n", command, minParams);
        return 0;
    }
    return 1;
}
int validateRangeParams(int argc, int minParams, int maxParams) {
    return invalidateMinParams(argc, minParams, command) || invalidateMaxParams(argc, maxParams, command);
}
int validateFileNonExistence(char* directory) {
    if(access(directory, F_OK) == 0) {
        // We can access the file, therefore we can't really make a new file without overwriting
        fprintf(stderr, "%s already exists\n", directory);
        return 0;
    }
    return 1;
}
int validateFileExistence(char* directory) {
    if(access(directory, F_OK) != 0) {
        fprintf(stderr, "%s could not be accessed\n", directory);
        return 0;
    }
    return 1;
}
int validateCreatedNewFile(char* directory) {
    if(access(directory, F_OK) != 0) {
        fprintf(stderr, "%s was not created\n", directory);
        return 0;
    }
    return 1;
}