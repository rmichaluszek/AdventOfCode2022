#include "Pairs.h"

void Pairs::ParseData(std::vector<std::string> data) {
    for(size_t i=0; i<data.size();i++) {
        int a,b,c,d = 0; // First section start, first section end, second section start, second section end
        std::string firstSection, secondSection = ";";

        int sectionsDelimeterPos = 0;
        sectionsDelimeterPos = data[i].find(',');
        firstSection = (data[i].substr(0, sectionsDelimeterPos));
        secondSection = (data[i].substr(sectionsDelimeterPos+1, data[i].length()));

        int rangeDelimeterPos = 0;
        rangeDelimeterPos = firstSection.find('-');
        a = stoi(firstSection.substr(0,rangeDelimeterPos));
        b = stoi(firstSection.substr(rangeDelimeterPos+1,firstSection.length()));

        rangeDelimeterPos = secondSection.find('-');
        c = stoi(secondSection.substr(0,rangeDelimeterPos));
        d = stoi(secondSection.substr(rangeDelimeterPos+1,secondSection.length()));

        std::pair<int,int> firstPair (a,b);
        std::pair<int,int> secondPair (c,d);
        this->sections.push_back(std::pair<std::pair<int,int>,std::pair<int,int>>(firstPair,secondPair));
    }
}

int Pairs::SolvePart1() {
    int result = 0;

    for(size_t i=0;i<this->sections.size();i++) {
        std::pair<std::pair<int,int>,std::pair<int,int>> data = this->sections[i];
        if(IsFullyContained(data.first.first,data.first.second,data.second.first,data.second.second)) {
            result++;
        }
    }

    return result;
}

int Pairs::SolvePart2() {
    int result = 0;

    for(size_t i=0;i<this->sections.size();i++) {
        std::pair<std::pair<int,int>,std::pair<int,int>> data = this->sections[i];
        if(DoOverlap(data.first.first,data.first.second,data.second.first,data.second.second)) {
            result++;
        }
    }

    return result;
}

bool Pairs::IsFullyContained(int a, int b, int c, int d) {
    if(a >= c && b <= d) return true;
    else if(c >= a && d <= b) return true;
    return false;
}

bool Pairs::DoOverlap(int a, int b, int c, int d) {
    if(a >= c && a <= d) return true;
    else if(b <= d && b >= c) return true;
    else if(c >= a && c <= b) return true;
    else if(d <= b && d >= a) return true;
    return false;
}
