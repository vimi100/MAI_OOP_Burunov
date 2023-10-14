#pragma once

#include <iostream>
#include <string>

using std::cout, std::initializer_list, std::string, std::ostream, std::logic_error, std::endl, std::exception, std::move;

class Four {
public:
    Four();
    Four(const size_t & n, unsigned char t = 0);
    Four(const initializer_list< unsigned char> &t);
    Four(const string &t);
    Four(const Four& other);
    Four(Four&& other) noexcept;

    // size_t four_to_dec (size_t num);
    // size_t dec_to_four() noexcept;

    bool bigger(const Four &other) const;
    bool smaller(const Four &other) const;
    bool equal(const Four& other) const;

    Four copy(const Four& other);
    Four addition(const Four& other);
    Four subtraction(const Four& other);

    ostream& print(ostream &os);

    virtual ~Four() noexcept;
private:
    size_t self_size;
    unsigned char *self_array;
};