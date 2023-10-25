#pragma once

#include <stdexcept>

template <typename T>
class LinkedList
{
public:
	
	/**
	 * @brief The Node struct will hold the data for each element in the list
	*/
	struct Node
	{
		Node* previous;
		Node* next;

		T data;

		Node(const T& item) : data(item), previous(nullptr), next(nullptr) {}
	};

protected:
	Node* begin_;
	Node* end_;

	size_t size_; // TODO REMOVE IF NOT IMPLEMENTED

public:
	LinkedList() : begin_(nullptr), end_(nullptr), size(0) {}

	Node* begin() { return begin_; }
	Node* end() { return end_; }

	/**
	 * @brief		Adds an element to the beginning of the list
	 * @param item	The item to add to the list
	*/
	void push_front(const T& item)
	{
		Node* node = new Node(item);

		//check if there is a node to link in-front of
		if (begin_ == nullptr)
		{
			begin_->previous = node;
			node->next = begin_;
		}
		else
		{
			end_ = node;
		}

		begin_ = node;
	}

	/**
	 * @brief		Adds an element to the end of the list
	 * @param item	The item to add to the list
	*/
	void push_back(const T& item)
	{
		Node* node = new Node(item);

		if (begin_ == nullptr && end_ == nullptr)
		{
			begin_ = node;
			end_ = node;
			return;
		}

		node->previous = end_;
		end_->next = node;

		end_ = node;
	}

	/**
	 * @brief	Removes the first element of the list and returns it
	 * @return	The first element of the list of type T
	*/
	T pop_front()
	{
		if (begin_ == nullptr) throw std::out_of_range("Linked List is empty, cannot pop.");

		Node* node = begin_;
		const T value = node->data;
		begin_ = node->next;

		// TODO delete node

		return value;
	}

	/**
	 * @brief	Removes the last element of the list and returns it
	 * @return	The last element of the list of type T
	*/
	T pop_back()
	{
		if (end_ == nullptr) throw std::out_of_range("Linked List is empty, cannot pop.");

		Node* node = end_;
		const T value = node->data;
		begin_ = node->previous;

		return value;
	}

	/**
	 * @brief	Returns if the list is empty
	 * @return	True if the list is empty, false otherwise
	*/
	bool empty() const
	{
		return begin_ == nullptr;
	}

	/**
	 * @brief	Returns the size of the list
	 * @return	The size of the list
	*/
	size_t size() const
	{

		// TODO Maybe implement a counter in the LinkedList class
		
		size_t counter = 0;

		Node* node = begin_;
		while (node != nullptr)
		{
			++counter;
			node = node->next;
		}

		return counter;
	}

	/**
	 * @brief			Gets an element at a specific index
	 * @param index		The index of the element to get
	 * @return			The node at the specified index
	*/
	Node* get_at_index(const size_t index) {

		Node* currNode = begin_;

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
