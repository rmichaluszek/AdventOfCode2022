#include "DataLoader.h"

DataLoader::DataLoader() {

}

DataLoader::~DataLoader() {

}

std::vector<std::string> DataLoader::GetData() {

    std::vector<std::string> data;

    std::ifstream file;
    file.open("./input.txt");

    if (!file) std::cout << "Input file not found" << std::endl;

    if (file.is_open()){

    	std::string l = "";

        while(getline(file, l)){
        	data.push_back(l);
        }
        file.close();

    }

    return data;
}
