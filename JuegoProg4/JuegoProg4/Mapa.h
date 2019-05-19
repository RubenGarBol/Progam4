#pragma once
#include "SFML/Graphics.hpp"
#include "Animacion.h"
#include "Coin.h"
#include "EnemigoAereo.h"
#include <vector>

using namespace sf;

class Mapa : public Sprite , public Animacion
{
	public:
		Texture texture;
		Clock timer;

		float deltatiempo = 0.0f;

		std::vector<Coin> coin = std::vector<Coin>(7);
		std::vector<RectangleShape> colisiones = std::vector<RectangleShape>(15);
		std::vector<RectangleShape> colisiones_daño = std::vector<RectangleShape>(15);
		std::vector<EnemigoAereo> enemigo = std::vector<EnemigoAereo>(5);

		RectangleShape conjParedes[4];
		RectangleShape conjPuertas[4];

		Mapa(Texture& textura, RectangleShape paredes[4], RectangleShape puertas[4], std::vector<Coin> coin, std::vector<RectangleShape> colisiones, std::vector<RectangleShape> colisiones_daño, std::vector<EnemigoAereo> enemigo);

		RectangleShape getPuertaIz();
		RectangleShape getPuertaDe();
		RectangleShape getPuertaAr();
		RectangleShape getPuertaAb();
		
		Mapa();
		~Mapa();
};

