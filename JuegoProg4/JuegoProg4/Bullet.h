#include "SFML/Graphics.hpp"

using namespace sf;

class Bullet : public sf::Sprite {
public:
	Texture textura;
	Vector2f posicion;
	double speed;

	Bullet(Vector2f posicion);

	~Bullet();

};



