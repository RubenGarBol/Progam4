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
	sf::Clock timer2;
	sf::Clock timercoin;
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

	sf::Texture texturaExpl;
	if (!texturaExpl.loadFromFile("./res/Imagenes/explosion.png"))
	{
		std::cout << "No se ha encontrado la textura de: explosion.png\n";
	}

	sf::Sprite explosion;
	
	explosion.setTexture(texturaExpl);
	sf::Vector2u vector2(12, 1);
	Animacion animaexpl(&texturaExpl, vector2, 0.1);
	float deltatiempo2 = 0.0f;

	//Carga y posicionamiento de los sprites/objetos del juego.
	Personaje roca;
	//Definicion de las balas como objetos(formados por vectores) circulares
	CircleShape proyectil;
	proyectil.setFillColor(Color::Blue);
	proyectil.setRadius(10.f);
	//Array de proyectiles

	//std::vector<CircleShape> proyectiles;
	
	//proyectiles.push_back(CircleShape(proyectil));
	int shottimer = 0;

	//Bullet * p;
	//p->bala;

	//Genera un cofre en la posición establecida
	sf::Vector2f vectorCofre((window.getSize().x/2)-56, (window.getSize().y / 2 )- 40);
	Cofre cofre(vectorCofre);

	//Genera la bomba en el pixel 250, 150.
	sf::Vector2f vectorBomba(250, 150);
