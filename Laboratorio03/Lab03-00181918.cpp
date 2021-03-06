
/*Laboratorio 03 00181918 Gustavo Jose Melgar Lopez

La UCA debe llevar un registro de los estudiantes para cada materia de Ingenier�a Inform�tica, por tanto, usted que es el Ingeniero deber� desarrollar un programa que facilite los datos almacenados de cada estudiante, con los datos relevantes como:
1. Nombre completo
2. Carnet
3. Nivel de carrera
4. horas sociales
Permitiendo el ingreso de nuevos estudiantes el proceso de inscripci�n, su b�squeda por carnet,
 mostrar todos los estudiantes que est�n registrados en la materia. De modo que la estructura que utilice para almacenar toda
  la informaci�n sea una pila.
Adem�s, el programa deber� llevar un registro de asistencia de los estudiantes que se presenten a clases,
 debido a la emergencia por Covid-19, estos estudiantes saldr�n del aula seg�n el orden de llegada, el primer estudiante que lleg� ser�
  el primero en salir. Para esta funcionalidad utilizar la estructura cola, y mostrar la asistencia de ellos*/



#include <iostream>
#include <conio.h>
using namespace std;

struct eEstudiante{
    string nombre, carrera;
    int carnet, horas;
};


struct nodo{
    eEstudiante datosEst;
    nodo *sig;
};


class claseEst{
    private:
        nodo *pInicioP;
        nodo *pInicioC;
        void filtrarInicioPriv(eEstudiante);
        void filtrarFinPriv(eEstudiante);
    public:
        claseEst(){
            pInicioP = NULL;
            pInicioC = NULL;
        }
        ~claseEst(){
            nodo *aux;
            while(pInicioP){
                aux = pInicioP;
                pInicioP = pInicioP->sig;
                delete aux;
            }
            while(pInicioC){
                aux = pInicioC;
                pInicioC = pInicioC->sig;
                delete aux;
            }
        }
        void filtrarInicioPub();
        void mostrarDatosP();
        void busquedaCarnet(int);
        void filtrarFinPub();
        void mostrarDatosC();
};



void claseEst::filtrarInicioPriv(eEstudiante datosEst){
    nodo *n = new nodo;
    n->datosEst = datosEst;
    n->sig = pInicioP;
    pInicioP = n;
}




void claseEst::filtrarInicioPub(){
    int masDatos = 0;
    do{
        eEstudiante datosEst;

        cout << "\nNombre: ";
        getline(cin, datosEst.nombre, '\n');

        cout << "Carnet: ";
        cin >> datosEst.carnet;
        cin.clear(); cin.ignore(1000, '\n');

        cout << "Nivel de carrera: ";
        getline(cin, datosEst.carrera, '\n');

        cout << "Horas sociales: ";
        cin >> datosEst.horas;
        cin.clear(); cin.ignore(1000, '\n');

        filtrarInicioPriv(datosEst);

        cout << "�Desea ingresar otro estudiante? (1 = Si, 0 = No): ";
        cin >> masDatos;
        cin.clear(); cin.ignore(1000, '\n');

        cout << endl;
    }while(masDatos != 0);
}





void claseEst::mostrarDatosP(){
    nodo *aux = pInicioP;
    while(aux){
        cout << "Nombre: " << aux->datosEst.nombre << endl;
        cout << "Carnet: " << aux->datosEst.carnet << endl;
        cout << "Nivel de carrera: " << aux->datosEst.carrera << endl;
        cout << "Horas sociales: " << aux->datosEst.horas << endl;
        cout << endl;
        aux = aux->sig;
    }
}




void claseEst::busquedaCarnet(int idBuscar){
    nodo *aux = pInicioP;
    bool encontrado = false;
    while(aux){
        if(aux->datosEst.carnet == idBuscar){
            encontrado = true;
            cout << "Nombre: " << aux->datosEst.nombre << endl;
            cout << "Carnet: " << aux->datosEst.carnet << endl;
            cout << "Nivel de carrera: " << aux->datosEst.carrera << endl;
            cout << "Horas sociales: " << aux->datosEst.horas << endl;
            cout << endl;
        }
        aux = aux->sig;
    }
    if(encontrado == false){
        cout << "Estudiante no encontrado" << endl;
    }
}




void claseEst::filtrarFinPub(){
    int masDatos = 0;
    do{
        eEstudiante datosEst;

        cout << "\nNombre: ";
        getline(cin, datosEst.nombre, '\n');

        filtrarFinPriv(datosEst);

        cout << "\n�Desea ingresar mas datos? (1 = Si, 0 = No): ";
        cin >> masDatos;
        cin.clear(); cin.ignore(1000, '\n');

        cout << endl;
    }while(masDatos != 0);
}

void claseEst::filtrarFinPriv(eEstudiante datosEst){
    nodo *n = new nodo;
    n->datosEst = datosEst;
    n->sig = NULL;
    if(!pInicioC){
        pInicioC = n;
    }
    else{
        nodo *s = pInicioC;
        while(s->sig){
            s = s->sig;
        }
        s->sig = n;
    }
}



void claseEst::mostrarDatosC(){
    nodo *aux = pInicioC;
    while(aux){
        cout << "Nombre: " << aux->datosEst.nombre << endl;
        cout << endl;
        aux = aux->sig;
    }
}

int main(void){
    cout << endl << endl;
    
    claseEst varEstudiante;
    int opcion = 0, idBuscar = 0;

    do{
        cout << "\nRegistro de estudiantes" << endl;
        cout << "1. Ingresar un nuevo estudiante" << endl;
        cout << "2. Buscar estudiante por carnet" << endl;
        cout << "3. Mostrar estudiantes" << endl;
        cout << "4. Pasar asistencia" << endl;
        cout << "5. Mostrar asistencia de estudiantes" << endl;
        cout << "0. Salir del menu" << endl;
        cin >> opcion;
        cin.clear(), cin.ignore(1000, '\n');

        switch(opcion){
            case 1:
                varEstudiante.filtrarInicioPub();
                cout << endl;
                break;
            case 2:
                cout << "\nIngrese el carnet del estudiante: ";
                cin >> idBuscar;
                cout << endl;
                varEstudiante.busquedaCarnet(idBuscar);
                break;
            case 3:
                cout << endl;
                varEstudiante.mostrarDatosP();
                cout << endl;
                break;
            case 4:
                cout << endl;
                varEstudiante.filtrarFinPub();
                cout << endl;
                break;
            case 5:
                cout << endl;
                varEstudiante.mostrarDatosC();
                cout << endl;
                break;
            default:
                break;
        }

    }while(opcion != 0);
	
    cout << endl;
    getch();
    return 0;
}
