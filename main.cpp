#include <iostream>
#include <stdexcept>
#include <cstring>
#include "testar_portas.hpp"
#include "globals.hpp"

using namespace std;

bool modo_teste;

int argc_1;
char **argv_1;

// DEclarado aqui para usar argc e argv
bool parseArguments()
{
    bool syntax_ta_okay = true;
    bool has_argument = (argc_1 == 2);

    if (has_argument)
    {
        modo_teste = (argc_1 == 2 && (strcmp(argv_1[1], "t") == 0 || strcmp(argv_1[1], "test") == 0));
        if (argc_1 == 2 && !modo_teste)
            syntax_ta_okay = false;
    }

    return (argc_1 != 2 || (modo_teste && syntax_ta_okay));
}

int main(int argc, char *argv[])
{
    argc_1 = argc;
    argv_1 = argv;

    if (!parseArguments())
    {
        cout << "Uso: " << argv[0] << " <t ou test (opcional)>" << endl;
        return 1;
    }

    if (modo_teste)
    {
        try
        {
            testar_todas_portas();
            cout << "passou todos os testes" << endl;
        }
        catch (logic_error &e)
        {
            cout << "Erro: " << e.what() << endl;
            return 1;
        }
    }

    return 0;
}
