#pragma once
#include "SFML/Audio.hpp"
#include <iostream>

class GestorSonido
{
public:
	sf::SoundBuffer buffer_moneda;
	sf::Sound sonido_moneda;
	
	sf::SoundBuffer buffer_daño_personaje;
	sf::Sound sonido_daño_personaje;

	sf::SoundBuffer buffer_muerte_personaje;
	sf::Sound sonido_muerte_personaje;
	
	sf::SoundBuffer buffer_pared;
	sf::Sound sonido_pared;

	sf::Music musica_juego;
	sf::Music musica_menu;

	GestorSonido();
	~GestorSonido();
};

