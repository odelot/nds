#ifndef __JOGADOR_H_
#define __JOGADOR_H_

#include "personagem.h"


#include "personagem1.h"
#include "personagem2.h"
#include "personagem3.h"
#include "personagem4.h"
#include "personagem5.h"

#include "personagem6.h"
#include "personagem7.h"
#include "personagem8.h"
#include "personagem9.h"
#include "personagem10.h"
#include "personagem11.h"


//define sub estados
#define IDLE_JOGADOR_1 0
#define IDLE_JOGADOR_2 1
#define IDLE_JOGADOR_3 2
#define IDLE_JOGADOR_4 3
#define SOCO_JOGADOR_1 4
#define SOCO_JOGADOR_2 5
#define SOCO_JOGADOR_3 6

#define ANDANDO_JOGADOR_1 7
#define ANDANDO_JOGADOR_2 8
#define ANDANDO_JOGADOR_3 9
#define ANDANDO_JOGADOR_4 10
#define ANDANDO_JOGADOR_5 11
#define ANDANDO_JOGADOR_6 12

class Jogador : public Personagem {

    public:

    Jogador (SpriteInfo *spriteInfo, OAM_Manager* oam_manager) : Personagem(spriteInfo,oam_manager) {
        mudaEstado (IDLE,IDLE_JOGADOR_1);
    }

    void configuraSpritesPersonagem ();

    void updateLogic (Controle * controle) {
        
        if (_estado != SOCO) {
            
            if (controle->left || controle->right || controle->up || controle->down){
                if (_estado != ANDANDO) {
                    mudaEstado (ANDANDO, ANDANDO_JOGADOR_1);
                }    
            }
            if (controle->left) {
                move (-2,0);
            }
            if (controle->right) {
                move (2,0);
            }
            if (controle->up) {
                move (0,-2);
            }
            if (controle->down) {
                move (0,+2);
            }
        }
        if (_estado == ANDANDO) {
            if (!controle->left && !controle->right && !controle->down && !controle->up ) {
                mudaEstado (IDLE, IDLE_JOGADOR_1);
            }
        }

        if (_estado != SOCO) {
            if (controle->old_a == false && controle->a == true) {
                mudaEstado (SOCO, SOCO_JOGADOR_1);
            }

        }
    }

};

#endif