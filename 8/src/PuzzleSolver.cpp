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

    // And add the trees that are on the edges
    int numberOfTreesOnThEdges = this->trees.size()*2+this->trees[0].size()*2-4;
    //result += numberOfTreesOnThEdges;
    return result;
}

int PuzzleSolver::SolvePart2() {
    return 0;
}

bool PuzzleSolver::IsTreeVisible(short x, short y) {

    // Check all 4 directions for trees that are as high or higher, if none is found the the tree is visible
    bool isVisible[4] = {true,true,true,true}; // 4 sides

    if(x==0 || x == this->trees[y].size()-1) {
        return true;
    } else if(y==0 || y == this->trees.size()-1) {
        return true;
    }

    // Left
    for(size_t i=1;i<x;i++) {
        if (this->trees[y][x-i] >= this->trees[y][x]) {
            isVisible[0] = false;
        }
    }
    // Left
    for(size_t i=1;i<this->trees[y].size()-x;i++) {
        if (this->trees[y][x+i] >= this->trees[y][x]) {
            isVisible[1] = false;
        }
    }

    // Left
    for(size_t i=1;i<y;i++) {
        if (this->trees[y-i][x] >= this->trees[y][x]) {
            isVisible[2] = false;
        }
    }
    // Left
    for(size_t i=1;i<this->trees.size()-y;i++) {
        if (this->trees[y+i][x] >= this->trees[y][x]) {
            isVisible[3] = false;
        }
    }

    for(int i=0;i<4;i++){
        if(isVisible[i]==true) {
            return true;
        }
    }
    return false;
};
