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

void Track::schedule_arrival() {
    auto time = 0;
    while (last_time > 0) {
        auto interval = generate_interval();
        last_time = last_time - interval;
        time = time + interval;
        clock->insert_sorted(EventOccurrence(ARRIVAL_OF_NEW_CAR, time));
    }
}

void Track::change_status (int time) {
    clock->insert_sorted(EventOccurrence(SIGNAL_LIGHT_SHIFT, time));
}

int Track::generate_interval() {
    return fount_time_ + rand()%(fount_variance_);
}

void Track::add_efferent_track(Track *efferent_track, int percentage) {

}
