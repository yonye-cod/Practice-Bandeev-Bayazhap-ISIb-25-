#include <Adafruit_NeoPixel.h>
#define LED_PIN    6    // Пин данных
#define LED_COUNT  64   // 8x8 = 64 светодиода
#define BRIGHTNESS 100  // Яркость (0–255)
#define WIDTH      8    // Ширина матрицы
// Создаём объект ленты
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Переводим координаты (x, y) в номер светодиода
// Змейка: чётные строки →, нечётные ←
int getIndex(int x, int y) {
  if (y % 2 == 0)
    return y * WIDTH + x;
  else
    return y * WIDTH + (WIDTH - 1 - x);
}
// Устанавливаем цвет пикселя по координатам
void setPixel(int x, int y, uint32_t color) {
  if (x >= 0 && x < 8 && y >= 0 && y < 8)
    strip.setPixelColor(getIndex(x, y), color);
}
void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Гасим все светодиоды при старте
}
void loop() {
  showHeart(3);      // Сердце на 3 секунды
  rainbowEffect(20); // Радуга
  showHeart(1);      // Сердце на 1 секунду
}
// Рисуем сердце на duration секунд
void showHeart(unsigned long duration) {
  uint8_t heart[8][8] = {
    {0,1,1,0,0,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0}
  };
  unsigned long start = millis();
  while (millis() - start < duration * 1000) {
    for (int y = 0; y < 8; y++)
      for (int x = 0; x < 8; x++)
        setPixel(x, y, heart[y][x] ? strip.Color(255, 0, 0) : 0);
    strip.show();
    delay(50);
  }
}
// Радужная волна по всей матрице
void rainbowEffect(int wait) {
  for (long hue = 0; hue < 5 * 65536; hue += 256) {
    for (int i = 0; i < LED_COUNT; i++) {
      // Каждый пиксель получает свой оттенок цвета
      uint32_t color = strip.gamma32(strip.ColorHSV(hue + i * 65536L / LED_COUNT));
      strip.setPixelColor(i, color);
    }
    strip.show();
    delay(wait);
  }
}