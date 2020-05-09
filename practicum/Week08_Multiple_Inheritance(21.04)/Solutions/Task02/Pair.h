#ifndef PAIR_H
#define PAIR_H

template <typename T, typename U>
class Pair
{
    T key;
    U value;

protected:
    void copy(T key, U value);

public:
    Pair();
    Pair(T key, U value);
    Pair(Pair const &other);
    Pair &operator=(Pair const &other);
    ~Pair();

    T getKey() const { return this->key; }
    U getValue() const { return this->value; }
};

#endif /* ifndef PAIR_H */