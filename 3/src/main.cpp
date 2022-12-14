#include <string>
#include <vector>

#include "DataLoader.h"
#include "Backpacks.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Backpacks backpacks;
    backpacks.ParseData(data);

    std::cout << "Part 1 result is: " << backpacks.CalculatePart1() << std::endl;

    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}