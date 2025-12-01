#include "iGraphics.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
#include <cctype>
#include <string>

using namespace std;

class TrafficLight {
private:
    char currentLight = 'G';

public:
    TrafficLight() {}

    void setColor(char color) {
        currentLight = color;
    }

    char getColor() const {
        return currentLight;
    }

    void draw() {
        // lightPole
        iSetColor(65, 65, 65);
        iFilledRectangle(750.0, 600.0 - (275.0 + 225.0), 16.0, 225.0);

        // lightBase
        iSetColor(45, 45, 45);
        iFilledRectangle(717.0, 600.0 - (492.0 + 28.0), 82.0, 28.0);

        // lightBox
        iSetColor(25, 25, 25);
        double box_bottom = 600.0 - (100.0 + 255.0);
        iFilledRectangle(715.0, box_bottom, 72.0, 255.0);
        iSetColor(100, 100, 100);
        iRectangle(715.0, box_bottom, 72.0, 255.0);

        // redVisor
        iSetColor(25, 25, 25);
        iFilledRectangle(714.0, 600.0 - (105.0 + 14.0), 72.0, 14.0);

        // yellowVisor
        iSetColor(25, 25, 25);
        iFilledRectangle(714.0, 600.0 - (185.0 + 14.0), 72.0, 14.0);

        // greenVisor
        iSetColor(25, 25, 25);
        iFilledRectangle(714.0, 600.0 - (265.0 + 14.0), 72.0, 14.0);

        // redLight
        double red_center_x = 724.0 + 29.0;
        double red_center_y_sf = 122.0 + 29.0;
        double red_center_y_ig = 600.0 - red_center_y_sf;
        iSetColor(180, 0, 0);
        iCircle(red_center_x, red_center_y_ig, 29.0);
        if (currentLight == 'R') {
            iSetColor(255, 50, 50);
            iFilledCircle(red_center_x, red_center_y_ig, 29.0);
            iSetColor(255, 100, 100);
            iFilledCircle(red_center_x, red_center_y_ig, 23.0);
        }

        // yellowLight
        double yellow_center_x = 724.0 + 29.0;
        double yellow_center_y_sf = 202.0 + 29.0;
        double yellow_center_y_ig = 600.0 - yellow_center_y_sf;
        iSetColor(180, 180, 0);
        iCircle(yellow_center_x, yellow_center_y_ig, 29.0);
        if (currentLight == 'Y') {
            iSetColor(255, 255, 50);
            iFilledCircle(yellow_center_x, yellow_center_y_ig, 29.0);
            iSetColor(255, 255, 100);
            iFilledCircle(yellow_center_x, yellow_center_y_ig, 23.0);
        }

        // greenLight
        double green_center_x = 724.0 + 29.0;
        double green_center_y_sf = 282.0 + 29.0;
        double green_center_y_ig = 600.0 - green_center_y_sf;
        iSetColor(0, 120, 0);
        iCircle(green_center_x, green_center_y_ig, 29.0);
        if (currentLight == 'G') {
            iSetColor(50, 255, 50);
            iFilledCircle(green_center_x, green_center_y_ig, 29.0);
            iSetColor(100, 255, 100);
            iFilledCircle(green_center_x, green_center_y_ig, 23.0);
        }
    }
};

class Road {
public:
    Road() {}

    void draw() {
        // roadShape
        iSetColor(90, 90, 90);
        iFilledRectangle(0.0, 600.0 - (395.0 + 110.0), 800.0, 110.0);

        // laneDashes
        for (int i = 0; i < 16; ++i) {
            iSetColor(255, 255, 255);
            iFilledRectangle(double(i * 50 + 10), 600.0 - (447.0 + 6.0), 35.0, 6.0);
        }

        // zebraStripes
        for (int i = 0; i < 6; ++i) {
            iSetColor(255, 255, 255);
            iFilledRectangle(710.0 + double(i * 12), 600.0 - (395.0 + 110.0), 8.0, 110.0);
        }
    }
};

class Car {
private:
    unsigned int carTexture;
    double carX;
    double stopPos;
    double currentSpeed = 0.0;
    bool hasPassedLight = false;
    const double car_width = 200.0;
    const double car_height = 100.0;

public:
    Car(double stop) : carX(-150.0), stopPos(stop) {
        carTexture = iLoadImage("file/car.png");
    }

    void update(double dt, char light) {
        currentSpeed = 0.0;
        if (light == 'G') {
            currentSpeed = 280.0;
        } else if (light == 'Y') {
            currentSpeed = 130.0;
        } else if (light == 'R') {
            if (!hasPassedLight && carX < stopPos) {
                currentSpeed = 130.0; // Approach slowly if not passed
            } else if (hasPassedLight) {
                currentSpeed = 130.0; // Continue if already passed
            }
        }

        double newX = carX + currentSpeed * dt;
        if (light == 'R' && !hasPassedLight && newX > stopPos) {
            newX = stopPos;
            currentSpeed = 0.0;
        }
        carX = newX;

        // Update hasPassedLight
        if (carX > stopPos + 50.0) { // Buffer to detect passing
            hasPassedLight = true;
        }
        if (carX < 0.0) { // When looping back
            hasPassedLight = false;
        }

        if (carX > 800.0 + 150.0) {
            carX = -150.0;
            hasPassedLight = false;
        }
    }

    string getStatus() const {
        if (currentSpeed > 200.0) {
            return "Car is moving fast!";
        } else if (currentSpeed > 0.0) {
            return "Car is moving slowly...";
        } else {
            return "Car stopped at red light.";
        }
    }

    void draw() {
        double center_x = carX + 70.0;
        double center_y_sf = 460.0;
        double center_y_ig = 600.0 - center_y_sf;
        double image_left = center_x - car_width / 2.0;
        double image_bottom = center_y_ig - car_height / 2.0;
        iShowImage(image_left, image_bottom, car_width, car_height, carTexture);
    }
};

TrafficLight trafficLight;
Road road;
Car car(550.0);
string status_str;

void update() {
    static auto last = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    double dt = chrono::duration<double>(now - last).count();
    last = now;

    car.update(dt, trafficLight.getColor());
    status_str = car.getStatus();
}

void iDraw() {
    iClear();
    iSetColor(20, 20, 40);
    iFilledRectangle(0.0, 0.0, 800.0, 600.0);

    iSetColor(255, 255, 255);
    iText(160.0, 600.0 - 15.0, "TRAFFIC CONTROL BANGLADESH", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(50.0, 600.0 - 520.0, "Controls: [G]reen | [Y]ellow | [R]ed", GLUT_BITMAP_HELVETICA_18);
    iText(50.0, 600.0 - 550.0, status_str.c_str(), GLUT_BITMAP_HELVETICA_18);

    trafficLight.draw();
    road.draw();
    car.draw();
}

void iKeyboard(unsigned char key) {
    char lower_key = tolower(key);
    if (lower_key == 'g') trafficLight.setColor('G');
    else if (lower_key == 'y') trafficLight.setColor('Y');
    else if (lower_key == 'r') trafficLight.setColor('R');
}

void iSpecialKeyboard(unsigned char key) {
    // Placeholder if needed
}

void iMouse(int button, int state, int mx, int my) {
    // Placeholder if needed
}

void iMouseMove(int mx, int my) {
    // Placeholder if needed
}

int main() {
    iSetTimer(10, update);
    iInitialize(800, 600, "Traffic Control Bangladesh");
    return 0;
}