#include "Catalogo.h"

Catalogo::Catalogo()
{
    
}

void Catalogo::CargaVideos() {

    const int iTotalVideos = 66;
    int iTotalVideos_Contador = 0;
    struct datos_video aVideo[iTotalVideos];
    int ivideo = 0;

    vector<Episodio> vEpisodios;

    string sIDSerie_Corte = "";    
    string sNombreSerie_Corte = "";
    string sGeneroSerie_Corte = "";
    
    string array_id;
    string array_nombre;
    string array_duracion;
    string array_genero;
    string array_calificacion;
    string array_fecha_estreno;

    string array_id_episodio;
    string array_nombre_episodio;
    string array_numero_temporada;
    string array_numero_episodio;

    if ( vPeliculas.size() > 0 )
        vPeliculas.clear();
    if ( vSeries.size() > 0 )
        vSeries.clear();

    ifstream oArchivo;
    oArchivo.open("BasePeliculas.csv");

    string sLinea;
    getline(oArchivo, sLinea);
    while (getline(oArchivo, sLinea))
    {
        stringstream cadena_stream(sLinea); 
        
        getline(cadena_stream, array_id, ',');
        getline(cadena_stream, array_nombre, ',');
        getline(cadena_stream, array_duracion, ',');
        getline(cadena_stream, array_genero, ',');
        getline(cadena_stream, array_calificacion, ',');
        getline(cadena_stream, array_fecha_estreno, ',');
        
        getline(cadena_stream, array_id_episodio, ',');
        getline(cadena_stream, array_nombre_episodio, ',');
        getline(cadena_stream, array_numero_temporada, ',');
        getline(cadena_stream, array_numero_episodio, ',');
        
        aVideo[ivideo].id = array_id;
        aVideo[ivideo].nombre = array_nombre;
        aVideo[ivideo].duracion = array_duracion;
        aVideo[ivideo].genero = array_genero;
        aVideo[ivideo].calificacion = array_calificacion;
        aVideo[ivideo].fecha_estreno = array_fecha_estreno;
        aVideo[ivideo].episodio_id = array_id_episodio;
        aVideo[ivideo].episodio_nombre = array_nombre_episodio;
        aVideo[ivideo].episodio_temporada = array_numero_temporada;
        aVideo[ivideo].episodio_num_episodio = array_numero_episodio;
        ivideo += 1;
    }
    oArchivo.close();

    Ordenar_por_NombreArreglo(aVideo, iTotalVideos);

    for (size_t i = 0; i < iTotalVideos; i++)
    {
        if ( aVideo[i].episodio_id == "" )
        {
            Pelicula *oPelicula = new Pelicula(aVideo[i].id, aVideo[i].nombre, stoi(aVideo[i].duracion), stof(aVideo[i].calificacion), aVideo[i].fecha_estreno, aVideo[i].genero);
            agregarPelicula(oPelicula);
        }
        else
        {
            if ( sNombreSerie_Corte == aVideo[i].nombre || sNombreSerie_Corte == "" )
            {
                Episodio *oEpisodio = new Episodio(aVideo[i].episodio_id, aVideo[i].episodio_nombre, stoi(aVideo[i].duracion), stof(aVideo[i].calificacion), aVideo[i].fecha_estreno, stoi(aVideo[i].episodio_num_episodio), stoi(aVideo[i].episodio_temporada));
                vEpisodios.push_back(*oEpisodio);
                
                sIDSerie_Corte = aVideo[i].id;
                sNombreSerie_Corte = aVideo[i].nombre;
                sGeneroSerie_Corte = aVideo[i].genero;
            }
            else
            {
                Serie *oSerie = new Serie(vEpisodios, sIDSerie_Corte, sNombreSerie_Corte, sGeneroSerie_Corte);
                agregarSerie(oSerie);
                vEpisodios.clear();

                Episodio *oEpisodio = new Episodio(aVideo[i].episodio_id, aVideo[i].episodio_nombre, stoi(aVideo[i].duracion), stof(aVideo[i].calificacion), aVideo[i].fecha_estreno, stoi(aVideo[i].episodio_num_episodio), stoi(aVideo[i].episodio_temporada));
                vEpisodios.push_back(*oEpisodio);

                sIDSerie_Corte = aVideo[i].id;
                sNombreSerie_Corte = aVideo[i].nombre;
                sGeneroSerie_Corte = aVideo[i].genero;

                if ( ( i + 1 ) == iTotalVideos )
                {
                    Serie *oSerie = new Serie(vEpisodios, sIDSerie_Corte, sNombreSerie_Corte, sGeneroSerie_Corte);
                    agregarSerie(oSerie);
                }
            }
        }
    }

    system("clear");
    cout << endl <<"Catalogo cargado exitosamente" << endl;
}

