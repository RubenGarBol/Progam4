#pragma once
   #include "SFML/Graphics.hpp"
#include "Animacion.h"

using namespace sf;

class Mapa : public sf::Sprite , public Animacion
{
	public:
		Texture texture;
		Clock timer;
		float deltatiempo = 0.0f;
		


		RectangleShape conjParedes[4];
		RectangleShape conjPuertas[4];

		Mapa(Texture& textura, RectangleShape paredes[4], RectangleShape puertas[4]);

	RectangleShape getPuertaIz();
	RectangleShape getPuertaDe();
	RectangleShape getPuertaAr();
	RectangleShape getPuertaAb();

	~Mapa();
};

