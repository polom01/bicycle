#pragma once
#include "Human.h"
#include<cstdlib>

class Queue {

	Human *first;
	Human *last;
	Human *preLast;
	bool empty;


public:
	Queue() {
		first = nullptr;
		last = nullptr;
		preLast = nullptr;
		empty = true;
	}

	void push(Human *h) {
		if (first == nullptr) {
			first = h;
			last = h;
			h->next = NULL;
			empty = false;
		}
		else {
			Human *tmp;
			tmp = last;
			tmp->next = h;
	//		while (tmp->next != NULL) { tmp = tmp->next; }
	//		tmp->next = h;
		//	last = h;
			h->next = NULL;
			last = h;


		}
	}

	Human *pull() {
		if (first == nullptr) {
			empty = true;
			return NULL;
		}
		else {
			Human *tmp = first;
			first = tmp->next;
			if (first==NULL)empty = true;
			tmp->next = NULL;//dodac lasta!!! jezeli bede go uzywal :)
			return tmp;
		}

	}

	bool GetEmpty() { return empty; }



};
