import cv2
import numpy as np

# Загружаем изображение
image = cv2.imread("test_2.jpg")

# Размываем и переводим в HSV
blurred = cv2.GaussianBlur(image, (11, 11), 0)
hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

# Маска зелёного цвета
green_mask = cv2.inRange(hsv, np.array((36, 25, 25)), np.array((70, 255, 255)))

# Находим все контуры
contours, _ = cv2.findContours(green_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Для каждого зелёного объекта рисуем центр
for contour in contours:
    x, y, w, h = cv2.boundingRect(contour)
    center_x = int(x + w / 2)
    center_y = int(y + h / 2)
    # Красная точка в центре
    cv2.circle(image, (center_x, center_y), 10, (0, 0, 255), -1)

cv2.imshow("Result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
