#include <iostream>

using namespace std;

class Circle {
public:
    virtual void draw() = 0;
};

class StandardCircle {
public:
    StandardCircle(int radius) {
        radius_ = radius;
        cout << "StandardCircle:  create. radius = " << radius_ << endl;
    }

    void oldDraw() {
        cout << "StandardCircle:  oldDraw. " << radius_ << endl;
    }

private:
    double radius_;
};

class Adapter : public Circle, private StandardCircle
{
public:
    Adapter(int diameter)
            : StandardCircle(diameter / 2) {
        cout << "Adapter: create. diameter = " << diameter << endl;
    }

    virtual void draw() {
        cout << "Adapter: draw." << endl;
        oldDraw();
    }
};

int main() {
    Circle *c = new Adapter(14);
    c->draw();
}
