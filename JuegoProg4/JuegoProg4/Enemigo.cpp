#include "Enemigo.h"
#include "Cofre.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <thread>
#include <stdio.h>
#include "Mapa.h"
#include "Proyectil.h"

sf::RenderWindow window;

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
int j = 1;
float xb = 100.0f;
std::vector<Proyectil> disparosene;

void Enemigo::cargarbala(Mapa m)//Elimina las balas si se golpean con la pared
{
	for (size_t i = 0; i < disparosene.size(); i++)
	{
		disparosene[i].move(disparosene[i].dirx, disparosene[i].diry);

		if (disparosene[i].getGlobalBounds().intersects(m.conjParedes[0].getGlobalBounds())
			|| disparosene[i].getGlobalBounds().intersects(m.conjParedes[1].getGlobalBounds()) || disparosene[i].getGlobalBounds().intersects(m.conjParedes[2].getGlobalBounds())
			|| disparosene[i].getGlobalBounds().intersects(m.conjParedes[3].getGlobalBounds()))
		{
			disparosene.erase(disparosene.begin() + i);
			printf("Bala fuera");
		}
	}
}

void Enemigo::movimiento()
{
	int random = rand() % 15;

	if (random == 1)
	{
		
	}
	if (random == 2)
	{

	}
	if (random == 3)
	{

	}
	if (random == 4)
	{

	}
	else
	{

	}
}


void Enemigo::disparoe(sf::RenderWindow& windowsup)
{
	bool ward = false;
	using namespace std::literals::chrono_literals;
	Proyectil disparoRe(10, 0); //Dispara hacia el lado derecho
	std::vector<Proyectil> disparoseneene;
	disparoRe.setPosition(xb, 100.0f);
	int bcount=0;
	while (ward != true)
	{
	
		printf("Iteración numero %i\n", j);
		
		std::this_thread::sleep_for(10ms);//18000 IQ
		if (j % 10 == 0) //Caada 100ms la bala se mueve
		{
			xb = xb + 10.75f; //El movimiento es doble

		}
		if (j % 40 == 0) 
		{
			disparoRe.setPosition(100.0f,100.0f);//En este vector deberia ir la pos enemiga
			disparoseneene.push_back(disparoRe);
			disparoRe.move(xb, 0);//Se movera xb pixels pixels (ya no tan necesaria por el metodo de abajo)
			printf("posicion del proyectil es (%f) y (%f)\n ", disparoRe.getPosition().x, disparoRe.getPosition().y);
			for (size_t i = 0; i < disparosene.size(); i++)
			{

				bcount++;
				//	windowsup.draw(disparosene[i]);
			}
			//printf("adsajafgfjgygajya");

		}
		if (j == 402) 
		{
			j = 2;
		}
		j++;
		ward = true;
	}
}

/*
void Enemigo::limpiarbal(Cofre f,Mapa m)
{
	f;	
	m;
	for (size_t i = 0; i < disparosene.size(); i++)
	{
		disparosene[i].move(disparosene[i].dirx, disparosene[i].diry);

		if (disparosene[i].getGlobalBounds().intersects(f.getGlobalBounds()) || disparosene[i].getGlobalBounds().intersects(m.conjParedes[0].getGlobalBounds())
			|| disparosene[i].getGlobalBounds().intersects(m.conjParedes[1].getGlobalBounds()) || disparosene[i].getGlobalBounds().intersects(m.conjParedes[2].getGlobalBounds())
			|| disparosene[i].getGlobalBounds().intersects(m.conjParedes[3].getGlobalBounds()))
		{
			disparosene.erase(disparosene.begin() + i);
		}
	}
}
*/