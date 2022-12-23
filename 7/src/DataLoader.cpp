#include "DataLoader.h"

DataLoader::DataLoader() = default;

DataLoader::~DataLoader() = default;

std::vector<std::string> DataLoader::GetData() {

    std::vector<std::string> data;

    std::ifstream file;

    file.open("data/input.txt");
    //file.open("data/example_input.txt");

    if (!file) std::cout << "Input file not found" << std::endl;

    if (file.is_open()){

        std::string l;

        while(getline(file, l)){
            data.push_back(l);
        }
        file.close();

    }

    return data;
}
