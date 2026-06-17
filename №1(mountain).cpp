#include <iostream>
#include <vector>
#include <climits>

int n;                          // высота пирамиды
std::vector<std::vector<int>> pyramid;    // сама пирамида
int minSum = INT_MAX;           // минимальная сумма (изначально бесконечность)
std::vector<int> bestPath;           // лучший путь

void DFS(int row, int col, int currentSum, std::vector<int>& path) {
    // добавляем текущий элемент к сумме и пути
    currentSum += pyramid[row][col];
    path.push_back(pyramid[row][col]);

    // находим детей (соседей снизу)
    std::vector<std::pair<int,int>> children;
    if (row + 1 < n) {
        children.push_back({row + 1, col});     // левый сосед снизу
        children.push_back({row + 1, col + 1}); // правый сосед снизу
    }

    // если детей нет — мы на дне пирамиды
    if (children.empty()) {
        if (currentSum < minSum) {
            minSum = currentSum;   // обновляем минимум
            bestPath = path;       // запоминаем лучший путь
        }
    }

    // рекурсивно идём в каждого ребёнка
    for (int i = 0; i < (int)children.size(); i++) {
        std::pair<int,int> ch = children[i];
        DFS(ch.first, ch.second, currentSum, path);
    }

    // убираем текущий элемент из пути (возврат назад)
    path.pop_back();
}

int main() {
    std::cin >> n;

    // считываем пирамиду
    pyramid.resize(n);
    for (int i = 0; i < n; i++) {
        pyramid[i].resize(i + 1); // в строке i+1 элементов
        for (int j = 0; j <= i; j++)
            std::cin >> pyramid[i][j];
    }

    // запускаем DFS с вершины пирамиды (0, 0)
    std::vector<int> path;
    DFS(0, 0, 0, path);

    // выводим минимальную сумму и путь
    std::cout << minSum << std::endl;
    for (int x : bestPath)
        std::cout << x << " ";
    return 0;
}