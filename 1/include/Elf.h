#ifndef ELF_H_
#define ELF_H_

#include <vector>
#include <string>

class Elf {
public:
	Elf();
	virtual ~Elf();

	std::vector<int> calories;

	void GiveCalories(std::string amount);
	int GetSumOfCalories();
};

#endif
