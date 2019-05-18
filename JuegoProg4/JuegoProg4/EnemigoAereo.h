#pragma once
#include "SFML/Graphics.hpp"
#include "Mapa.h"
#include <vector>
#include <stdlib.h>

class EnemigoAereo
{
public:

	sf::RectangleShape enemigo;
	int veloc_mov;
	int counter;
	int random;

	EnemigoAereo();
	~EnemigoAereo();

	void movimiento(Mapa mapaCompleto);
	void disparo();
};

