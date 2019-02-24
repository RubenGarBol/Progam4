#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdio.h>

int main()
{
	//Crear la pantalla principal de juego con nombre "Isaac" y dimensiones 1056x888p.
	sf::RenderWindow window(sf::VideoMode(1056, 888), "Isaac");

	//Carga de texturas desde los .png, si no se encuentran avisar al usuario mediante una excepción.
	sf::Texture texture;
	if (!texture.loadFromFile("./res/Imagenes/roca.png"))
	{
		std::cout << "No se ha encontrado la textura de: roca.png\n";
	}

	sf::Texture texture2;
	if (!texture2.loadFromFile("./res/Imagenes/chest.png"))
	{
		std::cout << "No se ha encontrado la textura de: chest.png\n";
	}

	sf::Texture texture3;
	if (!texture3.loadFromFile("./res/Imagenes/PiskelPrueba.png"))
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

	//velocidad de movimiento del personaje principal.
	double speed = 2.5;

	//Carga y posicionamiento de los sprites/objetos del juego.
	sf::Sprite r1;
	r1.setTexture(texture);
	r1.setPosition(616, 160);

	sf::Sprite r2;
	r2.setTexture(texture2);
	r2.setPosition(588, 489);

	sf::Sprite fondo;
	fondo.setTexture(texture3);

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
			r1.move(0.0, -speed);
			if (r1.getGlobalBounds().intersects(r2.getGlobalBounds())) {
				r1.move(0.0, speed);
			}
			if (r1.getGlobalBounds().intersects(pared1.getGlobalBounds())) {
				r1.move(0.0, speed);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			r1.move(-speed, 0.0);
			if (r1.getGlobalBounds().intersects(r2.getGlobalBounds())) {
				r1.move(speed, 0.0);
			}
			if (r1.getGlobalBounds().intersects(pared2.getGlobalBounds())) {
				r1.move(speed, 0.0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			r1.move(0.0, speed);
			if (r1.getGlobalBounds().intersects(r2.getGlobalBounds())) {
				r1.move(0.0, -speed);
			}
			if (r1.getGlobalBounds().intersects(pared3.getGlobalBounds())) {
				r1.move(0.0, -speed);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			r1.move(speed, 0.0);
			if (r1.getGlobalBounds().intersects(r2.getGlobalBounds())) {
				r1.move(-speed, 0.0);
			}
			if (r1.getGlobalBounds().intersects(pared4.getGlobalBounds())) {
				r1.move(-speed, 0.0);
			}
		}

		//Limpiar la pantalla principal
		window.clear();

		//Dibujar el fondo y los objetos, enemigos y personaje de la pantalla.
		window.draw(fondo);
		window.draw(r1);
		window.draw(r2);

		//Mostrar en la ventana creada los objetos dibujados.
		window.display();
	}
}