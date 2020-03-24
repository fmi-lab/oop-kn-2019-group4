#include <iostream>
#include "ActionFigure.h"

bool fight(ActionFigure hero1, ActionFigure hero2) {

    if(hero1 > hero2) {
        std::cout << hero1.name << " wins!" << std::endl;
        return true;
    } else if(hero1 < hero2) {
        std::cout << hero2.name << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw" << std::endl;
    }

    return false;
}


int main(void) {
    char name[100] = "Guts"; //c++ complains if you write the name directly in the constructor. Because it expects a pointer
    ActionFigure hero1(100, name);

    strcpy(name,"Casca");
    ActionFigure hero2(50, name); 

    strcpy(name, "Griffith");
    ActionFigure villain(150, name);
   
    fight(hero1, hero2);
    fight(hero1, villain);
    fight(hero1 + hero2, villain);
   
    hero1.power += 50;
    fight(hero1+hero2, villain);

    return 0;
}
