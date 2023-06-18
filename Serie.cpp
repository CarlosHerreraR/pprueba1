#include "Serie.h"


Serie::Serie(std::vector<Episodio> p_episodio, string p_serie_id, string p_serie_nombre, string p_serie_genero) : Episodio()
{
    oEpisodio = p_episodio;
    
    serie_id = p_serie_id;
    serie_nombre = p_serie_nombre;
    serie_genero = p_serie_genero;
}

string Serie::SerieNombre() {
    return serie_nombre;
}

string Serie::SerieGenero() {
    return serie_genero;
}

string Serie::EpisodioNombre(string p_episodio_nombre) {
    string sEpisodioNombre = "";
    for(int i=0; i<oEpisodio.size(); i++)
    {
        if ( oEpisodio[i].EpisodioNombre() == p_episodio_nombre )
        {
            sEpisodioNombre = p_episodio_nombre;
            break;
        }
    }
    return sEpisodioNombre;
}

void Serie::VideosporGenero(string p_serie_genero)
{
    if ( serie_genero.find(p_serie_genero) != std::string::npos )  //si hemos llegado al final de nuestra cadena.
    {
        for(int i=0; i<oEpisodio.size(); i++)
	    {
    		cout << "Nombre: " + serie_nombre + "\nGenero: " + serie_genero + "\n"+oEpisodio[i].ConsultaEpisodios() << endl;
    	}
    }
    else
    {
        cout << "No existe información";
    }
}

void Serie::VideosporCalificacion(float p_calificacion) {
    for(int i=0; i<oEpisodio.size(); i++)
    {
        string sVideo = oEpisodio[i].VideosporCalificacion(p_calificacion);
        if ( sVideo != "" )
            cout << "Nombre: " + serie_nombre + "\nGenero: " + serie_genero + sVideo << endl;
    }
}

void Serie::EpisodiosPorSerie(string p_serie_nombre)
{
    if ( serie_nombre == p_serie_nombre )
    {
        for(int i=0; i<oEpisodio.size(); i++)
	    {
    		cout << "Nombre: " + serie_nombre + "\nGenero: " + serie_genero + "\n"+ oEpisodio[i].ConsultaEpisodios() << endl;
    	}
    }
    else
    {
        cout << "No existe información";
    }
}

