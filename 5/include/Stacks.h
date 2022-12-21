#ifndef STACKS_H
#define STACKS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stack>

class  Stacks
{
public:
    int numberOfStacks = 0;
    std::vector<std::stack<char>> stacks; // Vector of Stacks of crates
    void ParseData(std::vector<std::string> data);

};

#endif
