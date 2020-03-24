#ifndef ACTIONFIGURE_H
#define ACTIONFIGURE_H

#include <string.h>

class ActionFigure {

public:
    char * name;
    int power;

    ActionFigure () : name(nullptr), power(0) {};
    ActionFigure (int _power, char * _name); 
    ActionFigure (ActionFigure const& otherFigure);
    bool operator<(ActionFigure const& otherFigure);
    bool operator>(ActionFigure const& otherFigure);
    bool operator==(ActionFigure const& otherFigure);
    ActionFigure operator+(ActionFigure const& otherFigure);
    void copy(int _power, char * _name);
};

#endif /* ACTIONFIGURE_H */
