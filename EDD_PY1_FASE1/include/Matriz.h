#ifndef MATRIZ_H
#define MATRIZ_H
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "NodoMatriz.h"
#include "NodoListaCircularDoble.h"
#include "ColaPrioridad.h"
#include "Proyecto.h"
#include "Empleado.h"
#include "ListaCircularDoble.h"



class Matriz
{
    public:
         NodoMatriz *Raiz;
        int CoordenadaX;
        int CoordenadaY;
        void insertar_elemento(std::string proyecto, std::string encargado, int x, int y);
        NodoMatriz *nueva_columna(int x);
        NodoMatriz *nueva_fila(int y);
        NodoMatriz *insertar_fila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila);
        NodoMatriz *insertar_columna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna);
        NodoMatriz *buscarF(int y);
        NodoMatriz *buscarC(int x);
        void Graficar();
        void GraficarCola();
        void ReporteJson();
        void VerProyectos();
        void VerEmpleado();
        void VerTareas(std::string codigo);
        void insertar_proyecto(ColaPrioridad *cola);
        void insertar_empleado(ListaCircularDoble *lista,std::string nombre);
        void insertar_empleado_1(Empleado *empleado);
        NodoMatriz *nueva_columna_1(int x, Proyecto *proyecto);
        NodoMatriz *nueva_fila_1(int y, Empleado *empleado);
        void asignarProyecto(std::string nombre_empleado, std::string codigo_proyecto,std::string codigo_empleado);
        NodoMatriz *buscarF_1(std::string nombre);
        NodoMatriz *buscarF_2(std::string codigo_empleado);
        NodoMatriz *buscarC_1(std::string codigo);
        void BuscarProyecto(std::string codigo, std::string nombre_tarea);
        void BuscarEmpleado(std::string codigo, std::string nombre_tarea, std::string nombre_empleado);
        Matriz();
        virtual ~Matriz();

    protected:

    private:
};

#endif // MATRIZ_H
