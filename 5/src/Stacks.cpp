#include "Stacks.h"

void Stacks::ParseData(std::vector <std::string> data) {
    // The crates appear every 4th character and are 3 characters long "[a] [b]"

    // And the number of stacks can be determined by dividing it, last one doesn't have space after so its only 3 chars long
    this->numberOfStacks = data[0].length()/4+1;

    for(int i=0;i<this->numberOfStacks;i++) {
        std::stack<char> newStackOfCrates;
        this->stacks.push_back(newStackOfCrates);
    }

    // Find max number of crates in stacks
    int commandsStartingLine = 0;
    for(size_t i=0;i<data.size();i++) {
        // If the second character in line is 1, then it means this is the list of crates, so no more crates
        if(data[i][1] == '1') {
            commandsStartingLine = i+2;
            break;
        }
    }

    // Add crates to stack, starting from bottom
    for(int i=commandsStartingLine-3;i>=0;i--) {
        for(int j=0; j<this->numberOfStacks;j++) {
            if(data[i][j*4+1]!=' ') {
                this->stacks[j].push((data[i][j*4+1]));
            }
        }
    }
    std::cout << this->stacks[0].size() << std::endl;

    // Parse commands
    for(size_t i=commandsStartingLine;i<data.size();i++) {

    }
}
