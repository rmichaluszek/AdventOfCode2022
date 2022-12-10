#include "RockPaperScissors.h"

RockPaperScissors::~RockPaperScissors() {
}

RockPaperScissors::RockPaperScissors() {
}

void RockPaperScissors::ParseData(std::vector<std::string> data) {
    for(size_t i=0;i<data.size();i++) {
        if(data[i] !="") {
            std::pair<short,short> pair;

            char first = data[i][0];
            char second = data[i][2];

            if( first == 'A') { pair.first = 1;}
            else if( first == 'B') { pair.first = 2;}
            else if( first == 'C') { pair.first = 3;}

            if( second == 'X') { pair.second = 1;}
            else if( second == 'Y') { pair.second = 2;}
            else if( second == 'Z') { pair.second = 3;}

            this->Rounds.push_back(pair);
        }
    }
}

int RockPaperScissors::CalculateResult() {
    int result = 0;
    short winScore = 6;
    short drawScore = 3;

    for(size_t i=0;i<this->Rounds.size();i++) {

        short enemyValue = this->Rounds[i].first;
        short myValue = this->Rounds[i].second;

        if(enemyValue == 1) {
            if(myValue == 2) { result +=winScore+myValue; }
            else if(myValue == 3) { result+=myValue; }
            else if(myValue == 1) { result+=drawScore+myValue; }
        }
        else if(enemyValue == 2) {
            if(myValue == 3) { result +=winScore+myValue; }
            else if(myValue == 1) { result+=myValue; }
            else if(myValue == 2) { result+=drawScore+myValue; }
        }
        if(enemyValue == 3) {
            if(myValue == 1) { result +=winScore+myValue; }
            else if(myValue == 2) { result+=myValue; }
            else if(myValue == 3) { result+=drawScore+myValue; }
        }
    }
    return result;
}


