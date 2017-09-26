#ifndef TRAFFICSIMULATOR_SEMAPHORE_H
#define TRAFFICSIMULATOR_SEMAPHORE_H


#include "linked_List.h"
#include "Track.h"

class Semaphore {
    //! Sinal Verde = true, Vermelho = false
    bool status {false};
    //! Tempo de sinal verde
    int time_open {30};
    structures::LinkedList<Track> afferent_track;
    structures::LinkedList<Track> efferent_tracks;

 public:
    Semaphore(Track afferent, Track efferent1, Track efferent2, Track efferent3) {
        afferent_track.push_back(afferent);
        efferent_tracks.push_back(efferent1);
        efferent_tracks.push_back(efferent2);
        efferent_tracks.push_back(efferent3);
    }

    void open();
    void close();
};


#endif //TRAFFICSIMULATOR_SEMAPHORE_H
