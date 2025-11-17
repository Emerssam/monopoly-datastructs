#include "Juego.h"
#include <iostream>

Juego::Juego() {}

void Juego::inicializarJugadores() {
    int n;
    std::cout << "Ingrese cantidad de jugadores (2-4): ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; ++i) {
        std::string nombre;
        std::cout << "Nombre del jugador " << i + 1 << ": ";
        std::getline(std::cin, nombre);
        estado.agregarJugador(nombre);
        banco.crearCuenta(nombre);
    }
}

void Juego::jugarTurno() {
    Jugador& actual = estado.getJugadorActual();
    int d1 = dado1.lanzar();
    int d2 = dado2.lanzar();
    int avance = d1 + d2;

    std::cout << "\nTurno de " << actual.nombre << " 🎲 (" << d1 << " + " << d2 << ")\n";
    actual.posicion = (actual.posicion + avance) % 40;

    reglas.evaluarCasilla(actual, banco, estado);
    estado.siguienteTurno();
}

void Juego::mostrarEstado() {
    std::cout << "\n=== ESTADO DEL JUEGO ===\n";
    for (auto& j : estado.getJugadores()) {
        std::cout << j.nombre << " está en posición " << j.posicion
                  << " | Dinero: $" << banco.getSaldo(j.nombre) << "\n";
    }
}

bool Juego::haTerminado() {
    int jugadoresActivos = 0;
    for (auto& j : estado.getJugadores())
        if (banco.getSaldo(j.nombre) > 0) jugadoresActivos++;
    return jugadoresActivos <= 1;
}
