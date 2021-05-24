#pragma once
#include "Jedi.h"
class Planet
{
public:
	Planet();
	Planet(const String& name);
	String getName() const;
	Vector<Jedi>& getJedis();

	void setJedis(const Vector<Jedi> other);
	void print() const;
	bool operator==(const Planet& other);

	friend std::ostream& operator<<(std::ostream& out, const Planet& other);
private:
	String name;
	Vector<Jedi> Jedis;
};

