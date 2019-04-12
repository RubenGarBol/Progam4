#include "Enemigo.h"
#include <iostream>
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

void Enemigo::disparoe()
{
	Proyectil disparoRe(10, 0); //Dispara hacia el lado derecho
	std::vector<Proyectil> disparosene;
	disparoRe.setPosition(100.0f, 100.0f);
	sf::Clock temporizador;
	int x = temporizador.getElapsedTime().asSeconds();
	printf("IM A SKAT MAN ");
	int j=0;
	/*
	// Para comprobar que x asciende
	if (x = 0)
	{
		printf("Secuendo %i", x);
		disparoRe.move(10.0f, 0);
	}
	if (x = 1)
	{
		printf("Secuendo %i", x);
		disparoRe.move(10.0f, 0);
	}
	if (x = 2)
	{
		printf("Secuendo %i", x);
		disparoRe.move(10.0f, 0);
	}
	if (x = 3)
	{
		printf("Secuendo %i", x);
		disparoRe.move(10.0f, 0);
	}

	if (x = 4)
	{
		disparoRe.move(10.0f, 0);
		printf("posicion del proyectil es (%f) y (%f) ", disparoRe.getPosition().x, disparoRe.getPosition().y);
		//No se mueven solo son introducidas en el array
	//	disparosene.push_back(Proyectil(disparoRe));
		temporizador.restart().asSeconds();
		x = 0;
	}*/
	printf("El tiempo es... %i", x);
	
	do
	{
		if (x = 0)
		{
			printf("Secuendo %i", x);
			disparoRe.move(10.0f, 0);
		}
		if (x = 1)
		{
			printf("Secuendo %i", x);
			disparoRe.move(10.0f, 0);
		}
		if (x = 2)
		{
			printf("Secuendo %i", x);
			disparoRe.move(10.0f, 0);
		}
		if (x = 3)
		{
			printf("Secuendo %i", x);
			disparoRe.move(10.0f, 0);
		}

		if (x = 4)
		{
			disparoRe.move(10.0f, 0);
			printf("posicion del proyectil es (%f) y (%f) ", disparoRe.getPosition().x, disparoRe.getPosition().y);
			//No se mueven solo son introducidas en el array
		//	disparosene.push_back(Proyectil(disparoRe));
			temporizador.restart().asSeconds();
			x = 0;
			j++;
		}
		printf("El tiempo es... %i", x);
	}while (j <= 5);
	//	std::cout << "Thread" << std::end;
	
}

