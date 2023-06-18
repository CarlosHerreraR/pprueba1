#include "Plataforma.h"
#include "Catalogo.h"

Plataforma::Plataforma()
{
    system("clear");
    bool bSalir = false;
        
    while (!bSalir)
    {
        string sUsuario = "";
        string sContrasena = "";
        cout << "⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆ BIENVENIDO A NETFLIX ⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆" << endl;
        cout << "Captura tu usuario:" << endl;
        cin >> sUsuario;
        cin.clear();            //LIMPIA EL INDICADOR DE ERROR, SI TECLEA UN VALOR DIFERENTE A NUMERO
        cin.ignore(1000,'\n');  //BORRA UNO O MAS CARACTERES DEL BUFFER, \N ES EL DELIMITADOR O CARACTER FINAL DE ENTRADA
        cout << "Captura tu contraseña:" << endl;
        cin >> sContrasena;
        cin.clear();            //LIMPIA EL INDICADOR DE ERROR, SI TECLEA UN VALOR DIFERENTE A NUMERO

        if ( sUsuario != "" && sContrasena != "" )
        {
            bSalir = true;
            system("clear");
            Menu();
        }
        else
        {
            system("clear");
            cout << "Captura el usuario y la contraseña correcta" << endl;
        }
    }
}

void Plataforma::Menu() {
    bool bSalir = false;
    Catalogo oCatalogo;
    oCatalogo.CargaVideos();  
    while (!bSalir)
    {
        int iOpcion = 0;
        cout << endl << "🡹      🡹       🡹       🡹       🡹       🡹       🡹" << endl;
        cout << endl << "⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆ MENU ⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆" << endl;
        cout << "Selecciona una opción:" << endl;
        cout << "1 - Ver todo el catálogo" << endl;
        cout << "2 - Consultar videos por mayor calificación" << endl;
        cout << "3 - Consultar videos por genero" << endl;
        cout << "4 - Consultar episodios de una serie" << endl;
        cout << "5 - Consultar peliculas por mayor calificación" << endl;
        cout << "6 - Calificar un video" << endl;
        cout << "7 - Salir" << endl;
        cout << "⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆" << endl;
        cin >> iOpcion;
        cin.clear();            //LIMPIA EL INDICADOR DE ERROR, SI TECLEA UN VALOR DIFERENTE A NUMERO
        cin.ignore(1000,'\n');  //BORRA UNO O MAS CARACTERES DEL BUFFER, \N ES EL DELIMITADOR O CARACTER FINAL DE ENTRADA
        try
        {
            if (iOpcion == 0)
            {
                system("clear");
                throw std::runtime_error("Error, selecciona una opcion correcta.");
            }
        }
        catch (const exception& p_error)
        {
            system("clear");
            cout << p_error.what() << "\n";
        }        


        if ( iOpcion == 1 )
        {
            system("clear");
            oCatalogo.VerTodo();  
        }
        else if ( iOpcion == 2 )
        {
            
            system("clear");
            try{
            oCatalogo.VideosporCalificacion();
            }
            catch (const std::exception& e) {
                    std::cerr << "Error: Ingresa una calificacion valida." << std::endl;
                }
        }
        else if ( iOpcion == 3 )
        {
            system("clear");
            
            try {
                    oCatalogo.VideosporGenero();
                } 
            catch (const std::exception& e) {
                    std::cerr << "Error: Ingresa un genero valido." << std::endl;
                }


            
        }
        else if ( iOpcion == 4 )
        {
            
            try{
                system("clear");
                oCatalogo.EpisodiosPorSerie();
            }
            catch (const exception& e){
                    cout << e.what() << endl;
            }
            
        }
        else if ( iOpcion == 5 )
        {
            system("clear");
            try{
                oCatalogo.PeliculasporCalificacion();
            }
            catch (const std::exception& e) {
                    std::cerr << "Error: Ingresa una calificacion valida." << std::endl;
                }
        }
        else if ( iOpcion == 6 )
        {
            system("clear");
            oCatalogo.CalificarVideo();
        }
        else if ( iOpcion == 7 )
        {
            bSalir = true;
            system("clear");
        }
        else if ( iOpcion != 0 )
        {
            system("clear");
            cout << "Captura una opción correcta." << endl;
        }
    }
}
