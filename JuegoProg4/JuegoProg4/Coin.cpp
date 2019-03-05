#include "Coin.h"
#include "SFML/Graphics.hpp"

Coin::Coin() 
{
	textura.loadFromFile("./res/Imagenes/coin.png");
	setTexture(textura);
}
