#include "portas.hpp"

bool[2] circuito_enable(bool entrada_a, bool entrada_enable, bool entrada_b) {
  bool saida_a = porta_and(entrada_a, enable);
  bool saida_b = porta_and(enable, entrada_b);
  return [saida_a, saida_b]
}