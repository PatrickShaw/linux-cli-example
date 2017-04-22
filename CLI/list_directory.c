/**
    @author Patrick Shaw (Patrick.Leong.Shaw@gmail.com)
*/
#include "list_directory.h"
#include "validation.h"
int cmdListDirectory(int argc, char* argv[], int commandArgC, char* commandArgs[]) {
    if(!validateRangeParams(commandArgC, 1, 1, commandArgs[0])) {
        return 1;
    }
    DIR *directory;
    struct dirent *entries;
    directory = opendir ("./");

    if (directory != NULL) {
        while (entries = readdir(directory)) {
            puts(entries->d_name); // print out name
        }
        (void) closedir(dp);
    }
    else {
        fprintf(stderr, "Couldn't open the directory\n");
    }
    return 0;
}