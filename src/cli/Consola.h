#ifndef CONSOLA_H
#define CONSOLA_H

#include <string>
#include "Comandos.h"

class Consola {
private:
    Comandos comandos;

public:
    // Inicia el menú principal
    void iniciar();

    // Muestra la bienvenida
    void mostrarBienvenida();
};

#endif
