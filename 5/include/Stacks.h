#ifndef STACKS_H
#define STACKS_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>

class  Stacks
{
public:
    int numberOfStacks = 0;
    std::vector<std::stack<char>> stacks; // Vector of Stacks of crates
    std::vector<std::vector<int>> commands;
    void ParseData(std::vector<std::string> data);

    std::string SolvePart1();
    std::string SolvePart2();
};

#endif
