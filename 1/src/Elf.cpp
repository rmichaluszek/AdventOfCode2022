#include "Elf.h"

Elf::Elf() {

}

Elf::~Elf() {

}

void Elf::GiveCalories(std::string amount) {
	this->calories.push_back(stoi(amount));
}

int Elf::GetSumOfCalories() {
	int result = 0;
	for(size_t i=0;i<this->calories.size();i++) {
		result+=this->calories[i];

	}
	return result;
}
