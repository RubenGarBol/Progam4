#include "EnemigoAereo.h"



EnemigoAereo::EnemigoAereo()
{
	enemigo.setSize(sf::Vector2f(20, 20));
	enemigo.setPosition(400, 400);
	veloc_mov = 3;
	random = 0;
	counter = 0;
}


EnemigoAereo::~EnemigoAereo()
{
}

//200IQ IA
void EnemigoAereo::movimiento(Mapa mapaCompleto)
{
	counter++;
	if (counter >= 60)
	{
		random = rand() % 10 + 1;
		counter = 0;
	}
	printf("%i", random);
	//Movimiento hacia Arriba
	
	if (random == 1)
	{
		enemigo.move(0, -veloc_mov);
	}
	if (enemigo.getGlobalBounds().intersects(mapaCompleto.conjParedes[0].getGlobalBounds()))
	{
		enemigo.move(0, veloc_mov);
	}
	//Movimiento hacia Abajo
	if (random == 2)
	{
		enemigo.move(0, veloc_mov);
	}
	if (enemigo.getGlobalBounds().intersects(mapaCompleto.conjParedes[1].getGlobalBounds()))
	{
		enemigo.move(veloc_mov, 0);
	}
	//Movimiento hacia la Izquierda
	if (random == 3)
	{
		enemigo.move(-veloc_mov, 0);
	}
	if (enemigo.getGlobalBounds().intersects(mapaCompleto.conjParedes[2].getGlobalBounds()))
	{
		enemigo.move(0, -veloc_mov);
	}
	//Movimiento hacia la Derecha
	if (random == 4)
	{
		enemigo.move(veloc_mov, 0);
		
	}
	if (enemigo.getGlobalBounds().intersects(mapaCompleto.conjParedes[3].getGlobalBounds()))
	{
		enemigo.move(-veloc_mov, 0);
	}
	//No moverse
	else
	{

	}
	
}

void EnemigoAereo::disparo()
{
}
