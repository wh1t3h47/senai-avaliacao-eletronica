using namespace std;

bool porta_not(bool entrada_a)
{
    return !entrada_a;
}

bool porta_or(bool entrada_a, bool entrada_b)
{
    return entrada_a || entrada_b;
}

bool porta_nor(bool entrada_a, bool entrada_b)
{
    return porta_not(porta_or(entrada_a, entrada_b));
}

bool porta_and(bool entrada_a, bool entrada_b)
{
    return entrada_a && entrada_b;
}

bool porta_nand(bool entrada_a, bool entrada_b)
{
    return porta_not(porta_and(entrada_a, entrada_b));
}
