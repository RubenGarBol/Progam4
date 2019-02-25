#include "SFML/Graphics.hpp"

using namespace sf;

class Coin : public sf::Sprite {
public:
	Texture textura;
	Vector2f posicion;

	Coin(Vector2f vector);

};
