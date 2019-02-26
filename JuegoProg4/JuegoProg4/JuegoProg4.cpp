#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdio.h>
#include "Cofre.h"
#include "Personaje.h"
#include "Item.h"
#include "Coin.h"

int main()
{
	//Crear la pantalla principal de juego con nombre "Isaac" y dimensiones 1056x888p.
	sf::RenderWindow window(sf::VideoMode(1056, 888), "Isaac");

	//Carga de texturas desde los .png, si no se encuentran avisar al usuario mediante una excepción.
	sf::Texture texturaFondo;
	if (!texturaFondo.loadFromFile("./res/Imagenes/PiskelPrueba.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPrueba.png\n";
	}

	//Objetos pared para delimitar los bordes jugables de la pantalla.
	sf::RectangleShape pared1;
	pared1.setPosition(sf::Vector2f(0, 0));
	pared1.setSize(sf::Vector2f(1056, 120));

	sf::RectangleShape pared2;
	pared2.setPosition(sf::Vector2f(0, 0));
	pared2.setSize(sf::Vector2f(30, 888));

	sf::RectangleShape pared3;
	pared3.setPosition(sf::Vector2f(0, 768));
	pared3.setSize(sf::Vector2f(1056, 120));

	sf::RectangleShape pared4;
	pared4.setPosition(sf::Vector2f(1026, 0));
	pared4.setSize(sf::Vector2f(30, 888));

	
	//Carga y posicionamiento de los sprites/objetos del juego.
	Personaje roca;
	
	sf::Vector2f vectorCofre(500, 489);
	Cofre cofre(vectorCofre);

	//Genera una moneda en el pixel 100,100
	sf::Vector2f vectorCoin(100, 300);
	Coin coin(vectorCoin);

	sf::Sprite fondo;
	fondo.setTexture(texturaFondo);

	//Bucle ejecutado mientras la pantalla se mantenga abierta.
	while (window.isOpen())
	{
		sf::Event event;
		
		//Bloquear los frames por segundo a 60 para que la velocidad del personaje sea consistente en todos los dispositivos.
		window.setFramerateLimit(60);

		//Función para cerrar la aplicación al pulsar el boton X de la parte superior derecha.
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}

		}

		//Metodos encargados de gestionar el movimiento y colision del personaje principal con el resto de objetos y paredes del juego.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			roca.move(0.0, -roca.velocidad);
			if (roca.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				roca.move(0.0, roca.velocidad);
			}
			if (roca.getGlobalBounds().intersects(pared1.getGlobalBounds())) {
				roca.move(0.0, roca.velocidad);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			roca.move(-roca.velocidad, 0.0);
			if (roca.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				roca.move(roca.velocidad, 0.0);
				
			}
			if (roca.getGlobalBounds().intersects(pared2.getGlobalBounds())) {
				roca.move(roca.velocidad, 0.0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			roca.move(0.0, roca.velocidad);
			if (roca.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				roca.move(0.0, -roca.velocidad);
			}
			if (roca.getGlobalBounds().intersects(pared3.getGlobalBounds())) {
				roca.move(0.0, -roca.velocidad);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			roca.move(roca.velocidad, 0.0);
			if (roca.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				roca.move(-roca.velocidad, 0.0);
			}
			if (roca.getGlobalBounds().intersects(pared4.getGlobalBounds())) {
				roca.move(-roca.velocidad, 0.0);
			}
		}

		//Limpiar la pantalla principal
		window.clear();

		//Dibujar el fondo y los objetos, enemigos y personaje de la pantalla.
		window.draw(fondo);
		window.draw(coin);
		window.draw(roca);
		window.draw(cofre);
	

		//Mostrar en la ventana creada los objetos dibujados.
		window.display();
	}
}