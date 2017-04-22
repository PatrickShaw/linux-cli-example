/**
    @author Patrick Shaw
*/

#ifndef CLI_ADVANCED_OPERATIONS_H
#define CLI_ADVANCED_OPERATIONS_H
#include "operation.h"
#include "basic_operations.h"
#include "new_file.h"
#include "copy.h"
#include "find.h"
#include "run.h"
#include "halt.h"
#define COMMAND_NEW "new"
#define COMMAND_COPY "cp"
#define COMMAND_FIND "find"
#define COMMAND_RUN "run"
#define COMMAND_HALT "halt"
#define ADVANCED_OPERATIONS \
{cmdNewFile, COMMAND_NEW, 1}, \
{cmdCopy, COMMAND_COPY, 1}, \
{cmdFind, COMMAND_FIND, 1}, \
{cmdRun, COMMAND_RUN, 1}, \
{cmdHalt, COMMAND_HALT, 1}
#define ADVANCED_OPERATIONS_SIZE 12
#endif //CLI_ADVANCED_OPERATIONS_H
