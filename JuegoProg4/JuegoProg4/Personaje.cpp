
#include "Personaje.h"
#include "Enemigo.h"
#include "SFML/Graphics.hpp"


Personaje::Personaje(sf::Texture &textura) :Sprite(textura), Animacion(&textura, Vector2u(4, 4), 0.15) {
	anim = 0;
	animd = 0;
	
	texture = textura;
	setTexture(texture);

	posicion.x = 200.0f;
	posicion.y = 200.0f;
	velocidad = 4;
	vida = 6;
	setPosition(posicion.x, posicion.y);

}


	
/*
void inmune(Personaje p, Enemigo e)
{
	if (p.getGlobalBounds().intersects(e.getGlobalBounds()))
	{
		sf::Clock temporizador;
		if (temporizador.getElapsedTime().asSeconds() == 4)
		{
			p.vida = p.vida - 1;
			temporizador.restart();
			printf("%i La vida es...", p.vida);
		}
		printf("El tiempo es... %i", temporizador);
	}
}
*/

