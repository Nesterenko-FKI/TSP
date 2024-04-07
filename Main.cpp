#include "Solver.cpp"

int main()
{
    Parser parser("tsp_100_1.txt");
    Solver solver(&parser);
    return 0;
}
