#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>


class RockPaperScissors
{
public:
    RockPaperScissors();
    virtual ~RockPaperScissors();

    // 1 = rock , 2 = paper , 3 = scissors
    // First part of pair is enemy's play, and the second part is what you're "supposed" to play
    std::vector<std::pair<short ,short>> Rounds;

    void ParseData(std::vector<std::string> data);
    int CalculateFirstPartResult();
    int CalculateSecondPartResult();

protected:

private:
};


#endif //ROCKPAPERSCISSORS_H
