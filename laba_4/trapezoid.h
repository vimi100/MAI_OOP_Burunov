#pragma once

#include "Figure.h"
#include <iostream>
using namespace std;

template <typename T>
class Trapezoid : public Figure<T>{

    friend ostream& operator << (ostream& os, const Trapezoid<T>& trapezia){
        for(size_t i = 0; i < 4; ++i){
            os << trapezia.po[i] << endl;
        }
        return os;
    }

    friend istream& operator >> (istream& is, Trapezoid<T>& trapezia) {
        cout << "Введите координаты трапеции по часовой стрелке, начиная от левой нижней вершины (x1 y1 ... x4 y4): " << endl;
        for (size_t i = 0; i < 4; ++i) {
            is >> trapezia.po[i];
        }
        return is;
    }

    public:
        Trapezoid();
        Trapezoid(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4);
        
        virtual T square() const override;
        virtual Point<T> center() const override;

        Trapezoid<T>& operator = (const Trapezoid<T> &other);
        Trapezoid<T>& operator = (Trapezoid<T> &&other);
        bool operator == (const Trapezoid<T> &other);
        virtual operator T() const override;

        ~Trapezoid() = default;

    private:
        Point<T> po[4];

};

template <typename T>
Trapezoid<T>::Trapezoid() : po{Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template <typename T>
Trapezoid<T>::Trapezoid(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4) : po{p1, p2, p3, p4}  {}

template <typename T>
Point<T> Trapezoid<T>::center() const {
    //cout << "Trapezoid center() " << endl;
    T x = 0, y = 0;
    for(size_t i = 0; i < 4; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point<T>(x / 4.0, y / 4.0);
}

template <typename T>
T Trapezoid<T>::square() const {
    //cout << "Trapezoid square() " << endl;
    T x1 = po[0].x_; T y1 = po[0].y_;
    T x2 = po[1].x_; T y2 = po[1].y_;
    T x3 = po[2].x_; T y3 = po[2].y_;
    T x4 = po[3].x_; T y4 = po[3].y_;

    T S = abs(x1*y2 + x2*y3 + x3*y4 + x4*y1 - x2*y1 - x3*y2 - x4*y3 - x1*y4) / 2.0;
    return S;
}

template <typename T>
Trapezoid<T>& Trapezoid<T>::operator = (const Trapezoid<T> &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

template <typename T>
Trapezoid<T>& Trapezoid<T>::operator = (Trapezoid<T> &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = move(other.po[i]);
    }

    return *this;
}

template <typename T>
bool Trapezoid<T>::operator == (const Trapezoid<T>& other){
    for(size_t i = 0; i < 4; ++i){
        if(!(po[i] == other.po[i])){
            return false;
        }
    }
    return true;
}


template <typename T>
Trapezoid<T>::operator T() const{
    return square();
}