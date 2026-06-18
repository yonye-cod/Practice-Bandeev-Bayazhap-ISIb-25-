#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> graph; // список смежности графа
std::vector<bool> visited;           // посещённые вершины

void DFS(int v) {
    visited[v] = true; // помечаем вершину как посещённую
    // обходим всех соседей
    for (int i = 0; i < (int)graph[v].size(); i++) {
        int ch = graph[v][i];
        if (!visited[ch]) // если сосед не посещён — идём в него
            DFS(ch);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m; // n - общее кол-во вершин, m - кол-во рёбер

    std::vector<std::pair<int,int>> edges(m); // храним все рёбра
    std::set<int> uniqueNodes;                // уникальные вершины из рёбер
    int maxNode = 0;                          // максимальный номер вершины

    // читаем рёбра
    for (int i = 0; i < m; i++) {
        std::cin >> edges[i].first >> edges[i].second;
        uniqueNodes.insert(edges[i].first);  // запоминаем вершину
        uniqueNodes.insert(edges[i].second); // запоминаем вершину
        if (edges[i].first > maxNode) maxNode = edges[i].first;
        if (edges[i].second > maxNode) maxNode = edges[i].second;
    }

    // выделяем память по максимальному номеру вершины
    graph.resize(maxNode + 1);
    visited.assign(maxNode + 1, false);

    // строим граф
    for (int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;
        graph[u].push_back(v); // ненаправленный — добавляем в обе стороны
        graph[v].push_back(u);
    }

    // запускаем DFS из каждой непосещённой вершины
    // каждый запуск = новая компонента
    int components = 0;
    for (int node : uniqueNodes) {
        if (!visited[node]) {
            DFS(node);
            components++;
        }
    }

    // изолированные вершины = N минус вершины которые есть в рёбрах
    // каждая изолированная = отдельная компонента
    int isolated = n - (int)uniqueNodes.size();
    components += isolated;

    // чтобы соединить k компонент нужно k-1 рёбер
    std::cout << components - 1 << std::endl;

    return 0;
}