void Catalogo::VerTodo() {
    
    cout << "⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆ PELICULAS ⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆" << endl;

  

    /*for (const auto& elemento : vPeliculas) {
        cout << elemento->PeliculaNombre();
        //cout << elemento.nombre;
    }*/

    /*for (std::size_t index = 0; index < vPeliculas.size(); ++index)
    {
            cout << *vPeliculas[index].nombre << " ";
    }*/


/*    for (auto iterP = vPeliculas.begin(); iterP != vPeliculas.end(); ++iterP) 
    {
          std::cout << "Nombre: " << (*iterP) -> nombre << std::endl;
    }*/


    /*vector<Pelicula*>::iterator iterP = vPeliculas.begin();
    for(iterP; iterP < vPeliculas.end(); iterP++) 
    {
        cout << "Nombre: " << (*iterP) -> nombre << endl;
        cout << "ID: " << (*iterP) -> id << endl;
        cout << "Género: " << (*iterP) -> pelicula_genero<< endl;
        cout << "Calificación: " << (*iterP) -> calificacion<< endl;
        cout << "Duración: " << (*iterP) -> duracion << " minutos" << endl;
        cout << endl;
    }*/

    /*cout << "⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆ SERIES ⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆" << endl << endl;
    vector<Serie*>::iterator iterS = vSeries.begin();
    for(iterS; iterS < vSeries.end(); iterS++)
    {
        cout << "Nombre: " << (*iterS) -> serie_nombre << endl;
        cout << "Género: " << (*iterS) -> serie_genero << endl;
        cout << endl;
    }*/
}


void Catalogo::VideosporCalificacion() {
    float iCalificacion = 0.0;
    cout << "Captura la calificación: ";
    cin >> iCalificacion;
    if (iCalificacion<=0 || iCalificacion>10) {
        throw std::runtime_error("Error: Ingresa una calificacion valida ");
    }
    cin.clear();            //LIMPIA EL INDICADOR DE ERROR, SI TECLEA UN VALOR DIFERENTE A NUMERO
    cin.ignore(1000,'\n');  //BORRA UNO O MAS CARACTERES DEL BUFFER, \N ES EL DELIMITADOR O CARACTER FINAL DE ENTRADA
    
    for(int i=0; i<vSeries.size(); i++)
    {
        vSeries[i]->VideosporCalificacion(iCalificacion);
    }
    for(int i=0; i<vPeliculas.size(); i++)
    {
        vPeliculas[i]->VideosporCalificacion(iCalificacion);
    }
}


void Catalogo::VideosporGenero() {
    string sGenero = "";
    cout << "Captura el genero del video: ";
    getline(cin,sGenero);

    if (sGenero.empty()) {
        throw std::runtime_error("Error: Ingresa un genero valido ");
    }

    bool sGeneroEncontrado = false;
    cout << "⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆ Peliculas de "<< sGenero << " ⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆" << endl << endl;
    for(int i=0; i<vPeliculas.size(); i++)
    {
        if ( vPeliculas[i]->PeliculaGenero().find(sGenero) != std::string::npos )  //si hemos llegado al final de nuestra cadena.
        {
            vPeliculas[i]->VideosporGenero(sGenero);
            sGeneroEncontrado = true;
        }
    }

    if (!sGeneroEncontrado) {
        system("clear");
        throw std::runtime_error("Error: Ingresa un genero valido ");
    }

    cout << "⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆ Series de "<< sGenero << " ⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆" << endl << endl;
    
    for(int i=0; i<vSeries.size(); i++)
    {
    
        if ( vSeries[i]->SerieGenero().find(sGenero) != std::string::npos )  //si hemos llegado al final de nuestra cadena.
        {
            vSeries[i]->VideosporGenero(sGenero);
            
        }
    }
}

