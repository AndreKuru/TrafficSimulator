#ifndef TRAFFICSIMULATOR_SEMAPHORE_H
#define TRAFFICSIMULATOR_SEMAPHORE_H


#include "linked_List.h"
#include "Track.h"

class Semaphore {
    structures::LinkedList<Track> afferent_track;
    structures::LinkedList<Track> efferent_tracks;

    Semaphore(Track afferent_track1, Track efferent_track1, Track efferent_track2, Track efferent_track3) {
        afferent_track.push_back(afferent_track1);
        efferent_tracks.push_back(efferent_track1);
        efferent_tracks.push_back(efferent_track2);
        efferent_tracks.push_back(efferent_track3);
    }

};


#endif //TRAFFICSIMULATOR_SEMAPHORE_H
