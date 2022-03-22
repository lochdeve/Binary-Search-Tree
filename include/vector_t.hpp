#ifndef _Vector
#define _Vector

#include <cassert>
#include <cstdio>
#include <iomanip>

using namespace std;
namespace AED {

template <class T>
class vector_t {
   private:
    T* v_;
    int sz_;

   public:
    vector_t(void) : v_(NULL),
                     sz_(0) {}

    vector_t(int sz) : v_(NULL),
                       sz_(sz) {
        crea_vector();
    }

    vector_t(const vector_t& v) : v_(NULL),
                                  sz_(v.sz_) {
        crea_vector();

        for (int i = 0; i < sz_; i++)
            v_[i] = v.v_[i];
    }

    vector_t& operator=(const vector_t& v) {
        resize(v.sz_);

        for (int i = 0; i < sz_; i++)
            v_[i] = v.v_[i];

        return *this;
    }

    ~vector_t(void) {
        destruye_vector();
    }

    void resize(int sz) {
        destruye_vector();
        sz_ = sz;
        crea_vector();
    }

    void swap(int i, int j, int modo) {
        T aux;
        aux = at(i);
        at(i) = at(j);
        at(j) = aux;
        if (modo == 1) {
            std::cout << "Comparamos posicion[" << i << "] con "
                      << "posicion[" << (j) << "] y se intercambian" << std::endl;
            std::cout << std::endl;
            write(std::cout);
        }
    }

    int size(void) const {
        return sz_;
    }

    const T& at(int pos) const {
        assert((pos < sz_) && ((pos >= 0)));

        return v_[pos];
    }

    T& at(int pos) {
        assert((pos < sz_) && ((pos >= 0)));

        return v_[pos];
    }

    const T& operator[](int pos) const {
        return at(pos);
    }

    T& operator[](int pos) {
        return at(pos);
    }

    ostream& write(ostream& os) const {
        for (int k = 0; k < size(); k++) {
            os << "[" << k << "]" << at(k) << " ";
        }
        os << std::endl;
        return os;
    }

   private:
    void crea_vector(void) {
        v_ = new T[sz_];
    }

    void destruye_vector(void) {
        if (v_ != NULL) {
            delete[] v_;
            v_ = NULL;
        }
    }
};

}  // namespace AED
#endif