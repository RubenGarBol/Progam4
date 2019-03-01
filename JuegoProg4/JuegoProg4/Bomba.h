#include "SFML/Graphics.hpp"

using namespace sf;

class Bomba : public sf::Sprite {
public:
	Texture textura;
	Vector2f posicion;

	Bomba(Vector2f vector);

};
