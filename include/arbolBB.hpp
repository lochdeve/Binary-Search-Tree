#ifndef __ARBOLBB__
#define __ARBOLBB__
#include "nodoBB.hpp"
#include "queue_l_t.hpp"

template <class clave>
class ArbolBB {
   public:
    ArbolBB();
    ~ArbolBB();
    void eliminarArbol(NodoBB<clave> *nodo);
    void InsertarRama(NodoBB<clave> *&nodo, clave dato);
    void Insertar(clave dato);
    void EliminarRama(NodoBB<clave> *&nodo, clave clave_dada);
    void Eliminar(clave clave_dada);
    void sustituye(NodoBB<clave> *&, NodoBB<clave> *&);
    void write();
    void Podar(NodoBB<clave> *&nodo);
    bool EsVacio(NodoBB<clave> *nodo);
    bool EsHoja(NodoBB<clave> *nodo);
    NodoBB<clave> *&get_raiz();
    NodoBB<clave> *buscarama(NodoBB<clave> *nodo, clave clave_dada);
    NodoBB<clave> *buscar(clave clave_dada);

   private:
    NodoBB<clave> *raiz_;
};

template <class clave>
ArbolBB<clave>::~ArbolBB() {
    queue_l_t<std::pair<NodoBB<clave> *, int>> cola;
    std::pair<NodoBB<clave> *, int> pareja;
    pair<NodoBB<clave> *, int> pareja2;
    int nivel = 0, nivel_actual = 0;
    pareja.first = raiz_;
    pareja.second = nivel;
    cola.push(pareja);
    while (!cola.empty()) {
        pareja2 = cola.front();
        pareja = cola.front();
        cola.pop();
        if (pareja.second > nivel_actual) {
            nivel_actual = pareja.second;  //Incremento de nivel
        }
        if (pareja.first) {
            pareja.first = pareja.first->get_izquierdo();
            pareja.second = pareja.second + 1;
            cola.push(pareja);
            pareja2.first = pareja2.first->get_derecho();
            pareja2.second = pareja2.second + 1;
            cola.push(pareja2);
        }
    }
}

template <class clave>
void ArbolBB<clave>::eliminarArbol(NodoBB<clave> *nodo) {
    if (nodo != NULL) {
        eliminarArbol(nodo->get_izquierdo());
        eliminarArbol(nodo->get_derecho());
        delete nodo;
    }
}

template <class clave>
ArbolBB<clave>::ArbolBB() {
    raiz_ = NULL;
}

template <class clave>
void ArbolBB<clave>::Insertar(clave dato) {
    InsertarRama(raiz_, dato);
}

template <class clave>
void ArbolBB<clave>::InsertarRama(NodoBB<clave> *&nodo, clave dato) {
    if (nodo == NULL)
        nodo = new NodoBB<clave>(dato);
    else if (dato < nodo->get_dato())
        InsertarRama(nodo->get_izquierdo(), dato);
    else if (dato > nodo->get_dato())
        InsertarRama(nodo->get_derecho(), dato);
    else
        return;
}

template <class clave>
void ArbolBB<clave>::Eliminar(clave clave_dada) {
    EliminarRama(raiz_, clave_dada);
}

template <class clave>
void ArbolBB<clave>::EliminarRama(NodoBB<clave> *&nodo, clave clave_dada) {
    if (nodo == NULL) return;
    if (clave_dada < nodo->get_dato())
        EliminarRama(nodo->get_izquierdo(), clave_dada);
    else if (clave_dada > nodo->get_dato())
        EliminarRama(nodo->get_derecho(), clave_dada);
    else {
        NodoBB<clave> *Eliminado = nodo;
        if (nodo->get_derecho() != NULL && nodo->get_izquierdo() != NULL)
            sustituye(Eliminado, nodo->get_izquierdo());
        else if (nodo->get_derecho() == NULL)
            nodo = nodo->get_izquierdo();
        else if (nodo->get_izquierdo() == NULL)
            nodo = nodo->get_derecho();
    }
}

template <class clave>
void ArbolBB<clave>::sustituye(NodoBB<clave> *&eliminado, NodoBB<clave> *&sust) {
    if (sust->get_derecho() != NULL)
        sustituye(eliminado, sust->get_derecho());
    else {
        eliminado->set_dato(sust->get_dato());
        eliminado = sust;
        sust = sust->get_izquierdo();
    }
}

template <class clave>
NodoBB<clave> *ArbolBB<clave>::buscar(clave clave_dada) { return buscarama(raiz_, clave_dada); }

template <class clave>
NodoBB<clave> *ArbolBB<clave>::buscarama(NodoBB<clave> *nodo, clave clave_dada) {
    if (nodo == NULL)
        return NULL;
    if (clave_dada == nodo->get_dato())
        return nodo;
    if (clave_dada < nodo->get_dato())
        return buscarama(nodo->get_izquierdo(), clave_dada);
    return buscarama(nodo->get_derecho(), clave_dada);
}

template <class clave>
void ArbolBB<clave>::write() {
    queue_l_t<std::pair<NodoBB<clave> *, int>> cola;
    std::pair<NodoBB<clave> *, int> pareja;
    int nivel = 0, nivel_actual = 0;
    if (raiz_ == NULL && nivel == 0) {
        std::cout << "Arbol vacio:" << std::endl;
    }
    std::cout << "\nNivel " << pareja.second << ":" << std::endl;
    pareja.first = raiz_;
    pareja.second = nivel;
    cola.push(pareja);
    while (!cola.empty()) {
        pair<NodoBB<clave> *, int> pareja2;
        pareja2 = cola.front();
        pareja = cola.front();
        cola.pop();
        if (pareja.second > nivel_actual) {
            nivel_actual = pareja.second;  //Incremento de nivel
            std::cout << "\nNivel " << pareja.second << ":" << std::endl;
        }
        if (pareja.first) {
            std::cout << " [" << pareja.first->get_dato() << "] ";
            pareja.first = pareja.first->get_izquierdo();
            pareja.second = pareja.second + 1;
            cola.push(pareja);
            pareja2.first = pareja2.first->get_derecho();
            pareja2.second = pareja2.second + 1;
            cola.push(pareja2);
        } else {
            std::cout << "[.] ";
        }
    }
    std::cout << std::endl;
}

template <class clave>
void ArbolBB<clave>::Podar(NodoBB<clave> *&nodo) {
    if (nodo == NULL) return;
    Podar(nodo->get_izquierdo());  // Podar subarbol izquierdo
    Podar(nodo->get_derecho());    // Podar subarbol derecho
    delete nodo;                   // Eliminar nodo
    nodo = NULL;
}

template <class clave>
bool ArbolBB<clave>::EsVacio(NodoBB<clave> *nodo) {
    return nodo == NULL;
}

template <class clave>
bool ArbolBB<clave>::EsHoja(NodoBB<clave> *nodo) {
    return !nodo->get_derecho() && !nodo->get_izquierdo();
}

template <class clave>
NodoBB<clave> *&ArbolBB<clave>::get_raiz() {
    return raiz_;
}
#endif