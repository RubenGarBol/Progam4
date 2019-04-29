#include "Enemigo.h"
#include "Cofre.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <thread>
#include <stdio.h>
#include "Mapa.h"
#include "Proyectil.h"


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
void Enemigo::disparoe()
{
	bool ward = false;
	using namespace std::literals::chrono_literals;
	Proyectil disparoRe(10, 0); //Dispara hacia el lado derecho
	std::vector<Proyectil> disparoseneene;
	disparoRe.setPosition(xb, 100.0f);

	while (ward != true)
	{
		printf("Iteración numero %i%\n", j);
		std::this_thread::sleep_for(10ms);//18000 IQ
		if (j % 10 == 0) //Caada 100ms la bala se mueve
		{
			xb = xb + 0.75f; //El movimiento es doble
		}
		if (j % 40 == 0) 
		{
			disparoRe.setPosition(100.0f,100.0f);//En este vector deberia ir la pos enemiga
			disparoseneene.push_back(disparoRe);
			disparoRe.move(xb, 0);//Se movera xb pixels pixels (ya no tan necesaria por el metodo de abajo)
			printf("posicion del proyectil es (%f) y (%f)\n ", disparoRe.getPosition().x, disparoRe.getPosition().y);
			//printf("adsajafgfjgygajya");

		}
		if (j == 401) 
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