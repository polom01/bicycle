#include"BfsAndDfs.h"
#include"Human.h"
#include"Bike.h"
#include"Queue.h"
#include<iostream>
using namespace std; 
void Bfs(int howManyHuman, int howManyBike, Human *tabH , Bike *tabB) {  // ok ?
	Queue MyQueue; 
	
	for (int j = 0; j < howManyHuman; j++) {
		tabH[j].SetDistance(-1);
		if (tabH[j].GetWitchBike() == false) {
			tabH[j].SetDistance(0);
			MyQueue.push(&tabH[j]);
		}
	}
	while (!MyQueue.GetEmpty()) {
	Human *tmp=MyQueue.pull();
	int size = tmp->GetSize(); // mozna dodac int zmenna = tabB[bikeIndex].GetHumanIndex(); //czas//
	
	for (int i = 0; i < size; i++) {
		int bikeIndex = tmp->TakeBikeNumber(i);
		int variable = tabB[bikeIndex].GetHumanIndex();
		if (variable != -1 && tabH[variable].GetDistance()==-1) {   //-1 w getHuman()  oznaczaza ze jest wolny
			tabH[variable].SetDistance(tmp->GetDistance() + 1);
			MyQueue.push(&tabH[tabB[bikeIndex].GetHumanIndex()]);
		}
	}
	}
	
	

//	cout << "ok" << endl;


}
