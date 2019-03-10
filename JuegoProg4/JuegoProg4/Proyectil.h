#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class Proyectil : public sf::CircleShape
{
public:

	int dirx;
	int diry;
	Proyectil(int x, int y);

	Vector2f getDirUp();
	Vector2f getDirDown();
	Vector2f getDirLeft();
	Vector2f getDirRight();

	~Proyectil();
};

