#include "SFML/Graphics.hpp"

using namespace sf;

class Item : public Sprite {
public:
	Texture textura;
	Vector2f posicion;
	double puntos;

	Item(Vector2f vector);

};


