#pragma once
#include "LinkedList.h"

/**
 * @brief		The PriorityQueue class will hold the data for each patient in the hospital in order
 * @tparam T	The type of data to hold in the queue
*/
template <typename T>
class PriorityQueue
{	
	/**
	 * @brief The Node struct will hold the data for each element in the list
	*/
	LinkedList<T> patients_;
	
	/**
	 * @brief Sorts the list based on the score of each patient
	*/
	void sort() {

		for (int i = 0; i < patients_.size(); i++) {

			int temp = i;
			int j = i;

			while (j > 0 && patients_.get_data_at_index(i) > patients_.get_data_at_index(j - 1)) {
				patients_.swap(j, j - 1);
				j--;
			}

		}
	
	}

public:

	/**
	 * @brief			Adds an element to the queue
	 * @param object	The object to add to the queue
	*/
	void enqueue(T object) {
		patients_.push_front(object); // We push front so it will be the first sorted element
		sort();
	};

	/**
	 * @brief	Removes the first element from the queue
	 * @return	The first element in the queue
	*/
	T dequeue() {
		return patients_.pop_front();
	}

	T peek() {
		return patients_.peek_head();
	}

	/**
	 * @brief	Returns the size of the queue
	 * @return	The size of the queue
	*/
	unsigned int size() const {
		return patients_.size();
	}

	/**
	 * @brief	Checks if the queue is empty
	 * @return	True if the queue is empty, false otherwise
	*/
	bool empty() {
		return patients_.empty();
	}

	LinkedList<T>& get_patient_list() {
		return patients_;
	}

};
