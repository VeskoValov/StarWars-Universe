#pragma once
#include<iostream>
template<typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);
	~Vector();

	void push_back(T element);
	void pop_back();

	bool isEmpty()const;

	void print()const;
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	Vector<T> operator+(const Vector<T>&);
	Vector<T>& operator+=(const Vector<T>&);

	size_t getSize() const;
	size_t getCapacity() const;

	bool isElementPresent(const T& element) const;
	const size_t findElementIndex(const T& element) const;

	void pop_by_index(const size_t& index);
	void clear();
	void sort(bool(comparator)(const T& element1, const T& element2));

private:
	T* elements;
	size_t size;
	size_t capacity;

	void copy(const Vector<T>& other);
	void erase();

	void resize();
};

