#pragma once
#include "String.h"
class Repository
{
public:
	void setFilepath(const String&);
	String& getFilepath() const;

	void add(Repository& rep);
	void update(Repository* rep);
	void deleteRep(Repository* rep);
private:
	String filepath;
};

