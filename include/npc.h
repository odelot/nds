#ifndef __INIMIGO_H_
#define __INIMIGO_H_

#include "personagem.h"


#include "inimigo1.h"
#include "inimigo2.h"



//define sub estados
#define IDLE_INIMIGO_1 0
#define IDLE_INIMIGO_2 1

class NPC : public Personagem {

    public:

    NPC (SpriteInfo *spriteInfo, OAM_Manager* oam_manager) : Personagem(spriteInfo,oam_manager) {
        mudaEstado (IDLE,IDLE_INIMIGO_1);
    }

    void configuraSpritesPersonagem ();

    void updateLogic (Controle * controle) {
        
    }

};

#endif