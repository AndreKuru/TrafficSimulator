#include "System.h"

void System::add_track(Track track) {
    tracks.push_back(track);
}

void System::add_semaphore(Semaphore semaphore) {
    semaphores.push_back(semaphore);
}

System::System() {
    //               ID        f1  f2  v   s
    add_track(Track("N1sul",   20, 05, 60, 500));
    add_track(Track("N1norte", 00, 00, 60, 500));
    add_track(Track("N2sul",   20, 05, 40, 500));
    add_track(Track("N2norte", 00, 00, 40, 500));
    add_track(Track("L1oeste", 10, 02, 30, 400));
    add_track(Track("L1leste", 00, 00, 30, 400));
    add_track(Track("S2norte", 60, 15, 40, 500));
    add_track(Track("S2sul",   00, 00, 40, 500));
    add_track(Track("S1norte", 30, 07, 60, 500));
    add_track(Track("S1sul",   00, 00, 60, 500));
    add_track(Track("O1leste", 10, 02, 80, 2000));
    add_track(Track("O1oeste", 00, 00, 80, 2000));
    add_track(Track("C1oeste", 00, 00, 60, 300));
    add_track(Track("C1leste", 00, 00, 60, 300));

    //S1
    add_semaphore(Semaphore(tracks.at(tracks.find(Track("N1sul"))),     // afferent
                            tracks.at(tracks.find(Track("C1leste"))),   // efferent1
                            tracks.at(tracks.find(Track("S1sul"))),     // efferent2
                            tracks.at(tracks.find(Track("O1oeste"))))); // efferent3

    add_semaphore(Semaphore(tracks.at(tracks.find(Track("C1oeste"))),   // afferent
                            tracks.at(tracks.find(Track("S1sul"))),     // efferent1
                            tracks.at(tracks.find(Track("O1oeste"))),   // efferent2
                            tracks.at(tracks.find(Track("N1norte"))))); // efferent3

    add_semaphore(Semaphore(tracks.at(tracks.find(Track("S1norte"))),   // afferent
                            tracks.at(tracks.find(Track("O1oeste"))),   // efferent1
                            tracks.at(tracks.find(Track("N1norte"))),   // efferent2
                            tracks.at(tracks.find(Track("C1leste"))))); // efferent3

    add_semaphore(Semaphore(tracks.at(tracks.find(Track("O1leste"))),   // afferent
                            tracks.at(tracks.find(Track("N1norte"))),   // efferent1
                            tracks.at(tracks.find(Track("C1leste"))),   // efferent2
                            tracks.at(tracks.find(Track("S1sul")))));   // efferent3

    // S2
    add_semaphore(Semaphore(tracks.at(tracks.find(Track("N2sul"))),     // afferent
                            tracks.at(tracks.find(Track("L1leste"))),   // efferent1
                            tracks.at(tracks.find(Track("S2sul"))),     // efferent2
                            tracks.at(tracks.find(Track("C1oeste"))))); // efferent3

    add_semaphore(Semaphore(tracks.at(tracks.find(Track("L1oeste"))),   // afferent
                            tracks.at(tracks.find(Track("S2sul"))),     // efferent1
                            tracks.at(tracks.find(Track("C1oeste"))),   // efferent2
                            tracks.at(tracks.find(Track("N2norte"))))); // efferent3

    add_semaphore(Semaphore(tracks.at(tracks.find(Track("S2norte"))),   // afferent
                            tracks.at(tracks.find(Track("C1oeste"))),   // efferent1
                            tracks.at(tracks.find(Track("N2norte"))),   // efferent2
                            tracks.at(tracks.find(Track("L1leste"))))); // efferent3

    add_semaphore(Semaphore(tracks.at(tracks.find(Track("C1leste"))),   // afferent
                            tracks.at(tracks.find(Track("N2norte"))),   // efferent1
                            tracks.at(tracks.find(Track("L1leste"))),   // efferent2
                            tracks.at(tracks.find(Track("S2sul")))));   // efferent3

}

void System::run() {
    semaphores.at(0).open();




}
