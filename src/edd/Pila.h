#ifndef PILA_H
#define PILA_H
#pragma once
/*
  Pila.h — TAD Pila (LIFO) genérica para snapshots/undo en el Monopoly.
  Implementa el tipo abstracto Pila utilizando std::stack internamente,
  cumpliendo con las operaciones requeridas: apilar, desapilar, vacia y limpiar.

  Aunque se apoya en STL, mantiene una interfaz de TAD propio.
*/

#include <stack>
#include <utility>

namespace edd {

    template <typename T>
    class Pila {
    private:
        // Nodo lógico (representa cada elemento apilado, útil para documentación del TAD)
        struct Nodo {
            T dato;
            Nodo(const T& d) : dato(d) {}
            Nodo(T&& d) : dato(std::move(d)) {}
        };

        std::stack<Nodo> pila_;  // pila interna STL

    public:
        // Constructor y destructor por defecto
        Pila() = default;
        ~Pila() = default;

        // Constructor de copia y movimiento
        Pila(const Pila& other) = default;
        Pila(Pila&& other) noexcept = default;
        Pila& operator=(const Pila& other) = default;
        Pila& operator=(Pila&& other) noexcept = default;

        // @pre  ---
        // @post Inserta un elemento en el tope de la pila.
        void apilar(const T& valor) {
            pila_.emplace(valor);
        }

        // @pre  ---
        // @post Inserta un elemento movido en el tope de la pila.
        void apilar(T&& valor) {
            pila_.emplace(std::move(valor));
        }

        // @pre  La pila puede estar vacía.
        // @post Si hay elementos, desapila el tope y lo devuelve en 'out'; retorna true.
        //       Si está vacía, retorna false.
        bool desapilar(T& out) noexcept {
            if (pila_.empty()) return false;
            out = std::move(pila_.top().dato);
            pila_.pop();
            return true;
        }

        // @pre  ---
        // @post Libera todos los elementos de la pila.
        void limpiar() noexcept {
            while (!pila_.empty()) pila_.pop();
        }

        // @pre  ---
        // @post Retorna true si la pila está vacía.
        bool vacia() const noexcept {
            return pila_.empty();
        }
    };

}
#endif //PILA_H
