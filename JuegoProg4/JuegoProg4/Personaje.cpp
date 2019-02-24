#include "Personaje.h"
#include "SFML/Graphics.hpp"

Personaje::Personaje() {
	posicion.x = 616;
	posicion.y = 160;
	velocidad = 4;

	textura.loadFromFile("./res/Imagenes/roca.png");
	setTexture(textura);
	setPosition(posicion.x, posicion.y);

}

