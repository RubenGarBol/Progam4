#pragma once
#include <SFML\Graphics.hpp>

class Animacion
{
public:
	Animacion(sf::Texture* texture, sf::Vector2u CuentaImg, float switchtiempo);
	~Animacion();

	void Update(int columna, float deltatiempo, sf::Clock &timer);
	void Update(int columna, float deltatiempo);

	sf::IntRect uvRect;

private:
	sf::Vector2u CuentaImg;
	sf::Vector2u ImgActual;
	
	float tiempotot;
	float switchtiempo;
	
};

