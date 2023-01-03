#include "PuzzleSolver.h"

void PuzzleSolver::ParseData(std::vector <std::string> data) {
    for(size_t i=0;i<data.size();i++) {
        std::vector<short> newVector;
        for(int j=0;j<data[i].length();j++) {
            newVector.push_back(data[i][j]-'0'); // Changes char number into corresponding int number
        }
        this->trees.push_back(newVector);
    }
}

int PuzzleSolver::SolvePart1() {
    int result = 0;
    // Count visible trees
    // We skip the ones on the edge (y=1)
    for(size_t y=0;y<this->trees.size();y++) {
        for (size_t x=0;x<this->trees[y].size();x++) {
           if(IsTreeVisible(x,y)) {
               result+=1;
           }
        }
    }

    return result;
}

int PuzzleSolver::SolvePart2() {

    int biggestScenicScore = 0;
    // Count visible trees
    // We skip the ones on the edge (y=1)
    for(size_t y=0;y<this->trees.size();y++) {
        for (size_t x=0;x<this->trees[y].size();x++) {
            int scenicScore = GetScenicScore(x,y);
            if(scenicScore>biggestScenicScore) biggestScenicScore = scenicScore;
        }
    }

    return biggestScenicScore;
}

bool PuzzleSolver::IsTreeVisible(short x, short y) {

    // Check all 4 directions for trees that are as high or higher, if none is found the the tree is visible
    bool isVisible[4] = {true,true,true,true}; // 4 sides

    // Left
    for(size_t i=0;i<x;i++) {
        if (this->trees[y][i] >= this->trees[y][x]) {
            isVisible[0] = false;
        }
    }
    // Right
    for(size_t i=x+1;i<this->trees[y].size();i++) {
        if (this->trees[y][i] >= this->trees[y][x]) {
            isVisible[1] = false;
        }
    }

    // Top
    for(size_t i=0;i<y;i++) {
        if (this->trees[i][x] >= this->trees[y][x]) {
            isVisible[2] = false;
        }
    }
    // Bottom
    for(size_t i=y+1;i<this->trees.size();i++) {
        if (this->trees[i][x] >= this->trees[y][x]) {
            isVisible[3] = false;
        }
    }

    for(int i=0;i<4;i++){
        if(isVisible[i]==true) {
            return true;
        }
    }
    return false;
}

int PuzzleSolver::GetScenicScore(short x, short y) {
    int score = 0;

    int treesVisible[4] = {0,0,0,0}; // how many trees are visible in each direction

    // Now we iterate in the direction that were counting

    // Left
    for(int i=x-1;i>=0;i--) {
        treesVisible[0]++;
        if (this->trees[y][i] >= this->trees[y][x]) {
            // we stop now
            break;
        }
    }

    // Right
    for(int i=x+1;i<this->trees[y].size();i++) {
        treesVisible[1]++;
        if (this->trees[y][i] >= this->trees[y][x]) {
            // we stop now
            break;
        }
    }

    // Top
    for(int i=y-1;i>=0;i--) {
        treesVisible[2]++;
        if (this->trees[i][x] >= this->trees[y][x]) {
            // we stop now
            break;
        }
    }

    // Bottom
    for(int i=y+1;i<this->trees.size();i++) {
        treesVisible[3]++;
        if (this->trees[i][x] >= this->trees[y][x]) {
            // we stop now
            break;
        }
    }

    score = treesVisible[0] * treesVisible[1] * treesVisible[2] * treesVisible[3];

    return score;
};
