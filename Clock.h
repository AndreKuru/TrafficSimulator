#ifndef UNTITLED1_CLOCK_H
#define UNTITLED1_CLOCK_H


#include <ctime>
#include "linked_List.h"

class Clock : public structures::LinkedList<EventOccurrence>{
 private:
    enum Events {
        ARRIVAL_OF_NEW_CAR,
        SIGNAL_LIGHT_SHIFT,
        ARRIVAL_OF_CAR_IN_SEMAPHORE,
        TRACK_EXCHANGE};

    class EventOccurrence {
     public:
        explicit EventOccurrence(Events event, clock_t time):
        event_{event},
        time_{time} {}

     private:
        Events event_;
        std::clock_t time_;
    };


};


#endif //UNTITLED1_CLOCK_H
