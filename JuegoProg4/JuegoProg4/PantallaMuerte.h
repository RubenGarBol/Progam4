#pragma once
#include "SFML/Graphics.hpp"
#include "Mapa.h"
#include "Personaje.h"

class PantallaMuerte
{
public:

	sf::Texture texturamuerte;

	sf::Sprite you_died;

	sf::Clock clock_muerte;

	float opacidadmuerte;


	PantallaMuerte(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player);
	~PantallaMuerte();
};

