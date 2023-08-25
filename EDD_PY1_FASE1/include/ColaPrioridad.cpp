#include "ColaPrioridad.h"

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
    /**
    1. Crear una funcion que tenga una cola temporal, una copia de la cola actual
    2. Cola temporal, le aplican un ordenamiento.
    3. this->Primero = colaTemp.Primero

    funcion Orderna
        *colatemp = this->primero
        ordenamientoBurbuja(colatemp)

    PY-100 | B - PY-101 | B - PY-102 | A
    PY-102 - PY-100 - PY-101
    */
}

void ColaPrioridad::VerProyectos()
{
    NodoCola *aux = this->Primero;
    int contador = 0;
    while(aux)
    {
        cout << aux->Proyecto_ABC->Codigo << endl;
        cout<<aux->Prioridad<<endl;
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
            cout<<pivote->Prioridad<<endl;
            cout<<actual->Prioridad<<endl;
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
