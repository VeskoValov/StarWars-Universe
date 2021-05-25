#include "CommandList.h"

CommandList::CommandList()
{
	this->command = String::String();
	this->planets = Vector<Planet>::Vector();
	this->working = true;
	this->commandList = Vector<String>::Vector();
	this->commandList.push_back("add_planet"); // 0
	this->commandList.push_back("create_jedi"); // 1
	this->commandList.push_back("remove_jedi"); // 2
	this->commandList.push_back("promote_jedi"); // 3
	this->commandList.push_back("demote_jedi"); // 4
	this->commandList.push_back("get_strongest_jedi"); // 5
	this->commandList.push_back("get_youngest_jedi"); // 6
	this->commandList.push_back("get_most_used_saber_color"); // 7
	this->commandList.push_back("get_most_used_saber_color_grand"); // 8
	this->commandList.push_back("print_planet"); // 9
	this->commandList.push_back("print_jedi"); // 10
	this->commandList.push_back("help"); // 11
}

void CommandList::run()
{
	std::cout << "Welcome!" << std::endl;
	while (this->working) {
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (!(this->commandList.isElementPresent(command))) {
			std::cout << "There is no command with that name! Try help for a list of commands." << std::endl;
			continue;
		}
		size_t commandNum = this->commandList.findElementIndex(command);
		switch (commandNum)
		{
		case 0: add_planet(); break;
		case 1: create_jedi(); break;
		case 2: remove_jedi(); break;
		case 3: promote_jedi(); break;
		case 4: demote_jedi(); break;
		case 5: get_strongest_jedi(); break;
		case 6: get_youngest_jedi(); break;
		case 7: get_most_used_saber_color(); break;
		case 8: get_most_used_saber_color_grand(); break;
		case 9: print_planet(); break;
		case 10: print_jedi(); break;
		//case 11: help(); break;
		}
	}
}

void CommandList::add_planet(const String& name)
{
	Planet newPlanet(name);
	planets.push_back(newPlanet);
	std::cout << "You have successfully added a planet!" << std::endl;
}

void CommandList::add_planet()
{
	std::cout << "Enter the planet's name: ";
	String name;
	std::cin >> name;
	Planet newPlanet(name);
	planets.push_back(newPlanet);
	std::cout << "You have successfully added a new planet!" << std::endl;
}

void CommandList::create_jedi(const String& pname, const String& jname, const String& rank, const size_t age, const String& saberColor, const double strength)
{
	Jedi newJedi(jname, rank, age, saberColor, strength);
	for (size_t i = 0; i < this->planets.getSize(); ++i) {
		if (this->planets[i].getJedis().isElementPresent(newJedi)) {
			std::cout << "There is already a jedi with the same name!" << std::endl;
			return;
		}
	}
	for (size_t i = 0; i < this->planets.getSize(); ++i)
	{
		if (this->planets[i].getName() == pname) {
			this->planets[i].addJedi(newJedi);
			std::cout << "You have successfully added a new Jedi!" << std::endl;
			return;
		}
	}
	std::cout << "There is no planet with such a name!" << std::endl;
}

void CommandList::create_jedi()
{
	String pname, jname, rank, saberColor;
	size_t age;
	double strength;
	std::cout << "Enter the planet's name: ";
	std::cin >> pname;
	std::cout << "Enter the jedi's name: ";
	std::cin >> jname;
	std::cout << "Enter the jedi's rank: ";
	std::cin >> rank;
	std::cout << "Enter the jedi's lightsaber color: ";
	std::cin >> saberColor;
	std::cout << "Enter the jedi's age: ";
	std::cin >> age;
	std::cout << "Enter the jedi's strength: ";
	std::cin >> strength;
	std::cin.ignore();
	Jedi newJedi(jname, rank, age, saberColor, strength);
	for (size_t i = 0; i < this->planets.getSize(); ++i) {
		if (this->planets[i].getJedis().isElementPresent(newJedi)) {
			std::cout << "There is already a jedi with the same name!" << std::endl;
			return;
		}
	}
	for (size_t i = 0; i < this->planets.getSize(); ++i)
	{
		if (this->planets[i].getName() == pname) {
			this->planets[i].addJedi(newJedi);
			std::cout << "You have successfully added a new Jedi!" << std::endl;
			return;
		}
	}
	std::cout << "There is no planet with such a name!" << std::endl;
}

