#ifndef _OAM_MANAGER_
#define _OAM_MANAGER_

#include <nds.h>
#include <assert.h>
#include "sprites.h"

class OAM_Manager {

    public:
        OAM_Manager (SpriteInfo *spriteInfo, OAMTable *oam ) {
           _proximoId = 0; 
           _proximoEndMemoria = 0;
           _spriteInfo = spriteInfo;
           _oam = oam;
        }

        void trocaSprite64x64x16 (int oamID,const unsigned int* tiles,const unsigned short* palheta) {
            
            static const int COLORS_PER_PALETTE = 16;
            static const int BOUNDARY_VALUE = 32; /* This is the default boundary value
                                                * (can be set in REG_DISPCNT) */
            static const int OFFSET_MULTIPLIER = BOUNDARY_VALUE /
                                                sizeof(SPRITE_GFX[0]);
            /* 64 linhas x 8 pixels de coluna x 4 bytes de profundidade */                                                
            int tamanhoTiles = 2048;
            //16 cores x 2 bytes de profunidade
            int tamanhoPaleta = 32;
            /* Copy over the sprite palettes */
            SpriteInfo * personagem1Info = &_spriteInfo[oamID];
            SpriteEntry * personagem1 = &_oam->oamBuffer[oamID];
            dmaCopyHalfWords(SPRITE_DMA_CHANNEL,
                            palheta,
                            &SPRITE_PALETTE[personagem1Info->oamId *
                                            COLORS_PER_PALETTE],
                            tamanhoPaleta);


            /* Copy the sprite graphics to sprite graphics memory */
            dmaCopyHalfWords(SPRITE_DMA_CHANNEL,
                            tiles,
                            &SPRITE_GFX[personagem1->gfxIndex * OFFSET_MULTIPLIER],
                            tamanhoTiles);
        }

        int criaSprite64x64x16cores () {
            int tamanhoTiles = 2048;
            static const int BYTES_PER_16_COLOR_TILE = 32;
            /* Keep track of the available tiles */
            

            /* Create the ship sprite. */
            int OAM_ID = _proximoId++;

            assert(OAM_ID < SPRITE_COUNT);
            SpriteInfo * personagem1Info = &_spriteInfo[OAM_ID];
            SpriteEntry * personagem1 = &_oam->oamBuffer[OAM_ID];

            /* Initialize personagemInfo */
            personagem1Info->oamId = OAM_ID;
            personagem1Info->width = 64;
            personagem1Info->height = 64;
            personagem1Info->angle = 0;
            personagem1Info->entry = personagem1;

            /*
            *  Configure attribute 0.
            *
            *  OBJCOLOR_16 will make a 16-color sprite. 
            */
            personagem1->y = SCREEN_HEIGHT / 2 - personagem1Info->height;
            personagem1->isRotateScale = false;
            personagem1->isHidden = true;
            personagem1->blendMode = OBJMODE_NORMAL;
            personagem1->isMosaic = false;
            personagem1->colorMode = OBJCOLOR_16;
            
            personagem1->shape = OBJSHAPE_SQUARE;
            /*
            *  Configure attribute 1.
            *
            *  OBJSIZE_64, in our case
            *  since we are making a square sprite, creates a 64x64 sprite.
            */
            personagem1->x = SCREEN_WIDTH / 2 - personagem1Info->width * 2 +
                            personagem1Info->width / 2;
            personagem1->hFlip = false;
            personagem1->vFlip = false;
            personagem1->size = OBJSIZE_64;
        
            /*
            *  Configure attribute 2.
            *
            *  Configure which tiles the sprite will use, which priority layer it will
            *  be placed onto, which palette the sprite should use, and whether or not
            *  to show the sprite.
            */
            personagem1->gfxIndex = _proximoEndMemoria;
            _proximoEndMemoria += tamanhoTiles / BYTES_PER_16_COLOR_TILE;
            personagem1->priority = OBJPRIORITY_0;
            personagem1->palette = personagem1Info->oamId;

            /* Rotate the sprite */
            /*rotateSprite(&oam->matrixBuffer[personagem1Info->oamId],
                        personagem1Info->angle);*/

            /*************************************************************************/
            return OAM_ID;

            
            /*************************************************************************/

            
        }

    private: 

        int _proximoId;
        int _proximoEndMemoria;
        SpriteInfo *_spriteInfo;
        OAMTable *_oam;

};

#endif