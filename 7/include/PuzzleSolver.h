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
        int size = 0;
        // files in this folder
        for(size_t i=0; i<this->files.size();i++) {
            size += this->files[i].second; // the size of file
        }
        // and size of folders that are within this one
        for(size_t i=0; i<this->folders.size();i++) {
            size += this->folders[i].getDataSize(); // the size of file
        }
        return size;
    }

    void addFile(std::string name, int size) {
        std::pair<std::string, int> newFile(name,size);
        this->files.push_back(newFile);;
    }
    void addFolder(std::string name) {
        bool folderDoesExist = false;
        for (size_t i = 0; i < this->folders.size(); i++) {
            if (name == this->folders[i].folderName) {
                folderDoesExist = true;
            }
        }

        if (!folderDoesExist) {
            Folder newFolder;
            newFolder.folderName = name;
            this->folders.push_back(newFolder);
        }
    }

    std::vector<Folder*> getFoldersList() {
        std::vector<Folder*> list;
        for(size_t i=0; i<this->folders.size();i++) {
            std::vector<Folder*> thisFoldersList = this->folders[i].getFoldersList();
            std::copy(std::begin(thisFoldersList), std::end(thisFoldersList), std::back_inserter(list));
            list.push_back(&this->folders[i]);
        }
        return list;
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
