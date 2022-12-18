#include <string>
#include <vector>

#include "DataLoader.h"
#include "Pairs.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Pairs pairs;
    pairs.ParseData(data);

    std::cout << "First part result is: " << pairs.SolvePart1() << std::endl;
    std::cout << "Second part result is: " << pairs.SolvePart2() << std::endl;

    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}