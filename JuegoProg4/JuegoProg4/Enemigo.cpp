#include "Enemigo.h"



Enemigo::Enemigo(Vector2f size, int danyo, int vida, int ptos, Texture &texture)
{
	//texture.loadFromFile("./res/Imagenes/coin.png");
	//setTexture(texture);
	danyo = 0;
	vida = 0;
	ptos = 0;
	size.x = 0;
	size.y = 0;
	
	setSize(size);
}



Enemigo::~Enemigo()
{
}
