#include "Enemigo.h"
#include "SFML/Graphics.hpp"


Enemigo::Enemigo(Vector2f pos, int danyo, int vida, int espeed, Texture& texture)
{
	danyo = 0;
	vida = 0;
	espeed = 10;
	setPosition(pos);
	setTexture(texture);
}

Enemigo::~Enemigo()
{
}

void disparoe(Proyectil p) 
{
		Proyectil disparoRe(10, 0); //Dispara hacia el lado derecho
		std::vector<Proyectil> disparosene;
		sf::Clock temporizador;
		if (temporizador.getElapsedTime().asSeconds() == 4)
		{
			//No se mueven solo son intrudicdas en el array
			disparosene.push_back(Proyectil(disparoRe));
			temporizador.restart();
		}
		printf("El tiempo es... %i", temporizador);
	
}

