#include "PantallaPausa.h"
#include "SFML/Graphics.hpp"
#include "Mapa.h"
#include "Personaje.h"
#include <iostream>


PantallaPausa::PantallaPausa(sf::RenderWindow& window)
{
	if (!font.loadFromFile("./res/pixeled.ttf"))
	{
		std::cout << "No se ha encontrado la fuente de: pixeled.ttf\n";
	}

	if (!cursortexture.loadFromFile("./res/Imagenes/cursor.png"))
	{
		std::cout << "No se ha encontrado la textura de: cursor.png\n";
	}
	if (!cursortexturepressed.loadFromFile("./res/Imagenes/pressed_cursor.png"))
	{
		std::cout << "No se ha encontrado la textura de: pressed_cursor.png\n";
	}
	cursor.setTexture(cursortexture);

	rectangle.setSize(sf::Vector2f(820.f, 600.f));
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	rectangle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	rectangle.setOutlineThickness(11.f);

	playboton.setSize(sf::Vector2f(200.f, 30.f));
	playboton.setOrigin(playboton.getSize().x / 2, playboton.getSize().y / 2);
	playboton.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	play.setFont(font);
	play.setString("C O N T I N U A R");
	play.setCharacterSize(45);
	play.setStyle(sf::Text::Bold);
	play.setFillColor(sf::Color::White);
	play.setOutlineColor(sf::Color::Black);
	play.setOutlineThickness(4);
	play.setOrigin(play.getGlobalBounds().width / 2, play.getGlobalBounds().height / 2);
	play.setPosition(playboton.getPosition().x, playboton.getPosition().y - 180);

	opciones.setFont(font);
	opciones.setString("O P C I O N E S");
	opciones.setCharacterSize(45);
	opciones.setStyle(sf::Text::Bold);
	opciones.setFillColor(sf::Color::White);
	opciones.setOutlineColor(sf::Color::Black);
	opciones.setOutlineThickness(4);
	opciones.setOrigin(opciones.getGlobalBounds().width / 2, opciones.getGlobalBounds().height / 2);
	opciones.setPosition(playboton.getPosition().x, playboton.getPosition().y);

	salir.setFont(font);
	salir.setString("S A L I R");
	salir.setCharacterSize(45);
	salir.setStyle(sf::Text::Bold);
	salir.setFillColor(sf::Color::White);
	salir.setOutlineColor(sf::Color::Black);
	salir.setOutlineThickness(4);
	salir.setOrigin(salir.getGlobalBounds().width / 2, salir.getGlobalBounds().height / 2);
	salir.setPosition(playboton.getPosition().x, playboton.getPosition().y + 180);
}

void PantallaPausa::Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	if (opacidadint < 140.f)
	{
		opacidadint += 140 / 6;
		rectangle.setFillColor(sf::Color::Color(64, 89, 102, opacidadint));
	}
	if (opacidadext < 252.f)
	{
		opacidadext += 252 / 6;
		rectangle.setOutlineColor(sf::Color::Color(209, 178, 100, opacidadext));
	}
	if (opacidadtextint < 252.f)
	{
		opacidadtextint += 252 / 6;
		play.setFillColor(sf::Color::Color(255, 255, 255, opacidadtextint));
		opciones.setFillColor(sf::Color::Color(255, 255, 255, opacidadtextint));
		salir.setFillColor(sf::Color::Color(255, 255, 255, opacidadtextint));
	}
	if (opacidadtextext < 252.f)
	{
		opacidadtextext += 252 / 6;
		play.setOutlineColor(sf::Color::Color(0, 0, 0, opacidadtextext));
		opciones.setOutlineColor(sf::Color::Color(0, 0, 0, opacidadtextext));
		salir.setOutlineColor(sf::Color::Color(0, 0, 0, opacidadtextext));
	}

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
			if (play.getGlobalBounds().contains(mousePosF) && opacidadtextint >= 252)
			{
				seleccion = 1;
			}
			else if (opciones.getGlobalBounds().contains(mousePosF) && opacidadtextint >= 252)
			{
				seleccion = 2;
			}
			else if (salir.getGlobalBounds().contains(mousePosF) && opacidadtextint >= 252)
			{
				seleccion = 3;
			}

		}
		break;

		case sf::Event::MouseButtonPressed:
		{
			if (play.getGlobalBounds().contains(mousePosF))
			{
				opacidadext = 0;
				opacidadint = 0;
				opacidadtextext = 0;
				opacidadtextint = 0;

				player.tiempotot -= player.timer.getElapsedTime().asSeconds();
				mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();

				*state = 0;
			}

			if (opciones.getGlobalBounds().contains(mousePosF))
			{
				opciones.setPosition(2000.f, 2000.f);
				salir.setPosition(2000.f, 2000.f);
			}

			if (salir.getGlobalBounds().contains(mousePosF))
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
					printf("%i\n", seleccion);
				}
				break;
			case sf::Keyboard::W:
				if (seleccion > 1)
				{
					seleccion--;
					printf("%i\n", seleccion);
				}
				break;
			case sf::Keyboard::Enter:
				if (seleccion == 1)
				{
					opacidadext = 0;
					opacidadint = 0;
					opacidadtextext = 0;
					opacidadtextint = 0;

					player.tiempotot -= player.timer.getElapsedTime().asSeconds();
					mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();

					state = 0;
				}
				if (seleccion == 2)
				{
					opciones.setPosition(2000.f, 2000.f);
					salir.setPosition(2000.f, 2000.f);
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

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		cursor.setTexture(cursortexturepressed);
	}
	else
	{
		cursor.setTexture(cursortexture);
	}

	if (seleccion == 1)
	{
		play.setFillColor(sf::Color(163, 131, 55));
		opciones.setFillColor(sf::Color::White);
		salir.setFillColor(sf::Color::White);
	}
	else if (seleccion == 2)
	{
		play.setFillColor(sf::Color::White);
		opciones.setFillColor(sf::Color(163, 131, 55));
		salir.setFillColor(sf::Color::White);

	}
	else if (seleccion == 3)
	{
		play.setFillColor(sf::Color::White);
		opciones.setFillColor(sf::Color::White);
		salir.setFillColor(sf::Color(163, 131, 55));
	}

	cursor.setPosition(sf::Vector2f(mousePos));

	window.clear();

	window.draw(mapa);
	//window.draw(coinpunt);
	//window.draw(vida);
	//window.draw(puntos);
	/*
	for (size_t i = 0; i < disparos.size(); i++)
	{
		window.draw(disparos[i]);
	}
	
	for (size_t i = 0; i < coin.size(); i++)
	{
		window.draw(coin[i]);
	}
	*/

	//window.draw(cofre);
	//window.draw(text);
	window.draw(player);
	window.draw(rectangle);
	window.draw(play);
	window.draw(opciones);
	window.draw(salir);
	window.draw(cursor);

	window.display();
}

PantallaPausa::~PantallaPausa()
{
}
