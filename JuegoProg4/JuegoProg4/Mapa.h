#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Mapa : public sf::Sprite {
	public:
		Texture texture;

		RectangleShape conjParedes[4];
		RectangleShape conjPuertas[4];

	Mapa(Texture& textura, RectangleShape paredes[4], RectangleShape puertas[4]);

	RectangleShape getPuertaIz();
	RectangleShape getPuertaDe();
	RectangleShape getPuertaAr();
	RectangleShape getPuertaAb();



	~Mapa();
};

