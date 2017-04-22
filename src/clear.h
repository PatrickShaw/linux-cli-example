/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#ifndef CLI_CLEAR_H
#define CLI_CLEAR_H
#include "operation.h"
/**
 * Clears the terminal screen
 * @param argc
 * Number of arguments
 * @param argv
 * Command arguments
 * @return
 * Command result code
 */
extern int cmdClear(int argc, char* argv[], int commandArgC, char* commandArgs[]);
#endif //CLI_CLEAR_H
