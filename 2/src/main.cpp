#include <string>
#include <vector>

#include "DataLoader.h"
#include "RockPaperScissors.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    RockPaperScissors rps;
    rps.ParseData(data);

    int firstPartResult = rps.CalculateFirstPartResult();
    int secondPartResult  = rps.CalculateSecondPartResult();

    std::cout << "First part of the puzzle result is: " << firstPartResult << std::endl;
    std::cout << "Second part of the puzzle result is: " << secondPartResult << std::endl;
    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}