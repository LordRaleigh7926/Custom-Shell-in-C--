#include <iostream>
#include <string>
#include <functional>
#include <utility>
#include <filesystem>

#include "shell_builtins.h"

using namespace std;
using std::unitbuf;

string getInput() {

  cout << "$ ";
  string input;
  getline(std::cin, input);

  return input;
}

void removeSpaces(string& str) {
    // Find the position of the last non-space character
    size_t pos = str.find_last_not_of(' ');
    // If a non-space character is found, erase everything after it
    if (pos != string::npos) {
        str.erase(pos + 1); // Erase from position after the last non-space character to the end
    } else {
        str.clear();
    }

    size_t pos2 = str.find_first_not_of(' ');

    if (pos2 != string::npos) {
        str.erase(0, pos2); // Erase from position after the last non-space character to the end
    }
}

pair<string, string> getCommandAndARGs(const string& str) {
    size_t spacePos = str.find(' ');
    if (spacePos == string::npos) {
        return make_pair(str, "None"); // No spaces, return the whole string
    }
    return make_pair(str.substr(0, spacePos), str.substr(spacePos+1));
}

int main() {
  // Flush after every std::cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;

  BuiltinCommands builtIns = BuiltinCommands();

  unordered_map<string, function<void(string)>> functionMap =  {
    {"echo", [&](string input) { builtIns.echo(input); }},
    {"type", [&](string input) { builtIns.typeCommand(input); }},
    {"cd", [&](string input) { builtIns.changeDirectory(input); }},
    {"pwd", [&](string input) { builtIns.printWorkingDirectory(input); }}
    
  };

  while (true) {

    string input = getInput();
    removeSpaces(input);
    auto [command, args] = getCommandAndARGs(input);

    int exit_code = builtIns.exitCommand(input);
    if (exit_code != 3) {
      return exit_code;
    } else if (input == "") {
      continue;
    }

    try
    {
      functionMap[command](args);
    }
    catch(const std::exception& e)
    {
      if (get_path(command)=="") {
        cerr<<input<<": command not found\n";
        continue;
      } else {
        int exec_code = system(input.c_str());
      }
    }

  }
}