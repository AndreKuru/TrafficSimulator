#ifndef UNTITLED1_CAR_H
#define UNTITLED1_CAR_H
#define FRONT_SPACE 1;
#define REAR_SPACE 2;


#include <glob.h>

class Car {
 public:
    Car(size_t size):
           size_{size} {}
    size_t size()const;

 private:
    size_t size_;

};


#endif //UNTITLED1_CAR_H
