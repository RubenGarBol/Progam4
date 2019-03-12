#include "Enemigo.h"

#include "SFML/Graphics.hpp"


Enemigo::Enemigo(Vector2f pos, int danyo, int vida, Texture& texture)
{
	//texture.loadFromFile("./res/Imagenes/coin.png");
	danyo = 0;
	vida = 0;
	
	setPosition(pos);
	setTexture(texture);

	
}

void Enemigo::track(Personaje p1)
{

}  

Enemigo::~Enemigo()
{
}