void CommandList::remove_jedi(const String& jname, const String& pname)
{
	Jedi newJedi(jname);
	for (size_t i = 0; i < this->planets.getSize(); ++i)
	{
		if (this->planets[i].getName() == pname) {
			this->planets[i].removeJedi(newJedi);
		}
	}
	std::cout << "There is no planet with such a name!" << std::endl;
}

void CommandList::remove_jedi()
{
	String jname, pname;
	std::cout << "Enter the jedi's name: ";
	std::cin >> jname;
	std::cout << "Enter the planet's name: ";
	std::cin >> pname;
	Jedi newJedi(jname);
	for (size_t i = 0; i < this->planets.getSize(); ++i)
	{
		if (this->planets[i].getName() == pname) {
				this->planets[i].removeJedi(newJedi);
				return;
		}
	}
	std::cout << "There is no planet with such a name!" << std::endl;
}

void CommandList::promote_jedi(const String& jname, const double& multiplier)
{
	Jedi newJedi(jname);
	for (size_t i = 0; i < this->planets.getSize(); ++i) {
		if (this->planets[i].getJedis().isElementPresent(newJedi)) {
			this->planets[i].promoteJedi(newJedi, multiplier);
			return;
		}
	}
	std::cout << "There is no Jedi with such a name!" << std::endl;
}

void CommandList::promote_jedi()
{
	String jname;
	double multiplier;
	std::cout << "Enter the jedi's name: ";
	std::cin >> jname;
	std::cout << "Enter the multiplier: ";
	std::cin >> multiplier;
	std::cin.ignore();
	Jedi newJedi(jname);
	for (size_t i = 0; i < this->planets.getSize(); ++i) {
		if (this->planets[i].getJedis().isElementPresent(newJedi)) {
			this->planets[i].promoteJedi(newJedi, multiplier);
			return;
		}
	}
	std::cout << "There is no Jedi with such a name!" << std::endl;
}

void CommandList::demote_jedi(const String& jname, const double& multiplier)
{
	Jedi newJedi(jname);
	for (size_t i = 0; i < this->planets.getSize(); ++i) {
		if (this->planets[i].getJedis().isElementPresent(newJedi)) {
			this->planets[i].demoteJedi(newJedi, multiplier);
			return;
		}
	}
	std::cout << "There is no Jedi with such a name!" << std::endl;
}

void CommandList::demote_jedi()
{
	String jname;
	double multiplier;
	std::cout << "Enter the jedi's name:";
	std::cin >> jname;
	std::cout << "Enter the multiplier: ";
	std::cin >> multiplier;
	std::cin.ignore();
	Jedi newJedi(jname);
	for (size_t i = 0; i < this->planets.getSize(); ++i) {
		if (this->planets[i].getJedis().isElementPresent(newJedi)) {
			this->planets[i].demoteJedi(newJedi, multiplier);
			return;
		}
	}
	std::cout << "There is no Jedi with such a name!" << std::endl;
}

void CommandList::get_strongest_jedi(const String& pname)
{
	double maxStrength = 0;
	for (size_t i = 0; i < this->planets.getSize(); ++i)
	{
		Jedi newJedi;
		if (this->planets[i].getName() == pname) {
			maxStrength = this->planets[i].getJedis()[0].getPower();
			newJedi = this->planets[i].getJedis()[0];
			for (size_t j = 1; j < this->planets[i].getJedis().getSize(); ++j)
			{
				if (this->planets[i].getJedis()[j].getPower() > maxStrength) {
					maxStrength = this->planets[i].getJedis()[j].getPower();
					newJedi = this->planets[i].getJedis()[j];
				}
			}
			std::cout << newJedi;
			return;
		}
	}
	std::cout << "There is no planet with that name!" << std::endl;
}

