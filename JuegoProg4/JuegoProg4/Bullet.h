#include "SFML/Graphics.hpp"

using namespace sf;

class Bullet : public sf::Sprite {
public:
	Texture textura;
	Vector2f posicion;
	double speed;
	int existe;//0 no, 1 si. Pensado para eliminar el sprite del objeto

	Bullet(Vector2f posicion);

	~Bullet();

};



