#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class Proyectil : public sf::CircleShape
{
public:

	float dirx;
	float diry;
	Proyectil(float x, float y);

	~Proyectil();
};

