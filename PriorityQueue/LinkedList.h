﻿#pragma once

#include <stdexcept>

template <typename T>
class LinkedList
{
public:
	
	/**
	 * @brief The Node struct will hold the data for each element in the list
	*/
	struct Node {
		Node* previous;
		Node* next;

		T data;

		Node(const T& item) : data(item), previous(nullptr), next(nullptr) {}
	};

protected:
	Node* head_; // First element in the list
	Node* tail_; // Last element in the list

	size_t size_; // Amount of nodes in list

public:
	LinkedList() : begin_(nullptr), end_(nullptr), size_(0) {}

	Node* begin() { return begin_; }
	Node* end() { return end_; }

	/** GETTERS **/
	Node* begin() { return head_; }
	Node* end() { return tail_; }
	size_t size() { return size_; }

	/** LINKED LIST OPERATIONS **/
	
	/**
	 * @brief		Adds an element to the beginning of the list
	 * @param item	The item to add to the list
	*/
	void push_front(const T& item)
	{
		Node* node = new Node(item);

		//check if there is a node to link in-front of
		if (head_ == nullptr)
		{
			head_->previous = node;
			node->next = head_;
		}
		else
		{
			tail_ = node;
		}

		head_ = node;
		count_++;
	}

	/**
	 * @brief		Adds an element to the end of the list
	 * @param item	The item to add to the list
	*/
	void push_back(const T& item) {
		
		Node* node = new Node(item);

		if (head_ == nullptr && tail_ == nullptr)
		{
			head_ = node;
			tail_ = node;
			return;
		}

		node->previous = tail_;
		tail_->next = node;

		tail_ = node;
	}

	/**
	 * @brief	Removes the first element of the list and returns it
	 * @return	The first element of the list of type T
	*/
	T pop_front() {
		
		if (head_ == nullptr) throw std::out_of_range("Linked List is empty, cannot pop.");

		Node* node = head_;
		const T value = node->data;
		head_ = node->next;

		// TODO delete node

		return value;
	}

	/**
	 * @brief	Removes the last element of the list and returns it
	 * @return	The last element of the list of type T
	*/
	T pop_back()
	{
		if (tail_ == nullptr) throw std::out_of_range("Linked List is empty, cannot pop.");

		Node* node = tail_;
		const T value = node->data;
		head_ = node->previous;

		return value;
	}

	/**
	 * @brief	Returns if the list is empty
	 * @return	True if the list is empty, false otherwise
	*/
	bool empty() const
	{
		return head_ == nullptr;
	}

	/**
	 * @brief			Gets an element at a specific index
	 * @param index		The index of the element to get
	 * @return			The node at the specified index
	*/
	Node* get_at_index(const size_t index) {

		Node* currNode = head_;

		// Iterate through the linked list
		for (int i = 0; i < index; i++) {
			
			// Make sure there is a next node
			if (currNode->next == nullptr) {
				throw std::out_of_range("Index out of range while using get_at_index()");
			}

			// Get the next node
			currNode = currNode->next;

		}

		return currNode;

	}

	/**
	 * @brief				Swap two elements in the linked list
	 * @param indexFrom		index to swap from
	 * @param indexTo		index to swap to
	*/
	void swap(size_t indexFrom, size_t indexTo) {

		// Get the nodes at the specified indexes and store pointers to them
		Node* nodeFrom = get_at_index(indexFrom);
		Node* nodeTo = get_at_index(indexTo);

		// Swap the nodes
		Node* temp = nodeFrom->next;
		Node* temp2 = nodeFrom->previous;

		nodeFrom->next = nodeTo->next;
		nodeFrom->previous = nodeTo.previous;

		nodeTo->next = temp;
		nodeTo->previous = temp2;
		
	}

};
