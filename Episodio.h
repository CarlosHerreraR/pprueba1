#ifndef _EPISODIO_H
#define _EPISODIO_H
#include <string>
using namespace std;
#include "Video.h"
#include <iostream>

class Episodio : public Video {
    private:
        int episodio_numero;
        int episodio_temporada;

    public:
        Episodio();
        Episodio(string p_id, string p_nombre, int p_duracion, float p_calificacion, string p_fecha_estreno, int p_episodio_numero, int p_episodio_temporada);
        
        string EpisodioNombre();
        string ConsultaEpisodios();
        string VideosporCalificacion(float p_calificacion);
};

#endif
