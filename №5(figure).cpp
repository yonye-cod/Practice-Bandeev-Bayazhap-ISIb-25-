#include <iostream>
int main() {
    int64_t h, w;
    std::cin >> h >> w; // высота и ширина матрицы
    int64_t minRow = h, maxRow = -1, minCol = w, maxCol = -1; // границы фигуры
    for (int64_t i = 0; i < h; i++) {
        for (int64_t j = 0; j < w; j++) {
            int64_t val;
            std::cin >> val;
            if (val == 1) { // нашли точку фигуры
                if (i < minRow) minRow = i; // обновляем верхнюю границу
                if (i > maxRow) maxRow = i; // обновляем нижнюю границу
                if (j < minCol) minCol = j; // обновляем левую границу
                if (j > maxCol) maxCol = j; // обновляем правую границу
            }
        }
    }
    // выводим с отступом 1, чтобы фигура не касалась сторон прямоугольника
    std::cout << minRow - 1 << " " << minCol - 1 << " " << maxRow + 1 << " " << maxCol + 1 << std::endl;
    return 0;
}