#ifndef DATALOADER_H
#define DATALOADER_H
#include <vector>
#include <string>
#include <iostream>


class DataLoader
{
public:
    DataLoader();
    virtual ~DataLoader();
    std::vector<std::string> GetData();

protected:

private:
};

#endif // DATALOADER_H
