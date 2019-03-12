#pragma once
#include "SFML/Graphics.hpp"
#include "Personaje.h"

using namespace sf;

class Enemigo :public Sprite
{
public:

	Texture texture;
	int danyo;
	int vida;


	Enemigo(Vector2f pos,int danyo, int vida, Texture& texture);
	void track(Personaje p1);
	~Enemigo();
};

