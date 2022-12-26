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

    void addFile(std::string name, int size) {
        std::pair<std::string, int> newFile(name,size);
        this->files.push_back(newFile);;
    }
    void addFolder(std::string name) {
        Folder newFolder;
        newFolder.folderName = name;
        this->folders.push_back(newFolder);
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
