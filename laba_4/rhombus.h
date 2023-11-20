#pragma once

#include "Figure.h"
#include <iostream>

using namespace std;

template <typename T>
class Rhombus : public Figure<T> {

    friend ostream& operator << (ostream& os, const Rhombus<T>& Rhombus){
        os << "Rhomb's coordinates x,y: "<< endl;
        for(size_t i = 0; i < 4; ++i){
            os << Rhombus.po[i] << endl;
        }
        return os;
    }

    friend istream& operator >> (istream& is, Rhombus<T>& Rhombus) {
        cout << "Введите координаты ромба по часовой стрелке, начиная от левой вершины, ";
        cout << "если бы ромб был расположен так, чтобы его большая диагональ была параллельна оси Y (x1 y1 ... x4 y4): " << endl;
        for (size_t i = 0; i < 4; ++i) {
            is >> Rhombus.po[i];
        }
        return is;
    }

public:
    Rhombus();
    Rhombus(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4);

    virtual T square() const override;
    virtual Point<T> center() const override;

    Rhombus<T>& operator = (const Rhombus<T> &other);
    Rhombus<T>& operator = (Rhombus<T> &&other);
    bool operator == (const Rhombus<T> &other);
    virtual operator T() const override;


    ~Rhombus() = default;

private:
    Point<T> po[4];

};


template <typename T>
Rhombus<T>::Rhombus() : po{Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template <typename T>
Rhombus<T>::Rhombus(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4) : po{p1, p2, p3, p4}  {}

template <typename T>
Point<T> Rhombus<T>::center() const {
    //cout << "Rhombus center() " << endl;
    T x = 0, y = 0;
    for(size_t i = 0; i < 4; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point<T>(x / 4.0, y / 4.0);
}

template <typename T>
T Rhombus<T>::square() const {
    //cout << "Rhombus square() " << endl;
    T x1 = po[0].x_; T y1 = po[0].y_;
    T x2 = po[1].x_; T y2 = po[1].y_;
    T x3 = po[2].x_; T y3 = po[2].y_;
    T x4 = po[3].x_; T y4 = po[3].y_;
    //первая диагональ
    T d1 = sqrt(pow(abs(x1 - x3),2) + pow(abs(y1 - y3),2));
    //вторая диагональ
    T d2 = sqrt(pow(abs(x2 - x4),2) + pow(abs(y2 - y4),2));
    //площадь
    T S = (d1*d2)/2.0;
    return S;
}

template <typename T>
Rhombus<T>& Rhombus<T>::operator = (const Rhombus<T> &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

template <typename T>
Rhombus<T>& Rhombus<T>::operator = (Rhombus<T> &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = move(other.po[i]);
    }

    return *this;
}


template <typename T>
bool Rhombus<T>::operator == (const Rhombus<T>& other){
    for(size_t i = 0; i < 4; ++i){
        if(!(po[i] == other.po[i])){
            return false;
        }
    }
    return true;
}


template <typename T>
Rhombus<T>::operator T() const{
    return square();
}