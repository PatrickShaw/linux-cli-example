/**
    @author Patrick Shaw
*/
#ifndef CLI_BASIC_OPERATIONS_H
#define CLI_BASIC_OPERATIONS_H
#include "operation.h"
#include "clear.h"
#include "change_directory.h"
#include "list_directory.h"
#include "echo.h"
#include "help.h"
#include "pause.h"
#include "quit.h"
#define COMMAND_CLEAR "clear"
#define COMMAND_CHANGE_DIRECTORY "cd"
#define COMMAND_LIST_DIRECTORY "dir"
#define COMMAND_ECHO "echo"
#define COMMAND_HELP "help"
#define COMMAND_PAUSE "pause"
#define COMMAND_QUIT "quit"
#define BASIC_COMMANDS {COMMAND_CLEAR}, COMMAND_CHANGE_DIRECTORY, COMMAND_LIST_DIRECTORY, \
COMMAND_ECHO, COMMAND_HELP, COMMAND_PAUSE, COMMAND_QUIT
#define BASIC_OPERATIONS \
{&cmdClear, COMMAND_CLEAR, 0}, \
{&cmdChangeDirectory, COMMAND_CHANGE_DIRECTORY, 0}, \
{&cmdListDirectory, COMMAND_LIST_DIRECTORY, 1}, \
{&cmdEcho, COMMAND_ECHO, 1}, \
{&cmdHelp, COMMAND_HELP, 1}, \
{&cmdPause, COMMAND_PAUSE, 1}, \
{&cmdQuit, COMMAND_QUIT, 0}
extern struct Operation basicOperations[];
#define BASIC_OPERATIONS_SIZE 7;
#endif //CLI_BASIC_OPERATIONS_H
