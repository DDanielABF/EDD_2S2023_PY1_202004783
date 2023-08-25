#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ListaCircularDoble.h"
#include "ColaPrioridad.h"
#include "Matriz.h"

using namespace std;
ListaCircularDoble *listaDobleCircular = new ListaCircularDoble();
ColaPrioridad *cola = new ColaPrioridad();
 Matriz *matriz = new Matriz();
void CargaEmpleado(ListaCircularDoble *listaCircularDoble){
string nombre="";
string password="";
string narchivo="";
int opcion;
cout << "1. Carga manual" << endl;
cout << "2. Crear masiva" << endl;
cin >> opcion;
switch (opcion) {
    case 1:

        cout << "ingrese nombre" << endl;
        cin >> nombre;
        cout << "ingrese Contraseña " << endl;
        cin >> password;
        cout<<" datos guardados exitosamente"<<endl;
        listaCircularDoble->Insertar(password,nombre);
        listaCircularDoble->VerLista();

        break;
    case 2:
        cout << "ingrese direccion de archivo csv" << endl;
        cin>> narchivo;
        ifstream archivo(narchivo);
        string Linea;
        char delimitador=',';
        getline(archivo,Linea);
        while (getline(archivo,Linea)){

            stringstream stream(Linea); // Convertir la cadena a un stream
            string name,contra;
            // Extraer todos los valores de esa fila
            getline(stream, name, delimitador);
            getline(stream, contra, delimitador);
            listaCircularDoble->Insertar(contra,name);
            listaCircularDoble->VerLista();


        }
        archivo.close();
        break;

}
}
void CargarProyecto(ColaPrioridad *Cola){
 int opcion;
 string prioridad, nombrep;
cout << "Ingrese Nombre del proyecto" << endl;
cin>> nombrep;
cout << "Ingrese tipo de prioridad" << endl;
cin >> prioridad;
Cola->Encolar(nombrep,prioridad);
cout<<"sin ordenar"<<endl;
Cola->VerProyectos();
Cola->Ordenar();
cout<<"ordenamiento: "<<endl;
Cola->VerProyectos();


}
void VerListas(ListaCircularDoble *listaCircularDoble,ColaPrioridad *Cola, Matriz *matriz){

//listaCircularDoble->VerLista();
Cola->VerProyectos();
 while(Cola->Primero)
    {
        matriz->insertar_proyecto(Cola);
        Cola->Descolar();
        cout<<"si entra al while"<<endl;
        //cout<<Cola.Primero.Siguiente<<endl;
    }

    matriz->insertar_empleado(listaCircularDoble);
    //matriz->asignarProyecto("Cristian Suy","PY-106");
    matriz->asignarProyecto("juan","PY-100");
    matriz->asignarProyecto("marielos","PY-101");
    matriz->asignarProyecto("alicia","PY-102");


    matriz->Graficar();


}

int main()
{


 string usuario="";
 string password="";
 string diseno=(50,"*");

    cout << "*************************** Bienvenido a EDD ProjectUp  ***************************" << endl;

    // Autenticación de usuario
    do {
        cout << "Usuario: " << endl;
        cin >> usuario;
        cout << "Contraseña: " << endl;
        cin >> password;

        if (usuario!="PM-202004783" && password!="pmPassword123" ) {
            cout << "Credenciales incorrectas. Intente nuevamente." << endl;
        }
    } while (usuario!="PM-202004783" && password!="pmPassword123");

    system("cls");  // Limpia la consola

    int opcion;

    while (usuario=="PM-202004783" && password=="pmPassword123") {
        cout <<"***************************"<<"EDD ProjectUp - Bienvenido "<< usuario << "***************************"<<endl;
        cout << "***************************  Opciones:  ***************************" << endl;
        cout << "1. Cargar empleados" << endl;
        cout << "2. Crear proyecto" << endl;
        cout << "3. Crear tareas" << endl;
        cout << "4. Asignar tareas" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese el número de la opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Lógica para cargar empleados
                CargaEmpleado(listaDobleCircular);
                cout << "Cargando empleados..." << endl;
                break;
            case 2:
                // Lógica para crear proyecto
                CargarProyecto(cola);
                cout << "Creando proyecto..." << endl;
                break;
            case 3:
                VerListas(listaDobleCircular,cola,matriz);
                //listaCircularDoble->VerLista();
                //cola->VerProyectos();
                // Lógica para crear tareas
                cout << "Creando tareas..." << endl;
                break;
            case 4:
                // Lógica para asignar tareas
                cout << "Asignando tareas..." << endl;
                break;
            case 5:
                cout << "Saliendo..." << endl;
                return 0;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    }

    return 0;
}






