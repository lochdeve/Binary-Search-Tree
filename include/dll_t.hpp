#pragma once

#include <cassert>
#include <cstdio>
#include <iostream>

#include "dll_node_t.hpp"

using namespace std;

namespace AED {

template <class T>
class dll_t {
   private:
    dll_node_t<T>* head_;
    dll_node_t<T>* tail_;

    int sz_;

   public:
    dll_t(void);
    ~dll_t(void);

    void merge(dll_t<T>&, dll_t<T>&);
    T mayor_elemento(dll_t<T>& lista1);
    void insert_tail(dll_node_t<T>*);
    void insert_after(dll_node_t<T>*, dll_node_t<T>*);
    void insert_head(dll_node_t<T>*);

    dll_node_t<T>* extract_tail(void);
    dll_node_t<T>* extract_head(void);

    dll_node_t<T>* get_tail(void);
    dll_node_t<T>* get_head(void);

    bool empty(void);

    void remove(dll_node_t<T>*);

    int get_size(void);

    ostream& write(ostream& os);
};

template <class T>
dll_t<T>::dll_t(void) : head_(NULL),
                        tail_(NULL),
                        sz_(0) {
}

template <class T>
dll_t<T>::~dll_t(void) {
    dll_node_t<T>* aux = NULL;

    while (head_ != NULL) {
        aux = head_;
        head_ = head_->get_next();
        delete aux;
        aux = NULL;
    }
    sz_ = 0;
    head_ = NULL;
    tail_ = NULL;
}

template <class T>
void dll_t<T>::merge(dll_t<T>& lista1, dll_t<T>& lista2) {
    assert(!lista1.empty());
    assert(!lista2.empty());

    while (!lista1.empty() && !lista2.empty()) {
        if (lista1.get_head()->get_data() < lista2.get_head()->get_data()) {
            insert_tail(lista1.extract_head());

        } else {
            insert_tail(lista2.extract_head());
        }
    }
    while (!lista1.empty()) {
        insert_tail(lista1.extract_head());
    }
    while (!lista2.empty()) {
        insert_tail(lista2.extract_head());
    }
}

template <class T>
T dll_t<T>::mayor_elemento(dll_t<T>& lista1) {
    assert(!lista1.empty());
    assert(!empty());

    dll_node_t<T>* aux1 = lista1.get_head();
    dll_node_t<T>* aux2 = get_head();
    T mayor;

    while (!lista1.empty() && !empty()) {
        if (aux1->get_data() > aux2->get_data()) {
            aux2 = aux2->get_next();
            mayor = aux1->get_data();
            extract_head();
        } else {
            aux1 = aux1->get_next();
            mayor = aux2->get_data();
            lista1.extract_head();
        }
    }
    while (!lista1.empty()) {
        if (aux2->get_data() > aux1->get_data()) {
            mayor = aux2->get_data();
            aux1 = aux1->get_next();
        } else {
            mayor = aux1->get_data();
            aux2 = aux2->get_next();
        }
    }
    // while (!empty()) {
    //     if (aux2->get_data() > aux1->get_data()) {
    //         mayor = aux2->get_data();
    //         aux1 = aux1->get_next();
    //     } else {
    //         mayor = aux1->get_data();
    //         aux2 = aux2->get_next();
    //     }
    // }
    return mayor;
}

template <class T>
bool dll_t<T>::empty(void) {
    if (head_ == NULL) {
        assert(tail_ == NULL);
        assert(sz_ == 0);

        return true;
    } else
        return false;
}

template <class T>
void dll_t<T>::insert_head(dll_node_t<T>* nodo) {
    assert(nodo != NULL);

    if (empty()) {
        head_ = nodo;
        tail_ = head_;
    } else {
        head_->set_prev(nodo);
        nodo->set_next(head_);
        head_ = nodo;
    }
    sz_++;
}

template <class T>
void dll_t<T>::insert_tail(dll_node_t<T>* nodo) {
    assert(nodo != NULL);

    if (empty()) {
        head_ = nodo;
        tail_ = head_;
    } else {
        tail_->set_next(nodo);
        nodo->set_prev(tail_);
        tail_ = nodo;
    }

    sz_++;
}

template <class T>
void dll_t<T>::insert_after(dll_node_t<T>* nodo, dll_node_t<T>* previo) {
    assert(nodo != NULL);
    if (empty()) {
        head_ = nodo;
        tail_ = head_;
    } else if (previo->get_next() == NULL)
        insert_tail(nodo);
    else {
        nodo->set_next(previo->get_next());
        previo->set_next(nodo);
        nodo->set_prev(previo);
        nodo->get_next()->set_prev(nodo);
    }
    sz_++;
}

template <class T>
dll_node_t<T>* dll_t<T>::extract_tail(void) {
    assert(!empty());

    dll_node_t<T>* aux = tail_;

    tail_ = tail_->get_prev();

    if (tail_ != NULL)
        tail_->set_next(NULL);
    else
        head_ = NULL;

    sz_--;

    aux->set_next(NULL);
    aux->set_prev(NULL);

    return aux;
}

template <class T>
dll_node_t<T>* dll_t<T>::extract_head(void) {
    assert(!empty());

    dll_node_t<T>* aux = head_;

    head_ = head_->get_next();

    if (head_)
        head_->set_prev(NULL);
    else
        tail_ = NULL;

    sz_--;

    aux->set_next(NULL);
    aux->set_prev(NULL);

    return aux;
}

template <class T>
dll_node_t<T>* dll_t<T>::get_head(void) {
    return head_;
}

template <class T>
dll_node_t<T>* dll_t<T>::get_tail(void) {
    return tail_;
}

template <class T>
ostream& dll_t<T>::write(ostream& os) {
    dll_node_t<T>* aux = head_;
    std::cout << "Lista: ";
    while (aux != NULL) {
        aux->write(os);
        aux = aux->get_next();
    }
    os << "\n";
    return os;
}

template <class T>
void dll_t<T>::remove(dll_node_t<T>* nodo) {
    assert(nodo != NULL);

    if (nodo->get_prev() != NULL)
        nodo->get_prev()->set_next(nodo->get_next());
    else
        head_ = nodo->get_next();

    if (nodo->get_next() != NULL)
        nodo->get_next()->set_prev(nodo->get_prev());
    else
        tail_ = nodo->get_prev();

    delete nodo;

    sz_--;
}

template <class T>
int dll_t<T>::get_size(void) {
    return sz_;
}
}  // namespace AED
