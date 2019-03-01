#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdio.h>
#include "Cofre.h"
#include "Personaje.h"
#include "Item.h"
#include "Coin.h"
#include "Bomba.h"
#include "Bullet.h"
#include "Animacion.h"
#include "Mapa.h"

#include<vector>

int main()
{
	//Crear la pantalla principal de juego con nombre "Isaac" y dimensiones 1056x888p.
	sf::RenderWindow window(sf::VideoMode(1056, 888), "NIK");

	sf::Image icon;
	icon.loadFromFile("./res/Imagenes/icon.png"); // File/Image/Pixel
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	//Carga de texturas desde los .png, si no se encuentran avisar al usuario mediante una excepción.
	sf::Texture texturaFondo;
	texturaFondo.loadFromFile("./res/Imagenes/PiskelPrueba.png");
	if (!texturaFondo.loadFromFile("./res/Imagenes/PiskelPasillo.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPrueba.png\n";
	}

	sf::RectangleShape player(sf::Vector2f(90.0f, 122.0f));
	player.setPosition(200.0f, 200.0f);

	sf::Texture pjtextura;
	if (!pjtextura.loadFromFile("./res/Imagenes/pjtextura.png"))
	{
		std::cout << "No se ha encontrado la textura de: knight_idle.png\n";
	}

	player.setTexture(&pjtextura);
	sf::Vector2u vector(4, 4);
	Animacion animapp(&pjtextura, vector, 0.20);
	float deltatiempo = 0.0f;
	int anim = 0;
	int animd = 0;

	sf::Clock timer;
	sf::Clock time;
	

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

	RectangleShape paredes[4];
	paredes[0] = pared1;
	paredes[1] = pared2;
	paredes[2] = pared3;
	paredes[3] = pared4;

	Mapa mapa(texturaFondo, paredes, paredes);

	//Carga y posicionamiento de los sprites/objetos del juego.
	Personaje roca;
	//Definicion de las balas como objetos(formados por vectores) circulares
	CircleShape proyectil;
	proyectil.setFillColor(Color::Blue);
	proyectil.setRadius(10.f);
	//Array de proyectiles
	std::vector<CircleShape> proyectiles;
	
	proyectiles.push_back(CircleShape(proyectil));
	int shottimer = 0;

	//Bullet * p;
	//p->bala;

	sf::Vector2f vectorCofre(500, 489);
	Cofre cofre(vectorCofre);

	//Genera la bomba en el pixel 250, 150.
	sf::Vector2f vectorBomba(250, 150);
//	Bomba bomba(vectorBomba);

	//Genera una moneda en el pixel 100,100.
	sf::Vector2f vectorCoin(100, 300);
	Coin coin(vectorCoin);

	//Timer
	sf::Sprite fondo;
	fondo.setTexture(texturaFondo);

	float tiempo = 0.0f;


	//Bucle ejecutado mientras la pantalla se mantenga abierta.
	while (window.isOpen())
	{
		sf::Event event;

		printf("%i", anim);
		deltatiempo = timer.restart().asSeconds();
		animapp.Update(anim, deltatiempo);
		player.setTextureRect(animapp.uvRect);
		
		//Bloquear los frames por segundo a 60 para que la velocidad del personaje sea consistente en todos los dispositivos.
		window.setFramerateLimit(60);
	
		//Función para cerrar la aplicación al pulsar el boton X de la parte superior derecha.
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		
		/*deltatiempo = timer.restart().asSeconds();
		animapp.Update(0, deltatiempo);
		player.setTextureRect(animapp.uvRect);*/

		int veloc = 4;

		//Metodos encargados de gestionar el movimiento y colision del personaje principal con el resto de objetos y paredes del juego.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			/*roca.move(0.0, -roca.velocidad);
			if (roca.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				roca.move(0.0, roca.velocidad);
			}
			if (roca.getGlobalBounds().intersects(pared1.getGlobalBounds())) {
				roca.move(0.0, roca.velocidad);
			}
			*/
			player.move(0.0, -veloc);
			if (player.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				player.move(0.0, veloc);
			}
			if (player.getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds())) {
				player.move(0.0, veloc);
			}
			if(anim==3)
			{ 
				animd = 2;
			}
			if(anim==0)
			{
				animd = 1;
			}
			deltatiempo = timer.restart().asSeconds();
			animapp.Update(animd, deltatiempo);
			player.setTextureRect(animapp.uvRect);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			/*roca.move(0.0, roca.velocidad);
			if (roca.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				roca.move(0.0, -roca.velocidad);
			}
			if (roca.getGlobalBounds().intersects(pared3.getGlobalBounds())) {
				roca.move(0.0, -roca.velocidad);
			}
			deltatiempo = timer.restart().asSeconds();
			animapp.Update(1, deltatiempo);
			player.setTextureRect(animapp.uvRect);
			*/
			player.move(0.0, veloc);
			if (player.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				player.move(0.0, -veloc);
			}
			if (player.getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())) {
				player.move(0.0, -veloc);
			}
			if (anim == 3)
			{
				animd = 2;
			}
			if(anim==0)
			{
				animd = 1;
			}
			deltatiempo = timer.restart().asSeconds();
			animapp.Update(animd, deltatiempo);
			player.setTextureRect(animapp.uvRect);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			/*roca.move(-roca.velocidad, 0.0);
			if (roca.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				roca.move(roca.velocidad, 0.0);
			}
			if (roca.getGlobalBounds().intersects(pared2.getGlobalBounds())) {
				roca.move(roca.velocidad, 0.0);
			}
			*/
			player.move(-veloc, 0.0);
			if (player.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				player.move(veloc, 0.0);
			}
			if (player.getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds())) {
				player.move(veloc, 0.0);
			}

			deltatiempo = timer.restart().asSeconds();
			animapp.Update(2, deltatiempo);
			player.setTextureRect(animapp.uvRect);

			anim = 3;

		}

	

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			/*roca.move(roca.velocidad, 0.0);
			if (roca.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				roca.move(-roca.velocidad, 0.0);
			}
			if (roca.getGlobalBounds().intersects(pared4.getGlobalBounds())) {
				roca.move(-roca.velocidad, 0.0);
			}
			*/
			player.move(veloc, 0.0);
			if (player.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				player.move(-veloc, 0.0);
			}
			if (player.getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds())) {
				player.move(-veloc, 0.0);
			}

			deltatiempo = timer.restart().asSeconds();
			animapp.Update(1, deltatiempo);
			player.setTextureRect(animapp.uvRect);

			anim = 0;
		}
		 int speed = 10;
		//Movimiento y KeyBindings de los proyectiles en funcion de su array
		
		 
		 printf(" ");

		 if (shottimer < 5)
		 {
			
			 printf(" Incremento el tiempo ");
			 shottimer++;
			 printf("%i ", shottimer);
		 }
		//Al presionar arriba que se meta en un bucle que se resetea al final 
		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shottimer >= 5)
		 {
			 proyectil.setPosition(1000.f, 1000.f);
			 proyectiles.push_back(CircleShape(proyectil));
			 printf("ehjewjhfdjfahgjsdhjdshrjegjwetj");
			 shottimer = 0;

		 }
		 for (size_t i = 0; i < proyectiles.size(); i++)
		 {
			 proyectil.move(0.0, speed);
			 if (proyectiles[i].getPosition().y < 0)

				 proyectiles.erase(proyectiles.begin() + i);

		 }
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			bala.move(0.0, speed);
			if (bala.getGlobalBounds().intersects(pared3.getGlobalBounds())) {
				bala.move(0.0, -speed);
				p-> ~Bullet();
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bala.move(-speed, 0.0);
			if (bala.getGlobalBounds().intersects(pared2.getGlobalBounds())) {
				bala.move(speed, 0.0);
				p-> ~Bullet();
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bala.move(speed, 0.0);
			if (bala.getGlobalBounds().intersects(pared4.getGlobalBounds())) {
				bala.move(-speed, 0.0);
				p-> ~Bullet();
			}

		}
		*/
		
		//Limpiar la pantalla principal
		window.clear();

		//Dibujar el fondo y los objetos, enemigos y personaje de la pantalla.
		window.draw(mapa);
		window.draw(coin);
		//window.draw(roca);
		window.draw(cofre);
	//	window.draw(bomba);
		window.draw(player);
		//Pintamos los proyectiles los cuales se encuantran en un array
		for (size_t i = 0; i < proyectiles.size(); i++)
			window.draw(proyectiles[i]);

		//Mostrar en la ventana creada los objetos dibujados.
		window.display();

	}
}