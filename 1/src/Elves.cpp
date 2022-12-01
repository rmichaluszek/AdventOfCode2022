#include "Elves.h"

Elves::Elves() {

}

Elves::~Elves() {

}

void Elves::ParseData(std::vector<std::string> data) {

	Elf* elf = new Elf();

	for(size_t i=0;i<data.size();i++) {
		if(data[i] == "") {
			elf = new Elf();
		}
		else {

			elf->GiveCalories(data[i]);
		}

		this->elves.push_back(*elf);
	}
}

int Elves::MostCaloriesCarriedByElf()
{
	int result = 0;

	std::vector<int> sumsOfCalories;

	for(size_t i=0; i<this->elves.size();i++) {
		sumsOfCalories.push_back(this->elves[i].GetSumOfCalories());
	}

	sort(sumsOfCalories.begin(),sumsOfCalories.end(),std::greater<int>());

	result = sumsOfCalories[0];

	return result;
}
