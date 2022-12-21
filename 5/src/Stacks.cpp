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

    // Parse commands
    for(size_t i=commandsStartingLine;i<data.size();i++) {
        std::stringstream stream(data[i]);
        std::string token;
        std::vector<int> tokens;

        int j=0;

        while( getline(stream,token,' ')) {
            if(token != "move" && token != "from" && token != "to") {
                tokens.push_back(stoi(token));
                j++;
            }
        }
        this->commands.push_back(tokens);
    }
}

std::string Stacks::SolvePart1() {
    std::string result = "";

    for(size_t c=0; c<this->commands.size();c++) {
        int howMany = this->commands[c][0];
        int whereFrom = this->commands[c][1]-1;
        int whereTo = this->commands[c][2]-1;

        for(int i=0;i<howMany;i++) {
            char crate = this->stacks[whereFrom].top();
            this->stacks[whereTo].push(crate);
            this->stacks[whereFrom].pop();
        }
    }

    for(size_t i=0;i<this->stacks.size();i++) {
        result += this->stacks[i].top();
    }

    return result;
}

std::string Stacks::SolvePart2() {
    return "";
}
