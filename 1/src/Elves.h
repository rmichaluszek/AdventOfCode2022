#ifndef ELVES_H_
#define ELVES_H_

#include "Elf.h"

#include <bits/stdc++.h>

class Elves {
public:
	Elves();
	virtual ~Elves();

	std::vector<Elf> elves;

	void ParseData(std::vector<std::string> data);
	int MostCaloriesCarriedByElf();

};

#endif
