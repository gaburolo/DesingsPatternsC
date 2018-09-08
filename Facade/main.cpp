#include <iostream>
using namespace std;


//Clase Formateo, puedes elegir entre respaldar la informacion del disco o formatearlo
class Formateo{
    int cont=1;

public:
    void Respaldar(){

        cout << "Respaldo"<<endl;
        cont=0;
    }
    void Formatear(){

        if(cont == 0){
            cout << "Formatear"<<endl;
        }else{
            cout<< "Realice una copia de Seguridad primero"<<endl;
        }
    }

};
//Intalación del sistema operativo, puedes instalar el SO y sus drivers
class InstalarSistemaOperativo{
    int cont=1;
public:
    void InstalarSistema(){
        cout << "Se ha instalado el Sistema Operativo correctamente"<<endl;
        cont =0;
    }
    void InstalarDrivers(){
        if(cont == 0){
            cout<< "Drivers Instalados Correctamente"<<endl;

        }else{
            cout << "Instale el Sistema Operativo primero";
        }

    }
};

//Repara tu pc, en cualquier estado, ya sea disco duro o tarjeta madre
class Reparacion{
    int estado;
public:
    Reparacion(int estado){
        estado=estado;
    }
    void RepararDiscoDuro(){
        cout << "Disco Duro reparado"<<endl;
        estado=100;
    }
    void ReparacionTarjetaMadre(){
        cout <<"Tarjeta Madre reparada"<<endl;
        estado=100;
    }
};


//Revisión del estado en el que se encuentra el computador
class Revision{
    int estado;
public:
    Revision(int estado){
        estado=estado;
    }
    void RevisarPc(){
        if(estado <50){
            cout << "Debe reparar Tarjeta Madre"<<endl;

        }else if (estado >50){
            cout << "Debe reparar Disco Duro"<<endl;
        }

    }
};


//Patrón de diseño facade, crea un estructura para simplificar el tratado de las clases, facilitando el uso al cliente
class PcFacade{
    int estado;
    Formateo formateo;
    InstalarSistemaOperativo iso;

public:
    PcFacade(int estado) {
        estado = estado;

    }

    void ReparacionCompleta(){
        cout<<"Iniciando Reparaciones"<<endl;
        Revision revision(estado);
        revision.RevisarPc();
        Reparacion reparacion(estado);
        reparacion.ReparacionTarjetaMadre();
        reparacion.RepararDiscoDuro();
        formateo.Respaldar();
        formateo.Formatear();
        iso.InstalarSistema();
        iso.InstalarDrivers();
    }
    void RepararDiscoDuro(){
        cout<<"Iniciando Reparaciones"<<endl;
        Revision revision(estado);
        revision.RevisarPc();
        Reparacion reparacion(estado);
        reparacion.RepararDiscoDuro();
        formateo.Respaldar();
        formateo.Formatear();
        iso.InstalarSistema();
        iso.InstalarDrivers();
    }
    void Limpieza(){
        cout<<"Iniciando Reparaciones"<<endl;
        formateo.Respaldar();
        formateo.Formatear();
        iso.InstalarSistema();
        iso.InstalarDrivers();
    }

};




int main() {


    //Con Facade
    cout<<"------------------Con Facade------------------"<<endl;
    PcFacade pc(80);
    pc.Limpieza();

    //SinFacade
    cout<<"------------------Sin Facade------------------"<<endl;
    Formateo formateo;
    InstalarSistemaOperativo iso;
    formateo.Respaldar();
    formateo.Formatear();
    iso.InstalarSistema();
    iso.InstalarDrivers();
    return 0;
}
