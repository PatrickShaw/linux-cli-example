/**
    @author Patrick Shaw
*/
#include "clear.h"
#include "new_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "advanced_operations.h"
#define INPUT_BUFFER_SIZE 4160
#define MAX_COMMAND_ARGS INPUT_BUFFER_SIZE / 2
#define ERROR_INVALID_COMMENT "Invalid command. Use the help command to view the user manual\n"
/**
 * Processes input and splits it up into command arguments
 * @param commandArgs
 * Place where the command args will be put inside.
 * @param buffer
 * Input from the user
 * @param characterCount
 * Number of input characters that are in the buffer
 * @return
 */
struct Operation advancedOperations[] = {
	BASIC_OPERATIONS,
	ADVANCED_OPERATIONS
};
int getCommandArgs(char** commandArgs, char* buffer, int characterCount) {
    int commandArgC = 0;
    int quotationCount = 0;
    for(int i = 0; i < characterCount; i++) {
	printf("Checking: %c\n",buffer[i]);
        int currentArgLen = strlen(commandArgs[commandArgC]);
        if(buffer[i] == '\"') {
            quotationCount++;
            if(quotationCount % 2 == 0) {
                // If it's a closing quote then we're done with this command arg
                commandArgs[commandArgC][currentArgLen] = '\0';
                commandArgC++;
            }
            // Regardless, we're adding the quotation to the commandArg
            commandArgs[commandArgC][currentArgLen + 1] = buffer[i];
            continue;
        } else if (buffer[i] == '\0' || buffer[i] == '\n') {
            printf("Ended with: %s\n", commandArgs[commandArgC]);
            if(commandArgs[commandArgC][0] != '\0') {
                commandArgs[commandArgC][currentArgLen] = '\0';
                commandArgC++;
                printf("Not nothing, increasing commandArgC\n");
            }
            break;
        } else if(isspace(buffer[i])) {
            // White space! But have we actually done anything with the current commandArg?
            if(strcmp(commandArgs[commandArgC], "")) {
                // Yes, we did do something with the current commandArg, time to start a new one!
                commandArgs[commandArgC][currentArgLen] = '\0';
                commandArgC++;
            }
        } else {
            // Wasn't a command arg terminating char, add the char to the command arg
            commandArgs[commandArgC][currentArgLen] = buffer[i];
        }
    }
    return commandArgC;
}
int inputCount(char* buffer, int bufferSize) {
    int inputCount = 0;
    for(int i = 0; i < bufferSize; i++) {
        inputCount++;
        if(buffer[i] == '\n' || buffer[i] == '\0') {
            buffer[i] = '\0';
            break;
        }
    }
    return inputCount;
}
int main(int argc, char* argv[]) {
    // Buffer for input
    int bufferSize = INPUT_BUFFER_SIZE;
    char buffer[bufferSize];
    // Until exit(...) is called...
    while(1) {
        printf("Rawr\n");
        // Get our input
	fgets(buffer, bufferSize, stdin);
	printf("Buffer %s\n", buffer);
        int characterCount = inputCount(buffer, bufferSize);
	printf("Character count: %d\n", characterCount);
        if(characterCount <= 0) {
            // We didn't get any input? Print an error!
            fprintf(stderr, ERROR_INVALID_COMMENT);
            continue;
        }
        // Process the buffer and turn it into command args
        
        char* commandArgs[MAX_COMMAND_ARGS];
        for(int i = 0; i < MAX_COMMAND_ARGS; i++) {
            char arg[bufferSize];
            commandArgs[i] = arg;
        }
        int commandArgC = getCommandArgs(commandArgs, buffer, characterCount);
        printf("Command args: %d\n", commandArgC);
        if(commandArgC <= 0) {
            // We don't have any arguments? Print an error!
            fprintf(stderr, ERROR_INVALID_COMMENT);
            continue;
        }
	printf("Yay!\n");
    	char* command = commandArgs[0];
        // Check if the user's command matches one of the operation mapped commands
        int foundMatch = 0;
        for(int i = 0; i < ADVANCED_OPERATIONS_SIZE; i++) {
            struct Operation operation = advancedOperations[i];
            printf("Comparing %s with %s\n", operation.command, command);
            if(strcmp(operation.command, command)) {
                // Look, we found an associated operation!
                foundMatch = 1;
                if(operation.isForked) {
                    // It's an operation that needs to be forked.
                    // Let's fork it
                    int pid = fork();
                    operation.method(argc, argv, commandArgC, commandArgs);
                } else {
                    // Not forked. Perform the operation synchronously.
                    operation.method(argc, argv, commandArgC, commandArgs);
                }
                break;
            }
        }
        if(!foundMatch) {
            // We had a command but it wasn't associated with any particular operation. Print an error!
            fprintf(stderr, ERROR_INVALID_COMMENT);
            continue;
        }
    }
}
