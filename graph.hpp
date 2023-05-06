#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

using namespace std;

class Graph
{
public:
    int vertices;
    int arestas;
    int max = 100003;
    // lista de adj que representa o grafo
    vector<pair<int, int>> *grafo;

    Graph() {}
    Graph(int vertices, int arestas);
    void criaGrafo();
    void addAresta(int O, int D, int comp);
    int menorCaminho(int vertAtual);
    int par(int val);
    int impar(int val);
};

#endif // GRAPH_HPP