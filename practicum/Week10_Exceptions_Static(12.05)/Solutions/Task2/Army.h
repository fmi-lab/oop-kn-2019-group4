#ifndef ARMY_H
#define ARMY_H value
#include "Clone.h"
#include "MyException.h"
#include <vector>
#include <iostream>

class Army {
    std::vector<Clone> troopers;

public:
    
    Clone findCloneById(int id) const {
        for (size_t i = 0; i < troopers.size(); ++i) {
            if(troopers[i].getId() == id) {
                return troopers[i];
            }
        }

        throw missingTrooperException();
    }

    void addClone(Clone& newClone) {
        troopers.push_back(newClone);
    }

};
#endif /* ifndef ARMY_H */
