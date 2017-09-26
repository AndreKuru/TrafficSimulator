#include "Track.h"


clock_t Track::ride() {
    //! km/h -> m/s
    auto speed = speed_/3.6;
    return (clock_t )length_/speed;
}

void Track::add_efferent_track(Track efferent_track) {
    tracks_output->push_back(efferent_track);
}

void Track::enqueue(const Car car) {
    if (available_length_ - car.size() >= 0){
        available_length_ = available_length_ - car.size();
        LinkedQueue().enqueue(car);
    } else {
        throw std::out_of_range("Car does not fit in this track");
    }
}

Car Track::dequeue() {
    auto car = LinkedQueue().dequeue();
    available_length_ = available_length_ + car.size();
    return car;
}
