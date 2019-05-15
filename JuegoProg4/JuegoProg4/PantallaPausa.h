#pragma once
#include "SFML/Graphics.hpp"
#include "Mapa.h"
#include "Personaje.h"

class PantallaPausa
{
public:
	int seleccion = 1;

	float opacidadint = 0;
	float opacidadext = 0;
	float opacidadtextint = 0;
	float opacidadtextext = 0;
	float opacidadint1 = 140;
	float opacidadext1 = 255;
	float opacidadtextint1 = 255;
	float opacidadtextext1 = 255;

	sf::RectangleShape rectangle;
	sf::RectangleShape playboton;
	sf::Text play;
	sf::Text opciones;
	sf::Text salir;
	sf::Font font;
	sf::Texture cursortexture;
	sf::Texture cursortexturepressed;
	sf::Sprite cursor; 

	PantallaPausa(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player);
	~PantallaPausa();
};

