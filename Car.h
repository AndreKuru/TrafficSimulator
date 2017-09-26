#ifndef UNTITLED1_CAR_H
#define UNTITLED1_CAR_H
#define FRONT_SPACE 1;
#define REAR_SPACE 2;


#include <cstdlib>

class Car {
 public:
    Car(std::size_t size):
           size_{size} {}
    std::size_t size()const;

 private:
    std::size_t size_;

};


#endif //UNTITLED1_CAR_H
