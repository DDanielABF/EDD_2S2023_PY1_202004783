#include "Matriz.h"
#include <iostream>

Matriz::Matriz()
{
    this->Raiz = new NodoMatriz(new Proyecto("RAIZ",""),new Empleado("",""),-1,-1);
    this->CoordenadaX = 0;
    this->CoordenadaY = 0;
    //ctor
}

Matriz::~Matriz()
{
    //dtor
}
NodoMatriz* Matriz::buscarF(int y)
{

    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {

        if(aux->PosY == y)
        {
            return aux;
        }
        aux = aux->Abajo;
    }
    return 0;
}

NodoMatriz* Matriz::buscarC(int x)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->PosX == x)
        {
            return aux;
        }
        aux = aux->Siguiente;
    }
    return 0;
}

NodoMatriz* Matriz::insertar_columna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna)
{
    NodoMatriz *temp = cabeza_columna;
    bool piv = false;
    while(true)
    {
        if(temp->PosX==nuevo->PosX){
            temp->PosY = nuevo->PosY;
            temp->Encargado_c = nuevo->Encargado_c;
            temp->Proyecto_ABC   = nuevo->Proyecto_ABC;
            return temp;
        }else if(temp->PosX > nuevo->PosX){
            piv=true;
            break;
        }
        if(temp->Siguiente){
            temp = temp->Siguiente;
        }else{
            break;
        }
    }
    if(piv)
    {
        nuevo->Siguiente = temp;
        temp->Anterior->Siguiente = nuevo;
        nuevo->Anterior=temp->Anterior;
        temp->Anterior=nuevo;
    }
    else
    {
        temp->Siguiente=nuevo;
        nuevo->Anterior=temp;
    }
    return nuevo;
}

NodoMatriz* Matriz::insertar_fila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila)
{
    NodoMatriz *temp = cabeza_fila;
    bool piv = false;
    while(true)
    {
        if(temp->PosY==nuevo->PosY){
                if(temp->Encargado_c->Nombre.compare(nuevo->Encargado_c->Nombre)==0){

                    break;
                }
            temp->PosX = nuevo->PosX;
            temp->Encargado_c = nuevo->Encargado_c;
            temp->Proyecto_ABC = nuevo->Proyecto_ABC;
            return temp;
        }else if(temp->PosY > nuevo->PosY){
            piv=true;
            break;
        }
        if(temp->Abajo){
            temp = temp->Abajo;
        }else{
            break;
        }
    }
    if(piv)
    {
        nuevo->Abajo = temp;
        temp->Arriba->Abajo = nuevo;
        nuevo->Arriba = temp->Arriba;
        temp->Arriba = nuevo;
    }
    else
    {
        temp->Abajo = nuevo;
        nuevo->Arriba = temp;
    }
    return nuevo;
}


NodoMatriz* Matriz::nueva_columna_1(int x, Proyecto *proyecto)
{
    NodoMatriz *columna = this->insertar_columna(new NodoMatriz(proyecto, 0, x, -1), this->Raiz);
    return columna;
}

void Matriz::insertar_proyecto(ColaPrioridad *cola)
{
    NodoMatriz *nodo_Columna = this->nueva_columna_1(this->CoordenadaX, cola->Primero->Proyecto_ABC);
    this->CoordenadaX++;
}

NodoMatriz* Matriz::nueva_fila_1(int y, Empleado *encargado)
{

    NodoMatriz *fila = this->insertar_fila(new NodoMatriz(0, encargado, -1, y), this->Raiz);
    return fila;
}

void Matriz::insertar_empleado(ListaCircularDoble *lista,std::string nombre)
{

    NodoListaCircularDoble *aux = lista->Primero;
    int contador = 0;
    while(lista->Tamanio > contador)
    {
        if(aux->EmpleadoSistema->Nombre.compare(nombre)==0){
        this->nueva_fila_1(this->CoordenadaY, aux->EmpleadoSistema);
        }
        aux = aux->Siguiente;
        contador++;
        this->CoordenadaY++;

    }
}
void Matriz::insertar_empleado_1(Empleado *empleado){
//aux = this->Raiz;
int contador;

int coordy = contador +1;
this->nueva_fila_1(coordy,empleado);

}

void Matriz::asignarProyecto(std::string nombre_empleado, std::string codigo_proyecto, std::string codigo_empleado)
{
    NodoMatriz *nodo_Columna =  this->buscarC_1(codigo_proyecto);
    NodoMatriz *nodo_Fila = this->buscarF_1(nombre_empleado);
    if(nodo_Fila->Encargado_c->Codigo.length()!=8){
        nodo_Fila->Encargado_c->Codigo = codigo_empleado +"-"+ nodo_Fila->Encargado_c->Codigo;
    }
    NodoMatriz *nuevo = new NodoMatriz(nodo_Columna->Proyecto_ABC, nodo_Fila->Encargado_c, nodo_Columna->PosX, nodo_Fila->PosY);

    if(nodo_Columna != 0 && nodo_Fila !=0 ){
        nuevo=this->insertar_columna(nuevo, nodo_Fila);
        nuevo=this->insertar_fila(nuevo, nodo_Columna);
        return;
    }
    else{
        cout << "Se podrujo un error al insertar el nuevo nodo" << endl;
    }
}

