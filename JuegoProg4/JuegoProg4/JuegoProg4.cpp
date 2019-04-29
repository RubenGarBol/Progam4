#include "Utilidades/Conexion.cpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdio.h>
#include "Cofre.h"
#include "Personaje.h"
#include "Item.h"
#include "Coin.h"
#include "Bomba.h"
#include "Proyectil.h"
#include "Animacion.h"
#include "Mapa.h"
#include "Enemigo.h"

#include<vector>

int main()
{
	B
	//Crear la pantalla principal de juego con nombre "Isaac" y dimensiones 1056x888p.
	sf::RenderWindow window(sf::VideoMode(1056.f, 888.f), "Issac");

	//Bloquear los frames por segundo a 60 para que la velocidad del personaje sea consistente en todos los dispositivos.
	window.setFramerateLimit(60);

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
	
	sf::RectangleShape hitbox;
	hitbox.setSize(sf::Vector2f(60.f, 20.f));
	hitbox.setOrigin(-18.f, -95.f);
	//hitbox.setFillColor(Color::White);

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
	pared1.setPosition(sf::Vector2f(0.f, 0.f));
	pared1.setSize(sf::Vector2f(1056.f, 120.f));

	sf::RectangleShape pared2;
	pared2.setPosition(sf::Vector2f(0.f, 0.f));
	pared2.setSize(sf::Vector2f(30.f, 888.f));

	sf::RectangleShape pared3;
	pared3.setPosition(sf::Vector2f(0.f, 768.f));
	pared3.setSize(sf::Vector2f(1056.f, 120.f));

	sf::RectangleShape pared4;
	pared4.setPosition(sf::Vector2f(1026.f, 0.f));
	pared4.setSize(sf::Vector2f(30.f, 888.f));

	RectangleShape paredes[4];
	paredes[0] = pared1;
	paredes[1] = pared2;
	paredes[2] = pared3;
	paredes[3] = pared4;

	Mapa mapa(texturaFondo, paredes, paredes);
	
	
	//sf::Vector2u vector1(3, 1);
	//Animacion animafondo(&mapa.texture, vector1, 0.25);
	//float deltatiempo1 = 0.0f;

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
	Enemigo ene(Vector2f size, int danyo, int vida, int ptos, Texture &texture);

	//std::vector<Bullet> bulletarray;

	//Genera un cofre en la posición establecida
	sf::Vector2f vectorCofre((window.getSize().x/2)-56.f, (window.getSize().y / 2 )- 40.f);
	Cofre cofre(vectorCofre);

	//Genera la bomba en el pixel 250, 150.
	sf::Vector2f vectorBomba(250, 150);

	//

	int cuenta = 0;

	std::vector<Coin> coin(7);

	sf::Vector2u vectorcoin(4, 1);
	Animacion animacoin(&coin[0].textura, vectorcoin, 0.25);
	float deltacoin = 0.0f;

	for (int i = 0; i < coin.size(); i++)
	{
		coin[0].setPosition(460.f, 150.f);
		coin[1].setPosition(140.f, 275.f);
		coin[2].setPosition(800.f, 300.f);
		coin[3].setPosition(700.f, 500.f);
		coin[4].setPosition(125.f, 500.f);
		coin[5].setPosition(250.f, 650.f);
		coin[6].setPosition(700.f, 700.f);
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
	coinpunt.setPosition(15.f, 830.f);

	sf::Text puntos;
	puntos.setFont(font);
	puntos.setCharacterSize(25.f);
	puntos.setStyle(sf::Text::Bold);
	puntos.setFillColor(sf::Color::White);
	puntos.setOutlineColor(sf::Color::Black);
	puntos.setOutlineThickness(2);
	puntos.setPosition(80.f, 845.f);

	sf::Text text;
	text.setFont(font);
	text.setString(": ");
	text.setCharacterSize(25.f);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
	text.setPosition(60.f, 845.f);

	//

	//Velocidad personaje principal
	int veloc = 4;

	///////////

	Vector2f centrar;

	int delaytiro = 0;

	Proyectil disparoup(0, -10);
	Proyectil disparodown(0, 10);
	Proyectil disparoR(10, 0);
	Proyectil disparoL(-10, 0);
	Proyectil disparoLUp(-7, -7);
	Proyectil disparoLDown(-7, 7);
	Proyectil disparoRUp(7, -7);
	Proyectil disparoRDown(7, 7);

	std::vector<Proyectil> disparos;

	///////////


	///////////

	//Bucle ejecutado mientras la pantalla se mantenga abierta.
	while (window.isOpen())
	{
		sf::Event event;

		//Función para cerrar la aplicación al pulsar el boton X de la parte superior derecha.
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		///////////
		

		///////////
		centrar = Vector2f(player.getPosition().x + player.getSize().x/2, player.getPosition().y + player.getSize().y/2);
		
		if (delaytiro < 10)
		{
			delaytiro++;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left) && delaytiro >= 10)
		{
			disparoLUp.setPosition(centrar);
			disparos.push_back(Proyectil(disparoLUp));
			delaytiro = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right) && delaytiro >= 10)
		{
			disparoRUp.setPosition(centrar);
			disparos.push_back(Proyectil(disparoRUp));
			delaytiro = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left) && delaytiro >= 10)
		{
			disparoLDown.setPosition(centrar);
			disparos.push_back(Proyectil(disparoLDown));
			delaytiro = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right) && delaytiro >= 10)
		{
			disparoRDown.setPosition(centrar);
			disparos.push_back(Proyectil(disparoRDown));
			delaytiro = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && delaytiro >= 10)
		{
			disparoup.setPosition(centrar);
			disparos.push_back(Proyectil(disparoup));
			delaytiro=0;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Down) && delaytiro >= 10)
		{
			disparodown.setPosition(centrar);
			disparos.push_back(Proyectil(disparodown));
			delaytiro = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && delaytiro >= 10)
		{
			disparoL.setPosition(centrar);
			disparos.push_back(Proyectil(disparoL));
			delaytiro = 0;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Right) && delaytiro >= 10)
		{
			disparoR.setPosition(centrar);
			disparos.push_back(Proyectil(disparoR));
			delaytiro = 0;
		}
	
		for (size_t i = 0; i < disparos.size(); i++)
		{
			disparos[i].move(disparos[i].dirx, disparos[i].diry);
			
			if (disparos[i].getGlobalBounds().intersects(cofre.getGlobalBounds()) || disparos[i].getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds()) 
				|| disparos[i].getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds()) || disparos[i].getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())
				|| disparos[i].getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds()) )
			{
				disparos.erase(disparos.begin() + i);
			}
		}
		///////////

		mapa.Update(0, mapa.deltatiempo, mapa.timer, mapa);
		
		deltatiempo = timer.restart().asSeconds();
		animapp.Update(anim, deltatiempo);
		player.setTextureRect(animapp.uvRect);

		explosion.setPosition(player.getPosition().x, player.getPosition().y);

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

		hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0.f, -veloc);
			hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));
			if (hitbox.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				player.move(0.f, veloc);
			}
			if (hitbox.getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds())) {
				player.move(0.f, veloc);
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
			player.move(0.f, veloc);
			hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));
			if (hitbox.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				player.move(0.f, -veloc);
			}
			if (player.getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())) {
				player.move(0.f, -veloc);
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
			player.move(-veloc, 0.f);
			hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));
			if (hitbox.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				player.move(veloc, 0.f);
			}
			if (hitbox.getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds())) {
				player.move(veloc, 0.f);
			}
			deltatiempo = timer.restart().asSeconds();
			animapp.Update(2, deltatiempo);
			player.setTextureRect(animapp.uvRect);

			anim = 3;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(veloc, 0.f);
			hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));
			if (hitbox.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
				player.move(-veloc, 0.f);
			}
			if (hitbox.getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds())) {
				player.move(-veloc, 0.f);
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
	
		//Limpiar la pantalla principal
		window.clear();

		//Dibujar el fondo y los objetos, enemigos y personaje de la pantalla.
		
		
		if (player.getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds()))
		{

		}
		else
		{

		
		window.draw(mapa);
		
		///////////
		for (size_t i = 0; i < disparos.size(); i++)
		{
			window.draw(disparos[i]);
		}
		/*
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
		*/
		for (int i=0; i < 7; i++)
		{
			window.draw(coin[i]);
		}
		///////////

		window.draw(coinpunt);
		
	
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
		//window.draw(hitbox);
		
		//Pintamos los proyectiles los cuales se encuantran en un array
		//for (size_t i = 0; i < proyectiles.size(); i++)
		//	window.draw(proyectiles[i]);

		//Mostrar en la ventana creada los objetos dibujados.
		}
		window.display();
		
	}
}