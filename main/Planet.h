#pragma once
#include "Jedi.h"
class Planet
{
public:
	Planet();
	Planet(const String& name);
	String getName() const;
	const Vector<Jedi>& getJedis() const;

	void addJedi(const Jedi& newJedi);
	void removeJedi(const Jedi& oldJedi);
	void setJedis(const Vector<Jedi> other);
	void setName(const String& newName);
	void promoteJedi(const Jedi& newJedi, const double& multiplier);
	void demoteJedi(const Jedi& newJedi, const double& multiplier);
	void print() const;
	bool operator==(const Planet& other);

	void saveToFile(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& out, const Planet& other);
private:
	String name;
	Vector<Jedi> jedis;
};

