#include <iostream>
#include "graph.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int cidades = 0;
    int estradas = 0;
    int origemId = 0;
    int destinoId = 0;
    int comprimento = 0;

    cin >> cidades >> estradas;

    // estratégia de robustez
    if (cidades > 10000 || cidades < 2)
    {
        cerr << "Erro: numero de cidades invalido" << endl;
        exit(1);
    }

    if (estradas > 100000 || estradas < 1)
    {
        cerr << "Erro: numero de estradas invalido" << endl;
        exit(1);
    }

    // inicializa o grafo
    Graph G(cidades + 1, estradas);

    // leitura da linha de comando
    for (int i = 0; i < estradas; i++)
    {
        cin >> origemId >> destinoId >> comprimento;

        if (origemId > cidades || destinoId > cidades)
        {
            cerr << "Erro: id de cidade invalido" << endl;
            exit(1);
        }
        // add arestas ao grafo
        G.addAresta(origemId, destinoId, comprimento);
    }
    // roda Dijkstra e acha o menor caminho
    int menor = G.menorCaminho(1);
    cout << menor << endl;

    return 0;
}