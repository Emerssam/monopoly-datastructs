#include "Consola.h"
#include <iostream>

void Consola::mostrarBienvenida() {
    std::cout << "============================" << std::endl;
    std::cout << "    MONOPOLY (Proyecto EDD) " << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Escribe 'ayuda' para ver los comandos disponibles." << std::endl;
    std::cout << std::endl;
}

void Consola::iniciar() {
    mostrarBienvenida();

    // Registrar comandos extra
    comandos.registrarComando("iniciar", []() {
        std::cout << "Iniciando nueva partida..." << std::endl;
        // Aquí luego se llamará al objeto Juego
    });

    comandos.registrarComando("tirar", []() {
        std::cout << "Tiras los dados...  (resultado simulado)" << std::endl;
        // Luego se conectará con Dado.cpp
    });

    comandos.registrarComando("comprar", []() {
        std::cout << "Intentas comprar la propiedad donde estás." << std::endl;
        // Luego se conecta con Jugador y Propiedad
    });

    // Bucle principal
    std::string entrada;
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, entrada);
        comandos.ejecutar(entrada);
    }
}
