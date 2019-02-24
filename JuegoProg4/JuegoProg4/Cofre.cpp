#include "Cofre.h"
#include "SFML/Graphics.hpp"

Cofre::Cofre(Vector2f vector) {
	textura.loadFromFile("./res/Imagenes/chest.png");
	setTexture(textura);
	posicion.x = vector.x;
	posicion.y = vector.y;
	setPosition(posicion.x,posicion.y);
}

