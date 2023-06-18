#ifndef _CATALOGO_H
#define _CATALOGO_H
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

using namespace std;

struct datos_video
{
    string id;
    string nombre;
    string duracion;
    string genero;
    string calificacion;
    string fecha_estreno;
    string episodio_id;
    string episodio_nombre;
    string episodio_temporada;
    string episodio_num_episodio;
};

class Catalogo 
{
    private:
        //vector<Pelicula*> vPeliculas;
        // vector<Serie*> vSeries;
        
        vector<Consultas*> vPeliculas;
        vector<Consultas*> vSeries;
        

    public:
    
        Catalogo();
        void VerTodo();
        void CargaVideos();
        void CalificarVideo();
        void VideosporGenero();
        void VideosporCalificacion();
        void EpisodiosPorSerie();
        void PeliculasporCalificacion();
        void Ordenar_por_NombreArreglo(datos_video * lista, int numElementos);

        void agregarPelicula(Consultas* oConsultas);
        void agregarSerie(Consultas* oConsultas);
};

#endif 

