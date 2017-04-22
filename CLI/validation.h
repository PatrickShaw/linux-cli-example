/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#ifndef CLI_VALIDATION_H
#define CLI_VALIDATION_H
/**
 * Note: Accounts for arg 0 and arg 1
 * @param argc
 * @param maxArgC
 * @param command
 * @return
 */
int validateMaxParams(int argc, int maxParams, char *command);
int validateMinParams(int argc, int minParams, char *command);
int validateRangeParams(int argc, int minParams, int maxParams, char *command);
int validateFileExistence(char* directory);
int validateFileNonExistence(char* directory);
int validateCreatedNewFile(char* directory);
#endif //CLI_VALIDATION_H