NodoMatriz* Matriz::buscarF_1(std::string nombre)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->Encargado_c->Nombre.compare(nombre) == 0)
        {
            return aux;
        }
        aux = aux->Abajo;
    }
    return 0;
}
NodoMatriz* Matriz::buscarF_2(std::string codigo_empleado){
NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->Encargado_c->Codigo.compare(codigo_empleado) == 0)
        {
            return aux;
        }
        aux = aux->Abajo;
    }
    return 0;

}
NodoMatriz* Matriz::buscarC_1(std::string codigo)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->Proyecto_ABC->Codigo.compare(codigo) == 0)
        {
            return aux;
        }
        aux = aux->Siguiente;
    }
    return 0;
}

void Matriz::VerProyectos(){

NodoMatriz *aux = this->Raiz;
int contador=0;
aux=aux->Siguiente;
 while(aux != 0)
    {
        cout <<to_string(contador+1)<<". "<< aux->Proyecto_ABC->Codigo << endl;
        contador++;

        aux = aux->Siguiente;
    }
}
void Matriz::BuscarProyecto(std::string codigo, std::string nombre_tarea)
{
    NodoMatriz *nodo_Columna =  this->buscarC_1(codigo);
    nodo_Columna->Tareas->insertar(codigo, nombre_tarea, "");
}

void Matriz::BuscarEmpleado(std::string codigo, std::string nombre_tarea, std::string nombre_empleado)
{
    NodoMatriz *nodo_Columna =  this->buscarC_1(codigo);
    NodoMatriz *nodo_Fila = this->buscarF_2(nombre_empleado);
    if(nodo_Fila != 0)
    {
        nodo_Columna->Tareas->Asignar(nodo_Columna->Proyecto_ABC->Codigo, nombre_tarea, nodo_Fila->Encargado_c->Codigo);
        //cout<<nodo_Fila->Encargado_c->Codigo<<endl;
    }
    else
    {
        cout << "No hay empleado con ese nombre" << endl;
    }
}

void Matriz::VerTareas(std::string codigo){

NodoMatriz *aux = this->Raiz;
int contador=0;
aux=aux->Siguiente;
 while(aux != 0)
    {
        if(aux->Proyecto_ABC->Codigo.compare(codigo)==0){
            while(aux->Tareas->Primero){
                cout <<to_string(contador+1)<<". "<< aux->Tareas->Primero->Nombre_Tarea << endl;
                contador++;
                aux->Tareas->Primero= aux->Tareas->Primero->Siguiente;
        }

        }
        //aux->Tareas->Primero= aux->Tareas->Primero->Siguiente;
        aux = aux->Siguiente;
    }

}

void Matriz::VerEmpleado(){
    NodoMatriz *aux = this->Raiz;
int contador=0;
aux=aux->Abajo;
 while(aux != 0)
    {
        cout <<to_string(contador+1)<<". "<< aux->Encargado_c->Codigo <<endl;
        cout << aux->Encargado_c->Nombre <<endl;
        contador++;

        aux = aux->Abajo;
    }


}

