#pragma once

#include "Figure.h"
#include <iostream>

class Rhombus : public Figure {

    friend std::ostream& operator<<(std::ostream& os, const Rhombus& f);
    friend std::istream& operator>>(std::istream& is, Rhombus& f);

public:
    Rhombus();
    Rhombus(Point& p1, Point& p2, Point& p3, Point& p4);

    virtual double square() const override;
    virtual Point center() const override;

    Rhombus& operator = (const Rhombus &other);
    Rhombus& operator = (Rhombus &&other);
    bool operator == (const Rhombus &other);
    virtual operator double() const override;



    ~Rhombus(){};

private:
    Point po[4];

};