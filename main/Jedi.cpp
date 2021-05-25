#include "Jedi.h"

Jedi::Jedi()
{
	this->name = "Unnamed";
	this->ranks.push_back("YOUNGLING");
	this->ranks.push_back("INITIATE");
	this->ranks.push_back("PADAWAN");
	this->ranks.push_back("KNIGHT-ASPIRANT");
	this->ranks.push_back("KNIGHT");
	this->ranks.push_back("MASTER");
	this->ranks.push_back("BATTLE_MASTER");
	this->ranks.push_back("GRAND_MASTER");
	this->currentRank = "YOUNGLING";
	this->age = 18;
	this->saberColor = "blue";
	this->power = 0;
}

Jedi::Jedi(const String& name, const String& currentRank, const size_t& age, const String& saberColor, const double& power) : Jedi()
{
	this->name = name;
	this->currentRank = currentRank;
	this->age = age;
	this->saberColor = saberColor;
	this->power = power;
}

Jedi::Jedi(const String& name) : Jedi()
{
	this->name = name;
}

void Jedi::promote(const double& multiplier)
{
	if (!(this->currentRank == "GRAND_MASTER")) {
		this->currentRank = this->ranks[this->ranks.findElementIndex(this->currentRank) + 1];
		std::cout << "The promotion is successful! " << std::endl;
	}
	else {
		std::cout << "The Jedi is currently at max rank! " << std::endl;
	}
	if (multiplier <= 0) {
		std::cout << "The multiplier is not a positive number, therefore it will not be taken into account! " << std::endl;
	}
	else {
		this->power += (multiplier * power);
	}
}

void Jedi::demote(const double& multiplier)
{
	if (!(this->currentRank == "YOUNGLING")) {
		this->currentRank = this->ranks[this->ranks.findElementIndex(this->currentRank) - 1];
		std::cout << "The demotion is successful! " << std::endl;
	}
	else {
		std::cout << "The Jedi is currently at the minimum rank! " << std::endl;
	}
	if (multiplier <= 0) {
		std::cout << "The multiplier is not a positive number, therefore it will not be taken into account! " << std::endl;
	}
	else {
		this->power -= (multiplier * power);
	}
}

Jedi& Jedi::operator=(const Jedi& other)
{
	this->name = other.name;
	this->currentRank = other.currentRank;
	this->age = other.age;
	this->saberColor = other.saberColor;
	this->power = other.power;
	return *this;
}

bool Jedi::operator==(const Jedi& other)
{
	return this->name == other.name;
}

String Jedi::getName() const
{
	return this->name;
}

String Jedi::getRank() const
{
	return this->currentRank;
}

size_t Jedi::getRankNumber() const
{
	return this->ranks.findElementIndex(this->currentRank);
}

size_t Jedi::getAge() const
{
	return this->age;
}

String Jedi::getColor() const
{
	return this->saberColor;
}

double Jedi::getPower() const
{
	return this->power;
}

Vector<String>& Jedi::getRanks()
{
	return this->ranks;
}

std::ostream& operator<<(std::ostream& out, const Jedi& other)
{
	out << other.name << " | Rank: " << other.currentRank << " | Age: " << other.age << " | Lightsaber color: " << other.saberColor << " | Strength: " << other.power;
	return out;
}
