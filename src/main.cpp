#include <iostream>

class Server{

public:
    // Текущий статус робота
    int robot_status;

private:
    // Проверка статуса
    void status_check();
    // Конвертация изображения
    void img_to_bmp();
    // Вычисление координат
    void find_coords();
    // Создание маршрута
    void make_route();
    // Отправка маршрута
    void send_route();   
}

class Robot{

public:
    // Х координата робота
    int coord_x;
    // У координата робота
    int coord_y;
    // Текущий заряд робота
    int power_level;
    // Текущий уровень чистящих средств
    int materials_level;

private:
    // Вычисление времени движения и поворота робота
    void split_route();
    // Передача команд на RPI
    void interpret_command();
    // Движение вперед в течение заданного времени
    void go_forward();
    // Движение назад в течение заданного времени
    void go_backward();
    // Поворот направо в течение заданного времени
    void rotate_right();
    // Поворот налево в течение заданного времени
    void roate_left();
    // Включение двигателя
    bool engine_on();
    // Выключение двигателя
    bool engine_off();
    // Отправка статуса на сервер
    bool send_status();
}

class Camera{

private:
    // Получение изображения
    void take_photo();
    // Отправка изображения
    void send_photo();

}

class Graffiti{

public:
    // Х координата граффити
    int coord_x;
    // У координата граффити
    int coord_y;
}

int main() {

}
