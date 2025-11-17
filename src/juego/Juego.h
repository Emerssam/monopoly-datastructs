#ifndef JUEGO_H
#define JUEGO_H

#include "Banco.h"
#include "Dado.h"
#include "Estado.h"
#include "Reglas.h"
#include "Turnos.h"

class Juego {
private:
    Banco banco;
    Dado dado1, dado2;
    Estado estado;
    Reglas reglas;
    Turnos turnos;

public:
    Juego();
    void inicializarJugadores();
    void jugarTurno();
    void mostrarEstado();
    bool haTerminado();
};

#endif
