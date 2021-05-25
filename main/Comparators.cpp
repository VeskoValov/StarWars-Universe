#include "Comparators.h"

bool byString(const String& s1, const String& s2) {
	return s1 > s2;
}

bool byName(const Jedi& s1, const Jedi& s2) {
	return s1.getName() > s2.getName();
}