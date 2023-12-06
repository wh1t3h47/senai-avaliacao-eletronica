#include "portas.hpp"
#include <utility>

using namespace std;

pair<bool, bool> circuito_enable(bool entrada_a, bool entrada_enable, bool entrada_b)
{
  bool saida_a = porta_and(entrada_a, entrada_enable);
  bool saida_b = porta_and(entrada_enable, entrada_b);
  return pair<bool, bool>(saida_a, saida_b);
}
