#include "Pelicula.h"
#include <string>
Pelicula::Pelicula(string p_id, string p_nombre, int p_duracion, float p_calificacion, string p_fecha_estreno, string p_genero) : Video(p_id, p_nombre, p_duracion, p_calificacion, p_fecha_estreno), Consultas()
{
    pelicula_genero = p_genero;
}

string Pelicula::PeliculaGenero() {
    return pelicula_genero;
}

string Pelicula::PeliculaNombre() {
    return nombre;
}



void Pelicula::VideosporGenero(string p_pelicula_genero)
{
    if ( pelicula_genero.find(p_pelicula_genero) != std::string::npos )  //si hemos llegado al final de nuestra cadena.
    {
        cout << Video::ConsultaVideos() << endl<< "Genero: " << pelicula_genero << endl <<endl;
        
    }
    else
    {
        cout << "No existe información";
    }
}

void Pelicula::VideosporCalificacion(float p_calificacion) {
    string sVideo = Video::VideosporCalificacion(p_calificacion);
    if ( sVideo != "" )
        cout << sVideo << endl << "Genero: " << pelicula_genero << endl<<endl;
}

void Pelicula::PeliculasporCalificacion(float p_calificacion) {
    string sVideo = Video::VideosporCalificacion(p_calificacion);
    if ( sVideo != "" )
        cout << sVideo << endl << "Genero: " << pelicula_genero << endl<<endl;
}
