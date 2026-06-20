#include <iostream>
#include <vector>
#include <string>
int main() {
    int64_t n, k;
    std::cin >> n >> k; // n - длина слова, k - кол-во раз шифрования
    std::vector<int64_t> p(n + 1);
    for (int64_t i = 1; i <= n; i++)
        std::cin >> p[i]; // читаем перестановку
    std::string word;
    std::cin >> word; // читаем зашифрованное слово
    // применяем обратную перестановку k раз
    for (int64_t step = 0; step < k; step++) {
        std::string temp(n, ' ');
        for (int64_t i = 1; i <= n; i++)
            temp[p[i] - 1] = word[i - 1]; // буква с позиции i идёт обратно на позицию p[i]
        word = temp;
    }
    std::cout << word << "\n"; // выводим исходное слово
}