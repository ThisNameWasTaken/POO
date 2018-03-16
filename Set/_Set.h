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

	/**
	 * Adds a new element to the Set
	 * @param element - the element to add
	 */
	void add(const T& element);

	/**
	 * Removes all the elements from the Set
	 */
	void clear();

	/**
	 * @param element - the element to search for
	 * @returns the index of the given element if it is found inside the set or -1 otherwise
	 */
	int indexOf(const T& element) const;

	/**
	* Removes an element from the Set
	* @param element - the element to remove
	*/
	void remove(const T& element);

private:
	T* elements;
	int length; // number of elements
	int size; // elements' size 
};

