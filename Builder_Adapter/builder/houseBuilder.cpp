#include <iostream>

using namespace std;

/* Clase interfase para armar la casa */
class HousePlan {
public:
    virtual void setWindow(string window) = 0;

    virtual void setDoor(string door) = 0;

    virtual void setBathroom(string bathroom) = 0;

    virtual void setKitchen(string kitchen) = 0;

    virtual void setFloor(string floor) = 0;
};

/* Clase concreta para armar la casa */
class House : public HousePlan {
private :
    string window, door, kitchen, bathroom, floor;

public:
    void setWindow(string window) {
        this->window = window;
    }

    void setDoor(string door) {
        this->door = door;
    }

    void setBathroom(string bathroom) {
        this->bathroom = bathroom;
    }

    void setKitchen(string kitchen) {
        this->kitchen = kitchen;
    }

    void setFloor(string floor) {
        this->floor = floor;
    }
};

/* Clase constructora */
class HouseBuilder {
public:
    /* Funciones abstractas para armar la partes de la casa */
    virtual void buildWindow() = 0;

    virtual void buildDoor() = 0;

    virtual void buildKitchen() = 0;

    virtual void buildBathroom() = 0;

    virtual void buildFloor() = 0;

    /* Producto final */
    virtual House *getHouse() = 0;
};

/* Clase concreta para construir un tipo de casa */
class AmericanHouse : public HouseBuilder {
private:
    House *house;
public:
    AmericanHouse() {
        house = new House();
    }

    void buildWindow() {
        house->setWindow("American Window");
    }

    void buildDoor() {
        house->setDoor("Metal Door");
    }

    void buildBathroom() {
        house->setBathroom("Modern Bathroom");
    }

    void buildKitchen() {
        house->setKitchen("Modern Kitchen");
    }

    void buildFloor() {
        house->setFloor("Ceramic Floor");
    }

    House *getHouse() {
        return this->house;
    }
};

/* Clase concreta para construir un tipo de casa */
class TreeHouse : public HouseBuilder {
private:
    House *house;
public:
    TreeHouse() {
        house = new House();
    }

    void buildWindow() {
        house->setWindow("Wooden Window");
    }

    void buildDoor() {
        house->setDoor("Wooden Door");
    }

    void buildBathroom() {
        house->setBathroom("Small Bathroom");
    }

    void buildKitchen() {
        house->setKitchen("Small Kitchen");
    }

    void buildFloor() {
        house->setFloor("Wooden Floor");
    }

    House *getHouse() {
        return this->house;
    }
};

/* Clase que dirije la construccion */
class Contractor {
private:
    HouseBuilder *houseBuilder;

public:
    Contractor(HouseBuilder *houseBuilder) {
        this->houseBuilder = houseBuilder;
    }

    House *getHouse() {
        return houseBuilder->getHouse();
    }

    void buildHouse() {
        houseBuilder->buildWindow();
        houseBuilder->buildDoor();
        houseBuilder->buildBathroom();
        houseBuilder->buildKitchen();
        houseBuilder->buildFloor();
    }
};

int main() {
    HouseBuilder *americanHouse = new AmericanHouse();
    HouseBuilder *treeHouse = new TreeHouse();

    Contractor *ctr1 = new Contractor(americanHouse);
    Contractor *ctr2 = new Contractor(treeHouse);

    ctr1->buildHouse();
    House *house1 = ctr1->getHouse();
    cout << "Constructed: " << house1;

    ctr2->buildHouse();
    House *house2 = ctr2->getHouse();
    cout << "\nConstructed: " << house2;
}