#pragma once

#include <stdexcept>

/**
 * @brief		The LinkedList class will hold the data for each patient in the hospital in order
 * @param T		The type of data to hold in the list
*/
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

		// TODO Maybe do not use a reference and instead accpet a direct object
		Node(T item) : data(item), previous(nullptr), next(nullptr) {}

	};

protected:
	Node* head_;
	Node* tail_;

	size_t size_;

public:

	/** CONSTRUCTOR **/
	LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}


	/** GETTERS **/
	Node* begin() const { return head_; }
	Node* end() const { return tail_; }
	size_t size() const { return size_; }


	/** LINKED LIST FUNCTIONS **/

	/**
	 * @brief			Adds an element to the beginning of the list
	 * @param item		The item to add to the list
	*/
	void push_front(const T& item)
{
    Node* node = new Node(item);

    if (head_ == nullptr)
    {
        head_ = node;
        tail_ = node;
    }
    else
    {
        head_->previous = node;
        node->next = head_;
        head_ = node;
    }
    size_++;
}

	/**
	 * @brief			Adds an element to the end of the list
	 * @param item		The item to add to the list
	*/
	void push_back(const T& item)
	{
		Node* node = new Node(item);

		if (head_ == nullptr && tail_ == nullptr) {
			head_ = node;
			tail_ = node;
		}
		else {
			node->previous = tail_;
			tail_->next = node;
			tail_ = node;
		}		
		size_++;
	}

	/**
	 * @brief	Removes the first element of the list and returns it
	 * @return	The first element of the list of type T
	*/
	T pop_front()
	{
		if (size_ == 0) throw std::out_of_range("Linked List is empty, cannot pop.");

		Node* node = head_;
		const T value = node->data;
		head_ = node->next;

		// Update tail to nullptr when the list becomes empty
		if (head_ == nullptr) {
			tail_ = nullptr; 
		}

		delete node;
		size_--;

		return value;
	}

	/**
	 * @brief			Removes the last element of the list and returns it
	 * @return			The last element of the list of type T
	*/
	T pop_back()
	{
		if (size_ == 0) throw std::out_of_range("Linked List is empty, cannot pop.");

		Node* node = tail_;
		const T value = node->data;
		tail_ = node->previous;

		// Update head to nullptr when the list becomes empty
		if (tail_ == nullptr) {
			head_ = nullptr;
		}

		delete node;

		size_--;
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

		if (index >= size_) {
			throw std::out_of_range("Index out of range while using get_at_index()");
		}
		
		// Iterate through the linked list
		for (int i = 0; i < index; i++) {

			// Get the next node
			currNode = currNode->next;

		}

		return currNode;

	}

	/**
	 * @brief			Gets the data at a specific index
	 * @param index		The index of the data to get
	 * @return			The data at the specified index
	*/
	T& get_data_at_index(const size_t index) {

		Node* curr = get_at_index(index);

		return curr->data;

	}

	/**
	 * @brief			Gets the data at the tail of the list
	 * @return			The data at the tail of the list
	*/
	T& peek_tail() {

		return tail_->data;

	}

	/**
	 * @brief			Gets the data at the head of the list
	 * @return			The data at the head of the list
	*/
	T& peek_head() {

		return head_->data;

	}

	/**
	 * @brief			Swap two elements in the linked list
	 * @param indexFrom	index to swap from
	 * @param indexTo	index to swap to
	*/
	void swap(size_t indexFrom, size_t indexTo) {
		
		// Initially, I was using swapping of pointers but it's more efficient to swap the data itself

		T temp = get_at_index(indexFrom)->data;
		get_at_index(indexFrom)->data = get_at_index(indexTo)->data;
		get_at_index(indexTo)->data = temp;

	}
};
