#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <memory>
#include "squirrel.hpp"
#include "thug.hpp"
#include "elf.hpp"
#include "factory.hpp"

TEST(Constructors, Squirrel) {
    Squirrel s(0, 0, "Belka");
    std::stringstream out;
    s.print(out);
    ASSERT_EQ(out.str(), "Squirrel Belka {0, 0}");
}

TEST(Constructors, Thug) {
    Thug t(1, 1, "Vor");
    std::stringstream out;
    t.print(out);
    ASSERT_EQ(out.str(), "Thug Vor {1, 1}");
}

TEST(Constructors, Elf) {
    Elf e(2, 2, "Dobbi");
    std::stringstream out;
    e.print(out);
    ASSERT_EQ(out.str(), "Elf Dobbi {2, 2}");
}

TEST(Fabric, basic) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Squirrel", "Name", 0, 0));
    persons.push_back(factory("Thug", "Name", 0, 0));
    persons.push_back(factory("Elf", "Name", 0, 0));

    std::stringstream out;
    for (auto& elem : persons) {
        elem->print(out);
    }
    ASSERT_EQ(out.str(), "Squirrel Name {0, 0}Thug Name {0, 0}Elf Name {0, 0}");
}

TEST(Fighting, basic) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Squirrel", "Name", 0, 0));
    persons.push_back(factory("Thug", "Name", 0, 0));
    persons.push_back(factory("Elf", "Name", 0, 0));

    for (auto& defender : persons) {
        for (auto& attacker : persons) {
            defender->accept(attacker.get(), 0);
        }
    }
    for (auto& elem : persons) {
        ASSERT_FALSE(elem->is_alive());
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}