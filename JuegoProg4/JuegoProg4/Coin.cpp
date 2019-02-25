#include "Coin.h"
#include "SFML/Graphics.hpp"

Coin::Coin(Vector2f vector) {

	textura.loadFromFile("./res/Imagenes/moneda.png");
	setTexture(textura);
	setPosition(vector);
}