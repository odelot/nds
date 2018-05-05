#ifndef __PERSONAGEM_H_
#define __PERSONAGEM_H_

#include <nds.h>
#include <math.h>
#include "sprite.h"
#include "sprites.h"
#include "controle.h"
#include "oam-manager.h"



#define SUB_ESTADOS_TAM 13

//definindo estados
#define IDLE 0
#define SOCO 1
#define ANDANDO 2




class Personagem {

    public: 

    Personagem (SpriteInfo *spriteInfo, OAM_Manager* oam_manager) {
        _spriteInfo = spriteInfo;
        /*_estado = IDLE;
        _subEstado = IDLE_1;*/
        _framesDoSprite = 0;
        _framesDaMovimentacao = 0;

        _estadoAntigo = 255;
        _subEstadoAntigo = 255;

        _y = SCREEN_HEIGHT / 2;    
        _x= SCREEN_WIDTH / 2;
        _oam_manager = oam_manager;


        

        _speedX = 0;
        _speedY = 0;


        _maxSpeed = 2;
        _maxFramesDaMovimentacao = 2;

        

    }

    virtual void configuraSpritesPersonagem () = 0;

    void inicializaListaSprites (int tamanho) {
        _sprites = new Sprite[tamanho];
    }



    void configuraSpritePersonagem (
        int estado,
        int subEstado, 
        const unsigned int * tiles, 
        const unsigned short *paleta,
        int proximoEstado,
        int proximoSubEstado,
        int proximoFrame ) {
        
        _sprites[subEstado].tiles = tiles;
        _sprites[subEstado].paleta = paleta;
        _sprites[subEstado].proximoEstado = proximoEstado;
        _sprites[subEstado].proximoSubEstado = proximoSubEstado;
        _sprites[subEstado].proximoFrame = proximoFrame;
        _sprites[subEstado].animado = true;
        _sprites[subEstado].estado = estado;

    }

    void initGfx () {
        configuraSpritesPersonagem ();
        _oamID = _oam_manager->criaSprite64x64x16cores ();
        //_oam_manager->trocaSprite64x64x16 (_oamID,personagem1Tiles,personagem1Pal);
        SpriteInfo * spriteInfo = &_spriteInfo[_oamID]; //TOFIX: criar um mapa de substado e id do sprite
        _spriteAtual = spriteInfo->entry;
        _spriteAtual->isHidden = false;
    }

    void update (Controle * controle) {
        updateLogic (controle);
        updateGfx ();
        updatePos ();
    }

    void move (int speedX, int speedY) {
        /*if (_estado != ANDANDO) {
            mudaEstado (ANDANDO, ANDANDO_1);
        }*/
        _estado = ANDANDO;
        _speedX += speedX;
        _speedY += speedY;

        if (_speedX > _maxSpeed) {
            _speedX = _maxSpeed;
        }
        if (_speedX < -_maxSpeed) {
            _speedX = -_maxSpeed;
        }
        if (_speedY > _maxSpeed) {
            _speedY = _maxSpeed;
        }
        if (_speedY < -_maxSpeed) {
            _speedY = -_maxSpeed;
        }

        /*while ( (abs (_speedX) + abs (_speedY)) > _maxSpeed ) {
            if (_speedX > 0) {
                _speedX -=1;
            }
            if (_speedX < 0) {
                _speedX +=1;
            }
            if (_speedY > 0) {
                _speedY -=1;
            }
            if (_speedY < 0) {
                _speedY +=1;
            }
        }*/
    }

    virtual void updateLogic (Controle * controle) = 0;
     

    void updateGfx () {
         int estadoAntigo = _estado;
         int subestadoAntigo = _subEstado;

         
        if (_framesDoSprite == _sprites[_subEstado].proximoFrame) {
                mudaEstado (_sprites[_subEstado].proximoEstado, _sprites[_subEstado].proximoSubEstado);
                       
        }

        _framesDoSprite += 1;
        if (_subEstado != subestadoAntigo) {
            //tem que trocar o sprite
            const unsigned int* tiles = _sprites[_subEstado].tiles;
            const unsigned short* paleta = _sprites[_subEstado].paleta;
            _oam_manager->trocaSprite64x64x16 (_oamID,tiles,paleta);
        }


    }

    void mudaEstado (int estado, int subEstado) {
        _estadoAntigo = _estado;
        _subEstadoAntigo = _subEstado;

        _subEstado = subEstado;
        _estado = estado;
        _framesDoSprite = 0;
    }

    void updatePos () {
        //if (_framesDaMovimentacao == _maxFramesDaMovimentacao) {
            _spriteAtual->x += _speedX >> 1;
            _spriteAtual->y +=  _speedY >> 1;
            if (_speedX > 0) {
                _speedX -=1;
                _spriteAtual->hFlip = false;
            }
            if (_speedX < 0) {
                _spriteAtual->hFlip = true;
                _speedX +=1;
            }
            if (_speedY > 0) {
                _speedY -=1;
            }
            if (_speedY < 0) {
                _speedY +=1;
            }
        //    _framesDaMovimentacao = 0;
        //} else {
        //    _framesDaMovimentacao += 1;
       //}
    }

    protected:

    SpriteInfo *_spriteInfo;
    byte _estado;
    byte _subEstado;

    byte _estadoAntigo;
    byte _subEstadoAntigo;


    unsigned short _framesDoSprite; 
    SpriteEntry * _spriteAtual;
    OAM_Manager* _oam_manager;

    int _x;
    int _y;

    unsigned short _framesDaMovimentacao; 
    unsigned short _maxFramesDaMovimentacao; 
    int _speedX;
    int _speedY;
    int _maxSpeed;

    int _oamID;

    

    Sprite *_sprites;


};

#endif
