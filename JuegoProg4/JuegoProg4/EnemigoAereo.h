#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <stdlib.h>
#include "Personaje.h"
#include "Proyectil.h"


class EnemigoAereo
{
public:

	sf::RectangleShape enemigo; 
	sf::Vector2f centrar;

	int veloc_mov;
	int counter;
	int counter2;
	int random;
	int random2;
	float delaytiro;

	Proyectil disparoup;
	Proyectil disparodown;
	Proyectil disparoR;
	Proyectil disparoL;

	std::vector<Proyectil> disparos;

	EnemigoAereo();
	EnemigoAereo(int posx, int posy);
	~EnemigoAereo();

	void movimiento();
	void disparo();
};

