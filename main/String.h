#pragma once
#include <iostream>
class String
{
public:
	String(); //���� �� �4
	String(const String&); //���� �� �4
	String& operator=(const String&); //���� �� �4
	String(size_t size); //������ ������� ������ �� ����
	String(const char* data); //������ ������� �������� �� ����
	~String(); //���� �� �4

	void setSize(const size_t& size);
	char* getData() const;
	size_t getSize() const;
	size_t getCapacity() const;

	bool operator==(const String&);
	char operator[](size_t index);
	char operator[](size_t index) const;

	void print() const;
	friend std::ostream& operator<<(std::ostream& out, const String& other);
	friend std::istream& operator>>(std::istream& in, String& other);
private:
	char* data;
	size_t size;
	size_t capacity;

	void copy(const String& other);
	void erase();

	void resize();
	void checkForResize();
};

