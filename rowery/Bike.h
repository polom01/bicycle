#pragma once
#include "Human.h"
class Bike {
private:
	int number;
	int HumanIndex; 


public:
	Bike() {
		HumanIndex = -1; //nie przydzielony
		number = 0;
	}
	void SetIndex(int HumanIndex) { this->HumanIndex = HumanIndex; }
	void SetNumber(int number) { this->number= number; }

	int GetHumanIndex() { return this->HumanIndex; }
	int GetNumber() { return this->number; }
};