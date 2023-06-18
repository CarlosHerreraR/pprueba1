#ifndef _VIDEO_H
#define _VIDEO_H
#include <string>
using namespace std;

#include <iostream>

class Video{
    
    public:
        string id;
        string nombre;
        int duracion;
        float calificacion;
        int totalCalificaciones;
        string fecha_estreno;

        Video();
        Video(string p_id, string p_nombre, int p_duracion, float p_calificacion, string p_fecha_estreno);
        string ConsultaVideos();
        string VideosporCalificacion(float p_calificacion);
        int getTotalCalificaciones() const;
        void setTotalCalificaciones(int total);

};

#endif 

