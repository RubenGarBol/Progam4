#include "Personaje.h"
#include "SFML/Graphics.hpp"

Personaje::Personaje(sf::Texture &textura) :Sprite(textura), Animacion(&textura, Vector2u(4, 4), 0.15) {
	anim = 0;
	animd = 0;
	setTexture(textura);
	texture = textura;

	posicion.x = 200.0f;
	posicion.y = 200.0f;
	velocidad = 4;

	setPosition(posicion.x, posicion.y);

}

