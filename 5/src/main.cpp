#include <string>
#include <vector>

#include "DataLoader.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    std::cout << "First part result is: "  << std::endl;
    std::cout << "Second part result is: " << std::endl;

    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}