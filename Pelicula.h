#ifndef _PELICULA_H
#define _PELICULA_H
#include <string>
using namespace std;
#include "Video.h"
#include <iostream>
#include "Consultas.h"

class Pelicula : public Video , public Consultas {
        

    public:
        string pelicula_genero;
        Pelicula(string p_id, string p_nombre, int p_duracion, float p_calificacion, string p_fecha_estreno, string p_genero);

        string PeliculaGenero();
        string PeliculaNombre();
        virtual void CalificarVideo(string p_video_nombre, float p_calificacion) {};
        void VideosporGenero(string p_pelicula_genero);
        void VideosporCalificacion(float p_calificacion);
        void PeliculasporCalificacion(float p_calificacion);
        virtual void EpisodiosPorSerie(string p_serie_nombre) {}; //SE IMPLEMENTA TAMBIEN VIRTUAL, SI NO VUELVA ABSTRACTA LA CLASE PELICULA

        virtual string SerieGenero() { return ""; };
        virtual string SerieNombre() { return ""; };
        virtual string EpisodioNombre(string p_video_genero) { return ""; };
};

#endif
