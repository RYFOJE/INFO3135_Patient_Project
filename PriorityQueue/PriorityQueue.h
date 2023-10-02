#pragma once
#include "LinkedList.h"

template <typename T>
class PriorityQueue
{
	LinkedList<T> patients_;

public:
	
	void sort() {

	}

	void enqueue(T object) {
		patients_.push_back(object); // We push back so it willl be the first sorted element
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
