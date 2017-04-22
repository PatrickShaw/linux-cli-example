/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#ifndef CLI_PAUSE_H
#define CLI_PAUSE_H
/**
 * Pauses the execution of the CLI program until the ENTER key is pressed
 * @param argc
 * Number of arguments
 * @param argv
 * Command arguments
 * @return
 * Command result code
 */
int cmdPause(int argc, char* argv[], int commandArgC, char* commandArgs[]);
#endif //CLI_PAUSE_H
