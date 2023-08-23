#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ListaCircularDoble.h>

using namespace std;

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
        char delimitador=';';
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

int main()
{
 ListaCircularDoble *listaDobleCircular = new ListaCircularDoble();
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
                cout << "Creando proyecto..." << endl;
                break;
            case 3:
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
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    }

    return 0;
}






