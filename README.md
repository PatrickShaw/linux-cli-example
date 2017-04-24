# Command line interpreter
## FTI2070 Operating Systems - Assignment 1
### Running the basic interpreter
1. Navigate to and open a terminal in the Basic/bin folder
2. Enter `./bin/basic_cli`
3. The basic CLI should now be running. You may now enter commands into the CLI or type help to display the user manual.

### Running the advanced interpreter
1. Navigate to and open a terminal in the Advanced/bin folder
2. Type `./bin/advanced_cli`
3. The advanced CLI should now be running. You may now enter commands into the CLI or type help to display the user manual.

### Commands
`clear`
Clears the output screen.
`cd `**`<directory>`**
Changes the default directory to **`<directory>`**.
If the argument is not present, the current directory is changed to the *HOME* environment.

`dir `**`<directory>`**
Lists the contents of the given directory **`<directory>`**.

`echo `**`<comment>`**
Prints the first **`<comment>`**.
A comment is a sequence of characters start with a double quote character.
It is terminated by the next double quote.

`help`
Displays the user manual using the less command.

`pause`
Pauses the execution of the CLI program until the Enter key is pressed.

`quit`
Stops executing the CLI program and terminates.

`new `**`<file>`**
Create a new file with name **`<file>`**.

`cp `**`<old> <new>`**
Copy the contents of an existing file with name **`<old>`** to a new file with 

`name `**`<new>`**

`find `**`<char> <file>`**
Displays the number of occurrence of the character **`<char>`** in an existing file with name **`<file>`**.

`run `**`<program>`**
Execute any executable program with name **`<program>`**.

`halt `**`<program>`**
Stop executing the program with name **`<program>`**.

### Using command arguments that include spaces
The CLI seperates command arguments/parameters by spaces. However, command arguments can be combined by encapsulating them within double quotation marks.

#### Example
The following command will not work:
`cp ./original file with space ./new file with whitespace`

The following command will work:
`cp "./original file with whitespace" "./new file with whitespace"`
