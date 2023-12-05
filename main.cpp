#include <iostream>
#include <stdexcept>
#include "testar_portas.h"

using namespace std;


int main() {
    try {
    testar_todas_portas();
    cout << "passou todos os testes" << endl;
    } catch (logic_error &e) {
        cout << "Erro: " << e.what() << endl;
        return 1;
    }
    return 0;
}