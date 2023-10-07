#include "four.h"

Four::Four(): self_size(0), self_array{nullptr} {}

Four::Four(const size_t &n, unsigned char t) {
    if (n == 0) {
        throw logic_error("array can't has size 0");
    }
    if (not(t <= '3' and t >= '0')) {
        throw logic_error("wrong number");
    }
    self_array = new unsigned char[n];
    for (size_t i = 0; i < n; i++) {
        self_array[i] = t;
    }
    self_size = n;
}

Four::Four(const initializer_list< unsigned char> &t) {
    if (t.size() == 0) {
        throw logic_error("array can't has size 0");
    }
    self_array = new unsigned char[t.size()];
    size_t i{t.size() - 1};
    for (auto &c: t) {
        if ((c <= '9' and c >= '0') or c == 'a' or c == 'A') {
            self_array[i--] = c;
        }
        else {
            throw logic_error("wrong number");
        }
        self_size = t.size();
    }

    for (size_t i = self_size - 1; self_array[i] == '0' and i > 0; --i) {
        self_size--;
    }
}

Four::Four(const string &t) {
    if (t.size() == 0) {
        throw logic_error("array can't has size 0");
    }
    else {
        self_array = new unsigned char[t.size()];
        self_size  = t.size();

        for(size_t i{0}; i<self_size; ++i) {                                                //неясная вещь, возможно придеться править
            if (((t[self_size - 1 - i] <= '9' and t[self_size - 1 - i] >= '0')) or (t[self_size - 1 - i] == 'a' or t[self_size - 1 - i] == 'A')) {
                self_array[i] = t[self_size - 1 - i];
            }
            else {
                throw logic_error("wrong number");
            }
        }
        for (size_t i = self_size - 1; self_array[i] == '0' and i > 0; --i) {
            self_size--;
        }

    } 
}

Four::Four(const Four &other) {
    self_size  = other.self_size;
    self_array = new unsigned char[self_size];
    for(size_t i{0} ;i < self_size; ++i) {
        self_array[i] = other.self_array[i];
    }
}

Four::Four(Four&& other) noexcept {
    self_size = other.self_size;
    self_array = other.self_array;

    other.self_size = 0;
    other.self_array = nullptr;
}


Four::~Four() noexcept {
    if (self_size > 0) {
        self_size = 0;
        delete[] self_array;
        self_array = nullptr;
    }
}

Four Four::four_to_el(size_t num){
    string result = "";
    if(!num) result += '0';
    while(num){
        char tmp = num%4 + '0';
        result = tmp + result;
        num /= 4;
    }
    return Four{result};
}

size_t Four::el_to_four() noexcept{
    size_t res = 0;
    int pow = 1;
    int digit = 0;
    for(size_t i{0}; i<self_size; ++i){
        digit = self_array[i] - '0';
        res += digit * pow;
        pow *= 4;
    }
    
    return res;

}

bool Four::bigger(const Four &other) const {
    if (self_size < other.self_size) {
        return false;
    }
    if (self_size > other.self_size) {
        return true;                        //могут быть какие-то неполадки здесь!
    }
    for (int i = self_size - 1; i >= 0; --i) {
        if (self_array[i] < other.self_array[i]) {
            return false;
        }
        if (self_array[i] > other.self_array[i]) {
            return true;
        }
    }
    return false;
}

bool Four::smaller(const Four &other) const {
    if (self_size < other.self_size) {
        return true;
    }
    if (self_size > other.self_size) {
        return false;
    }
    for (int i = self_size - 1; i >= 0; --i) {
        if (self_array[i] < other.self_array[i]) {
            return true;
        }
        if (self_array[i] > other.self_array[i]) {
            return false;
        }
    }
    return false;
}

bool Four::equal(const Four &other) const {
    bool eql{false};
    int digit_1;
    int digit_2;
    if (self_size == other.self_size) {
        size_t temp{self_size};
        eql = true;
        while (temp) {
            digit_1 = self_array[temp - 1] - '0';
            digit_2 = other.self_array[temp - 1] - '0';
            eql = (digit_1 == digit_2) and eql;
            temp--;
        }
    }
    return eql;
}

Four Four::copy(const Four& other){
    this->self_size = other.self_size;
    for(size_t i{0}; i < other.self_size; ++i){ 
        this->self_array[i] = other.self_array[i];
    }
    return *this;
}

Four Four::addition(const Four& other) {
    this->copy(four_to_el(this->el_to_four() + Four{other}.el_to_four()));
    return *this;
}

Four Four::subtraction(const Four& other) {
    if (this->smaller(other)) {
        throw logic_error("number can't be negative\n");
    }
    else {
        this->copy(four_to_el(this->el_to_four() - Four{other}.el_to_four()));
    }
    return *this;
}

std::ostream &Four::print(std::ostream &os) {
    for (size_t i = 1; i <= self_size; ++i) {
        os << self_array[self_size - i];
    }
}





// int main () {
//     Four a{"312"};
//     Four c{"31"};
//     bool result = a.smaller(c);
//     bool res = a.equal(c); 
//     size_t b = a.el_to_four();
//     size_t d = c.el_to_four();
//     Four b1 = b1.four_to_el(b);
//     cout << b1.el_to_four() << endl;
//     b1.print(cout);
//     cout << "a: " << b << endl;
//     cout << "c: " << d << endl;
//     if (res) {
//         cout << "they are equal!\n";
//     }
//     else {
//         cout << "they are not equal!\n";
//     }
//     if (result) {
//         cout << "a is smaller than c" << endl;
//     }
//     else {
//         cout << "a is't smaller than c" << endl;
//     }
// }