#ifndef DATALOADER_H
#define DATALOADER_H

#include <bits/stdc++.h>
#include <fstream>
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
