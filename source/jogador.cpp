#include "jogador.h"

void Jogador::configuraSpritesPersonagem () {
        inicializaListaSprites (13);
        configuraSpritePersonagem (IDLE, IDLE_JOGADOR_1, personagem1Tiles, personagem1Pal, IDLE, IDLE_JOGADOR_2, 10);
        configuraSpritePersonagem (IDLE, IDLE_JOGADOR_2, personagem2Tiles, personagem2Pal, IDLE, IDLE_JOGADOR_3, 10);
        configuraSpritePersonagem (IDLE, IDLE_JOGADOR_3, personagem3Tiles, personagem3Pal, IDLE, IDLE_JOGADOR_4, 10);
        configuraSpritePersonagem (IDLE, IDLE_JOGADOR_4, personagem2Tiles, personagem2Pal, IDLE, IDLE_JOGADOR_1, 10);

        configuraSpritePersonagem (SOCO, SOCO_JOGADOR_1, personagem4Tiles, personagem4Pal, SOCO, SOCO_JOGADOR_2, 5);
        configuraSpritePersonagem (SOCO, SOCO_JOGADOR_2, personagem5Tiles, personagem5Pal, SOCO, SOCO_JOGADOR_3, 5);
        configuraSpritePersonagem (SOCO, SOCO_JOGADOR_3, personagem4Tiles, personagem4Pal, IDLE, IDLE_JOGADOR_1, 5);

        configuraSpritePersonagem (ANDANDO, ANDANDO_JOGADOR_1, personagem6Tiles, personagem6Pal, ANDANDO, ANDANDO_JOGADOR_2, 10);
        configuraSpritePersonagem (ANDANDO, ANDANDO_JOGADOR_2, personagem7Tiles, personagem7Pal, ANDANDO, ANDANDO_JOGADOR_3, 10);
        configuraSpritePersonagem (ANDANDO, ANDANDO_JOGADOR_3, personagem8Tiles, personagem8Pal, ANDANDO, ANDANDO_JOGADOR_4, 10);
        configuraSpritePersonagem (ANDANDO, ANDANDO_JOGADOR_4, personagem9Tiles, personagem9Pal, ANDANDO, ANDANDO_JOGADOR_5, 10);
        configuraSpritePersonagem (ANDANDO, ANDANDO_JOGADOR_5, personagem10Tiles, personagem10Pal, ANDANDO, ANDANDO_JOGADOR_6, 10);
        configuraSpritePersonagem (ANDANDO, ANDANDO_JOGADOR_6, personagem11Tiles, personagem11Pal, ANDANDO, ANDANDO_JOGADOR_1, 10);
    }