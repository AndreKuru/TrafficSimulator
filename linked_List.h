#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
//! Lista encadeada
class LinkedList {
 public:
    LinkedList();  // construtor padrão
    ~LinkedList();  // destrutor

    //! limpar lista
    void clear();

    //! inserir no fim
    void push_back(const T& data);

    //! inserir no início
    void push_front(const T& data);

    //! inserir na posição
    void insert(const T& data, std::size_t index);

    //! inserir em ordem
    void insert_sorted(const T& data);

    //! acessar um elemento na posição index
    T& at(std::size_t index);

    //! retirar da posição
    T pop(std::size_t index);

    //! retirar do fim
    T pop_back();

    //! retirar do início
    T pop_front();

    //! remover específico
    void remove(const T& data);

    //! lista vazia
    bool empty() const;

    //! contém
    bool contains(const T& data) const;

    //! posição do dado
    std::size_t find(const T& data) const;

    //! tamanho da lista
    std::size_t size() const;

 private:
    //! Elemento
    class Node {
     public:
        explicit Node(const T& data):
                data_{data}
        {}

        Node(const T& data, Node* next):
                data_{data},
                next_{next}
        {}

        //! getter: dado
        T& data() {
            return data_;
        }

        //! getter const: dado
        const T& data() const {
            return data_;
        }

        //! getter: próximo
        Node* next() {
            return next_;
        }

        //! getter const: próximo
        const Node* next() const {
            return next_;
        }

        //! setter: próximo
        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    //! último nodo da lista
    Node* end() {
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    void delete_head() {
        auto it = head;
        head = head->next();
        delete it;
        size_--;
    }

    Node* head{nullptr};
    std::size_t size_{0u};
};  //! LinkedList

template<typename T>
LinkedList<T>::LinkedList() {}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void LinkedList<T>::clear() {
    while (!empty()) {
        auto it = head;
        head = head->next();
        delete it;
        size_--;
    }
}

template<typename T>
void LinkedList<T>::push_back(const T &data) {
    if (empty())
        head = new Node(data);
    else
        end()->next(new Node(data));
    size_++;
}

template<typename T>
void LinkedList<T>::push_front(const T &data) {
    if (empty()) {
        head = new Node(data);
    } else {
        auto it = head;
        head = new Node (data, it);
    }
    size_++;
}

template<typename T>
void LinkedList<T>::insert(const T &data, std::size_t index) {
    if (index >= size_)
        throw std::out_of_range("Index invalid!");
    auto it = head;
    for (auto i = 0u; i < index-1; i++)
        it = it->next();
    it->next(new Node(data, it->next()));
    size_++;
}

template<typename T>
void LinkedList<T>::insert_sorted(const T &data) {
    if (empty() || head->data() >= data) {
        head = new Node(data, head);
    } else {
        auto it = head;
        auto index = 1u;
        while (index < size_ &&
               it->next()->data() < data) {
            it = it->next();
            index++;
        }
        it->next(new Node(data, it->next()));
    }
    size_++;
}

template<typename T>
T& LinkedList<T>::at(std::size_t index) {
    if (index >= size_)
        throw std::out_of_range("Index invalid!");
    auto it = head;
    for (auto i = 0; i < index; i++)
        it = it->next();
    return it->data();
}

template<typename T>
T LinkedList<T>::pop(std::size_t index) {
    if (empty())
        throw std::out_of_range("List is empty!");
    if (index >= size())
        throw std::out_of_range("Index invalid!");
    if (index == 0u)
        return pop_front();
    auto it = head;
    for (auto i = 1u; i < index; i++)
        it = it->next();
    auto target = it->next();
    it->next(target->next());
    auto target_content = *target;
    delete target;
    size_--;
    return target_content.data();
}

template<typename T>
T LinkedList<T>::pop_back() {
    if (empty())
        throw std::out_of_range("List is empty!");
    if (size_ == 1) {
        auto last = *head;
        delete head;
        head = nullptr;
        size_--;
        return last.data();
    } else {
        auto it = head;
        for (auto i = 1u; i < size() - 1; i++)
            it = it->next();
        auto last = *it->next();
        delete it->next();
        it->next(nullptr);
        size_--;
        return last.data();
    }
}

template<typename T>
T LinkedList<T>::pop_front() {
    if (empty())
        throw std::out_of_range("List is empty!");
    auto first = *head;
    auto it = head;
    head = head->next();
    delete it;
    size_--;
    return first.data();
}

template<typename T>
void LinkedList<T>::remove(const T &data) {
    if (head->data() == data) {
        delete_head();
    } else {
        auto previous = head;
        while (previous->next()->data() != data) {
            previous = previous->next();
        }
        auto it = previous->next();
        previous->next(it->next());
        delete it;
        size_--;
    }
}

template<typename T>
bool LinkedList<T>::empty() const {
    return size_ == 0u;
}

template<typename T>
bool LinkedList<T>::contains(const T &data) const {
    auto it = head;
    for (auto i = 1u; i < size_; i++) {
        if (it->data() == data)
            return true;
        else
            it = it->next();
    }
    return false;
}

template<typename T>
std::size_t LinkedList<T>::find(const T &data) const {
    auto it = head;
    for (auto i = 0u; i < size_; i++)
        if (it->data() == data)
            return i;
        else
            it = it->next();
    return size_;
}

template<typename T>
std::size_t LinkedList<T>::size() const {
    return size_;
}

}  //! namespace structures

#endif

