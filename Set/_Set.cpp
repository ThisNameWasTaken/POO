#include "_Set.h"

template <class T>
Set<T>::Set(const T* arr = nullptr, const int length = 0) {
	this->length = length;
	this->elements = new T[length];
	for (int i = 0; i < this->length; i++) {
		this->elements[i] = arr[i];
	}
}

template <class T>
Set<T>::~Set() {
	this->length = 0;
	delete[] this->elements;
}