#define GREEN_PIN 9    // зелёный — двери открыты
#define RED_PIN   5    // красный — двери закрыты
#define SENSOR    A0   // фоторезистор
const unsigned long OPEN_TIME = 3000; // время открытия (мс)
void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  Serial.begin(9600);
  // По умолчанию двери закрыты
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
}
void setDoor(bool open) {
  // Одна функция управляет дверью: true — открыть, false — закрыть
  digitalWrite(GREEN_PIN, open ? HIGH : LOW);
  digitalWrite(RED_PIN,   open ? LOW  : HIGH);
  Serial.println(open ? "Двери открываются" : "Двери закрываются");
}
void loop() {
  int val = analogRead(SENSOR);
  Serial.print("Фоторезистор: ");
  Serial.println(val);
  if (val < 512) {
    // Человек рядом — открыть
    setDoor(true);
    delay(OPEN_TIME);

    // Проверить ещё раз — ушёл ли?
    if (analogRead(SENSOR) >= 512)
      setDoor(false);
    else
      Serial.println("Человек всё ещё рядом");
  } else {
    setDoor(false);
  }
  delay(500);
}
