#pragma once
#include "Vector.h"

template<typename T>
Vector<T>::Vector()
{
	this->capacity = 8;
	this->size = 0;
	this->elements = new T[this->capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		this->erase();
		this->copy(other);
	}
	return *this;
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->elements = new T[other.capacity];
	this->capacity = other.capacity;
	this->size = other.size;
	for (size_t i = 0; i < this->size; i++) {
		this->elements[i] = other.elements[i];
	}
}

template <typename T>
void Vector<T>::erase()
{
	delete[] this->elements;
}

template <typename T>
Vector<T>::~Vector()
{
	this->erase();
}

template <typename T>
void Vector<T>::resize()
{
	this->capacity *= 2;
	T* newElements = new T[this->capacity];
	for (size_t i = 0; i < this->size; ++i) {
		newElements[i] = this->elements[i];

	}
	this->erase();
	this->elements = newElements;
}

template <typename T>
void Vector<T>::push_back(T element)
{
	++this->size;
	if (this->size >= this->capacity) {
		this->resize();
	}
	this->elements[size - 1] = element;
}

template <typename T>
void Vector<T>::pop_back()
{
	if (this->size == 0) {
		return;
	}
	this->size--;
}

template <typename T>
bool Vector<T>::isEmpty() const
{
	return this->size == 0;
}

template <typename T>
void Vector<T>::print() const
{
	for (size_t i = 0; i < this->size; ++i)
	{
		std::cout << this->elements[i] << std::endl;
	}
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
	return this->elements[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const
{
	return this->elements[index];
}

template<typename T>
size_t Vector<T>::getSize() const
{
	return this->size;
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
bool Vector<T>::isElementPresent(const T& element) const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->elements[i] == element) {
			return true;
		}
	}
	return false;
}

template<typename T>
const size_t Vector<T>::findElementIndex(const T& element) const
{
	if (isElementPresent(element)) {
		for (size_t i = 0; i < this->size; i++)
		{
			if (this->elements[i] == element) {
				return i;
			}
		}
	}
	return 0;
}

template<typename T>
void Vector<T>::pop_by_index(const size_t& index)
{
	if (index >= size) {
		return;
	}
	if (index == this->size - 1) {
		this->pop_back();
		return;
	}
	T* temp = new T[this->size - 1];
	for (size_t i = 0; i < index; ++i)
	{
		temp[i] = this->elements[i];
	}
	for (size_t i = index + 1; i < size; ++i)
	{
		temp[i - 1] = this->elements[i];
	}
	--this->size;
	delete[] elements;
	this->elements = temp;
}

template<typename T>
void Vector<T>::sort(bool(comparator)(const T& element1, const T& element2))
{
	for (int i = 0; i < this->size - 1; ++i)
	{
		for (int j = 0; j < this->size - i - 1; ++j)
		{
			if (comparator(elements[j], elements[j + 1]))
			{
				std::swap(elements[j], elements[j + 1]);
			}
		}
	}
}
