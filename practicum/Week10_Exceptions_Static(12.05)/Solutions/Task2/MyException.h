#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <exception>
#include <string>

struct missingTrooperException : public std::exception {
    //throw(<type>) is a variant of noexcept but it is considered depricated
    //Does not mesh well with template classess. Not extensible when you can throw a ton of exceptions
    //throw() with no type is = noexcept
    //they both guarantee that an exception will not be thrown
    //Use noexcept
    const char * what() const noexcept override {
        return "Invalid clone id";
    }
};

#endif /* ifndef MY_EXCEPTION_H */
