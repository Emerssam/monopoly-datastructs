#include "Comandos.h"

Comandos::Comandos() {
    // Registrar comandos básicos
    registrarComando("ayuda", [this]() {
        mostrarComandos();
    });

    registrarComando("salir", []() {
        std::cout << "Saliendo del juego..." << std::endl;
        exit(0);
    });
}

void Comandos::registrarComando(const std::string& nombre, std::function<void()> accion) {
    comandos[nombre] = accion;
}

void Comandos::ejecutar(const std::string& entrada) {
    if (comandos.find(entrada) != comandos.end()) {
        comandos[entrada]();
    } else {
        std::cout << "Comando no reconocido. Escribe 'ayuda' para ver los disponibles." << std::endl;
    }
}

void Comandos::mostrarComandos() const {
    std::cout << "=== COMANDOS DISPONIBLES ===" << std::endl;
    for (const auto& [nombre, _] : comandos) {
        std::cout << "- " << nombre << std::endl;
    }
    std::cout << "============================" << std::endl;
}
