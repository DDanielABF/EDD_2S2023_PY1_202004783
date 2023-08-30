#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ListaCircularDoble.h"
#include "ColaPrioridad.h"
#include "Matriz.h"
#include "Empleado.h"
#include "ListaDoble.h"

using namespace std;
ListaCircularDoble *listaDobleCircular = new ListaCircularDoble();
ColaPrioridad *cola = new ColaPrioridad();
 Matriz *matriz = new Matriz();
 ListaDoble *listaDoble = new ListaDoble();
 Empleado *empleado  = new Empleado("","");


void CargaEmpleado(ListaCircularDoble *listaCircularDoble){
std::string nombre="";
std::string n="";
std::string password="";
string narchivo="";
int opcion;
cout << "1. Carga manual" << endl;
cout << "2. Crear masiva" << endl;
cin >> opcion;
switch (opcion) {
    case 1:
        try{
        std::cout << "Ingrese nombre: ";
        cin.ignore();
        std::getline(std::cin, nombre);
       // cin>>n;


        std::cout << "\nIngrese contraseña: ";

        std::getline(std::cin, password);
        //cin >> password;
        cout<<" datos guardados exitosamente"<<endl;


        listaCircularDoble->Insertar(password,nombre);
        //listaCircularDoble->VerLista();
        } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        break;
    case 2:
       try{
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
            //listaCircularDoble->VerLista();


        }
        archivo.close();
        } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        break;

}
}
void CargarProyecto(ColaPrioridad *Cola){
 try{
 int opcion;
 string prioridad, nombrep;
cout << "Ingrese Nombre del proyecto" << endl;
cin>> nombrep;
cout << "Ingrese tipo de prioridad" << endl;
cin >> prioridad;
Cola->Encolar(nombrep,prioridad);
//cout<<"sin ordenar"<<endl;
//Cola->VerProyectos();
Cola->Ordenar();
//cout<<"ordenamiento: "<<endl;
//Cola->VerProyectos();
} catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }

}
void VerListas(ListaCircularDoble *listaCircularDoble,ColaPrioridad *Cola, Matriz *matriz, Empleado *empleado){
std::string nombre;
std::string proyecto;
std::string puesto;
int opcion;
//listaCircularDoble->VerLista();
cout<<"1. Primera asignacion del empleado"<<endl;
cout<<"2. asignacion"<<endl;
cin>>opcion;

switch(opcion){
 case 1:
try{
    cout<<"Nombre de empleados"<<endl;
    listaCircularDoble->VerLista();
    cout<<"ingrese nombre a asignar: ";
    cin.ignore();
    std::getline(std::cin, nombre);

    cout<<"ingrese nombre del puesto"<<endl;
    cout<<"1. FDEV"<<endl;
    cout<<"2. BDEV"<<endl;
    cout<<"3. QA"<<endl;
    cin>>puesto;
    cout<<"ingrese codigo del proyecto"<<endl;

    while(Cola->Primero)
        {
            matriz->insertar_proyecto(Cola);
            Cola->Descolar();
        }
        matriz->VerProyectos();
        cin>>proyecto;
        matriz->insertar_empleado(listaCircularDoble,nombre);
        matriz->asignarProyecto(nombre,proyecto,puesto);
        cout<<"si asigno"<<endl;
        } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        break;

 case 2:
   try{
    cout<<"Nombre de empleados"<<endl;
    listaCircularDoble->VerLista();
    cout<<"ingrese nombre a asignar: ";
    cin.ignore();
    std::getline(std::cin, nombre);
    cout<<"ingrese nombre del puesto"<<endl;
    cout<<"1. FDEV"<<endl;
    cout<<"2. BDEV"<<endl;
    cout<<"3. QA"<<endl;
    cin>>puesto;
    cout<<"ingrese codigo del proyecto"<<endl;

    matriz->VerProyectos();
    while(Cola->Primero)
        {
            matriz->insertar_proyecto(Cola);
            Cola->Descolar();
        }
        cin>>proyecto;
        empleado = listaCircularDoble->BuscarEmpleado(nombre);
        //matriz->insertar_empleado_1(empleado);
        //
        //matriz->insertar_empleado(listaCircularDoble,nombre);
        matriz->asignarProyecto(nombre,proyecto,puesto);
        cout<<"si asigno"<<endl;
        } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        break;



}



}
void CrearTarea(ListaDoble *listaDoble,Matriz *matriz){
std::string codigo;
std::string nombre_tarea;
cout<<"ingrese el codigo del proyecto"<<endl;
matriz->VerProyectos();
cin>>codigo;
cout<<"ingrese nombre de tarea: ";
cin.ignore();
std::getline(std::cin, nombre_tarea);
listaDoble->insertar(codigo, nombre_tarea,"");
matriz->BuscarProyecto(codigo,nombre_tarea);
cout<<"Tarea Creada con exito"<<endl;


}
void AsignarTarea(ListaDoble *listaDoble,Matriz *matriz){
std::string codigo;
std::string nombre_tarea;
std::string codigo_empleado;
cout<<"ingrese el codigo del proyecto"<<endl;
matriz->VerProyectos();
cin>>codigo;
cout<<"Tareas"<<endl;
matriz->VerTareas(codigo);
cout<<"ingrese nombre de tarea a asignar: ";
cin.ignore();
std::getline(std::cin, nombre_tarea);
cout<<"ingrese el codigo del empleado a asignar tarea"<<endl;
matriz->VerEmpleado();
cin>>codigo_empleado;
matriz->BuscarEmpleado(codigo,nombre_tarea,codigo_empleado);



}
void Reportes(Matriz *matriz){
int opcion;
cout << "1. Reporte de cola" << endl;
cout << "2. Reporte de matriz Dispersa" << endl;
cout << "3. Reporte json" << endl;
cin >> opcion;
switch(opcion){
    case 1:
        matriz->GraficarCola();
        cout<<"reporte de cola creado con exito..."<<endl;
        break;
    case 2:
        matriz->Graficar();
        cout<<"reporte matriz dispersa creado con exito..."<<endl;
        break;
    case 3:
        cout<<"reporte json creado con exito..."<<endl;



}
}
int main()
{


 string usuario="";
 string password="";
 string diseno=(50,"*");

    cout << "*************************** Bienvenido a EDD ProjectUp  ***************************" << endl;
try{
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
    } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
    int opcion;
   try{
    while (usuario=="PM-202004783" && password=="pmPassword123") {
        cout <<"***************************"<<"EDD ProjectUp - Bienvenido "<< usuario << "***************************"<<endl;
        cout << "***************************  Opciones:  ***************************" << endl;
        cout << "1. Cargar empleados" << endl;
        cout << "2. Crear proyecto" << endl;
        cout << "3. Asignar Proyecto" << endl;
        cout << "4. Reportes" << endl;
        cout << "5. crear tareas" << endl;
        cout << "6. Asignar Tareas" << endl;
        cout << "7. Salir" << endl;
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
                VerListas(listaDobleCircular,cola,matriz,empleado);
                //listaCircularDoble->VerLista();
                //cola->VerProyectos();
                // Lógica para crear tareas
                cout << "Creando tareas..." << endl;
                break;
            case 4:

                 cout << "Reportes" << endl;
                Reportes(matriz);
                //cout << "Asignando tareas..." << endl;
                break;
            case 5:
                CrearTarea(listaDoble, matriz);
                // Lógica para asignar tareas
               cout<<"crear tarea"<<endl;
                break;
            case 6:
                AsignarTarea(listaDoble, matriz);
                // Lógica para asignar tareas
               cout<<"asignar  tarea"<<endl;
                break;
            case 7:
                cout << "Saliendo..." << endl;
                return 0;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    }
    } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
    return 0;
}






