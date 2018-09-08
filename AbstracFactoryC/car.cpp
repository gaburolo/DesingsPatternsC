//
// Created by ocastro on 31/08/18.
//

#ifndef __io__
#define __io__
#include <iostream>
using namespace std;
#endif

//Se crean los neumaticos del auto como clase base
class Tire {

protected:
    string name;
    int presure;

public:
    Tire(string n, int presure):name(n),presure(presure){};
    string getName(){return name;}
    int getPresure(){return presure;}
};

//Se define una clase de neumatico
class SimpleTire : public Tire{

public:
    SimpleTire():Tire("SimpleTire",75) {}

};

//Se utiliza otra clase de neumatico
class LuxuryTire : public Tire{

public:
    LuxuryTire():Tire("LuxuryTire",100) {}

};


//Es creado el cuerpo del auto como base
class Body {

protected:
    string name;
    int strength;

public:
    Body(string n, int strength):name(n),strength(strength) {}
    string getName(){return name;}
    int getStrength() {return strength;}

};

//Se crea un cuerpo simple para el auto
class SimpleBody : public Body{
public:
    SimpleBody():Body("SimpleBody",75) {}

};

//Se crea un cuerpo diferente para el auto
class LuxuryBody : public Body{

public:
    LuxuryBody():Body("LuxuryBody",100) {}

};


//Se crea el objeto autf
//Se creab funciones que serviran de herencia para añadir caracteristicas distintas
class Car {

protected:
    string name;
    Tire *tire;
    Body *body;

public:
    Car(string n):name(n) {}
    void setTire(Tire* t) { tire = t;}
    void setBody(Body* b) {	body = b;}
    void printDetails(){
        cout << endl << "Car: " << name << endl;
        cout << "Tire: " << tire->getName() << " Presure: " << tire->getPresure() << endl;
        cout << "Body: " << body->getName() << " Strength: " << body->getStrength() << endl << endl;
    }
};

