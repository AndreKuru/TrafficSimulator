#ifndef TRAFFICSIMULATOR_EVENTOCCURRENCE_H
#define TRAFFICSIMULATOR_EVENTOCCURRENCE_H

#include <ctime>

enum Events {
    ARRIVAL_OF_NEW_CAR,
    SIGNAL_LIGHT_SHIFT,
    ARRIVAL_OF_CAR_IN_SEMAPHORE,
    TRACK_EXCHANGE};

class EventOccurrence {
 public:
    explicit EventOccurrence(Events event, clock_t time) :
            event_{event},
            time_{time} {}

    bool operator >(const EventOccurrence other);
    bool operator >=(const EventOccurrence other);
    bool operator <=(const EventOccurrence other);
    bool operator <(const EventOccurrence other);

 private:
    Events event_;
    std::clock_t time_;
};


#endif //TRAFFICSIMULATOR_EVENTOCCURRENCE_H
