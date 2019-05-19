#include "PantallaMuerte.h"
#include "SFML/Graphics.hpp"
#include <iostream>

PantallaMuerte::PantallaMuerte(sf::RenderWindow& window)
{
	if (!texturamuerte.loadFromFile("./res/Imagenes/death_screen.png"))
	{
		std::cout << "No se ha encontrado la textura de: death_Screen.png\n";
	}

	you_died.setTexture(texturamuerte);

	opacidadmuerte = 0.f;
}

void PantallaMuerte::Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			exit(0);
			break;
		}
	}

	if (opacidadmuerte < 255.f)
	{
		opacidadmuerte += 3;
		you_died.setColor(sf::Color::Color(255, 255, 255, opacidadmuerte));
	}

	window.draw(mapa);
	window.draw(player);
	window.draw(you_died);
	
	//Mostrar en la ventana creada los objetos dibujados.
	window.display();
}


PantallaMuerte::~PantallaMuerte()
{
}
