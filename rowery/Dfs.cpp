#include"BfsAndDfs.h"

bool MyDfs(int howManyHuman, int howManyBike, Human *tabH, Bike *tabB) {
	bool ans = false;
	for (int i = 0; i < howManyHuman; i++) {
		tabH[i].visited = false;
	}

	for (int i = 0; i < howManyHuman; i++) {
		if (tabH[i].GetWitchBike() == false) {
			if (Dfs(i, howManyHuman, howManyBike, tabH, tabB)) {
				ans = true;
			}
		}
	}
	return ans;

	
}

bool Dfs(int index , int howManyHuman, int howManyBike, Human *tabH, Bike *tabB) {
	tabH[index].visited = true;
	int size = tabH[index].GetSize(); 
	for (int i = 0; i < size; i++) {
		int bikeIndex = tabH[index].TakeBikeNumber(i);
		if (tabB[bikeIndex].GetHumanIndex() == -1) {
			tabH[index].SetWichBike(true);
			tabB[bikeIndex].SetIndex(index);
			return true;
		}
		else {
			int someoneElse = tabB[bikeIndex].GetHumanIndex();
			if (tabH[someoneElse].visited == false && tabH[someoneElse].GetDistance() == tabH[index].GetDistance() + 1) {
				if (Dfs(someoneElse, howManyHuman, howManyBike, tabH, tabB)) {     //rekurencja
					tabH[index].SetWichBike(true);
				//	tabH[someoneElse].SetWichBike(false);
					tabB[bikeIndex].SetIndex(index);
					return true;
				//spr czy trzeba odkojazyc someone else !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!WAZNE
				
				}
			}
		}
	}
	return false;

}