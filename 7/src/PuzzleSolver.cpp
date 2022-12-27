#include "PuzzleSolver.h"

void PuzzleSolver::ParseData(std::vector <std::string> data) {

    bool listing = false;
    std::vector<std::string> currentFolder; // by having that, we can be in /c/d/e folder and go back any time

    for(size_t i=0; i<data.size();i++) {

        if(data[i][0]=='$') { // this is out command, so were creating folders and files based on later output
            std::string command;
            std::string argument;

            int delimeterPos = data[i].find(' ',2); // only searching for second space
            command = data[i].substr(2,2);

            if(delimeterPos != std::string::npos) {
                argument = data[i].substr(delimeterPos+1,data[i].length());
            }

            if(command=="cd" && argument=="/") {
                currentFolder.clear();
            } else if (command=="cd") {
                if(argument!="..") {
                    currentFolder.push_back(argument);
                } else {
                    currentFolder.pop_back();
                }
            } else if (command == "ls") {
                listing = true;
            }

        } else {
            int delimeterPos = data[i].find(' ');
            std::string firstPart = data[i].substr(0,delimeterPos);
            std::string secondPart = data[i].substr(delimeterPos+1,data[i].length()-delimeterPos);

            std::vector<std::string> pathToFolder = currentFolder;

            if(firstPart=="dir") {
                Folder *parentFolder = &this->fileSystem;
                while(pathToFolder.size()>0){
                    parentFolder=parentFolder->getFolder(pathToFolder[0]);
                    pathToFolder.erase(pathToFolder.begin());
                }
                parentFolder->addFolder(secondPart);
            } else {
                Folder *parentFolder = &this->fileSystem;
                while(pathToFolder.size()>0){
                    parentFolder=parentFolder->getFolder(pathToFolder[0]);
                    pathToFolder.erase(pathToFolder.begin());
                }
                parentFolder->addFile(secondPart,stoi(firstPart));
            }
        }
    }
}

int PuzzleSolver::SolvePart1() {
    int result = 0;
    int folderSizeLimit = 100000;

    std::vector<Folder*> folders = this->fileSystem.getFoldersList();

    for(size_t i=0;i<folders.size();i++) {
        int size = folders[i]->getDataSize();

        if(size<folderSizeLimit) {
            result += size;
        }
    }

    return result;
}

int PuzzleSolver::SolvePart2() {
    return 0;
}
