#ifndef ELVES_H_
#define ELVES_H_

#include <vector>
#include <string>
#include <algorithm>

#include "Elf.h"

class Elves {
public:
	Elves();
	virtual ~Elves();

	std::vector<Elf> elves;

	void ParseData(std::vector<std::string> data);
	int MostCaloriesCarriedByElf();
	int MostCaloriesCarriedByTop3();

};

#endif
