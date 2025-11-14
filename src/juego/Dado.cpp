#include "Dado.h"
#include <cstdlib>
#include <ctime>

int Dado::lanzar() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  return (std::rand() % 6) + 1;

}
