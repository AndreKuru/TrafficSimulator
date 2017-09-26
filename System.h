#ifndef TRAFFICSIMULATOR_SYSTEM_H
#define TRAFFICSIMULATOR_SYSTEM_H


#include "linked_List.h"
#include "Track.h"
#include "Semaphore.h"

class System {
    structures::LinkedList<Track> tracks;
    structures::LinkedList<Semaphore> semaphores;

 public:
    System();

    void add_track(Track track);

    void add_semaphore(Semaphore semaphore);
};


#endif //TRAFFICSIMULATOR_SYSTEM_H
