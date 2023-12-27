#pragma once
#include "NPC.hpp"


class Elf: public NPC {
public:
    Elf(const int&, const int&);

    void print(std::ostream&) override;

    void accept(NPC*) override;
    bool attack(Thug&) override;

    friend std::ostream& operator<<(std::ostream&, const Elf&);

    bool is_close(const NPC&) const noexcept override;

    char token() const noexcept override;
    void rand_move(const int&, const int&) override;
};
