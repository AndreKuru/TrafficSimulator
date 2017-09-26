#include "Semaphore.h"

void Semaphore::open() {
    status = true;
}

void Semaphore::close() {
    status = false;
}
