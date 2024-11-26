#include <iostream>
#include <string>

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

int main() {
  // Flush after every std::cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;


  // Array of all the builtin commands
  string builtinCommands[] = {"echo", "exit", "type"};



  while (true) {

    string input = getInput();
    removeSpaces(input);

    if (input == "exit 0" || input == "exit") {
      return 0;

    } else if (input == "exit 1") {
      return 1;

    } else if (input.find("echo ") == 0) {

      const int ECHO_LEN = 5; // Including space
      string text = input.substr(ECHO_LEN);
      cout << text << endl;

    } else if (input == "") {
      continue;
    } else {

      cout<<input<<": command not found\n";
    }


  }
}