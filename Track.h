#ifndef UNTITLED1_LANE_H
#define UNTITLED1_LANE_H


#include "linked_queue.h"
#include "array_list.h"
#include "Car.h"
#include "linked_List.h"

class Track : public structures::LinkedQueue<Car>{
    structures::LinkedList<Track> tracks_output;
    //! ID
    std::string id_;
    //! Fonte tempo base (x onde x+y)
    int fount_time_;
    //! Variação do tempo (y onde x+y)
    int fount_variance_;
    //! km/h
    int speed_;
    //! tamanho em m
    int length_;
    //! tamanho restante em m
    int available_length_;

 public:
    Track(std::string id, int fount_time, int fount_variance, int speed, int length):
        id_{id},
        fount_time_(fount_time),
        fount_variance_(fount_variance),
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
