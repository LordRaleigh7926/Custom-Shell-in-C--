// shell_builtins.cpp
#include "shell_builtins.h"  // Include the header file for declarations

using namespace std;

// Set unitbuf globally, so cout and cerr are automatically flushed after every output
static struct UnitBufSetter
{
    UnitBufSetter()
    {
        cout << unitbuf;
        cerr << unitbuf;
    }
} unitBufSetter; // This will run when the program starts

// Function to split a string into words based on spaces
vector<string> splitString(const string &str)
{
    vector<string> words;
    istringstream stream(str);
    string word;

    while (stream >> word)
    {
        words.push_back(word);
    }

    return words;
}

// Function to check if an item exists in an array
bool isInArray(string* arr, int size, string target) {
    return find(arr, arr + size, target) != arr + size;
}

// Method to handle the 'echo' command
void BuiltinCommands::echo(const string &text)
{
    cout << text << endl;
}

// Method to handle the 'exit' command
int BuiltinCommands::exitCommand(const string &input)
{
    if (input == "exit" || input == "exit 0")
    {
        return 0; // Exit with code 0
    }
    else if (input == "exit 1")
    {
        return 1; // Exit with code 1
    }
    else
    {
        return 3;
    }
}

// Method to handle the 'type' command
void BuiltinCommands::typeCommand(const string &input)
{
    vector<string> commands = splitString(input);
    string CommandsBuiltin[3] = {"echo", "exit", "type"};
    for (const auto &command : commands)
    {
        if (isInArray(CommandsBuiltin, 3, command)) {
            cout << command << " is a shell builtin\n";
        } else {
            cout << command << ": not found\n";
        }
    }
}
