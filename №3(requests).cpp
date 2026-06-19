#include <iostream>
#include <vector>
std::vector<int64_t> bit; // массив дерева Фенвика
int64_t n;                // количество улиц
// добавляем val к элементу с индексом i
void update(int64_t i, int64_t val) {
    for (; i <= n; i += i & (-i)) // идём вверх, прибавляя младший бит
        bit[i] += val;
}
// сумма от 1 до i
int64_t query(int64_t i) {
    int64_t s = 0;
    for (; i > 0; i -= i & (-i)) // идём вниз, вычитая младший бит
        s += bit[i];
    return s;
}
int main() {
    int64_t k;
    std::cin >> n >> k; // n - кол-во улиц, k - кол-во запросов
    bit.assign(n + 1, 0); // инициализируем массив нулями
    for (int64_t i = 0; i < k; i++) {
        int64_t type;
        std::cin >> type;
        if (type == 1) {
            // запрос типа 1: обновление — добавить val снега на улицу idx
            int64_t idx, val;
            std::cin >> idx >> val;
            update(idx, val);
        } else {
            // запрос типа 2: сумма снега на улицах от u до r
            int64_t u, r;
            std::cin >> u >> r;
            std::cout << query(r) - query(u - 1) << "\n";
        }
    }
}