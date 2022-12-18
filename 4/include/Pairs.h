#ifndef PAIRS_H
#define PAIRS_H

#include <vector>
#include <string>
#include <iostream>

class Pairs {
public:
    //List of a pair of elves, that have beginning and end of a section (int,int)
    std::vector<std::pair<std::pair<int,int>,std::pair<int,int>>> sections;

    void ParseData(std::vector<std::string> data);

    int SolvePart1();
    int SolvePart2();


private:
    bool IsFullyContained(int a,int b,int c,int d);
    bool DoOverlap(int a,int b,int c,int d);
};

#endif //PAIRS_H
