#pragma once
#include"human.h"
#include"Bike.h"
void Bfs(int howManyHuman, int howManyBike, Human *tabH , Bike *tabB);
bool MyDfs(int howManyHuman, int howManyBike, Human *tabH, Bike *tabB);
bool Dfs(int index, int howManyHuman, int howManyBike, Human *tabH, Bike *tabB);