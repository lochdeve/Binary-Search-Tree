#pragma once

#include <cassert>
#include <iomanip>
#include <iostream>

#include "dll_t.hpp"

using namespace std;

template <class T>
class queue_l_t {
   private:
    AED::dll_t<T> l_;

   public:
    queue_l_t(void) : l_() {}

    ~queue_l_t(void) {}

    bool empty(void) {
        return l_.empty();
    }

    int size(void) {
        return l_.get_size();
    }

    T front(void) {
        assert(!empty());

        AED::dll_node_t<T>* node = l_.get_tail();
        T data = node->get_data();
        return (data);
    }

    T back(void) {
        assert(!empty());

        AED::dll_node_t<T>* node = l_.get_head();
        T data = node->get_data();
        return (data);
    }

    void pop(void) {
        assert(!empty());

        AED::dll_node_t<T>* node = l_.extract_tail();
        delete node;
    }

    void push(T dato) {
        AED::dll_node_t<T>* node = new AED::dll_node_t<T>(dato);
        l_.insert_head(node);
    }

    ostream& write(ostream& os) {
        AED::dll_node_t<T>* aux = l_.get_head();

        while (aux != NULL) {
            os << setw(4) << aux->get_data();
            aux = aux->get_next();
        }

        os << endl;

        return os;
    }
};