void Catalogo::EpisodiosPorSerie() 
{
    string sNombre = "";
    cout << "Captura el nombre de la serie: ";
    getline(cin,sNombre);
    bool serieEncontrada = false;

    for(int i=0; i<vSeries.size(); i++)
    {
        if ( vSeries[i]->SerieNombre() == sNombre )
        {
            vSeries[i]->EpisodiosPorSerie(sNombre);
            serieEncontrada = true;
            
        }
    }

    if (!serieEncontrada)
    {
        throw runtime_error("Error: Ingrese una serie del catálogo.");
    }
    
}

void Catalogo::PeliculasporCalificacion() {
    float iCalificacion = 0.0;
    cout << "Captura la calificación: ";
    cin >> iCalificacion;
    if (iCalificacion<=0 || iCalificacion>10) {
        throw std::runtime_error("Error: Ingresa una calificacion valida ");
    }
    cin.clear();            //LIMPIA EL INDICADOR DE ERROR, SI TECLEA UN VALOR DIFERENTE A NUMERO
    cin.ignore(1000,'\n');  //BORRA UNO O MAS CARACTERES DEL BUFFER, \N ES EL DELIMITADOR O CARACTER FINAL DE ENTRADA
    cout << "⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆ PELICULAS CON CALIFICACION MAYOR A "<<iCalificacion<<" ⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆" << endl << endl;
    for(int i=0; i<vPeliculas.size(); i++)
    {
        vPeliculas[i]->PeliculasporCalificacion(iCalificacion);
    }
}

void Catalogo::CalificarVideo() {
    bool bExisteVideo = false;
    float iCalificacion = 0.0;

    string sNombre = "";
    cout << "Captura el nombre del video: ";
    getline(cin,sNombre);
    
    for(int i=0; i<vPeliculas.size(); i++)
    {
        if ( vPeliculas[i]->PeliculaNombre() == sNombre )
            bExisteVideo = true;
    }

    for(int i=0; i<vSeries.size(); i++)
    {
        if ( vSeries[i]->EpisodioNombre(sNombre) == sNombre )
            bExisteVideo = true;
    }

    if ( bExisteVideo )
    {
        try
        {
            cout << "Captura la calificacion para el video " << sNombre << ": " << endl;
            cin >> iCalificacion;
            cin.clear();            //LIMPIA EL INDICADOR DE ERROR, SI TECLEA UN VALOR DIFERENTE A NUMERO
            cin.ignore(1000,'\n');  //BORRA UNO O MAS CARACTERES DEL BUFFER, \N ES EL DELIMITADOR O CARACTER FINAL DE ENTRADA
            if (iCalificacion == 0)
            {
                system("clear");
                throw std::runtime_error("Error, captura una calificacion correcta.");
            }
            system("clear");
            cout << "Calificacion guardada." << endl;
        }
        catch (const exception& p_error)
        {
            system("clear");
            cout << p_error.what() << "\n";
        }   
    }
    else
        cout << "El nombre del video no existe." << endl;
}







void Catalogo::Ordenar_por_NombreArreglo(datos_video *lista, int numElementos)
{ 
    for (int i = 0; i < numElementos-1; i++)     
    {  
        for (int j = 0; j < numElementos-i-1; j++)
        {
            if (lista[j].nombre > lista[j+1].nombre) 
            {
                datos_video temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
} 


void Catalogo::agregarPelicula(Consultas* oConsultas)
{
   vPeliculas.push_back(oConsultas);
}


void Catalogo::agregarSerie(Consultas* oConsultas)
{
   vSeries.push_back(oConsultas);
}
