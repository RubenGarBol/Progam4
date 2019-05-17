#include "PantallaPrincipal.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Animacion.h"
#include "Mapa.h"
#include "Personaje.h"
#include <iostream>
#include "PantallaJuego.h"

PantallaPrincipal::PantallaPrincipal(sf::RenderWindow& window)
{
	playboton.setSize(sf::Vector2f(200.f, 30.f));
	playboton.setOrigin(playboton.getSize().x / 2, playboton.getSize().y / 2);
	playboton.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	seleccion = 1;

	if (!font.loadFromFile("./res/pixeled.ttf"))
	{
		std::cout << "No se ha encontrado la fuente de: pixeled.ttf\n";
	}
	
	if (!textura_pprincipal.loadFromFile("./res/Imagenes/PantallaPrincipal.png"))
	{
		std::cout << "No se ha encontrado la textura de: PantallaPrincipal.png\n";
	}

	sprite_pprincipal.setTexture(textura_pprincipal);

	sf::Vector2u vector_pprincipal(12, 1);
	animacion_pprincipal = Animacion(&textura_pprincipal, vector_pprincipal, 0.15);
	delta_pprincipal = 0.0f;

	play_pprincipal.setFont(font);
	play_pprincipal.setString("JUGAR");
	play_pprincipal.setCharacterSize(45);
	play_pprincipal.setStyle(sf::Text::Bold);
	play_pprincipal.setFillColor(sf::Color::White);
	play_pprincipal.setOutlineColor(sf::Color::Black);
	play_pprincipal.setOutlineThickness(4);
	play_pprincipal.setOrigin(play_pprincipal.getGlobalBounds().width / 2, play_pprincipal.getGlobalBounds().height / 2);
	play_pprincipal.setPosition(playboton.getPosition().x, playboton.getPosition().y - 170);

	opciones_pprincipal.setFont(font);
	opciones_pprincipal.setString("OPCIONES");
	opciones_pprincipal.setCharacterSize(45);
	opciones_pprincipal.setStyle(sf::Text::Bold);
	opciones_pprincipal.setFillColor(sf::Color::White);
	opciones_pprincipal.setOutlineColor(sf::Color::Black);
	opciones_pprincipal.setOutlineThickness(4);
	opciones_pprincipal.setOrigin(opciones_pprincipal.getGlobalBounds().width / 2, opciones_pprincipal.getGlobalBounds().height / 2);
	opciones_pprincipal.setPosition(playboton.getPosition().x, playboton.getPosition().y + 20);

	salir_pprincipal.setFont(font);
	salir_pprincipal.setString("SALIR");
	salir_pprincipal.setCharacterSize(45);
	salir_pprincipal.setStyle(sf::Text::Bold);
	salir_pprincipal.setFillColor(sf::Color::White);
	salir_pprincipal.setOutlineColor(sf::Color::Black);
	salir_pprincipal.setOutlineThickness(4);
	salir_pprincipal.setOrigin(salir_pprincipal.getGlobalBounds().width / 2, salir_pprincipal.getGlobalBounds().height / 2);
	salir_pprincipal.setPosition(playboton.getPosition().x, playboton.getPosition().y + 210);
}

void PantallaPrincipal::Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player, sf::Texture& cursortexture, sf::Sprite& cursor, PantallaJuego& pjuego)
{
	mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			exit(0);
			break;

		case sf::Event::MouseMoved:
		{
			if (play_pprincipal.getGlobalBounds().contains(mousePosF))
			{
				seleccion = 1;
			}
			else if (opciones_pprincipal.getGlobalBounds().contains(mousePosF))
			{
				seleccion = 2;
			}
			else if (salir_pprincipal.getGlobalBounds().contains(mousePosF))
			{
				seleccion = 3;
			}

		}
		break;

		case sf::Event::MouseButtonPressed:
		{
			if (play_pprincipal.getGlobalBounds().contains(mousePosF))
			{
				player.tiempotot -= player.timer.getElapsedTime().asSeconds();
				mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();
				pjuego.animacoin.tiempotot-= pjuego.timer.getElapsedTime().asSeconds();
				*state = 0;
			}

			if (opciones_pprincipal.getGlobalBounds().contains(mousePosF))
			{
				opciones_pprincipal.setPosition(2000.f, 2000.f);
				salir_pprincipal.setPosition(2000.f, 2000.f);
			}

			if (salir_pprincipal.getGlobalBounds().contains(mousePosF))
			{
				exit(0);
			}
		}

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::S:
				if (seleccion < 3)
				{
					seleccion++;
				}
				break;
			case sf::Keyboard::W:
				if (seleccion > 1)
				{
					seleccion--;
				}
				break;
			case sf::Keyboard::Enter:
				if (seleccion == 1)
				{
					player.tiempotot -= player.timer.getElapsedTime().asSeconds();
					mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();
					pjuego.animacoin.tiempotot -= pjuego.timer.getElapsedTime().asSeconds();
					*state = 0;
				}
				if (seleccion == 2)
				{
					opciones_pprincipal.setPosition(2000.f, 2000.f);
					salir_pprincipal.setPosition(2000.f, 2000.f);
				}
				if (seleccion == 3)
				{
					exit(0);
				}
				break;
			}
			break;
		}
	}

	////
	////
	//// OPTIMIZAR CARGA DE TEXTURAS
	////
	////
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		cursortexture.loadFromFile("./res/Imagenes/pressed_cursor.png");
	}
	else
	{
		cursortexture.loadFromFile("./res/Imagenes/cursor.png");
	}
	////
	////
	//// OPTIMIZAR CARGA DE TEXTURAS
	////
	////

	if (seleccion == 1)
	{
		play_pprincipal.setFillColor(sf::Color(163, 131, 55));
		opciones_pprincipal.setFillColor(sf::Color::White);
		salir_pprincipal.setFillColor(sf::Color::White);
	}
	else if (seleccion == 2)
	{
		play_pprincipal.setFillColor(sf::Color::White);
		opciones_pprincipal.setFillColor(sf::Color(163, 131, 55));
		salir_pprincipal.setFillColor(sf::Color::White);
	}
	else if (seleccion == 3)
	{
		play_pprincipal.setFillColor(sf::Color::White);
		opciones_pprincipal.setFillColor(sf::Color::White);
		salir_pprincipal.setFillColor(sf::Color(163, 131, 55));
	}

	delta_pprincipal = clock_pprincipal.restart().asSeconds();
	animacion_pprincipal.Update(0, delta_pprincipal);
	sprite_pprincipal.setTextureRect(animacion_pprincipal.uvRect);

	cursor.setPosition(sf::Vector2f(mousePos));

	window.clear();

	window.draw(sprite_pprincipal);
	window.draw(play_pprincipal);
	window.draw(opciones_pprincipal);
	window.draw(salir_pprincipal);
	window.draw(cursor);

	window.display();

}

PantallaPrincipal::~PantallaPrincipal()
{
}