//	Bomba bomba(vectorBomba);

	//Genera una moneda en el pixel 100,100.
	//Coin coin(vectorCoin);

	int cuenta = 0;

	std::vector<Coin> coin(8);

	sf::Vector2u vectorcoin(4, 1);
	Animacion animacoin(&coin[0].textura, vectorcoin, 0.25);
	float deltacoin = 0.0f;

	//for (int i = 0; i < coin.size(); i++)
	{
		coin[0].setPosition(460, 150);
		coin[1].setPosition(140, 275);
		coin[2].setPosition(800, 300);
		coin[3].setPosition(700, 500);
		coin[4].setPosition(125, 500);
		coin[5].setPosition(250, 650);
		coin[6].setPosition(700, 700);
	}
		
	sf::Font font;
	font.loadFromFile("./res/pixeled.ttf");

	sf::Texture texturapuntos;
	if (!texturapuntos.loadFromFile("./res/Imagenes/coinpunt.png"))
	{
		std::cout << "No se ha encontrado la textura de: coinpunt.png\n";
	}

	sf::Sprite coinpunt;
	coinpunt.setTexture(texturapuntos);
	coinpunt.setPosition(15, 830);

	sf::Text puntos;
	puntos.setFont(font);
	puntos.setCharacterSize(25);
	puntos.setStyle(sf::Text::Bold);
	puntos.setFillColor(sf::Color::White);
	puntos.setOutlineColor(sf::Color::Black);
	puntos.setOutlineThickness(2);
	puntos.setPosition(80, 845);

	sf::Text text;
	text.setFont(font);
	text.setString(": ");
	text.setCharacterSize(25);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
	text.setPosition(60, 845);

	//Velocidad personaje principal
	int veloc = 4;

	//Velocidad proyectiles
	int speed = 15;

	///////////
	CircleShape proyectil1;
	proyectil1.setFillColor(Color::White);
	proyectil1.setRadius(5.f);

	CircleShape proyectil2;
	proyectil2.setFillColor(Color::White);
	proyectil2.setRadius(5.f);

	CircleShape proyectil3;
	proyectil3.setFillColor(Color::White);
	proyectil3.setRadius(5.f);

	CircleShape proyectil4;
	proyectil4.setFillColor(Color::White);
	proyectil4.setRadius(5.f);

	RectangleShape enemigo1;
	enemigo1.setFillColor(Color::Black);
	enemigo1.setSize(Vector2f(50.f, 50.f));

	std::vector<RectangleShape> enemigo;
	std::vector<CircleShape> proyectiles1;
	std::vector<CircleShape> proyectiles2;
	std::vector<CircleShape> proyectiles3;
	std::vector<CircleShape> proyectiles4;

	proyectiles1.push_back(CircleShape(proyectil1));
	proyectiles2.push_back(CircleShape(proyectil2));
	proyectiles3.push_back(CircleShape(proyectil3));
	proyectiles4.push_back(CircleShape(proyectil4));
	enemigo.push_back(RectangleShape(enemigo1));

	Vector2f centrar;
	Vector2f balamove;

	int delaytiro = 0;
	///////////



	//Bucle ejecutado mientras la pantalla se mantenga abierta.
	while (window.isOpen())
	{
		sf::Event event;

		
		///////////
		centrar = Vector2f(player.getPosition().x + player.getSize().x/2, player.getPosition().y + player.getSize().y/2);
		
		if (delaytiro < 10)
		{
			delaytiro++;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && delaytiro >= 10)
		{
			proyectil1.setPosition(centrar);
			proyectiles1.push_back(CircleShape(proyectil1));
			delaytiro=0;
			
		}
		for (size_t i = 0; i < proyectiles1.size(); i++)
		{
			
			proyectiles1[i].move(0, -10.f);
			if (proyectiles1[i].getGlobalBounds().intersects(cofre.getGlobalBounds()) || proyectiles1[i].getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds())
				|| proyectiles1[i].getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds()) || proyectiles1[i].getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())
				|| proyectiles1[i].getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds()))
			{
				proyectiles1.erase(proyectiles1.begin() + i);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) && delaytiro >= 10)
		{
			proyectil2.setPosition(centrar);
			proyectiles2.push_back(CircleShape(proyectil2));
			delaytiro = 0;
			
		
		}
		for (size_t i = 0; i < proyectiles2.size(); i++)
		{
			
			proyectiles2[i].move(0, 10.f);
			if (proyectiles2[i].getGlobalBounds().intersects(cofre.getGlobalBounds()) || proyectiles2[i].getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds())
				|| proyectiles2[i].getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds()) || proyectiles2[i].getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())
				|| proyectiles2[i].getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds()))
			{
				proyectiles2.erase(proyectiles2.begin() + i);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) && delaytiro >= 10)
		{
			proyectil3.setPosition(centrar);
			proyectiles3.push_back(CircleShape(proyectil3));
			delaytiro = 0;
			
		
		}
		for (size_t i = 0; i < proyectiles3.size(); i++)
		{
			
			proyectiles3[i].move(-10.f, 0);
			if (proyectiles3[i].getGlobalBounds().intersects(cofre.getGlobalBounds()) || proyectiles3[i].getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds())
				|| proyectiles3[i].getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds()) || proyectiles3[i].getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())
				|| proyectiles3[i].getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds()))
			{
				proyectiles3.erase(proyectiles3.begin() + i);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) && delaytiro >= 10)
		{
			proyectil4.setPosition(centrar);
			proyectiles4.push_back(CircleShape(proyectil4));
			delaytiro = 0;
			
		}
		for (size_t i = 0; i < proyectiles4.size(); i++)
		{
			proyectiles4[i].move(10.f, 0);
			if (proyectiles4[i].getGlobalBounds().intersects(cofre.getGlobalBounds()) || proyectiles4[i].getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds())
				|| proyectiles4[i].getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds()) || proyectiles4[i].getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())
				|| proyectiles4[i].getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds()))
			{
				proyectiles4.erase(proyectiles4.begin() + i);
			}
		}

		
		/*for (size_t i = 0; i < proyectiles.size(); i++)
		{
			proyectiles[i].move(balamove);
			if (proyectiles[i].getGlobalBounds().intersects(cofre.getGlobalBounds()) || proyectiles[i].getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds()) 
				|| proyectiles[i].getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds()) || proyectiles[i].getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())
				|| proyectiles[i].getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds()) )
			{
				proyectiles.erase(proyectiles.begin() + i);
			}
		}*/
		///////////

		deltatiempo1 = timer1.restart().asSeconds();
		animafondo.Update(0, deltatiempo1);
		mapa.setTextureRect(animafondo.uvRect);

		deltatiempo = timer.restart().asSeconds();
		animapp.Update(anim, deltatiempo);
		player.setTextureRect(animapp.uvRect);

		explosion.setPosition(player.getPosition().x, player.getPosition().y);

		//Bloquear los frames por segundo a 60 para que la velocidad del personaje sea consistente en todos los dispositivos.
		window.setFramerateLimit(60);
	
		//Función para cerrar la aplicación al pulsar el boton X de la parte superior derecha.
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		for (int a=0; a<7; a++)
		{ 
			deltacoin = timercoin.restart().asSeconds();
			animacoin.Update(0, deltacoin);
			coin[a].setTextureRect(animacoin.uvRect);

			if (player.getGlobalBounds().intersects(coin[a].getGlobalBounds()))
			{
				coin[a].setPosition(2000, 2000);
				cuenta++;
			}
		}
		
		
		puntos.setString(std::to_string(cuenta));
		
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
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			deltatiempo = timer.restart().asSeconds();
			animapp.Update(anim, deltatiempo);
			player.setTextureRect(animapp.uvRect);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			deltatiempo = timer.restart().asSeconds();
			animapp.Update(anim, deltatiempo);
			player.setTextureRect(animapp.uvRect);
		}

		int speed = 10;
		//Movimiento y KeyBindings de los proyectiles en funcion de su array

		 if (shottimer < 5)
		 {
			 printf(" Incremento el tiempo ");
			 shottimer++;
			 printf("%i ", shottimer);
		 }
		//Al presionar arriba que se meta en un bucle que se resetea al final 
		/* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shottimer >= 5)
		 {
			 proyectil.setPosition(100,100);
			 proyectiles.push_back(CircleShape(proyectil));
			 printf("Dispara ");
			
			 shottimer = 0;
		 }
		 for (size_t i = 0; i < proyectiles.size(); i++)
		 {
			 proyectil.move(0.0, speed);

			 if (proyectiles[i].getPosition().y < 0)

				 proyectiles.erase(proyectiles.begin() + i);

		 }
		 */
		
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
		
		///////////
		for (size_t i = 0; i < proyectiles1.size(); i++)
		{
			window.draw(proyectiles1[i]);
		}
		for (size_t i = 0; i < proyectiles2.size(); i++)
		{
			window.draw(proyectiles2[i]);
		}
		for (size_t i = 0; i < proyectiles3.size(); i++)
		{
			window.draw(proyectiles3[i]);
		}
		for (size_t i = 0; i < proyectiles4.size(); i++)
		{
			window.draw(proyectiles4[i]);
		}
	
		for (int i=0; i < 7; i++)
		{
			window.draw(coin[i]);
		}
		///////////

		window.draw(coinpunt);
		//window.draw(bala);
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			deltatiempo2 = timer2.restart().asSeconds();
			animaexpl.Update(0, deltatiempo2);
			explosion.setTextureRect(animaexpl.uvRect);
			window.draw(explosion);
		}

		window.draw(puntos);
		window.draw(text);
		window.draw(cofre);
		window.draw(text);
		window.draw(player);
		
		//Pintamos los proyectiles los cuales se encuantran en un array
		//for (size_t i = 0; i < proyectiles.size(); i++)
		//	window.draw(proyectiles[i]);

		//Mostrar en la ventana creada los objetos dibujados.
		window.display();
		
	}
}