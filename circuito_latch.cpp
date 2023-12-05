#include "circuito_enable.hpp"
#include "portas.hpp"

bool [2] circuito_latch(bool entrada_a,bool enable,bool entrada_b){
bool saidas_circuito_enable[2] = circuito_enable(entrada_a,enable,entrada_b);
bool saida_a_circuito_enable = saidas_circuito_enable[0];
bool saida_b_circuito_enable = saidas_circuito_enable[1];

}