#pragma once
#include "LinkedList.h"

template <typename T>
class PriorityQueue
{
	LinkedList<T> patients_;
	
	// USING INSERTION SORT AS THE DATA IS "online" AND WE CAN SORT AS WE GO
	void sort() {

		int i, j, key;

		for (i = 1; i < patients_.size(); i++) {
			key = i;
			j = i - 1;
			
			// TODO FIND A BETTER WAY TO IMPLEMENT THIS
			while (j > 0 && patients_.get_at_index(j) < patients_.get_at_index(key)) { 
				patients_.swap(j, j - 1);
				j--;
				
			}	
		}
	}

public:


	void enqueue(T object) {
		patients_.push_front(object); // We push back so it will be the first sorted element
		sort();
	};

	T dequeue() {
		return patients_.pop_back();
	}

	unsigned int size() const {
		return patients_.size();
	}

	bool empty() {
		return patients_.empty();
	}

};
