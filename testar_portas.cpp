#include <stdexcept>
#include "portas.h"
using namespace std;

void testar_porta_and() {
    // 0 e 0 = 0
    bool resultado = porta_and(false, false);
    if (resultado) {
        throw logic_error("Tabela verdade AND falhou, false e false resultou em true, esperava false");
    }

    // 0 e 1 = 0
    resultado = porta_and(false, true);
    if (resultado) {
        throw logic_error("Tabela verdade AND falhou, false e true resultou em true, esperava false");
    }

    // 1 e 0 = 0
    resultado = porta_and(true, false);
    if (resultado) {
        throw logic_error("Tabela verdade AND falhou, true e false resultou em true, esperava false");
    }

    // 1 e 1 = 1
    resultado = porta_and(true, true);
    if (!resultado) {
        throw logic_error("Tabela verdade AND falhou, true e true resultou em false, esperava true");
    }
}

void testar_porta_nand() {
    // 0 e 0 = 1
    bool resultado = porta_nand(false, false);
    if (!resultado) {
        throw logic_error("Tabela verdade NAND falhou, false e false resultou em false, esperava true");
    }

    // 0 e 1 = 1
    resultado = porta_nand(false, true);
    if (!resultado) {
        throw logic_error("Tabela verdade NAND falhou, false e true resultou em false, esperava true");
    }

    // 1 e 0 = 1
    resultado = porta_nand(true, false);
    if (!resultado) {
        throw logic_error("Tabela verdade NAND falhou, true e false resultou em false, esperava true");
    }

    // 1 e 1 = 0
    resultado = porta_nand(true, true);
    if (resultado) {
        throw logic_error("Tabela verdade NAND falhou, true e true resultou em true, esperava false");
    }
}

void testar_porta_nor() {
    // 0 ou 0 = 1
    bool resultado = porta_nor(false, false);
    if (!resultado) {
        throw logic_error("Tabela verdade NOR falhou, false ou false resultou em false, esperava true");
    }

    // 0 ou 1 = 0
    resultado = porta_nor(false, true);
    if (resultado) {
        throw logic_error("Tabela verdade NOR falhou, false ou true resultou em true, esperava false");
    }

    // 1 ou 0 = 0
    resultado = porta_nor(true, false);
    if (resultado) {
        throw logic_error("Tabela verdade NOR falhou, true ou false resultou em true, esperava false");
    }

    // 1 ou 1 = 0
    resultado = porta_nor(true, true);
    if (resultado) {
        throw logic_error("Tabela verdade NOR falhou, true ou true resultou em true, esperava false");
    }
}

void testar_porta_not() {
    // NOT de 0 = 1
    bool resultado = porta_not(false);
    if (!resultado) {
        throw logic_error("Tabela verdade NOT falhou, NOT de false resultou em false, esperava true");
    }

    // NOT de 1 = 0
    resultado = porta_not(true);
    if (resultado) {
        throw logic_error("Tabela verdade NOT falhou, NOT de true resultou em true, esperava false");
    }
}

void testar_todas_portas() {
    testar_porta_and();
    testar_porta_nand();
    testar_porta_nor();
    testar_porta_not();
}