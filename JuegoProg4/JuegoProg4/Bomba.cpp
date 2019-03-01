#include "Bomba.h"
#include "SFML/Graphics.hpp"

Bomba::Bomba(Vector2f vector) {
	textura.loadFromFile("./res/Imagenes/bomba.png");
	setTexture(textura);
	posicion.x = vector.x;
	posicion.y = vector.y;
	setPosition(posicion.x, posicion.y);
}


