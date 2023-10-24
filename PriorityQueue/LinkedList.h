#pragma once

#include <stdexcept>

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		Node* previous;
		Node* next;

		T data;

		Node(T& item) : data(item), previous(nullptr), next(nullptr) {}
	};

protected:
	Node* begin_;
	Node* end_;

public:
	LinkedList() : begin_(nullptr), end_(nullptr) {}

	Node* begin() { return begin_; }
	Node* end() { return end_; }

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

	T pop_front()
	{
		if (begin_ == nullptr)
		{
			//todo: throw
			throw "";
		}

		Node* node = begin_;
		const T value = node->data;
		begin_ = node->next;

		return value;
	}

	T pop_back()
	{
		if (end_ == nullptr)
		{
			//todo: throw
			throw "";
		}

		Node* node = end_;
		const T value = node->data;
		begin_ = node->previous;

		return value;
	}

	bool empty() const
	{
		return begin_ == nullptr;
	}

	size_t size() const
	{
		size_t counter = 0;

		Node* node = begin_;
		while (node != nullptr)
		{
			++counter;
			node = node->next;
		}

		return counter;
	}

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

	void swap(size_t indexFrom, size_t indexTo) {

		Node* nodeFrom = get_at_index(indexFrom);
		Node* nodeTo = get_at_index(indexTo);

	}

};
