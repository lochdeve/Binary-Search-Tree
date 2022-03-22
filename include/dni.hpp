#ifndef __Dnier__
#define __Dnier__
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Dni {
   public:
    static int ncomparaciones_;

    Dni() {
        ncomparaciones_ = 0;
        dni_ = 1 + rand() % 9999999;
    }
    Dni(int value) : dni_(value) {}
    ~Dni() {}
    int get_comparaciones() {
        return ncomparaciones_;
    }

    int get_Dni() {
        return dni_;
    }

    operator unsigned long() const {
        return dni_;
    }

    bool operator<(const Dni& n) const {
        n.ncomparaciones_++;
        ncomparaciones_++;
        if (dni_ < n.dni_)
            return true;
        else
            return false;
    }

    bool operator<=(const Dni& n) const {
        n.ncomparaciones_++;
        ncomparaciones_++;
        if (dni_ <= n.dni_)
            return true;
        else
            return false;
    }

    bool operator>(const Dni& n) const {
        n.ncomparaciones_++;
        ncomparaciones_++;
        if (dni_ > n.dni_)
            return true;
        else
            return false;
    }

    bool operator>=(Dni& n) const {
        n.ncomparaciones_++;
        ncomparaciones_++;
        if (dni_ >= n.dni_)
            return true;
        else
            return false;
    }
    bool operator==(Dni& n) {
        n.ncomparaciones_++;
        ncomparaciones_++;
        return (dni_ == n.dni_);
    }

    //std::ostream& write(std::ostream&) const;

   private:
    unsigned long dni_;
};

#endif