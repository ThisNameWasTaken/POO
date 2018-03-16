#define REALLOC_SIZE 16

#include "_Set.h"
#include <type_traits>

template <class T>
Set<T>::Set(const T* arr = nullptr, const int length = 0) {
	this->length = 0;
	this->size = 0;
	
	for (int i = 0; i < length; i++) {
		this->add(arr[i]);
	}
}

template <class T>
Set<T>::~Set() {
	this->length = 0;
	this->size = 0;
	delete[] this->elements;
}

template<class T>
bool Set<T>::has(const T& element) const {
	for (int i = 0; i < this->length; i++) {
		if (this->elements[i] == element) {
			return true;
		}
	}
	return false;
}

template<class T>
void Set<T>::add(const T& element) {
	if (this->has(element)) {
		return;
	}

	// Check if there is need for more memory
	if (this->length >= this->size) {
		this->size += REALLOC_SIZE;
		T* temp = new T[this->size];
		for (int i = 0; i < this->length; i++) {
			temp[i] = elements[i];
		}

		delete[] this->elements;
		this->elements = temp;
	}
	
	// If it is a nummber then keep the order
	if (std::is_arithmetic<T>::value) {
		// Use a binary search to determine where to insert the new element
		int leftIndex = 0, rightIndex = this->length - 1;

		while (leftIndex <= rightIndex) {
			int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

			if (this->elements[middleIndex] < element) {
				leftIndex = middleIndex + 1;
			} else {
				rightIndex = middleIndex - 1;
			}
		}

		for (int i = length; i > leftIndex; i--) {
			this->elements[i] = this->elements[i - 1];
		}
		this->elements[leftIndex] = element;
	} 
	// Otherwise add it at the end
	else { 
		this->elements[this->length] = element;
	}

	this->length++;
}
