#include <SFML/Graphics.hpp>
#include "Item.h"

Item::Item(Vector2f vector) 
{
	
	puntos = 100.0;
	textura.loadFromFile("./res/Imagenes/moneda.png");
	setTexture(textura);
	setPosition(vector);

}
