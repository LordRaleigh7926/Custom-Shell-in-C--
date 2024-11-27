// shell_builtins.h
#ifndef SHELL_BUILTINS_H
#define SHELL_BUILTINS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to split a string into words based on spaces
vector<string> splitString(const string &str);

// Function to check if an item exists in an array
bool isInArray(string* arr, int size, string target);

// Class that contains the built-in shell commands
class BuiltinCommands
{
public:
    // Method to handle the 'echo' command
    static void echo(const string &text);

    // Method to handle the 'exit' command
    static int exitCommand(const string &input);

    // Method to handle the 'type' command
    static void typeCommand(const string &input);
};

#endif // SHELL_BUILTINS_H