void CommandList::get_strongest_jedi()
{
	String pname;
	std::cout << "Enter the planet's name: ";
	std::cin >> pname;
	double maxStrength = 0;
	for (size_t i = 0; i < this->planets.getSize(); ++i)
	{
		Jedi newJedi;
		if (this->planets[i].getName() == pname) {
			maxStrength = this->planets[i].getJedis()[0].getPower();
			newJedi = this->planets[i].getJedis()[0];
			for (size_t j = 0; j < this->planets[i].getJedis().getSize(); ++j)
			{
				if (this->planets[i].getJedis()[j].getPower() > maxStrength) {
					maxStrength = this->planets[i].getJedis()[j].getPower();
					newJedi = this->planets[i].getJedis()[j];
				}
			}
			std::cout << newJedi << std::endl;
			return;
		}
	}
	std::cout << "There is no planet with that name!" << std::endl;
}

void CommandList::get_youngest_jedi(const String& pname, const String& rank)
{
	Planet newPlanet(pname);
	if (this->planets.isElementPresent(pname)) {
		Vector<Jedi> youngJedis;
		Jedi newJedi;
		size_t age = INT_MAX;
		bool thereIsJedi = false;
		size_t planetIndex = this->planets.findElementIndex(pname);
		for (size_t i = 0; i < this->planets[planetIndex].getJedis().getSize(); ++i)
		{
			youngJedis = this->planets[planetIndex].getJedis();
			youngJedis.sort(byName);
			this->planets[planetIndex].setJedis(youngJedis);
			if (this->planets[planetIndex].getJedis()[i].getRank() == rank && this->planets[planetIndex].getJedis()[i].getAge() < age) {
				newJedi = this->planets[planetIndex].getJedis()[i];
				age = this->planets[planetIndex].getJedis()[i].getAge();
				thereIsJedi = true;
			}
			/*else if (this->Planets[planetIndex].getJedis()[i].getRank() == rank && this->Planets[planetIndex].getJedis()[i].getAge() == age) {
				youngJedis.push_back(this->Planets[planetIndex].getJedis()[i]);
				youngJedis.push_back(newJedi);
				thereIsJedi = true;
			}
		}
		if (youngJedis.isElementPresent(newJedi)) {
			size_t asciiCode = 'Z';
			for (size_t i = 0; i < youngJedis.getSize(); ++i)
			{
				size_t charIndex = 0;
				if (asciiCode < youngJedis[i].getName()[charIndex]) {
					asciiCode = youngJedis[i].getName()[charIndex];
					newJedi = youngJedis[i];
				}
				if (asciiCode == youngJedis[i].getName()[charIndex]) {

					for (charIndex = 1; charIndex < youngJedis[i].getName().getSize(); ++charIndex)
					{
						asciiCode = newJedi.getName()[charIndex];
						if (asciiCode < youngJedis[i].getName()[charIndex]) {
							asciiCode = youngJedis[i].getName()[0];
							newJedi = youngJedis[i];
						}
					}
				}
			}*/
		}
		if (!thereIsJedi) {
			std::cout << "There is no Jedi with that rank!" << std::endl;
			return;
		}
		std::cout << newJedi << std::endl;
		return;
	}
	std::cout << "There is no planet with that name!" << std::endl;
}

