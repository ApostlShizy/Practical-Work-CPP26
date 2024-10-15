#include<iostream>

class Monitor {

    class Window {
        int sizeW_y = 1;
        int sizeW_x = 1;
        int placeW_y = 0;
        int placeW_x = 0;
        friend Monitor;
    };

    Window paint;
    int monitor_Y = 50;
    int monitor_X = 80;

public:

    void move() {
        int temp_x, temp_y;
        std::cout << "\nEnter (x,y) : ";
        std::cin >> temp_x >> temp_y;
        if (temp_x > 0) {
            if (paint.sizeW_x + paint.placeW_x + temp_x > monitor_X) {
                std::cout << "\nCant move winow like that !";
                return;
            }
        }
        else if (temp_x < 0) {
            if (paint.placeW_x + temp_x < 0) {
                std::cout << "\nCant move winow like that !";
                return;
            }
        }
        if (temp_y > 0) {
            if (paint.sizeW_y + paint.placeW_y + temp_y > monitor_Y) {
                std::cout << "\nCant move winow like that !";
                return;
            }
        }
        else if (temp_y < 0) {
            if (paint.placeW_y + temp_y < 0) {
                std::cout << "\nCant move winow like that !";
                return;
            }
        }
        paint.placeW_x += temp_x;
        paint.placeW_y += temp_y;
    }

    void resize() {
        int temp_x;
        int temp_y;
        std::cout << "\nEnter (x,y) : ";
        std::cin >> temp_x >> temp_y;
        if (temp_x <= 0) {
            temp_x = 1;
        }
        else if (temp_x >= monitor_X) {
            temp_x = 79;
        }
        if (temp_y <= 0) {
            temp_y = 1;
        }
        else if (temp_y >= monitor_Y) {
            temp_y = 49;
        }
        if (temp_x + paint.placeW_x >= monitor_X) {
            std::cout << "\nCant resize window!";
            return;
        }
        if (temp_y + paint.placeW_y >= monitor_Y) {
            std::cout << "\nCant resize winwod!";
        }
        paint.sizeW_x = temp_x;
        paint.sizeW_y = temp_y;
    }

    void display() {
        std::cout << std::endl;
        for (int i = 0; i < monitor_Y; ++i) {
            for (int j = 0; j < monitor_X; ++j) {
                if ((i >= paint.placeW_y && i <= paint.sizeW_y + paint.placeW_y) && (j >= paint.placeW_x && j <= paint.sizeW_x + paint.placeW_x)) {
                    std::cout << "1 ";
                }
                else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }

};

int main() {
    Monitor first;
    std::string choice;
    while (choice != "close") {
        std::cout << "\nMake choice\nmove\nresize\ndisplay\nclose\nEnter : ";
        std::cin >> choice;
        if (choice == "move") {
            first.move();
        }
        else if (choice == "resize") {
            first.resize();
        }
        else if (choice == "display") {
            first.display();
        }
        else if (choice != "close") {
            std::cout << "\nInvalid option!";
        }
    }
}