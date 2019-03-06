#include "SFML/Graphics.hpp"

using namespace sf;

class Coin : public sf::Sprite {
public:
	Texture textura;
	Texture texturapuntos;
	Vector2f posicion;

	Coin();
};
