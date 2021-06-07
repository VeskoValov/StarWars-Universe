#pragma once
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Planet.h"

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

void runtests() {
    doctest::Context().run();
}