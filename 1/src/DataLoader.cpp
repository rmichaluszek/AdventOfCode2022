#include "DataLoader.h"

DataLoader::DataLoader() {

}

DataLoader::~DataLoader() {

}

std::vector<std::string> DataLoader::GetData() {

    std::vector<std::string> data;

    int numberOfEmptyLines = 0;
    bool inputEnabled = true;
    while(inputEnabled) {

        std::string l = "";
        getline(std::cin,l);

        if(l.length()<= 0) {
        	numberOfEmptyLines++;
        	data.push_back("");
    	}
        else {
            data.push_back(l);
            numberOfEmptyLines = 0;
        }

        if(numberOfEmptyLines>=2) {
        	inputEnabled = false;
        }

    }
    return data;
}
