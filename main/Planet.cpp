#include "Planet.h"

Planet::Planet()
{
	this->name = "Unknown";
	this->Jedis = Vector<Jedi>::Vector();
}

Planet::Planet(const String& name) : Planet()
{
	this->name = name;
	//this->Jedis = Vector<Jedi>::Vector();
}

String Planet::getName() const
{
	return this->name;
}

Vector<Jedi>& Planet::getJedis()
{
	return this->Jedis;
}

void Planet::setJedis(const Vector<Jedi> other)
{
	this->Jedis = other;
}

void Planet::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	this->Jedis.print();
}

bool Planet::operator==(const Planet& other)
{
	return this->name == other.name;
}

std::ostream& operator<<(std::ostream& out, const Planet& other)
{
	out << other.name;
	return out;
}
