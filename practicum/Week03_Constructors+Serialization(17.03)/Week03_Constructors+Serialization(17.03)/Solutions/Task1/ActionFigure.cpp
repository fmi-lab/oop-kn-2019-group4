#include <string.h>
#include <cstring>
#include "ActionFigure.h"

void ActionFigure::copy(int _power, char * _name) {
   this->power = _power;

   this->name = new char [strlen(_name) + 1];
   strcpy(this->name, _name);
}

ActionFigure::ActionFigure (int _power, char * _name) {
   this->copy(_power, _name); 
}

ActionFigure::ActionFigure (ActionFigure const& otherFigure) {
    this->copy(otherFigure.power, otherFigure.name);
}

bool ActionFigure::operator<(ActionFigure const& otherFigure) {
    return this->power < otherFigure.power;
}

bool ActionFigure::operator>(ActionFigure const& otherFigure) {
    return this->power > otherFigure.power;
}

bool ActionFigure::operator==(ActionFigure const& otherFigure) {
    return this->power == otherFigure.power;
}

ActionFigure ActionFigure::operator+(ActionFigure const& otherFigure) {
    char teamName[3];
    teamName[0] = this->name[0];
    teamName[1] = otherFigure.name[0];

    return ActionFigure(this->power + otherFigure.power, teamName);
}
