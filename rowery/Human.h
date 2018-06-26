#pragma once

class Human {

private: 
	int distance;
	bool witchBike;
	int *tabNumbers;
	int index;
	int humanIndex;
	int size;
	
	

public:
	bool visited; //hermetyzacja
	Human *next;
	Human() {
		index = 0;
		visited = false;
		tabNumbers = nullptr;
		witchBike = false;
	}

	void addNumber(int numberBike) {
		tabNumbers[index++]=numberBike;
	}

	
	int TakeBikeNumber(int index) {
		return tabNumbers[index];
	}




	void SetSizeAndtab(int size) {
		this->size = size;
		this->tabNumbers = new int[size];
	}

	void SetDistance(int distance) { this->distance = distance; }
	void SetWichBike(bool witchBike) { this->witchBike = witchBike; }

	int GetDistance() { return this->distance; }
	bool GetWitchBike() { return this->witchBike; }
	int GetSize() { return this->size; }

	void SetHumanIndex(int humanIndex) { this->humanIndex = humanIndex; }

	int GetHumanIndex() { return this->humanIndex; }

	void deletetab() {
		if (tabNumbers != nullptr) {
			delete tabNumbers;
		}
	}
};