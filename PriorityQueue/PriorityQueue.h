#pragma once
#include "LinkedList.h"

template <typename T>
class PriorityQueue
{
	LinkedList<T> patients_;
	
	void sort() {

		T keyNode;
		size_t i, j;
		for (i = 1; i < size(); i++) {
			j = 1;

			while (j > 0 && patients_.get_at_index(j) < patients_.get_at_index(j - 1)) {
				
				patients_.swap(j, j - 1);

				j--;

			}

		}

	}

public:


	void enqueue(T object) {
		patients_.push_back(object); // We push back so it willl be the first sorted element
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
