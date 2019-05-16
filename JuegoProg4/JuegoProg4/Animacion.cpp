#include "Animacion.h"
#include "SFML/Graphics.hpp"



Animacion::Animacion()
{
}

Animacion::Animacion(sf::Texture* texture, sf::Vector2u CuentaImg, float switchtiempo)
{
	this->CuentaImg  = CuentaImg;
	this->switchtiempo = switchtiempo;
	tiempotot = 0.0f;
	ImgActual.x = 0;

	uvRect.width = texture->getSize().x / float(CuentaImg.x);
	uvRect.height = texture->getSize().y / float(CuentaImg.y);
}


Animacion::~Animacion()
{
}

void Animacion::Update(int columna, float deltatiempo, sf::Clock &timer, sf::Sprite &objeto)
{
	deltatiempo = timer.restart().asSeconds();
	ImgActual.y = columna;
	tiempotot += deltatiempo;

	if (tiempotot >= switchtiempo)
	{
		tiempotot -= switchtiempo;
		ImgActual.x++;
		
		if (ImgActual.x >= CuentaImg.x)
		{
			ImgActual.x = 0;
		}
	}

	uvRect.left = ImgActual.x * uvRect.width;
	uvRect.top = ImgActual.y * uvRect.height;
	objeto.setTextureRect(this->uvRect);
}
void Animacion::Update(int columna, float deltatiempo)
{
	ImgActual.y = columna;
	tiempotot += deltatiempo;

	if (tiempotot >= switchtiempo)
	{
		tiempotot -= switchtiempo;
		ImgActual.x++;

		if (ImgActual.x >= CuentaImg.x)
		{
			ImgActual.x = 0;
		}
	}

	uvRect.left = ImgActual.x * uvRect.width;
	uvRect.top = ImgActual.y * uvRect.height;
}

