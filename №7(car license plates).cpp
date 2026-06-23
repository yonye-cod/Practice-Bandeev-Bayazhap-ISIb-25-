#include <iostream>
#include <string>
int main() {
    std::string s;
    std::cin >> s; // читаем строку из 6 символов
    // проверяем формат: 1 заглавная буква, 3 цифры, 2 заглавные буквы
    if (std::isupper(s[0]) && // первый символ - заглавная буква
        std::isdigit(s[1]) && // второй символ - цифра
        std::isdigit(s[2]) && // третий символ - цифра
        std::isdigit(s[3]) && // четвёртый символ - цифра
        std::isupper(s[4]) && // пятый символ - заглавная буква
        std::isupper(s[5])) { // шестой символ - заглавная буква
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}