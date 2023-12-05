#include <iostream>
#include <stdexcept>
#include "testar_portas.hpp"

using namespace std;


int main(int argc, char *argv[]) {
    if (argc != 0) {
        cout << "Uso: " << argv[0] << endl;
        return 1;
    }

    try {
    testar_todas_portas();
    cout << "passou todos os testes" << endl;
    } catch (logic_error &e) {
        cout << "Erro: " << e.what() << endl;
        return 1;
    }
    return 0;
}
