#include "EnemigoAereo.h"

EnemigoAereo::EnemigoAereo(){}

EnemigoAereo::EnemigoAereo(int posx, int posy)
{
	enemigo.setSize(sf::Vector2f(20, 20));
	enemigo.setPosition(posx, posy);

	veloc_mov = 3;
	random = 0;
	random2 = 0;
	counter = 0;
	counter2 = 0;
	delaytiro = 0.f;

	disparoup = Proyectil(0, -10);
	disparodown = Proyectil(0, 10);
	disparoR = Proyectil(10, 0);
	disparoL = Proyectil(-10, 0);
}


EnemigoAereo::~EnemigoAereo()
{
}

//200IQ IA
void EnemigoAereo::movimiento()
{
	counter++;
	if (counter >= 60)
	{
		random = rand() % 6 + 1;
		counter = 0;
	}

	if (delaytiro < 10)
	{
		delaytiro++;
	}

	//Movimiento hacia Arriba
	if (random == 1)
	{
		enemigo.move(0, -veloc_mov);
	}
	//Movimiento hacia Abajo
	if (random == 2)
	{
		enemigo.move(0, veloc_mov);
	}
	
	//Movimiento hacia la Izquierda
	if (random == 3)
	{
		enemigo.move(-veloc_mov, 0);
	}

	//Movimiento hacia la Derecha
	if (random == 4)
	{
		enemigo.move(veloc_mov, 0);
		
	}
	
	//No moverse

}

void EnemigoAereo::disparo()
{
	centrar = Vector2f(enemigo.getPosition().x , enemigo.getPosition().y);

	counter2++;
	if (counter2 >= 60)
	{
		random2 = rand() % 5 + 1;
		counter2 = 0;
	}
	if (delaytiro < 30)
	{
		delaytiro++;
	}

	if (random2 == 1 && delaytiro >= 30)
	{
		disparoup.setPosition(centrar);
		disparos.push_back(disparoup);
		delaytiro = 0;
	}
	if (random2 == 2 && delaytiro >= 30)
	{
		disparodown.setPosition(centrar);
		disparos.push_back(disparodown);
		delaytiro = 0;
	}
	if (random2 == 3 && delaytiro >= 30)
	{
		disparoL.setPosition(centrar);
		disparos.push_back(disparoL);
		delaytiro = 0;
	}
	if (random2 == 4 && delaytiro >= 30)
	{
		disparoR.setPosition(centrar);
		disparos.push_back(disparoR);
		delaytiro = 0;
	}

	
}
