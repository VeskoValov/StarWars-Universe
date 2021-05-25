#pragma once
#include "String.h"
#include "Vector.cpp"
class Jedi
{
public:
	Jedi();
	Jedi(const String& name, const String& currentRank, const size_t& age, const String& saberColor, const double& power);
	Jedi(const String& name);
	void promote(const double& multiplier);
	void demote(const double& multiplier);

	Jedi& operator=(const Jedi& other);

	bool operator==(const Jedi& other);

	friend std::ostream& operator<<(std::ostream& out, const Jedi& other);

	String getName() const;
	String getRank() const;
	size_t getRankNumber() const;
	size_t getAge() const;
	String getColor() const;
	double getPower() const;
	Vector<String>& getRanks();
private:
	String name; 
	Vector<String> ranks;
	String currentRank;
	size_t age;
	String saberColor;
	double power;
};

