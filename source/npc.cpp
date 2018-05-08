#include "npc.h"

void NPC::configuraSpritesPersonagem () {
        inicializaListaSprites (2);
        configuraSpritePersonagem (IDLE, IDLE_INIMIGO_1, inimigo1Tiles, inimigo1Pal, IDLE, IDLE_INIMIGO_2, 20);
        configuraSpritePersonagem (IDLE, IDLE_INIMIGO_2, inimigo2Tiles, inimigo2Pal, IDLE, IDLE_INIMIGO_1, 20);
        
    }