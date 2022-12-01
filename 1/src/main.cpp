#include <bits/stdc++.h>
#include <iostream>

#include "DataLoader.h"
#include "Elves.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Elves elves;
    elves.ParseData(data);

    std::cout << "Biggest amount of calories: " << elves.MostCaloriesCarriedByElf() << std::endl;
    std::cout << "Amount of calories held by top 3: " << elves.MostCaloriesCarriedByTop3() << std::endl;

    std::cout << std::endl;
    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}
