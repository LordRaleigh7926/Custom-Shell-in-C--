# Command-Line Shell Simulation

This project simulates a simple command-line shell that reads user input, processes basic commands, and outputs results to the terminal. The shell supports a few built-in commands and handles basic input parsing, with functionality for `echo`, `exit`, and an error message for unrecognized commands.

## Features
- **`echo` Command**: Prints the given string to the console.
- **`exit` Command**: Exits the shell. The command can optionally accept an argument (`exit 0` or `exit 1`) to return a corresponding exit code.
- **Input Trimming**: Automatically removes leading and trailing spaces from the input.
- **Error Handling**: Displays a "command not found" message for unsupported commands.
- **Flush Output**: Ensures output is flushed immediately after each `cout` and `cerr` operation.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., G++, Clang, or MSVC)
- C++11 or later for standard library support

### Compilation

To compile the project, use the following command:

```bash
g++ -o main main.cpp
```

This will create an executable named `main`.

### Running the Shell

After compiling, run the shell simulation with:

```bash
./main
```

The shell will start, and you can enter commands in the format:

- **`echo [text]`**: Prints the text to the terminal.
- **`exit`**: Exits the shell (returns an exit code of 0).
- **`exit [code]`**: Exits the shell with the specified exit code (e.g., `exit 1` for exit code 1).
- **Invalid commands**: Prints `command not found` for any unsupported input.

Example usage:

```bash
$ echo Hello, World!
Hello, World!

$ exit 0
```

### Code Explanation

- **`getInput()`**: Prompts the user for input by displaying a `$` symbol and reads a line from the console.
- **`removeSpaces()`**: Removes leading and trailing spaces from the user input.
- **Main loop**: Continuously accepts user input and processes commands until `exit` is entered.

### Code Structure

- **`builtinCommands[]`**: Contains a list of the available commands (currently only `echo`, `exit`, and `type`).
- **`removeSpaces()`**: A helper function that trims both leading and trailing spaces from the input string.
- **Command handling**:
  - **`echo`**: Extracts and prints the text following the `echo` keyword.
  - **`exit`**: Terminates the program with the corresponding exit status.
  - **Invalid command**: Displays a message indicating the command is not recognized.


### Limitations & Future Improvements
- The current shell implementation only supports a few commands (`echo`, `exit`).
- Additional built-in commands (e.g., `cd`, `ls`, `pwd`, etc.) can be added.
- Error handling can be enhanced, particularly for invalid inputs and command arguments.
- Adding support for background processes or piping commands could expand functionality.
