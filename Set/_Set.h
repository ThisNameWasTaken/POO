#pragma once

template <class T>
class Set {
public:
	using iterator = T*;
	iterator begin() const { return this->elements; };
	iterator end() const { return (this->elements + (this->length)); };

	/**
	 * @param arr - the array on which the Set is based
	 * @param length - the length of the array
	 */
	Set(const T* arr = nullptr, const int length = 0);
	~Set();

	/**
	 * @returns the number of elements inside the Set
	 */
	inline int getLength() const { return this->length; }

	/**
	 * @param element - the element to look for
	 * @returns a boolean asserting whether the given element is found in the Set or not
	 */
	bool has(const T& element) const;
private:
	T* elements;
	int length;
};

