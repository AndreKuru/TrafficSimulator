#ifndef UNTITLED1_LANE_H
#define UNTITLED1_LANE_H


#include "linked_queue.h"
#include "array_list.h"
#include "Car.h"
#include "linked_List.h"
#include <ctime>

class Track : public structures::LinkedQueue<Car>{
    structures::LinkedList<Track> *tracks_output;
    //! km/h
    int speed_;
    //! tamanho em m
    int length_;
    //! tamanho restante em m
    int available_length_;

    Track(){};
    Track(int speed, int length):
        tracks_output {},
        speed_{speed},
        length_{length},
        available_length_{length}
    {};

    //! Tempo que um carro percorre a pista até o semáforo
    clock_t ride();

    //! Define a pista do parametro como eferente
    void add_efferent_track(Track efferent_track);

    //! Enfileira carro
    void enqueue(const Car car);

    //! Desenfileira carro
    Car dequeue();

};

#endif
