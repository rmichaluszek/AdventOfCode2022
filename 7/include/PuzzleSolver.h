#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H

#include <vector>
#include <string>
#include <iostream>

class Folder {
public:
    std::string folderName = "/"; // default name of the filesystem folder
    std::vector<std::pair<std::string,int>> files; // files, each one is made of its name and size
    std::vector<Folder> folders; // folders, containing files and folders

    int getDataSize() {
        return 0;
    }

    void addFile(std::string name, int size,std::vector<std::string> pathToCurrentFolder) {
        std::pair<std::string, int> newFile(name,size);
        this->files.push_back(newFile);;
    }
    void addFolder(std::string name) {
        bool folderDoesExist = false;
        for (size_t i = 0; i < this->folders.size(); i++) {
            if (name == this->folders[i].folderName) {
                folderDoesExist = true;
                std::cout << "Folder exists: " << name << std::endl;
            }
        }

        if (!folderDoesExist) {
            Folder newFolder;
            newFolder.folderName = name;
            this->folders.push_back(newFolder);

            std::cout << "Created folder: " << name << " in folder " << this->folderName << std::endl;
        }
    }

    Folder* getFolder(std::string name) {
        Folder *folder;
        for(size_t i=0;i<this->folders.size();i++) {
            if(this->folders[i].folderName==name) {
                folder = &this->folders[i];
            }
        }
        return folder;
    }
};

class PuzzleSolver {
public:
    void ParseData(std::vector<std::string> data);

    Folder fileSystem; // the root of the filesystem

    int SolvePart1();
    int SolvePart2();
};

#endif //PUZZLESOLVER_H
