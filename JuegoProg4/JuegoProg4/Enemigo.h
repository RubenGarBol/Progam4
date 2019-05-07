#pragma once
#include "Mapa.h"
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
	//Va a ser un enemigo estático así que la velocidad es 0

	Enemigo(Vector2f pos,int danyo, int vida,int espeed, Texture& texture);
	~Enemigo();

	void disparoe(sf::RenderWindow* windowsup);
	void cargarbala(Mapa m);
//	void limpiarbal(Cofre f, Mapa m);


};
