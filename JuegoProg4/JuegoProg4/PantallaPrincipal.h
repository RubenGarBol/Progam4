#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Animacion.h"
#include "Mapa.h"
#include "Personaje.h"
#include <iostream>
#include "PantallaJuego.h"

class PantallaPrincipal
{
public:

	sf::Texture textura_pprincipal;

	sf::RectangleShape playboton;

	sf::Clock clock_pprincipal;

	sf::Font font;

	sf::Text play_pprincipal;
	sf::Text opciones_pprincipal;
	sf::Text salir_pprincipal;

	sf::Sprite sprite_pprincipal;

	sf::Vector2u vector_pprincipal;

	sf::Vector2i mousePos;
	sf::Vector2f mousePosF;

	Animacion animacion_pprincipal;

	float delta_pprincipal = 0.0f;
	int seleccion;

	PantallaPrincipal(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player, sf::Texture& cursortexture, sf::Sprite& cursor, PantallaJuego& pjuego);
	~PantallaPrincipal();
};

