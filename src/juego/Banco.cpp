#include "Banco.h"
#include <iostream>

Banco::Banco() {}

void Banco::crearCuenta(const std::string& jugador, int MontoInicial) {
  cuentas[jugador] = MontoInicial;
}

bool Banco::transFerir(const std::string& origen, const std::string& destino, int monto); {
  if cuentas[origen] < monto) return false;
  cuentas[origen] -= monto;
  cuentas [destino] += monto;
  return true;
}

bool Banco::pagarBanco(const std::string& jugador, int monto); {
  if (cuentas[jugador] < monto) return false;
  cuantas[jugador] -= monto;
  return true;
}

int Banco::gtSaldo(const std::string& jugador) const; {
  auto it = cuentas.find(jugador);
  if (it != cuentas.end())
    return it->second;
  return 0;

}