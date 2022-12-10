#include <string>
#include <vector>

#include "DataLoader.h"
#include "RockPaperScissors.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    RockPaperScissors rps;
    rps.ParseData(data);

    int myEstaminatedScore = rps.CalculateResult();

    std::cout << "First part of the puzzle result is: " << myEstaminatedScore << std::endl;
    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}