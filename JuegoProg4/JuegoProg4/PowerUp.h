#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Personaje.h"

class PowerUp : sf::Sprite
{
public:
	sf::Texture textura_vel_ataque;
	sf::Texture textura_vel_mov;

	sf::Sprite Poti_A;
	sf::Sprite Poti_B;

	sf::Vector2f pos;

	PowerUp();
	void PickUp(Personaje& player, float* veloc, float* delaytiro);
	~PowerUp();
};

