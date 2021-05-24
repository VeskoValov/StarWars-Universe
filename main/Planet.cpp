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

const Vector<Jedi>& Planet::getJedis() const
{
	return this->Jedis;
}

void Planet::addJedi(const Jedi& newJedi)
{
	this->Jedis.push_back(newJedi);
}

void Planet::removeJedi(const Jedi& oldJedi)
{
	if (this->Jedis.isElementPresent(oldJedi)) {
		this->Jedis.pop_by_index(this->Jedis.findElementIndex(oldJedi));
		std::cout << "The Jedi was successfully removed!" << std::endl;
		return;
	}
	else {
		std::cout << "There is no Jedi with such name on this planet!" << std::endl;
		return;
	}

}

void Planet::setJedis(const Vector<Jedi> other)
{
	this->Jedis = other;
}

void Planet::promoteJedi(const Jedi& newJedi, const double& multiplier)
{
	this->Jedis[this->Jedis.findElementIndex(newJedi)].promote(multiplier);
}

void Planet::demoteJedi(const Jedi& newJedi, const double& multiplier)
{
	this->Jedis[this->Jedis.findElementIndex(newJedi)].demote(multiplier);
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