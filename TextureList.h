#include "texture.h"

texture smurfTexture;
texture character;
texture frontpage;
texture game_over;



void textureInit()
{
	smurfTexture.Create("bird.bmp");
	character.Create("background.bmp");
	frontpage.Create("frontpage1.bmp");
	game_over.Create("gameover.bmp");

}
