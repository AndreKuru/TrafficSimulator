#include <cstddef>
#include <stdexcept>

namespace structures {


template<typename T>

//! Fila encadeada
class LinkedQueue {
 public:
    LinkedQueue();

    ~LinkedQueue();

    //! limpar
    void clear();

    //! enfilerar
    void enqueue(const T& data);

    //! desenfilerar
    T dequeue();

    //! primeiro dado
    T& front() const;

    //! último dado
    T& back() const;

    //! fila vazia
    bool empty() const;

    //! tamanho
    std::size_t size() const;

 private:
    class Node {
     public:
        explicit Node(const T data):
                data_{data},
                next_{nullptr} {}

        Node(const T data, Node* next):
                data_{data},
                next_{next} {}

        //! getter data_
        T& data() {
            return data_;
        }

        //! getter next_
        Node* next() {
            return next_;
        }

        //! setter next_
        void next(Node* next) {
            next_ = next;
        }

     private:
        T data_;
        Node* next_;
    };  // Node

    //! nodo-cabeça
    Node* head = nullptr;

    //! nodo-fim
    Node* tail = nullptr;

    //! tamanho
    std::size_t size_ = 0;
};  // LinkedQueue

template<typename T>
LinkedQueue<T>::LinkedQueue() {}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template<typename T>
void LinkedQueue<T>::clear() {
    while (!empty()) {
        dequeue();
    }
}


template<typename T>
void LinkedQueue<T>::enqueue(const T &data) {
    if (empty()) {
        head = new Node(data);
        tail = head;
    } else {
        tail->next(new Node(data));
        tail = tail->next();
    }
    size_++;
}

template<typename T>
T LinkedQueue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Queue empty!");
    }
    auto it = *head;
    delete head;
    head = it.next();
    size_--;
    return it.data();
}

template<typename T>
T& LinkedQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue empty!");
    }
    return head->data();
}

template<typename T>
T& LinkedQueue<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Queue empty!");
    }
    return tail->data();
}

template<typename T>
bool LinkedQueue<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t LinkedQueue<T>::size() const {
    return size_;
}

}  // namespace structures
