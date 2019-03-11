#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Enemigo :public sf::RectangleShape
{
public:

	Texture texture;
	int danyo;
	int vida;
	int ptos;
	Vector2f size;

	Enemigo(Vector2f size, int danyo, int vida, int ptos, Texture &texture);

	~Enemigo();
};

