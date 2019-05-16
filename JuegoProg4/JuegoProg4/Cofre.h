#include "SFML/Graphics.hpp"
#pragma once

using namespace sf;

class Cofre : public sf::Sprite {
	public:
		Texture textura;
		Vector2f posicion;

		Cofre();
		Cofre(Vector2f vector);

};

