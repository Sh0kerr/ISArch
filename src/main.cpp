#include <iostream>
#include <opencv2/opencv.hpp>

enum Estates 
{
    EWork,
    EProcessGraffiti,
    ERotateRight,
    ERotateLeft,
    EMoveForward,
};

// Класс для отправки команд
class CommandSender 
{
    public:
        void rotateRight(int time){
            cout << "rotate right" << endl;
        };
        void rotateLeft(int time){
            cout << "rotate left" << endl;
        };
        void moveForward(int time){
            cout << "move forward" << endl;
        };
};

// Определяет наличие граффити
class Detector 
{
    public:
        // Показывает существование граффити
        bool GraffitiExists() {};

        // Показывает "рассогласование" (?) угла
        bool hasDeltaAngle() {};

};

// Класс для определния объектов с изображения камеры
// 
// @property col1max    Показывает максимальный предел цвета 1
// @property col1min    Показывает минимальный предел цвета 1
// @property col2max    Показывает максимальный предел цвета 2
// @property col2min    Показывает минимальный предел цвета 2
// @property col3max    Показывает максимальный предел цвета 3
// @property col3min    Показывает минимальный предел цвета 3
class ColorConfiguration
{

    private:
        int col1max[3] = {0, 110, 153};
        int col1min[3] = {0, 110, 153};
        int col2max[3] = {0, 110, 153};
        int col2min[3] = {0, 110, 153};
        int col3max[3] = {0, 110, 153};
        int col3min[3] = {0, 110, 153};

    public:
        

};

// Пока хз зачем этот класс, мб понадобится
class Server
{

    private:
        // Текущий статус робота
        int robot_status;

    public:
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
    
};

// Класс для управления роботом
// 
// @property coord_x           Абсцисса робота
// @property coord_y           Ордината робота
// @property power_level       Уровень заряда робота
// @property materials_level   Уровень материалов для очистки граффити
class Robot 
{

    private:
        CommandSender commandsender;


        // Х координата робота
        int coord_x;
        // У координата робота
        int coord_y;
        // Текущий заряд робота
        int power_level;
        // Текущий уровень чистящих средств
        int materials_level;
        // Действие робота
        int state;

    public:

        Robot() 
        {
            state = EWork;
        }

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

        void processEvent()
        {
            switch(state)
            {
            case ERotateRight:
                commandsender.rotateRight(time);
                break;
                
            case ERotateLeft:
                commandsender.rotateLeft(time);
                break;

            case EMoveForward:
                commandsender.moveForward(time);

            case EProcessGraffiti:
                

            }
        }

};

// Пока хз, нужно ли внатурен
class Camera
{

    public:
        // Получение изображения
        void take_photo();
        // Отправка изображения
        void send_photo();

};

class Graffiti
{

    private:
        // Х координата граффити
        int coord_x;
        // У координата граффити
        int coord_y;

};

int main() {
    Robot r;
    r.run();
}
