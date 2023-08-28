#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include "NodoCola.h"
#include "Proyecto.h"
#include <string>
#include <iostream>
using namespace std;


class ColaPrioridad
{
    public:
        NodoCola *Primero;
        int Tamanio;
        void Ordenar();
        void Encolar(std::string Nombre, std::string Tipo_de_Prioridad);
        void graficar();
        void Descolar();
        void VerProyectos();
        ColaPrioridad();
        virtual ~ColaPrioridad();

    protected:

    private:
        std::string textoGrafica();
        std::string textoGraficaProyecto();
};

#endif // COLAPRIORIDAD_H