void CommandList::get_youngest_jedi()
{
	String pname, rank;
	std::cout << "Enter the planet's name: ";
	std::cin >> pname;
	std::cout << "Enter the jedi's rank: ";
	std::cin >> rank;
	Planet newPlanet(pname);
	if (this->planets.isElementPresent(pname)) {
		Vector<Jedi> youngJedis;
		Jedi newJedi;
		size_t age = INT_MAX;
		bool thereIsJedi = false;
		size_t planetIndex = this->planets.findElementIndex(pname);
		for (size_t i = 0; i < this->planets[planetIndex].getJedis().getSize(); ++i)
		{
			youngJedis = this->planets[planetIndex].getJedis();
			youngJedis.sort(byName);
			this->planets[planetIndex].setJedis(youngJedis);
			if (this->planets[planetIndex].getJedis()[i].getRank() == rank && this->planets[planetIndex].getJedis()[i].getAge() < age) {
				newJedi = this->planets[planetIndex].getJedis()[i];
				age = this->planets[planetIndex].getJedis()[i].getAge();
				thereIsJedi = true;
			}
		}
		if (!thereIsJedi) {
			std::cout << "There is no Jedi with that rank!" << std::endl;
			return;
		}
		std::cout << newJedi << std::endl;
		return;
	}
	std::cout << "There is no planet with that name!" << std::endl;
}

void CommandList::get_most_used_saber_color(const String& pname, const String& rank)
{
	if (this->planets.isElementPresent(pname)) {
		size_t PlanetIndex = this->planets.findElementIndex(pname);
		Vector<String> colors;
		Vector<Jedi> correctRank;
		for (size_t i = 0; i < this->planets[PlanetIndex].getJedis().getSize(); ++i)
		{
			if (this->planets[PlanetIndex].getJedis()[i].getRank() == rank) {
				correctRank.push_back(this->planets[PlanetIndex].getJedis()[i]);
				if (!(colors.isElementPresent(this->planets[PlanetIndex].getJedis()[i].getColor()))) {
					colors.push_back(this->planets[PlanetIndex].getJedis()[i].getColor());
				}
			}
		}
		if (correctRank.getSize() == 0) {
			std::cout << "There is no Jedi with that rank!" << std::endl;
			return;
		}
		size_t maxColorCount = 0;
		String currentColor;
		size_t currentCount = 0;
		for (size_t i = 0; i < colors.getSize(); ++i)
		{
			currentCount = 0;
			for (size_t j = 0; j < correctRank.getSize(); ++j)
			{
				if (colors[i] == correctRank[j].getColor()) {
					++currentCount;
				}
			}
			if (maxColorCount < currentCount) {
				maxColorCount = currentCount;
				currentColor = colors[i];
			}
		}
		std::cout << currentColor << std::endl;
		return;
	}
	std::cout << "There is no planet with that name!" << std::endl;
}

void CommandList::get_most_used_saber_color()
{
	String pname, rank;
	std::cout << "Enter the planet's name: ";
	std::cin >> pname;
	std::cout << "Enter the jedi's rank: ";
	std::cin >> rank;
	if (this->planets.isElementPresent(pname)) {
		size_t PlanetIndex = this->planets.findElementIndex(pname);
		Vector<String> colors;
		Vector<Jedi> correctRank;
		for (size_t i = 0; i < this->planets[PlanetIndex].getJedis().getSize(); ++i)
		{
			if (this->planets[PlanetIndex].getJedis()[i].getRank() == rank) {
				correctRank.push_back(this->planets[PlanetIndex].getJedis()[i]);
				if (!(colors.isElementPresent(this->planets[PlanetIndex].getJedis()[i].getColor()))) {
					colors.push_back(this->planets[PlanetIndex].getJedis()[i].getColor());
				}
			}
		}
		if (correctRank.getSize() == 0) {
			std::cout << "There is no Jedi with that rank!" << std::endl;
			return;
		}
		size_t maxColorCount = 0;
		String currentColor;
		size_t currentCount = 0;
		for (size_t i = 0; i < colors.getSize(); ++i)
		{
			currentCount = 0;
			for (size_t j = 0; j < correctRank.getSize(); ++j)
			{
				if (colors[i] == correctRank[j].getColor()) {
					++currentCount;
				}
			}
			if (maxColorCount < currentCount) {
				maxColorCount = currentCount;
				currentColor = colors[i];
			}
		}
		std::cout << currentColor << std::endl;
		return;
	}
	std::cout << "There is no planet with that name!" << std::endl;
}

