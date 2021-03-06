#pragma once
#include "Planet.h"
#include "Comparators.h"
#include <fstream>
class CommandList
{
public:
	CommandList();
	void run();
	void add_planet(const String& name);
	void add_planet();
	void create_jedi(const String& pname, const String& jname, const String& rank, const size_t age, const String& saberColor, const double strength);
	void create_jedi();
	void remove_jedi(const String& jname, const String& pname);
	void remove_jedi();
	void promote_jedi(const String& jname, const double& multiplier);
	void promote_jedi();
	void demote_jedi(const String& jname, const double& multiplier);
	void demote_jedi();
	void get_strongest_jedi(const String& pname);
	void get_strongest_jedi();
	void get_youngest_jedi(const String& pname, const String& rank);
	void get_youngest_jedi();
	void get_most_used_saber_color(const String& pname, const String& rank);
	void get_most_used_saber_color();
	void get_most_used_saber_color_grand();
	void print_planet(const String& pname);
	void print_planet();
	void print_planets(const String& firstPName, const String& secondPName);
	void print_planets();
	void print_jedi(const String& jname);
	void print_jedi();

	void saveToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	void open(const char* filepath);
	void open();
	void close();
	void save();
	void saveas(const String& filepath);
	void saveas();
	void help() const;
	void print_contents();
	Vector<Planet>& getPlanets();
private:
	String command;
	String filepath;
	Vector<String> commandList;
	Vector<Planet> planets;
	bool isOpenedAFile;
};

