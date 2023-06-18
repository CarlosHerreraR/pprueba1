#include "Episodio.h"

Episodio::Episodio(): Video()
{
}

Episodio::Episodio(string p_id, string p_nombre, int p_duracion, float p_calificacion, string p_fecha_estreno, int p_episodio_numero, int p_episodio_temporada): Video(p_id, p_nombre, p_duracion, p_calificacion, p_fecha_estreno)
{
    episodio_numero = p_episodio_numero;
    episodio_temporada = p_episodio_temporada;
}

string Episodio::VideosporCalificacion(float p_calificacion) 
{
    return Video::VideosporCalificacion(p_calificacion);
}

string Episodio::ConsultaEpisodios()
{
    return "\n \nEpisodio "+ Video::ConsultaVideos() + " Episodio: " + to_string(episodio_numero) + " Temporada: " + to_string(episodio_temporada);
}

string Episodio::EpisodioNombre() {
    return nombre;
}
