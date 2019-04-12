#include "Enemigo.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <thread>
#include <stdio.h>


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
void Enemigo::disparoe()
{
	bool ward = false;
	using namespace std::literals::chrono_literals;
	Proyectil disparoRe(10, 0); //Dispara hacia el lado derecho
	std::vector<Proyectil> disparosene;
	disparoRe.setPosition(xb, 100.0f);

	while (ward != true)
	{
		printf("Disparo numero %i%\n", j);
		std::this_thread::sleep_for(10ms);//18000 IQ
		if (j % 40 == 0) 
		{
			xb = xb + 10.0f;
			disparoRe.move(xb, 0);//Se movera 20 pixels
			printf("posicion del proyectil es (%f) y (%f) ", disparoRe.getPosition().x, disparoRe.getPosition().y);
			printf("adsajafgfjgygajya");
			disparosene.push_back(disparoRe);
		}
		j++;
		ward = true;
	}
}