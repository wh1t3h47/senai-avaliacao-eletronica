#include "circuito_enable.hpp"
#include "portas.hpp"
#include "globals.hpp"
#include <utility>

using namespace std;

pair<bool, bool> circuito_latch(bool entrada_a, bool enable, bool entrada_b)
{
    auto saidas_circuito_enable = circuito_enable(entrada_a, enable, entrada_b);

    // Liga as saidas do circuito de enable nas entradas do circuito de latch
    bool saida_a_circuito_enable = saidas_circuito_enable.first;
    bool saida_b_circuito_enable = saidas_circuito_enable.second;

    bool entrada_a_circuito_latch = saida_a_circuito_enable;
    bool entrada_b_circuito_latch = saida_b_circuito_enable;

    // recupera o estado anterior do flip flop
    auto FlipFlopState = getFlipFlopState();

    if (!enable)
    {
        // Comportamento indefinido (dependendo do CI usado)
        FlipFlopState.comportamento_indefinido = true;
    }
    else
    {
        // set e reset não podem ser ativados ao mesmo tempo
        // caso seja, coloque comportamento indefinido
        FlipFlopState.set = entrada_a_circuito_latch;
        FlipFlopState.reset = entrada_b_circuito_latch;
        FlipFlopState.comportamento_indefinido = (FlipFlopState.set != FlipFlopState.reset);
    }

    // Faz a ligação da saída do flip flop com as entradas
    // de cada nand (entrada b do primeiro e a do segundo)
    bool saida_a_circuito_latch = FlipFlopState.Q;
    bool saida_b_circuito_latch = FlipFlopState.Qn;

    saida_a_circuito_latch = porta_nand(saida_a_circuito_enable, saida_b_circuito_latch);
    saida_b_circuito_latch = porta_nand(saida_b_circuito_enable, saida_a_circuito_latch);

    FlipFlopState.Q = saida_a_circuito_latch;
    FlipFlopState.Qn = saida_b_circuito_latch;

    // Atualiza o estado do flip flop pra próxima execução
    setFlipFlopState(FlipFlopState);

    return pair<bool, bool>(saida_a_circuito_latch, saida_b_circuito_latch);
}
