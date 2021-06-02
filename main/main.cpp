#include "CommandList.h"
#include <fstream>
int main()
{
	/*Vector<Jedi> a;
	Jedi b("Vesko");
	Jedi c("Alex");
	Jedi d("Dobri");
	a.push_back(b);
	a.push_back(c);
	a.push_back(d);
	a.sort(byName);
	a.print();*/
	CommandList a;
	////a.run();
	a.add_planet("Earth");
	a.add_planet("Mars");
	a.add_planet("Uranus");
	a.create_jedi("Earth", "Vesko", "PADAWAN", 20, "red", 3);
	a.create_jedi("Mars", "Alex", "KNIGHT", 20, "blue", 7);
	a.create_jedi("Earth", "Dobri", "KNIGHT", 20, "blue", 6);

	std::ofstream out("planets.star");
	a.saveToStream(out);
	out.close();

	CommandList b;

	std::ifstream in("planets.star");
	b.loadFromStream(in);
	in.close();
	b.saveToStream(std::cout);
	//a.get_youngest_jedi("Mars", "PADAWAN");
	//a.print_planets("Earth", "Earth");
	//a.remove_jedi("Gosho", "Mars");
	//a.promote_jedi("Vesko", 10);
	//a.demote_jedi("Vesko", 1);
	//a.get_most_used_saber_color("Mars", "KNIGHT");
	//a.get_youngest_jedi("Mars", "KNIGHT");
	//a.getPlanets()[0].getJedis().print();
	//a.print_jedi("Tosho");
}
