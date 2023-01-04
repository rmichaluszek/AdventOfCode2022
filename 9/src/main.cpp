#include <string>
#include <vector>

#include "DataLoader.h"
#include "PuzzleSolver.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    PuzzleSolver puzzleSolver;
    puzzleSolver.ParseData(data);

    std::cout << "Part 1 result is: " << puzzleSolver.SolvePart1() << std::endl;
    std::cout << "Part 2 result is: " << puzzleSolver.SolvePart2() << std::endl;

    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}