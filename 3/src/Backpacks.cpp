#include <sstream>
#include <iostream>
#include "Backpacks.h"

void Backpacks::ParseData(std::vector <std::string> data) {
    for(size_t i=0; i<data.size();i++) {
        std::vector<char> backpack;
        for(int j=0;j<data[i].length();j++) {
            backpack.push_back(data[i][j]);
        }
        this->backpacks.push_back(backpack);
    }
}

int Backpacks::CalculatePart1() {
    int result = 0;
    std::string doubleItems = "";
    for(size_t i=0;i<this->backpacks.size();i++) {
        for(size_t a=0;a<this->backpacks[i].size()/2;a++) {
            bool shouldBreak = false;
            // First half of the backpack checks if the same item is in second
            for(size_t b=this->backpacks[i].size()/2;b<this->backpacks[i].size();b++) {
                if(this->backpacks[i][a] == this->backpacks[i][b]) {
                    doubleItems+=this->backpacks[i][a];
                    shouldBreak = true;
                    break;
                }
            }
            if(shouldBreak) break;
        }
    }
    // get the priority value of the double items
    for (int i=0; i< doubleItems.length(); i++) {
        char item = int(doubleItems[i]);
        if(isupper(item)) {
            result += int(doubleItems[i])-38;
        } else {
            result += int(doubleItems[i])-96;
        }
    }
    return result;
}
