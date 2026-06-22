#include <iostream>
#include <algorithm>
int main() {
    int64_t n;
    std::cin >> n; // кол-во запросов
    for (int64_t i = 0; i < n; i++) {
        int64_t a, b, x, y;
        std::cin >> a >> b >> x >> y; // a-контроллеров A, b-контроллеров B, x-модулей 1, y-модулей 2
        int64_t v1 = std::min(a, x) + std::min(b, x); // A+м1 и B+м1 одновременно
        int64_t v2 = std::min(a, y) + std::min(b, x); // A+м2 и B+м1 одновременно
        int64_t v3 = std::min(a, x);                  // только A+м1
        int64_t v4 = std::min(a, y);                  // только A+м2
        int64_t v5 = std::min(b, x);                  // только B+м1

        // выводим максимум из всех допустимых комбинаций
        std::cout << std::max({v1, v2, v3, v4, v5}) << " ";
    }
    return 0;
}