#ifndef UNTITLED1_LANE_H
#define UNTITLED1_LANE_H


#include "linked_queue.h"
#include "array_list.h"
#include "Car.h"
#include "linked_List.h"
#include <ctime>

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
    Track(std::string id):
    id_{id} {};

    Track(std::string id, int fount_time_middle, int fount_variance_middle, int speed, int length):
        id_{id},
        fount_time_(fount_time_middle-fount_variance_middle),
        fount_variance_(fount_variance_middle*2),
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

    //! Verifica apenas ID
    bool operator ==(const Track& other);
    bool operator !=(const Track& other);

};

#endif
