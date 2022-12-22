#include <sstream>
#include "PuzzleSolver.h"

void PuzzleSolver::ParseData(std::vector <std::string> data) {
    this->dataStreamString = data[0];
}

int PuzzleSolver::SolvePart1() {
    int result = 0;

    std::string string = this->dataStreamString;
    std::string usedCharacters = "";
    for(int i=0;i<string.length();i++) {
        if(usedCharacters.find(string[i])==std::string::npos){
            usedCharacters+=string[i];
        } else { // Something has repeated
            usedCharacters=string[i]; // Reset the unique characters list
        }
        result++;

        if(usedCharacters.length()>=4) {
            break;
        }
    }

    return result;
}

int PuzzleSolver::SolvePart2() {
    return 0;
}
