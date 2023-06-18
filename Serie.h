#ifndef _SERIE_H
#define _SERIE_H
#include <string>
using namespace std;
#include "Episodio.h"
#include <iostream>
#include <vector>
#include "Consultas.h"

class Serie : public Episodio , public Consultas {
    public:
        string serie_id;
        string serie_nombre;
        string serie_genero;
        vector<Episodio> oEpisodio;

        Serie(std::vector<Episodio> p_episodio, string p_serie_id, string p_serie_nombre, string p_serie_genero);

        string SerieNombre();
        string SerieGenero();
        string EpisodioNombre(string p_episodio_nombre);
        virtual void CalificarVideo(string p_video_nombre, float p_calificacion) {};
        void VideosporGenero(string p_serie_genero);
        void VideosporCalificacion(float p_calificacion);
        void EpisodiosPorSerie(string p_serie_nombre);
        virtual void PeliculasporCalificacion(float p_calificacion) {}; //SE IMPLEMENTA TAMBIEN VIRTUAL, SI NO VUELVA ABSTRACTA LA CLASE SERIE
        
        virtual string PeliculaNombre() { return ""; };
        virtual string PeliculaGenero() { return ""; };
};

#endif
