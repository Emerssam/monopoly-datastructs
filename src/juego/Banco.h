#ifndef "BANCO_H"
#define "BANCO_H"

#include <string>
#include <unordered_map>

class Banco {
private:
    std::unordered_map<std::string, int> cuentas;

public:
    Banco();

    void crearCuenta(const std::string& jugador, int montoInicial = 1500);
    bool transFerir(const std::string& origen, const std::string& destino, int monto);
    bool pagarBanco(const std::string& jugador, int monto);
    bool recibirBanco(const std::string& jugador, int monto);
    int gtSaldo(const std::string& jugador) const;

};
#endif