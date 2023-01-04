#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class DataLoader
{
public:
    DataLoader();
    virtual ~DataLoader();
    static std::vector<std::string> GetData();

protected:

private:
};

#endif // DATALOADER_H