void CommandList::get_most_used_saber_color_grand()
{
	String pname, rank;
	std::cout << "Enter the planet's name: ";
	std::cin >> pname;
	rank = "GRANDMASTER";
	if (this->planets.isElementPresent(pname)) {
		size_t PlanetIndex = this->planets.findElementIndex(pname);
		Vector<String> colors;
		Vector<Jedi> correctRank;
		for (size_t i = 0; i < this->planets[PlanetIndex].getJedis().getSize(); ++i)
		{
			if (this->planets[PlanetIndex].getJedis()[i].getRank() == rank) {
				correctRank.push_back(this->planets[PlanetIndex].getJedis()[i]);
				if (!(colors.isElementPresent(this->planets[PlanetIndex].getJedis()[i].getColor()))) {
					colors.push_back(this->planets[PlanetIndex].getJedis()[i].getColor());
				}
			}
		}
		if (correctRank.getSize() == 0) {
			std::cout << "There is no Jedi with GRANDMASTER rank!" << std::endl;
			return;
		}
		size_t maxColorCount = 0;
		String currentColor;
		size_t currentCount = 0;
		for (size_t i = 0; i < colors.getSize(); ++i)
		{
			currentCount = 0;
			for (size_t j = 0; j < correctRank.getSize(); ++j)
			{
				if (colors[i] == correctRank[j].getColor()) {
					++currentCount;
				}
			}
			if (maxColorCount < currentCount) {
				maxColorCount = currentCount;
				currentColor = colors[i];
			}
		}
		std::cout << currentColor << std::endl;
		return;
	}
	std::cout << "There is no planet with that name!" << std::endl;
}

void CommandList::print_planet(const String& pname)
{
	if (this->planets.isElementPresent(pname)) {
		size_t planetIndex = this->planets.findElementIndex(pname);
		Vector<Jedi> sortedJedis = this->planets[planetIndex].getJedis();
		sortedJedis.sort(byNameAndRank);
		this->planets[planetIndex].setJedis(sortedJedis);
		this->planets[planetIndex].print();
	}
	else
	{
		std::cout << "There is no planet with that name!" << std::endl;
	}
}


void CommandList::print_planet()
{
	String pname;
	std::cout << "Enter the planet's name: ";
	std::cin >> pname;
	if (this->planets.isElementPresent(pname)) {
		size_t planetIndex = this->planets.findElementIndex(pname);
		Vector<Jedi> sortedJedis = this->planets[planetIndex].getJedis();
		sortedJedis.sort(byNameAndRank);
		this->planets[planetIndex].setJedis(sortedJedis);
		this->planets[planetIndex].print();
	}
	else
	{
		std::cout << "There is no planet with that name!" << std::endl;
	}
}

void CommandList::print_jedi(const String& jname)
{
	for (size_t i = 0; i < this->planets.getSize(); i++)
	{
		if (this->planets[i].getJedis().isElementPresent(jname)) {
			std::cout << "Planet: " << this->planets[i] << std::endl;
			std::cout << this->planets[i].getJedis()[this->planets[i].getJedis().findElementIndex(jname)] << std::endl;
			return;
		}
	}
	std::cout << "There is no jedi with that name!" << std::endl;
}

void CommandList::print_jedi()
{
	String jname;
	std::cout << "Enter the jedi's name: ";
	std::cin >> jname;
	for (size_t i = 0; i < this->planets.getSize(); i++)
	{
		if (this->planets[i].getJedis().isElementPresent(jname)) {
			std::cout << "Planet: " << this->planets[i] << std::endl;
			std::cout << this->planets[i].getJedis()[this->planets[i].getJedis().findElementIndex(jname)] << std::endl;
			return;
		}
	}
	std::cout << "There is no jedi with that name!" << std::endl;
}

Vector<Planet>& CommandList::getPlanets()
{
	return this->planets;
}
