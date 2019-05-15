#include "PowerUp.h"

PowerUp::PowerUp()
{
	if (!textura_vel_ataque.loadFromFile("./res/Imagenes/textura_vel_ataque.png"))
	{
		std::cout << "No se ha encontrado la textura de: textura_vel_ataque.png\n";
	}

	if (!textura_vel_mov.loadFromFile("./res/Imagenes/textura_vel_mov.png"))
	{
		std::cout << "No se ha encontrado la textura de: textura_vel_mov.png\n";
	}

	Poti_A.setTexture(textura_vel_ataque);
	Poti_A.setPosition(400.f, 400.f);

	Poti_B.setTexture(textura_vel_mov);
	Poti_B.setPosition(600.f, 600.f);
}

void PowerUp::PickUp(Personaje& player, float* veloc, float* delaytiro)
{
	if (Poti_A.getGlobalBounds().intersects(player.getGlobalBounds()))
	{
		*veloc++;
		*delaytiro--;
	}
	if (Poti_B.getGlobalBounds().intersects(player.getGlobalBounds()))
	{
		player.velocidad++;
	}
}


PowerUp::~PowerUp()
{
}
