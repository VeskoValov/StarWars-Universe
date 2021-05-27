#include "String.h"

String::String()
{
	this->capacity = 32;
	this->size = 0;
	this->data = new char[this->capacity];
}

String::String(const String& other)
{
	this->copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		this->erase();
		this->copy(other);
	}
	return *this;
}

String& String::operator=(const char* newData)
{
	this->setData(newData);
	return *this;
}

String::String(size_t size) : String()
{
	this->setSize(size);
}

String::String(const char* data) : String()
{
	this->setData(data);
}

String::~String()
{
	this->erase();
}

void String::setSize(const size_t& size)
{
	this->size = size;
	this->checkForResize();
}

void String::setData(const char* other)
{
	this->size = strlen(other);
	if (this->size < capacity && this->data != nullptr) {
		delete[] this->data;
	}
	checkForResize();
	this->data = new char[this->capacity];
	strcpy_s(this->data, this->size + 1, other);
}

char* String::getData() const
{
	return this->data;
}

size_t String::getSize() const
{
	return this->size;
}

size_t String::getCapacity() const
{
	return this->capacity;
}

bool String::operator==(const String& newString) const
{
	if (this->size != newString.size) {
		return false;
	}
	return strcmp(this->data, newString.data) == 0;
	/*for (size_t i = 0; i < this->size; ++i)
	{
		if (data[i] != newString.data[i]) {
			return false;
		}
	}
	return true;*/
}

bool String::operator>(const String& other) const
{
	return strcmp(this->data, other.data) > 0;
}

bool String::operator<(const String& other) const
{
	return strcmp(this->data, other.data) < 0;
}

char String::operator[](size_t index)
{
	return this->data[index];
}

char String::operator[](size_t index) const
{
	return this->data[index];
}

void String::print() const
{
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << this->data[i];
	}
	std::cout << std::endl;
}

void String::copy(const String& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->data = new char[other.capacity];
	if (other.size > 0) {
		strcpy_s(this->data, other.size + 1, other.data);
	}
}

//void String::copy(const char* other)
//{
//	this->size = strlen(other);
//	checkForResize();
//	this->data = new char[this->capacity];
//	strcpy_s(this->data, this->size + 1, other);
//}

void String::erase()
{
	delete[] this->data;
}

void String::resize()
{
	this->capacity *= 3;
	char* newData = new char[this->capacity];
	strcpy_s(newData, this->capacity, this->data);
	if (this->data != nullptr) {
		delete[] this->data;
	}
	this->data = newData;
}

void String::checkForResize()
{
	while (this->size >= this->capacity) {
		this->resize();
	}
}

std::ostream& operator<<(std::ostream& out, const String& other)
{
	for (size_t i = 0; i < other.size; ++i)
	{
		out << other.data[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, String& other)
{
	in.getline(other.data, other.capacity);
	other.size = strlen(other.data);
	if (other.size == other.capacity - 1) {
		other.resize();
	}
	/*for (size_t i = 0; i < other.size; i++)
	{
		in >> other.data[i];
	}*/
	return in;
}
