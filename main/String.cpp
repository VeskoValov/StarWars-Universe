#include "String.h"

String::String()
{
	this->capacity = 31;
	this->size = 0;
	this->data = new char[this->capacity];
	for (size_t i = 0; i < this->capacity; ++i)
	{
		this->data[i] = '\0';
	}
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

String::String(size_t size) : String()
{
	this->setSize(size);
}

String::String(const char* data) : String()
{
	this->size = strlen(data);
	this->checkForResize();
	for (size_t i = 0; i < this->size; ++i)
	{
		this->data[i] = data[i];
	}
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

bool String::operator==(const String& newString)
{
	for (size_t i = 0; i < this->size; ++i)
	{
		if (data[i] != newString.data[i]) {
			return false;
		}
	}
	return true;
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
	this->checkForResize();
	this->data = new char[other.capacity];
	for (size_t i = 0; i < this->size; ++i)
	{
		this->data[i] = other.data[i];
	}
}

void String::erase()
{
	delete[] this->data;
}

void String::resize()
{
	this->capacity *= 3;
	char* newData = new char[this->capacity];
	for (size_t i = 0; i < this->capacity; ++i)
	{
		newData[i] = '\0';
	}
	for (size_t i = 0; i < this->size; ++i)
	{
		newData[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newData;
}

void String::checkForResize()
{
	if (this->size >= this->capacity) {
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
