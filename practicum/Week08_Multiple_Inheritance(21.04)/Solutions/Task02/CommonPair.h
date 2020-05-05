#ifndef COMMON_PAIR_H
#define COMMON_PAIR_H

#include "Pair.h"

class CommonPair: public Pair<int, double>
{
protected:
    void copy(int key, double value);

public:
    CommonPair();
    CommonPair(int key, double value);
    CommonPair(CommonPair const &other);
    CommonPair &operator=(CommonPair const &other);
    ~CommonPair();
};

#endif /* ifndef COMMON_PAIR_H */