/**
    @author Patrick Shaw
*/

#ifndef CLI_OPERATIONS_H
#define CLI_OPERATIONS_H
struct Operation {
    int (*method)(int, char **, int, char **);
    char* command; // TODO: We could technically make a single operation map to multiple commands. E.g. copy & cp rather than just cp
    int isForked;
};
#endif //CLI_OPERATIONS_H
