#include <Servo.h>  // Библиотека для работы с сервоприводом
Servo myServo;  // Объект сервопривода
void setup() {
  Serial.begin(9600);       // Запуск Serial порта
  myServo.attach(9);        // Сервопривод подключён к пину 9
  myServo.write(90);        // Начальное положение — 90 градусов
  Serial.println("Введите угол (0-180):");
}
void loop() {
  if (Serial.available()) {         // Если есть данные в Serial
    int angle = Serial.parseInt();  // Считываем число
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);         // Поворачиваем сервопривод
      Serial.print("Угол: ");
      Serial.println(angle);        // Выводим угол в Serial
    } else {
      Serial.println("Ошибка: введите 0-180");  // Неверный диапазон
    }
  }
}
