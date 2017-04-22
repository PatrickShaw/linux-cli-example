/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)

*/
#ifndef CLI_CHANGE_DIRECTORY_H
#define CLI_CHANGE_DIRECTORY_H
#include "operation.h"
/**
 * Changes the default directory to the directory specified. If the
 * directory does not exist, an appropriate error message is
 * displayed. If a directory argument is not specified, the current directory
 * is changed to the HOME enviornment directory.
 * @param argc
 * Number of arguments
 * @param argv
 * Command arguments
 * @return
 * Command result code
 */
int cmdChangeDirectory(int argc, char* argv[], int commandArgC, char* commandArgs[]);
#endif //CLI_CHANGE_DIRECTORY_H
