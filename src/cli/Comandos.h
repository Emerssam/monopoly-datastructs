#ifndef COMANDOS_H
#define COMANDOS_H

#include <string>
#include <map>
#include <functional>
#include <iostream>

class Comandos {
private:
    std::map<std::string, std::function<void()>> comandos;

public:
    // Constructor
    Comandos();

    // Agrega un nuevo comando con su función
    void registrarComando(const std::string& nombre, std::function<void()> accion);

    // Ejecuta un comando si existe
    void ejecutar(const std::string& entrada);

    // Muestra los comandos disponibles
    void mostrarComandos() const;
};

#endif
