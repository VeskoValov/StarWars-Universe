#pragma once
#include "Jedi.h"

bool byString(const String& s1, const String& s2);

bool byName(const Jedi& s1, const Jedi& s2);

bool byRank(const Jedi& s1, const Jedi& s2);

bool byNameAndRank(const Jedi& s1, const Jedi& s2);