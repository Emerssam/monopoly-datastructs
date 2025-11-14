#ifndef ESTADO_H
#define ESTADO_H

#include <string>
#include <vector>
#include <unordered_map>

struct Jugador {
  std::string nombre;
  int posicion;
  bool enCarcel;

};

class Estado {
  private:
    std::vector<Jugador> jugadors;
    int turnoActual;
    std::unordered_map<std::string, std::string> propiedades;

public:
  Estado();

  void agregarJugador(const std::string& nombre);
  jugador& getJugadorActual();
  void siguienteTurno();
  int getTurnoActual() const;
  std::vector<jugador>& getJugadors() const;
  void asignarPropiedad(const std::string& propiedad, const std::string& jugador);
  std::string getPropietario(const std::string& propiedad)
};

#endif //ESTADO_H
