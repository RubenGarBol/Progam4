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
	sf::RenderWindow window(sf::VideoMode(1056, 888), "DNI");

	//Cargar y establecer un icono de aplicación
	sf::Image icon;
	if (!icon.loadFromFile("./res/Imagenes/icon.png"))
	{
		std::cout << "No se ha encontrado la textura de: icon.png\n";
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	//Carga de texturas desde los .png, si no se encuentran avisar al usuario mediante una excepción.
	sf::Texture texturaFondo;
	if (!texturaFondo.loadFromFile("./res/Imagenes/PiskelPruebaAnim.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPrueba.png\n";
	}

	//Creación de objeto rectangular que contendrá la textura del personaje
	sf::RectangleShape player(sf::Vector2f(90.0f, 122.0f));
	player.setPosition(200.0f, 200.0f);

	//Carga del spritesheet de las animaciones del personaje principal
	sf::Texture pjtextura;
	if (!pjtextura.loadFromFile("./res/Imagenes/pjtextura.png"))
	{
		std::cout << "No se ha encontrado la textura de: knight_idle.png\n";
	}

	//Establecer la textura al personaje y declarar las propiedades de las animaciones y sprisheet
	player.setTexture(&pjtextura);
	sf::Vector2u vector(4, 4);
	Animacion animapp(&pjtextura, vector, 0.15);
	float deltatiempo = 0.0f;

	//Variables encargadas de la posicion de la animación
	int anim = 0;
	int animd = 0;

	//Timers encargados de la gestion del tiempo para el cambio de imagen de las animaciones
	sf::Clock timer;
	sf::Clock timer1;
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
	
	sf::Vector2u vector1(3, 1);
	Animacion animafondo(&texturaFondo, vector1, 0.25);
	float deltatiempo1 = 0.0f;

	//Carga y posicionamiento de los sprites/objetos del juego.
	Personaje roca;
	//Definicion de las balas como objetos(formados por vectores) circulares
	CircleShape proyectil;
	proyectil.setFillColor(Color::Blue);
	proyectil.setRadius(10.f);
	//Arraay de proyectiles
	std::vector<CircleShape> proyectiles;
	
	proyectiles.push_back(CircleShape(proyectil));
	
	//Bullet * p;
	//p->bala;

	//Genera un cofre en la posición establecida
	sf::Vector2f vectorCofre((window.getSize().x/2)-56, (window.getSize().y / 2 )- 40);
	Cofre cofre(vectorCofre);

	//Genera la bomba en el pixel 250, 150.
	sf::Vector2f vectorBomba(250, 150);
	Bomba bomba(vectorBomba);

	//Genera una moneda en el pixel 100,100.
	sf::Vector2f vectorCoin(100, 300);
	Coin coin(vectorCoin);

	//Velocidad personaje principal
	int veloc = 4;

	//Velocidad proyectiles
	int speed = 15;

	//Bucle ejecutado mientras la pantalla se mantenga abierta.
	while (window.isOpen())
	{
		sf::Event event;

		deltatiempo1 = timer1.restart().asSeconds();
		animafondo.Update(0, deltatiempo1);
		mapa.setTextureRect(animafondo.uvRect);

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
		
		//Metodos encargados de gestionar el movimiento y colision del personaje principal con el resto de objetos y paredes del juego.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
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

		//Movimiento y KeyBindings de los proyectiles hay que hacer un array
		int speed = 15;
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			
			//bala.setPosition(player.getPosition().x,player.getPosition().y);
			bala.move(0.0, -speed);
			if (bala.getGlobalBounds().intersects(pared1.getGlobalBounds())) {
				bala.move(0.0, speed);
			//	p-> ~Bullet(); //Destruye el objeto pero genera errores
			}

		}
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
		//window.draw(coin);
		//window.draw(bala);
		window.draw(cofre);
		//window.draw(bomba);
		window.draw(player);
		//window.draw(bala);
		/* if (bala.existe = 0) 
		{
			window.draw(proyectiles[i]);
		}
		*/
		//Mostrar en la ventana creada los objetos dibujados.
		window.display();
		
	}
}