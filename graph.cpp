#include "graph.hpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// inicializa o grafo
Graph::Graph(int vertices, int arestas)
{
    this->vertices = vertices;
    this->arestas = arestas;
    criaGrafo();
}

// aloca memoria p/ o grafo
void Graph::criaGrafo()
{
    this->grafo = new vector<pair<int, int>>[max];
}

// transforma na representação par do vertice
int Graph::par(int val)
{
    return val * 10 + 2;
}
// transforma na representação impar do vertice
int Graph::impar(int val)
{
    return val * 10 + 1;
}

// cria arestas par e impar da origem para o destino com o comprimento
void Graph::addAresta(int O, int D, int comp)
{
    this->grafo[par(O)].push_back(pair<int, int>(impar(D), comp));
    this->grafo[par(D)].push_back(pair<int, int>(impar(O), comp));
    this->grafo[impar(O)].push_back(pair<int, int>(par(D), comp));
    this->grafo[impar(D)].push_back(pair<int, int>(par(O), comp));
}

// aplica Dijkstra e retorna o menor caminho par
int Graph::menorCaminho(int origem)
{
    // fila de prioridade
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaP;
    // vetor de comprimento das estradas
    vector<int> comp(max, 100000);
    filaP.push(pair<int, int>(0, par(origem)));
    // distancia do vertice pra ele mesmo é 0
    comp[par(origem)] = 0;

    while (filaP.size() > 0)
    {
        int O = filaP.top().second;
        filaP.pop();
        // itera sobre os vizinhos de O
        vector<pair<int, int>>::iterator it;
        for (it = this->grafo[O].begin(); it < this->grafo[O].end(); it++)
        {
            int D = it->first;
            int dist = it->second;
            // se a distancia for par e menor do que o valor atual
            if ((dist % 2 == 0) && (comp[D] > comp[O] + dist))
            {
                comp[D] = comp[O] + dist;
                filaP.push(pair<int, int>(comp[D], D));
            }
        }
    }
    return (comp[par(this->vertices - 1)] == 100000) ? -1 : comp[par(this->vertices - 1)];
}
