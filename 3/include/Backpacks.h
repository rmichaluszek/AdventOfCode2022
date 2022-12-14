#ifndef BACKPACKS_H
#define BACKPACKS_H

#include <vector>
#include <string>

class Backpacks {
public:
    std::vector<std::vector<char>> backpacks;

    void ParseData(std::vector<std::string> data);
    int CalculatePart1();
    int CalculatePart2();
};

#endif //INC_3_BACKPACKS_H
