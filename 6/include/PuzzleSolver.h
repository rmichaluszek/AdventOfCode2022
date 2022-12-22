#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H

#include <vector>
#include <string>
#include <iostream>

class PuzzleSolver {
public:
    std::string dataStreamString;

    void ParseData(std::vector<std::string> data);
    int SolvePart1();
    int SolvePart2();
};

#endif //PUZZLESOLVER_H
