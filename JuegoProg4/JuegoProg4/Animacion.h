#pragma once
#include <SFML\Graphics.hpp>

class Animacion
{
public:
	Animacion();
	Animacion(sf::Texture* texture, sf::Vector2u CuentaImg, float switchtiempo);
	~Animacion();

	void Update(int columna, float deltatiempo, sf::Clock &timer, sf::Sprite &objeto);
	void Update(int columna, float deltatiempo);

	sf::IntRect uvRect;

	float tiempotot;

	sf::Vector2u CuentaImg;
	sf::Vector2u ImgActual;
	
	
	float switchtiempo;
	
};

