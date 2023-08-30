#include "ColaPrioridad.h"
#include <fstream>
ColaPrioridad::ColaPrioridad()
{
    this->Primero = 0;
    this->Tamanio = 0;
    //ctor
}

ColaPrioridad::~ColaPrioridad()
{
    //dtor
}
void ColaPrioridad::Encolar(std::string Nombre, std::string Tipo_de_Prioridad)
{
    int numero_proyecto = 100 + this->Tamanio;
    Proyecto *nuevoProyecto = new Proyecto("PY-"+std::to_string(numero_proyecto),Nombre);
    NodoCola *nuevoNodo = new NodoCola(nuevoProyecto,Tipo_de_Prioridad);
    if(this->Primero == 0)
    {
        this->Primero = nuevoNodo;
        this->Tamanio++;
    }else{
        NodoCola *aux = this->Primero;
        while(aux->Siguiente)
        {
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevoNodo;
        this->Tamanio++;
    }

}

void ColaPrioridad::VerProyectos()
{
    NodoCola *aux = this->Primero;
    int contador = 0;
    while(aux)
    {
        cout <<to_string(contador+1)<<". "<< aux->Proyecto_ABC->Codigo << endl;

        aux = aux->Siguiente;
        contador++;
    }
}

void ColaPrioridad::Descolar()
{
    if(this->Primero)
    {
        this->Primero = this->Primero->Siguiente;
    }
}
void ColaPrioridad::Ordenar()
{
if(this->Primero){
    NodoCola *pivote = this->Primero;
    NodoCola *actual;
    int contador=0;
    while(contador!= this->Tamanio)

    {
        actual = pivote->Siguiente;
        while(actual)
        {
           // cout<<pivote->Prioridad<<endl;
            //cout<<actual->Prioridad<<endl;
            if(pivote->Prioridad.compare(actual->Prioridad)==1 ||pivote->Prioridad.compare(actual->Prioridad)==2)
            {
                Proyecto *tempProyecto = pivote->Proyecto_ABC;
                //std::string tempProyecto= pivote->Proyecto_ABC;
                std::string tempPrioridad = pivote->Prioridad;

                pivote->Prioridad = actual->Prioridad;
                actual->Prioridad = tempPrioridad;
                pivote->Proyecto_ABC = actual->Proyecto_ABC;
                actual->Proyecto_ABC = tempProyecto;

            }
            actual= actual->Siguiente;
        }
        pivote = pivote->Siguiente;
        contador++;
    }

}



}
std::string ColaPrioridad::textoGrafica()
{
    std::string cuerpo = "";
    NodoCola *aux = this->Primero;
    for(int i = 0; i < this->Tamanio; i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+="[label=\"";
        cuerpo+=aux->Proyecto_ABC->Nombre;
        cuerpo+="\n";
        cuerpo+=aux->Prioridad;
        cuerpo+="\"]; \n";
        aux = aux->Siguiente;
    }
     for(int i = 0; i < (this->Tamanio-1); i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+=" -> nodo";
        cuerpo+=std::to_string(i+1);
        cuerpo+="\n";
    }
    return cuerpo;
}
//std::string NodoCola::textoGraficaProyecto()
void ColaPrioridad::graficar()
{
    ofstream archivo;
    archivo.open("Cola.dot",ios::out);
    if(archivo.fail())
    {
        cout << "Se produjo un error" << endl;
    }else{
        archivo << "digraph migrafica{\n rankdir=LR; \n node[shape=box]" << textoGrafica() << "\n }";
        archivo.close();
    }

    try{
        system("dot -Tpng Cola.dot -o Cola.png");
    }catch(exception e){
        cout << "Error al generar imagen";
    }
}
