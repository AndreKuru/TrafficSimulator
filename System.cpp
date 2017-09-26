#include "System.h"

void System::add_track(Track track) {
    tracks.push_back(track);
}

void System::add_semaphore(Semaphore semaphore) {
    semaphores.push_back(semaphore);
}
