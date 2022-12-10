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

int RockPaperScissors::CalculateFirstPartResult() {
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

int RockPaperScissors::CalculateSecondPartResult() {
    int result = 0;
    short winScore = 6;
    short drawScore = 3;

    // Now, in second pair part, the 1 means we have to lose, 2 means we have to draw, and 3 means it's time to win

    for(size_t i=0;i<this->Rounds.size();i++) {

        short enemyValue = this->Rounds[i].first;
        short whatWeHaveToDo = this->Rounds[i].second;

        if(whatWeHaveToDo == 1) { // Lose
            // We play scissors to lose
            if(enemyValue == 1) { result +=3; }
            // We play rock to lose
            else if(enemyValue == 2) { result+=1; }
            // We play paper to lose
            else if(enemyValue == 3) { result+=2; }
        }
        else if(whatWeHaveToDo == 2) { // Draw
            // We just play the same as the opponent
            result += drawScore+enemyValue;
        }
        else if(whatWeHaveToDo == 3) { // Win
            // We play paper to win
            if(enemyValue == 1) { result +=winScore+2; }
            // We play scissors to win
            else if(enemyValue == 2) { result+=winScore+3; }
            // We play rock to win
            else if(enemyValue == 3) { result+=winScore+1; }
        }

    }
    return result;
}


