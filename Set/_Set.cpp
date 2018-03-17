#define REALLOC_SIZE 16

#include "_Set.h"
#include <type_traits>

template <class T>
Set<T>::Set(const T* arr = nullptr, const int length = 0) {
	this->length = 0;
	this->size = 0;
	this->elements = nullptr;
	
	for (int i = 0; i < length; i++) {
		this->add(arr[i]);
	}
}

template<class T>
Set<T>::Set(const Set<T>& set) {
	this->length = 0;
	this->size = 0;
	this->elements = nullptr;

	for (const T& element : set) {
		this->add(element);
	}
}

template <class T>
Set<T>::~Set() {
	this->clear();
}

template<class T>
bool Set<T>::has(const T& element) const {
	return this->indexOf(element) == -1 ? false : true;
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

		if (this->elements) {
			delete[] this->elements;
		}
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

template<class T>
void Set<T>::clear() {
	if (this->elements) {
		delete[] this->elements;
	}
	this->length = 0;
	this->size = 0;
	this->elements = nullptr;
}

template<class T>
int Set<T>::indexOf(const T& element) const {
	// If it is a nummber then do a binary search
	if (std::is_arithmetic<T>::value) {
		int leftIndex = 0, rightIndex = this->length - 1;

		while (leftIndex <= rightIndex) {
			int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

			if (this->elements[middleIndex] == element) {
				return middleIndex;
			}

			if (this->elements[middleIndex] < element) {
				leftIndex = middleIndex + 1;
			} else {
				rightIndex = middleIndex - 1; rightIndex = middleIndex - 1;
			}	
		}

		return -1;
	}

	// Otherwise go through all the elements
	for (int i = 0; i < this->length; i++) {
		if (this->elements[i] == element) {
			return i;
		}
	}

	return -1;
}

template<class T>
void Set<T>::remove(const T& element) {
	// The index of the item which must be removed
	const int index = this->indexOf(element);
	if (index == -1) {
		return;
	}

	this->length--;

	for (int i = index; i < this->length; i++) {
		this->elements[i] = this->elements[i + 1];
	}

	// Check if some memory can be freed
	if (this->length <= this->size - REALLOC_SIZE) {
		this->size -= REALLOC_SIZE;

		T* temp = new T[this->size];
		for (int i = 0; i < this->length; i++) {
			temp[i] = elements[i];
		}
		if (this->elements) {
			delete[] this->elements;
		}
		this->elements = temp;
	}
}

template<class T>
const T& Set<T>::operator[](int index) const {
	if (!this->length) {
		return NULL;
	}

	while (index < 0) {
		index += this->length;
	}

	while (index >= this->length) {
		index -= this->length;
	}

	return this->elements[index];
}

template<class T>
Set<T>& Set<T>::operator=(const Set<T>& set) {
	if (this == &set) {
		return *this;
	}

	this->clear();

	for (const T& element : set) {
		this->add(element);
	}

	return *this;
}

template<class T>
Set<T> Set<T>::operator+(const Set<T>& set)
{
	Set<T> newSet = *this;

	for (const T& element : set) {
		newSet.add(element);
	}

	return newSet;
}

template<class T>
Set<T>& Set<T>::operator+=(const Set<T>& set) {
	*this = *this + set;
	return *this;
}
