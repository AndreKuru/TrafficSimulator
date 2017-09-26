#include "Track.h"
#include <ctime>


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

bool Track::operator==(const Track &other) {
    return id_ == other.id_;
}

bool Track::operator!=(const Track &other) {
    return id_!= other.id_;
}

bool Track::full() {
    return available_length_ <= 4;
}


bool Track::fill(Car car) {
    return available_length_ - car.size() >= 0;
}

void Track::leak() {


}

int Track::check_arrival() {
}

int Track::generate_interval() {
    return fount_time_ + rand()%(fount_variance_);
}
