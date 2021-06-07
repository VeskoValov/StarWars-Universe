#pragma once
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "CommandList.h"

TEST_CASE("Testing Jedi") {

    Jedi testJedi;

    String buffer = "jedi";
    testJedi.setName(buffer);
    CHECK(testJedi.getName() == "jedi");

    buffer = "PADAWAN";
    testJedi.setcurrentRank(buffer);
    CHECK(testJedi.getRank() == "PADAWAN");

    size_t age = 30;
    testJedi.setAge(age);
    CHECK(testJedi.getAge() == 30);

    buffer = "green";
    testJedi.setSaberColor(buffer);
    CHECK(testJedi.getColor() == "green");

    double power = 10.4;
    testJedi.setPower(power);
    CHECK(testJedi.getPower() == 10.4);

    double multi = 3;
    testJedi.promote(multi);
    CHECK(testJedi.getRank() == "KNIGHT-ASPIRANT");
    CHECK(testJedi.getPower() == 41.6);

    multi = 1;
    testJedi.demote(multi);
    CHECK(testJedi.getRank() == "PADAWAN");
    CHECK(testJedi.getPower() == 0);

}

TEST_CASE("Testing Planet") {
    Planet testPlanet;

    String name = "Mars";
    testPlanet.setName(name);
    CHECK(testPlanet.getName() == "Mars");

    Jedi testJedi("Vesko", "KNIGHT", 30, "green", 10.4);
    testPlanet.addJedi(testJedi);
    CHECK(testPlanet.getJedis().getSize() == 1);
    CHECK(testPlanet.getJedis()[0].getName() == "Vesko");
    CHECK(testPlanet.getJedis()[0].getRank() == "KNIGHT");
    CHECK(testPlanet.getJedis()[0].getAge() == 30);
    CHECK(testPlanet.getJedis()[0].getColor() == "green");
    CHECK(testPlanet.getJedis()[0].getPower() == 10.4);

    testPlanet.removeJedi(testJedi);
    CHECK(testPlanet.getJedis().getSize() == 0);


}

TEST_CASE("Testing CommandList"){
    CommandList testList;

    testList.add_planet("Earth");
    CHECK(testList.getPlanets()[0].getName() == "Earth");

    testList.add_planet("Mars");
    CHECK(testList.getPlanets()[1].getName() == "Mars");

    testList.add_planet("Uranus");
    CHECK(testList.getPlanets()[2].getName() == "Uranus");

    testList.create_jedi("Earth", "Vesko", "PADAWAN", 20, "green", 3.4);
    CHECK(testList.getPlanets()[0].getJedis()[0].getName() == "Vesko");
    CHECK(testList.getPlanets()[0].getJedis()[0].getRank() == "PADAWAN");
    CHECK(testList.getPlanets()[0].getJedis()[0].getAge() == 20);
    CHECK(testList.getPlanets()[0].getJedis()[0].getColor() == "green");
    CHECK(testList.getPlanets()[0].getJedis()[0].getPower() == 3.4);

    testList.create_jedi("Mars", "Alex", "KNIGHT", 20, "blue", 7);
    testList.create_jedi("Earth", "Dobri", "KNIGHT", 20, "blue", 6);

    std::ofstream out("Test.txt");
    testList.saveToStream(out);
    out.close();

    CommandList testList2;
    std::ifstream in("Test.txt");
    testList2.loadFromStream(in);
    in.close();

    for (size_t i = 0; i < testList.getPlanets().getSize(); ++i)
    {
        CHECK(testList.getPlanets()[i] == testList2.getPlanets()[i]);
    }
}
void runtests() {
    doctest::Context().run();
}