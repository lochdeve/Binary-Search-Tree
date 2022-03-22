#ifndef __NodoBB__
#define __NodoBB__

template <class clave>
class NodoBB {
   public:
    NodoBB(clave dato, NodoBB<clave>* izda, NodoBB<clave>* drcha);
    NodoBB(clave);
    NodoBB();
    ~NodoBB();
    void Buscar(clave);
    void Insertar(clave);
    void Eliminar(clave);
    NodoBB<clave>*& get_derecho();
    NodoBB<clave>*& get_izquierdo();
    clave get_dato();
    void set_dato(clave);
    void set_derecho(NodoBB<clave>*);
    void set_izquierdo(NodoBB<clave>*);

   private:
    clave dato_;
    NodoBB<clave>* derecho_;
    NodoBB<clave>* izquierdo_;
    int nHijos_;
};

template <class clave>
NodoBB<clave>::NodoBB(clave dato, NodoBB<clave>* izda, NodoBB<clave>* drcha) {
    dato_ = dato;
    izquierdo_ = izda;
    derecho_ = drcha;
}

template <class clave>
NodoBB<clave>::NodoBB(clave dato) {
    dato_ = dato;
    izquierdo_ = nullptr;
    derecho_ = nullptr;
}

template <class clave>
NodoBB<clave>::NodoBB() {
    izquierdo_ = nullptr;
    derecho_ = nullptr;
}

template <class clave>
NodoBB<clave>::~NodoBB() {
    delete derecho_;
    derecho_ = nullptr;
    delete izquierdo_;
    izquierdo_ = nullptr;
}

template <class clave>
NodoBB<clave>*& NodoBB<clave>::get_derecho() {
    return derecho_;
}

template <class clave>
NodoBB<clave>*& NodoBB<clave>::get_izquierdo() {
    return izquierdo_;
}

template <class clave>
clave NodoBB<clave>::get_dato() {
    return dato_;
}

template <class clave>
void NodoBB<clave>::set_dato(clave dato) {
    dato_ = dato;
}

template <class clave>
void NodoBB<clave>::set_derecho(NodoBB<clave>* new_nodo) {
    derecho_ = new_nodo;
}

template <class clave>
void NodoBB<clave>::set_izquierdo(NodoBB<clave>* new_nodo) {
    izquierdo_ = new_nodo;
}
#endif
