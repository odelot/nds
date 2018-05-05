#ifndef _SPRITE_H_
#define _SPRITE_H_

class Sprite {

    public:

    Sprite () {
        animado = false;
    }

    const unsigned int* tiles;
    const unsigned short* paleta;
    bool animado;
    int estado;
    int proximoEstado;
    int proximoSubEstado;
    int proximoFrame;


};

#endif