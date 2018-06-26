#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include"BfsAndDfs.h"
#include "Human.h"
#include"Bike.h"
#define MAXSIZE 1200
#pragma warning( disable : 4996 )
using namespace std;




int main() {

	char arr[MAXSIZE];
	
	char *k;

	int howManyHuman , howManyBike;
	

	//cin >> howManyHuman;
	
	fgets(arr, MAXSIZE, stdin);
	k = strtok(arr, " ");
	howManyHuman = atoi(arr);
	while (k != NULL)
	{
		if(atoi(k)!=0)
		howManyBike = atoi(k);
		k = strtok(NULL, " ");
		
	}
	Human *tabH = new Human[howManyHuman];
	for (int j = 0; j < howManyHuman; j++) {
		int bikesForHuman;
		
		//cin >> bikesForHuman;
		fgets(arr, MAXSIZE, stdin);
		k = strtok(arr, " ");
		bikesForHuman= atoi(arr);
	
		tabH[j].SetHumanIndex(j);
		tabH[j].SetSizeAndtab(bikesForHuman);

		while (bikesForHuman>0 ) {//bikesForHuman > 0 && k!=NULL
			int numberBike;
			k = strtok(NULL, " ");
				numberBike = atoi(k);
				tabH[j].addNumber(numberBike);
			bikesForHuman--;
		
		}

	}
	



	Bike *tabB = new Bike[howManyBike+1];  //index od 1
	for (int j = 1; j < howManyBike + 1; j++) {
		tabB[j].SetNumber(j);
	}



	bool ans;
	do {
		Bfs(howManyHuman , howManyBike , tabH , tabB);
		 ans=MyDfs(howManyHuman, howManyBike, tabH, tabB);
	} while (ans);

	int score = 0;
	for (int j = 0; j < howManyHuman; j++) {
		if (tabH[j].GetWitchBike() == true) score++;
	}


	cout << score << endl;

	for (int j = 0; j < howManyHuman; j++) {
		tabH[j].deletetab();
	}
	delete tabH;


	return 0;
}