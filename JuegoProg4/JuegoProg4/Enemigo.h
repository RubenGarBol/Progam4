
#pragma once
#include "Personaje.h"
#include "SFML/Graphics.hpp"
#include "Proyectil.h"


using namespace sf;

class Enemigo : public Sprite
{
public:

	Texture texture;
	int danyo;
	int vida;
	int espeed;
	//Va a se un enemigo estático asi que la velocidad es 0
	Enemigo(Vector2f pos,int danyo, int vida,int espeed, Texture& texture);
	~Enemigo();

	void disparoe(Proyectil p) {}
};
