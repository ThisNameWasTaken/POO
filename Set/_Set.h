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
	Set(const Set<T>& set);
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

	/** 
	 * @param index
	 * @returns the element found at the given index or 'NULL' if the Set is empty
	 *
	 * @description If the index exceeds Set's length it will keep counting from the first element
	 * If the index has a negative value then it will start counting, in reverse, from the last element
	 */
	const T& operator[](int index) const;

	/**
	 * @param set - the Set which is assigned to the current instance
	 * @returns - set
	 */
	Set<T>& operator=(const Set<T>& set);

	/**
	 * Does the union between the given Set and the current instance
	 * @param set
	 * @returns a new set
	 */
	Set<T> operator+(const Set<T>& set);

	/**
	 * Does the union between the given Set and the current instance
	 * @param set
	 * @returns the current instace
	 */
	Set<T>& operator+=(const Set<T>& set);

	/**
	 * @param set - the Set to compare to
	 * @returns a boolean asserting whether the current instance has less elements than the given Set or not
	 */
	inline bool operator<(const Set<T>& set) const { return this->length < set.getLength(); }

	/**
	 * @param set - the Set to compare to
	 * @returns a boolean asserting whether the current instance has more+ elements than the given Set or not
	 */
	inline bool operator>(const Set<T>& set) const { return this->length > set.getLength(); }

private:
	T* elements;
	int length; // number of elements
	int size; // elements' size 
};