void Matriz::Graficar()
{
    ofstream archivo;
    std::string texto = "";
	std::string nombre_archivo = "matriz.dot";
	std::string nombre_imagen = "matriz.jpg";
	NodoMatriz *aux1 = this->Raiz;
	NodoMatriz *aux2 = this->Raiz;
	NodoMatriz *aux3 = this->Raiz;
	archivo.open(nombre_archivo, ios::out);
	if ( aux1 != 0 ) {
		archivo << "digraph MatrizCapa{ \n node[shape=box] \n rankdir=UD;\n";
        while( aux2 != 0 ) {
            aux1 = aux2;
            archivo << "{rank=same; \n";
            while( aux1 != 0 ) {
                if(aux1->Proyecto_ABC)
                {
                    if(aux1->Encargado_c)
                    {
                        archivo << "nodo" << aux1 << "[label=\"" << aux1->Proyecto_ABC->Codigo << "\\n" << aux1->Encargado_c->Codigo << "\" ,group=" << (aux1->PosX+1) << "]; \n";
                    }else{
                        archivo << "nodo" << aux1 << "[label=\"" << aux1->Proyecto_ABC->Codigo << "\" ,group=" << (aux1->PosX+1) << "]; \n";
                    }
                }else if(aux1->Encargado_c)
                {
                    archivo << "nodo" << aux1 << "[label=\"" << aux1->Encargado_c->Nombre << "\" ,group=" << (aux1->PosX+1) << "]; \n";
                }
                aux1 = aux1->Siguiente;
            }
            archivo << "} \n";
            aux2 = aux2->Abajo;
        }

        aux2 = aux3;
        while( aux2 != 0 ) {
            aux1 = aux2;
            while( aux1->Siguiente != 0 ) {
                archivo << "nodo" << aux1 << " -> " << "nodo" << aux1->Siguiente << " [dir=both];\n";
                aux1 = aux1->Siguiente;
            }
            aux2 = aux2->Abajo;
        }
        aux2 = aux3;
        while( aux2 != 0 ) {
            aux1 = aux2;
            while( aux1->Abajo != 0 ) {
                archivo << "nodo" << aux1 << " -> " << "nodo" << aux1->Abajo << " [dir=both];\n";
                aux1 = aux1->Abajo;
            }
            aux2 = aux2->Siguiente;
        }
        archivo << "} \n";
	} else {
		texto = "No hay elementos en la matriz";
	}


	archivo.close();
    std::string codigo_cmd="dot -Tjpg ";
    codigo_cmd+=nombre_archivo;
    codigo_cmd+=" -o ";
    codigo_cmd+=nombre_imagen;
    char j[codigo_cmd.size()+1];
    strcpy(j,codigo_cmd.c_str());
    cout << j << endl;
    system(j);
}


void Matriz::GraficarCola(){
 ofstream archivo;
    std::string texto = "";
	std::string nombre_archivo = "ColaP.dot";
	std::string nombre_imagen = "ColaP.jpg";
	NodoMatriz *aux1 = this->Raiz;
	NodoMatriz *aux2 = this->Raiz;
	int cont =0;
	int auxcont=0;
	//NodoMatriz *aux3 = this->Raiz;
	archivo.open(nombre_archivo, ios::out);

	if ( aux1->Proyecto_ABC != 0 ) {
		archivo << "digraph ColaPCapa{ \n node[shape=box] \n rankdir=UD;\n";

            archivo << "{rank=same; \n";
            while( aux1!= 0 ) {
                if(aux1->Proyecto_ABC)
                {

                        archivo << "nodo" << aux1 << "[label=\"" << aux1->Proyecto_ABC->Codigo << "\" ,group=" << (aux1->PosX+1) << "]; \n";
                        cont++;
                }
                aux1 = aux1->Siguiente;
            }
            archivo << "} \n";
            aux1= aux2;

            while( aux1 != 0 ) {
                 if(aux1->Proyecto_ABC && auxcont < cont-1)
                {

                archivo << "nodo" << aux1 << " -> " << "nodo" << aux1->Siguiente << " [dir=both];\n";
                auxcont++;

            }
            aux1 = aux1->Siguiente;
            }

            archivo << "} \n";

	}


	archivo.close();
    std::string codigo_cmd="dot -Tjpg ";
    codigo_cmd+=nombre_archivo;
    codigo_cmd+=" -o ";
    codigo_cmd+=nombre_imagen;
    char j[codigo_cmd.size()+1];
    strcpy(j,codigo_cmd.c_str());
    cout << j << endl;
    system(j);
    archivo << "{\n";


}

void Matriz::ReporteJson(){
ofstream archivo;
    std::string texto = "";
	std::string nombre_archivo = "Reporte.json";
	//std::string nombre_imagen = "ColaP.jpg";
	NodoMatriz *aux1 = this->Raiz;
	//NodoMatriz *aux2 = this->Raiz;
	//int cont =0;
	//int auxcont=0;
    archivo.open(nombre_archivo, ios::out);
    aux1=aux1->Siguiente;
    if ( aux1 != 0 ){
        archivo<<"{\n"<<" \"proyectos\":[\n";

        while( aux1!= 0 ) {
                if(aux1->Proyecto_ABC)
                {
                archivo<<"{\n"<<"\"id\": "<<"\""<<aux1->Proyecto_ABC->Codigo<<"\",\n";

                archivo<<"\"nombre\": "<<"\""<<aux1->Proyecto_ABC->Nombre<<"\",\n";
                archivo<<"\"tareas\":[\n";

                 while(aux1->Tareas->Primero){
                        archivo<<"{\n"<<"\"nombre\":\""<<aux1->Tareas->Primero->Nombre_Tarea<<"\",\n";
                        archivo<<"\"empleado\": \""<<aux1->Tareas->Primero->Codigo_Encargado<<"\"\n},";


                aux1->Tareas->Primero= aux1->Tareas->Primero->Siguiente;
                }

                archivo<<"]";

                } aux1=aux1->Siguiente;


                }




        archivo<<"]\n"<<"}";

    }
    archivo.close();
    cout<<"se creo reporte json con exito!"<<endl;

}
