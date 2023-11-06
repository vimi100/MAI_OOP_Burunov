#pragma once

#include "Figure.h"
#include <iostream>

class Trapezoid : public Figure{
    friend std::ostream& operator << (std::ostream& os, const Trapezoid& f);
    friend std::istream& operator >> (std::istream& is, Trapezoid& f);

    public:
        Trapezoid();
        Trapezoid(Point& p1, Point& p2, Point& p3, Point& p4);
        
        virtual double square() const override;
        virtual Point center() const override;

        Trapezoid& operator = (const Trapezoid &other);
        Trapezoid& operator = (Trapezoid &&other);
        bool operator == (const Trapezoid &other);
        virtual operator double() const override;

        ~Trapezoid(){};

    private:
        Point po[4];

};