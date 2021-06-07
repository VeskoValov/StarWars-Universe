#include "CommandList.h"

CommandList::CommandList()
{
	this->filepath = "StarWars.universe";
	this->isOpenedAFile = false;
	this->commandList.push_back("open"); // 0
	this->commandList.push_back("help"); // 1
	this->commandList.push_back("exit"); // 2
	this->commandList.push_back("add_planet"); // 3
	this->commandList.push_back("create_jedi"); // 4
	this->commandList.push_back("remove_jedi"); // 5
	this->commandList.push_back("promote_jedi"); // 6
	this->commandList.push_back("demote_jedi"); // 7
	this->commandList.push_back("get_strongest_jedi"); // 8
	this->commandList.push_back("get_youngest_jedi"); // 9
	this->commandList.push_back("get_most_used_saber_color"); // 10
	this->commandList.push_back("get_most_used_saber_color_grand"); // 11
	this->commandList.push_back("print_planet"); // 12
	this->commandList.push_back("print_planets"); // 13
	this->commandList.push_back("print_jedi"); // 14
	this->commandList.push_back("close"); // 15
	this->commandList.push_back("save"); // 16
	this->commandList.push_back("saveas"); // 17
	this->commandList.push_back("print_contents"); // 18
}

void CommandList::run()
{
	std::cout << "Welcome!" << std::endl;
	while (true) {
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (!(this->commandList.isElementPresent(command))) {
			std::cout << "There is no command with that name! Try help for a list of commands." << std::endl;
			continue;
		}
		size_t commandNum = this->commandList.findElementIndex(command);
		if (commandNum < 3) {
			switch (commandNum)
			{
			case 0: open(); break;
			case 1: help(); break;
			case 2: exit(0); break;
			}
		}
		if (this->isOpenedAFile) {
			switch (commandNum)
			{
			case 3: add_planet(); break;
			case 4: create_jedi(); break;
			case 5: remove_jedi(); break;
			case 6: promote_jedi(); break;
			case 7: demote_jedi(); break;
			case 8: get_strongest_jedi(); break;
			case 9: get_youngest_jedi(); break;
			case 10: get_most_used_saber_color(); break;
			case 11: get_most_used_saber_color_grand(); break;
			case 12: print_planet(); break;
			case 13: print_planets(); break;
			case 14: print_jedi(); break;
			case 15: close(); break;
			case 16: save(); break;
			case 17: saveas(); break;
			case 18: print_contents(); break;
			}
		}
		else if (commandNum > 2) {
			std::cout << "Please open a file first!" << std::endl;
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
	Jedi newJedi;
	if (!(this->planets.isElementPresent(pname))) {
		std::cout << "There is no planet with that name in the database! Please try again." << std::endl;
		return;
	}
	if (!(newJedi.getRanks().isElementPresent(rank))) {
		std::cout << "The rank entered is not a valid one! Please try again." << std::endl;
		return;
	}
	newJedi = Jedi::Jedi(jname, rank, age, saberColor, strength);
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
	Jedi newJedi;
	size_t age;
	double strength;
	std::cout << "Enter the planet's name: ";
	std::cin >> pname;
	if(!(this->planets.isElementPresent(pname))) {
		std::cout << "There is no planet with that name in the database! Please try again." << std::endl;
		return;
	}
	std::cout << "Enter the jedi's name: ";
	std::cin >> jname;
	newJedi.setName(jname);
	for (size_t i = 0; i < this->planets.getSize(); ++i) {
		if (this->planets[i].getJedis().isElementPresent(newJedi)) {
			std::cout << "There is already a jedi with the same name! Please try again." << std::endl;
			return;
		}
	}
	std::cout << "Enter the jedi's rank: ";
	std::cin >> rank;
	if (!(newJedi.getRanks().isElementPresent(rank))) {
		std::cout << "The rank entered is not a valid one! Please try again." << std::endl;
		return;
	}
	std::cout << "Enter the jedi's lightsaber color: ";
	std::cin >> saberColor;
	std::cout << "Enter the jedi's age: ";
	std::cin >> age;
	if (!std::cin.good()) {
		std::cout << "Invalid input! Try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return;
	}
	std::cout << "Enter the jedi's strength: ";
	std::cin >> strength;
	if (!std::cin.good()) {
		std::cout << "Invalid input! Try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return;
	}
	std::cin.ignore();
	newJedi = Jedi::Jedi(jname, rank, age, saberColor, strength);
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
	if (!std::cin.good()) {
		std::cout << "Invalid input! Try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return;
	}
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
	if (!std::cin.good()) {
		std::cout << "Invalid input! Try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return;
	}
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

void CommandList::print_planets(const String& firstPName, const String& secondPName)
{
	Vector<Jedi> JedisFromBoth;
	if (this->planets.isElementPresent(firstPName)) {
		JedisFromBoth = this->planets[this->planets.findElementIndex(firstPName)].getJedis();
		if (firstPName == secondPName) {
			std::cout << "Both names are the same, therefore result shown is only from " << firstPName << std::endl;
			JedisFromBoth.sort(byName);
			JedisFromBoth.print();
		}
		else if (this->planets.isElementPresent(secondPName)) {
			JedisFromBoth += this->planets[this->planets.findElementIndex(secondPName)].getJedis();
			JedisFromBoth.sort(byName);
			std::cout << "The jedis from " << firstPName << " and " << secondPName << " in alphabetical order are: " << std::endl;
			JedisFromBoth.print();
		}
		else {
			std::cout << secondPName << " is not present in the database! Therefore only " << firstPName << " will be printed!" << std::endl;
			JedisFromBoth.sort(byName);
			JedisFromBoth.print();
		}
	}
	else if (this->planets.isElementPresent(secondPName)) {
		JedisFromBoth = this->planets[this->planets.findElementIndex(secondPName)].getJedis();
		std::cout << firstPName << " is not present in the database! Therefore only " << secondPName << " will be printed!" << std::endl;
		JedisFromBoth.sort(byName);
		JedisFromBoth.print();
	}
	else {
		std::cout << "There are no planets with such names in the database!" << std::endl;
	}
}

void CommandList::print_planets()
{
	String firstPName;
	String secondPName;
	std::cout << "Enter the first planet's name: ";
	std::cin >> firstPName;
	std::cout << "Enter the second planet's name: ";
	std::cin >> secondPName;
	Vector<Jedi> JedisFromBoth;
	if (this->planets.isElementPresent(firstPName)) {
		JedisFromBoth = this->planets[this->planets.findElementIndex(firstPName)].getJedis();
		if (firstPName == secondPName) {
			std::cout << "Both names are the same, therefore result shown is only from " << firstPName << std::endl;
			JedisFromBoth.sort(byName);
			JedisFromBoth.print();
		}
		else if (this->planets.isElementPresent(secondPName)) {
			JedisFromBoth += this->planets[this->planets.findElementIndex(secondPName)].getJedis();
			JedisFromBoth.sort(byName);
			std::cout << "The jedis from " << firstPName << " and " << secondPName << " in alphabetical order are: " << std::endl;
			JedisFromBoth.print();
		}
		else {
			std::cout << secondPName << " is not present in the database! Therefore only " << firstPName << " will be printed!" << std::endl;
			JedisFromBoth.sort(byName);
			JedisFromBoth.print();
		}
	}
	else if (this->planets.isElementPresent(secondPName)) {
		JedisFromBoth = this->planets[this->planets.findElementIndex(secondPName)].getJedis();
		std::cout << firstPName << " is not present in the database! Therefore only " << secondPName << " will be printed!" << std::endl;
		JedisFromBoth.sort(byName);
		JedisFromBoth.print();
	}
	else {
		std::cout << "There are no planets with such names in the database!" << std::endl;
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

void CommandList::saveToStream(std::ostream& out)
{
	for (size_t i = 0; i < this->planets.getSize(); ++i)
	{
		this->planets[i].saveToFile(out);
	}
}

void CommandList::loadFromStream(std::istream& in)
{
	char* buffer = new char[500];
	char* nJedis = new char[3];
	Planet tempPlanet;
	Jedi tempJedi;
	Vector<Jedi> tempJedis;
	String emptyLine;
	while (!(in.eof())) {
		in.getline(nJedis, 500, ' ');
		in.getline(buffer, 500);
		tempPlanet.setName(buffer);
		for (size_t i = 0; i < atoi(nJedis); ++i)
		{
			in.getline(buffer, 500, '|');
			tempJedi.setName(buffer);
			in.getline(buffer, 500, ' ');
			tempJedi.setcurrentRank(buffer);
			in.getline(buffer, 500, ' ');
			emptyLine = buffer;
			tempJedi.setAge(emptyLine.atoi());
			in.getline(buffer, 500, ' ');
			tempJedi.setSaberColor(buffer);
			in.getline(buffer, 500);
			emptyLine = buffer;
			tempJedi.setPower(emptyLine.atof());
			tempJedis.push_back(tempJedi);
		}
		emptyLine = nJedis;
		if (emptyLine.getSize() != 0) {
			tempPlanet.setJedis(tempJedis);
			tempJedis.clear();
			this->planets.push_back(tempPlanet);
		}
	}
	delete[] nJedis;
	delete[] buffer;
}

void CommandList::close()
{
	this->planets.clear();
	this->isOpenedAFile = false;
	std::cout << "File successfully closed." << std::endl;
}

void CommandList::save()
{
	std::ofstream out(this->filepath.getData(), std::ios::out);
	this->saveToStream(out);
	out.close();
	std::cout << "FIle successfully saved." << std::endl;
}

void CommandList::saveas(const String& filepath)
{
	std::ofstream out(filepath.getData(), std::ios::out);
	this->saveToStream(out);
	out.close();
	std::cout << "File successfully saved as " << filepath << "." << std::endl;
}

void CommandList::saveas()
{
	String filepath;
	std::cout << "Enter the designated filepath: ";
	std::cin >> filepath;
	std::ofstream out(filepath.getData());
	this->saveToStream(out);
	out.close();
	std::cout << "File successfully saved as " << filepath << "." << std::endl;
}

void CommandList::help() const
{
	std::cout << "open <filename> - opens a file of your choise. If such does not exists, creates a new empty one." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "add_planet <planet name> - creates and adds a planet to the database." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "create_jedi <planet name> <jedi name> <rank> <saber color> <age> <power> - creates a jedi on the " << std::endl;
	std::cout << "specified planet with the given info." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "remove_jedi <jedi name> <planet name> - removes a certain jedi from a given planet." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "promote_jedi <jedi name> <multiplier> - promotes the jedi and increases his power based on a formula." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "demote_jedi <jedi name> <multiplier> - demotes the jedi and decreases his power based on a formula." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "get_strongest_jedi <planet name> - finds and returns the strongest jedi on the given planet." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "get_youngest_jedi <planet name> <rank> - finds and returns the youngest jedi on the given planet from " << std::endl; 
	std::cout << "the specified rank." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "get_most_used_saber_color <planet name> <rank> - finds and returns the most used saber color on the " << std::endl;
	std::cout << "given planet by the specified rank." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "get_most_used_saber_color_grand <planet name> - finds and returns the most used saber color on the " << std::endl;
	std::cout << "given planet by the grandmasters." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "print_planet <planet name> - prints the name of the planet and the inhabitants, first sorted in ascending order " << std::endl;
	std::cout << "by rank, then by second key - lexicographically by name." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "print_planets <planet name> <planet name> - prints the contents of the both planet and sorts the inhabitants " << std::endl;
	std::cout << "lexicographically." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "print_jedi <jedi name> - prints the information about the jedi." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "close - closes the currently opened file." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "save - saves the currently opened file." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "saveas <filename> - saves the currently opened file as a new file with a new name." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "print_contents - prints the contents of the currently opened file." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "help - prints all the avaible commands." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "exit - exits the program." << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
}

void CommandList::print_contents()
{
	this->saveToStream(std::cout);
}

Vector<Planet>& CommandList::getPlanets()
{
	return this->planets;
}

void CommandList::open(const char* filepath)
{
	this->planets.clear();
	this->filepath = filepath;
	std::ifstream in(this->filepath.getData());
	if (!(in.good())) {
		std::cout << "File does not exists, therefore a new one will be created!" << std::endl;
		std::ofstream out(this->filepath.getData());
		out.close();
		in.open(this->filepath.getData());
	}
	this->loadFromStream(in);
	in.close();
	this->isOpenedAFile = true;
	std::cout << "File successfully opened." << std::endl;
}

void CommandList::open()
{
	this->planets.clear();
	String filepath;
	std::cout << "Enter the designated filepath: ";
	std::cin >> filepath;
	this->filepath = filepath;
	std::ifstream in(this->filepath.getData());
	if (!(in.good())) {
		std::cout << "File does not exists, therefore a new one will be created!" << std::endl;
		std::ofstream out(this->filepath.getData());
		out.close();
	}
	else {
		this->loadFromStream(in);
		std::cout << "File successfully opened." << std::endl;
	}
	in.close();
	this->isOpenedAFile = true;
}
