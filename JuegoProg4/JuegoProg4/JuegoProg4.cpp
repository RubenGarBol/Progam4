#include "Utilidades/Conexion.cpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
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
#include <thread>
#include "SFML/System.hpp"
#include<vector>
#include "JuegoProg4.h"

int main()
{
	
	//Crear la pantalla principal de juego con nombre "Isaac" y dimensiones 1056x888p.
	sf::RenderWindow window(sf::VideoMode(1056, 888, 32), "Issac");

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

	//Carga del spritesheet de las animaciones del personaje principal
	sf::Texture pjtextura;
	if (!pjtextura.loadFromFile("./res/Imagenes/pjtextura.png"))
	{
		std::cout << "No se ha encontrado la textura de: knight_idle.png\n";
	}

	//Creación de objeto rectangular que contendrá la textura del personaje
	/*
	sf::Sprite player(pjtextura);
	player.setPosition(200.0f, 200.0f);
	*/
	sf::RectangleShape hitbox;
	hitbox.setSize(sf::Vector2f(60.f, 20.f));
	hitbox.setOrigin(-15.f, -95.f);
	//hitbox.setFillColor(Color::White);

	
	
	//Establecer la textura al personaje y declarar las propiedades de las animaciones y sprisheet

	//sf::Vector2u vector(4, 4);
	//Animacion animapp(&pjtextura, vector, 0.15f);
	//float deltatiempo = 0.0f;

	//Variables encargadas de la posicion de la animación
	//int anim = 0;
	//int animd = 0;

	//Timers encargados de la gestion del tiempo para el cambio de imagen de las animaciones
	sf::Clock timer;
	sf::Clock timer1;
	sf::Clock timer2;
	sf::Clock timercoin;
	sf::Clock time;
	sf::Clock invframes;
	sf::Clock vidaanim;
	
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

	Personaje player(pjtextura);
	
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
	Animacion animaexpl(&texturaExpl, vector2, 0.1f);
	float deltatiempo2 = 0.0f;

	//Carga y posicionamiento de los sprites/objetos del juego.
	sf::Texture texturaEn;
	texturaEn.loadFromFile("./res/Imagenes/chest.png");
	Enemigo e1(Vector2f(200.0f,200.0f),0,0,10,texturaEn);
	
	//sDefinicion de las balas como objetos(formados por vectores) circulares
	sf::Texture texturaVida;
	if (!texturaVida.loadFromFile("./res/Imagenes/Vida_Full_6.png"))
	{
		std::cout << "No se ha encontrado la textura de: Vida_Full_6.png\n";
	}
	sf::Sprite vida;

	vida.setTexture(texturaVida);
	vida.setPosition(840, 820);

	int vidacount=6;

	//Genera un cofre en la posición establecida
	sf::Vector2f vectorCofre((window.getSize().x / 2) - 56.f, (window.getSize().y / 2) - 40.f);
	Cofre cofre(vectorCofre);

	//Genera la bomba en el pixel 250, 150.
	sf::Vector2f vectorBomba(250, 150);

	int cuenta = 0;

	std::vector<Coin> coin(7);

	sf::Vector2u vectorcoin(4, 1);
	Animacion animacoin(&coin[0].textura, vectorcoin, 0.25);
	float deltacoin = 0.0f;

	coin[0].setPosition(460.f, 150.f);
	coin[1].setPosition(140.f, 275.f);
	coin[2].setPosition(800.f, 300.f);
	coin[3].setPosition(700.f, 500.f);
	coin[4].setPosition(125.f, 500.f);
	coin[5].setPosition(250.f, 650.f);
	coin[6].setPosition(700.f, 700.f);


	sf::Font font;

	if (!font.loadFromFile("./res/pixeled.ttf"))
	{
		std::cout << "No se ha encontrado la fuente de: pixeled.ttf\n";
	}

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
	puntos.setCharacterSize(25);
	puntos.setStyle(sf::Text::Bold);
	puntos.setFillColor(sf::Color::White);
	puntos.setOutlineColor(sf::Color::Black);
	puntos.setOutlineThickness(2);
	puntos.setPosition(80.f, 845.f);

	sf::Text text;
	text.setFont(font);
	text.setString(": ");
	text.setCharacterSize(25);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
	text.setPosition(60.f, 845.f);

	//Velocidad personaje principal
	float veloc = 4.f;

	///////////

	Vector2f centrar;

	float delaytiro = 0.f;

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

	int state=2;

	//////////

	int seleccion = 1;

	float opacidadint = 0;
	float opacidadext = 0;
	float opacidadtextint = 0;
	float opacidadtextext = 0;
	float opacidadint1 = 140;
	float opacidadext1 = 255;
	float opacidadtextint1 = 255;
	float opacidadtextext1 = 255;

	RectangleShape rectangle;
	rectangle.setSize(Vector2f(820.f,600.f));
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	rectangle.setPosition(window.getSize().x/2, window.getSize().y / 2);
	rectangle.setOutlineThickness(11.f);

	RectangleShape playboton;
	Text play;
	Text opciones;
	Text salir;

	playboton.setSize(Vector2f(200.f, 30.f));
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
	
	//Cursor Personalizado
	window.setMouseCursorVisible(false);
	sf::Texture cursortexture;
	if (!cursortexture.loadFromFile("./res/Imagenes/cursor.png"))
	{
		std::cout << "No se ha encontrado la textura de: cursor.png\n";
	}
	sf::Sprite cursor(cursortexture);

	//Musica
	sf::SoundBuffer buffer_moneda;
	if (!buffer_moneda.loadFromFile("./res/Sonidos/Find_Money.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound sonido_moneda;
	sonido_moneda.setBuffer(buffer_moneda);
	sonido_moneda.setVolume(80);

	sf::SoundBuffer buffer_daño_personaje;
	if (!buffer_daño_personaje.loadFromFile("./res/Sonidos/Hero_Hurt.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound sonido_daño_personaje;
	sonido_daño_personaje.setBuffer(buffer_daño_personaje);
	sonido_daño_personaje.setVolume(80);

	sf::SoundBuffer buffer_muerte_personaje;
	if (!buffer_muerte_personaje.loadFromFile("./res/Sonidos/Hero_Dies.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound sonido_muerte_personaje;
	sonido_muerte_personaje.setBuffer(buffer_muerte_personaje);
	sonido_muerte_personaje.setVolume(80);

	sf::SoundBuffer buffer_pared;
	if (!buffer_pared.loadFromFile("./res/Sonidos/Wall_Collision.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound sonido_pared;
	sonido_pared.setBuffer(buffer_pared);
	sonido_pared.setVolume(80);

	sf::Music musica_juego;
	musica_juego.openFromFile("./res/Sonidos/mountainoftrials.wav");
	musica_juego.setLoop(true);
	musica_juego.play();

	sf::Music musica_menu;
	musica_menu.openFromFile("./res/Sonidos/mountainoftrials_muffled.wav");
	musica_menu.setLoop(true);
	musica_menu.play();
	
	//Death screen
	sf::Texture texturamuerte;
	if (!texturamuerte.loadFromFile("./res/Imagenes/death_screen.png"))
	{
		std::cout << "No se ha encontrado la textura de: death_Screen.png\n";
	}

	//B&W texturas
	sf::Texture texturamapaBW;
	if (!texturamapaBW.loadFromFile("./res/Imagenes/PiskelPruebaAnimBW.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim_BW.png\n";
	}

	sf::Texture texturachestBW;
	if (!texturachestBW.loadFromFile("./res/Imagenes/chestBW.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim_BW.png\n";
	}

	sf::Texture texturacoinBW;
	if (!texturacoinBW.loadFromFile("./res/Imagenes/coinBW.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim_BW.png\n";
	}

	sf::Texture texturacoinpuntBW;
	if (!texturacoinpuntBW.loadFromFile("./res/Imagenes/coinpuntBW.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim_BW.png\n";
	}

	sf::Texture pjtextura_muerte;
	if (!pjtextura_muerte.loadFromFile("./res/Imagenes/pjtextura_death.png"))
	{
		std::cout << "No se ha encontrado la textura de: pjtextura_death.png\n";
	}

	sf::Sprite you_died;
	you_died.setTexture(texturamuerte);

	sf::Clock clock_muerte;
	float opacidadmuerte= 0.f;

	//Pantalla Inicio
	sf::Texture textura_pprincipal;
	if (!textura_pprincipal.loadFromFile("./res/Imagenes/PantallaPrincipal.png"))
	{
		std::cout << "No se ha encontrado la textura de: PantallaPrincipal.png\n";
	}

	sf::Sprite sprite_pprincipal;
	sprite_pprincipal.setTexture(textura_pprincipal);

	sf::Vector2u vector_pprincipal(12, 1);
	Animacion animacion_pprincipal(&textura_pprincipal, vector_pprincipal, 0.15);
	float delta_pprincipal = 0.0f;

	sf::Clock clock_pprincipal;

	Text play_pprincipal;
	Text opciones_pprincipal;
	Text salir_pprincipal;

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
	opciones_pprincipal.setPosition(playboton.getPosition().x, playboton.getPosition().y+20);

	salir_pprincipal.setFont(font);
	salir_pprincipal.setString("SALIR");
	salir_pprincipal.setCharacterSize(45);
	salir_pprincipal.setStyle(sf::Text::Bold);
	salir_pprincipal.setFillColor(sf::Color::White);
	salir_pprincipal.setOutlineColor(sf::Color::Black);
	salir_pprincipal.setOutlineThickness(4);
	salir_pprincipal.setOrigin(salir_pprincipal.getGlobalBounds().width / 2, salir_pprincipal.getGlobalBounds().height / 2);
	salir_pprincipal.setPosition(playboton.getPosition().x, playboton.getPosition().y + 210);

	//Bucle ejecutado mientras la pantalla se mantenga abierta.
	while (window.isOpen())
	{
		while (state == 1)
		{
			musica_juego.setVolume(0);
			musica_menu.setVolume(80);

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

			printf("%f", opacidadtextext);

			sf::Event event;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
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
						animacoin.tiempotot -= timercoin.getElapsedTime().asSeconds();
						mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();

						musica_menu.pause();

						state = 0;
					}

					if (opciones.getGlobalBounds().contains(mousePosF))
					{
						opciones.setPosition(2000.f, 2000.f);
						salir.setPosition(2000.f, 2000.f);
					}

					if (salir.getGlobalBounds().contains(mousePosF))
					{
						window.close();
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
							animacoin.tiempotot -= timercoin.getElapsedTime().asSeconds();
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
							window.close();
						}
						break;
					}
					break;
				}
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				cursortexture.loadFromFile("./res/Imagenes/pressed_cursor.png");
			}
			else
			{
				cursortexture.loadFromFile("./res/Imagenes/cursor.png");
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
			else
			{
				//main();
				/*
				play.setFillColor(sf::Color::White);
				opciones.setFillColor(sf::Color::White);
				salir.setFillColor(sf::Color::White);
				*/
			}

			cursor.setPosition(sf::Vector2f(mousePos));

			window.clear();

			window.draw(mapa);
			window.draw(coinpunt);
			window.draw(vida);
			window.draw(puntos);

			for (size_t i = 0; i < disparos.size(); i++)
			{
				window.draw(disparos[i]);
			}

			for (size_t i = 0; i < coin.size(); i++)
			{
				window.draw(coin[i]);
			}

			window.draw(text);
			window.draw(cofre);
			window.draw(text);
			window.draw(player);
			window.draw(rectangle);
			window.draw(play);
			window.draw(opciones);
			window.draw(salir);
			window.draw(cursor);

			window.display();
		}

		while (state == 0)
		{
			//musica_juego.setPlayingOffset(musica_menu.getPlayingOffset());
			musica_juego.setVolume(80);
			musica_menu.setVolume(0);



			sf::Event event;

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

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				state = 1;
				opciones.setPosition(playboton.getPosition().x, playboton.getPosition().y);
				salir.setPosition(playboton.getPosition().x, playboton.getPosition().y + 180);
			}


			///////////
			centrar = Vector2f(player.getPosition().x + player.getTextureRect().width / 2, player.getPosition().y + player.getTextureRect().height / 2);

			if (delaytiro < 10)
			{
				delaytiro++;
			}

			if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left) && delaytiro >= 10)
			{
				disparoLUp.setPosition(centrar);
				disparos.push_back(Proyectil(disparoLUp));
				delaytiro = 0;
				sonido_daño_personaje.play();
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
				delaytiro = 0;
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
					|| disparos[i].getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds()))
				{
					disparos.erase(disparos.begin() + i);
				}
			}
			///////////

			mapa.Update(0, mapa.deltatiempo, mapa.timer, mapa);
			
			player.Update(player.anim, player.deltatiempo, player.timer, player);

			explosion.setPosition(player.getPosition().x, player.getPosition().y);

			for (size_t i = 0; i < coin.size(); i++)
			{
				deltacoin = timercoin.restart().asSeconds();
				animacoin.Update(0, deltacoin);
				coin[i].setTextureRect(animacoin.uvRect);

				if (player.getGlobalBounds().intersects(coin[i].getGlobalBounds()))
				{
					coin[i].setPosition(2000.f, 2000.f);
					sonido_moneda.play();
					cuenta++;
				}
			}

			if (vidacount <= 5)
			{
				texturaVida.loadFromFile("./res/Imagenes/Vida_Full_5.png");
			}
			if (vidacount <= 4)
			{
				texturaVida.loadFromFile("./res/Imagenes/Vida_Full_4.png");

			}
			if (vidacount <= 3)
			{
				texturaVida.loadFromFile("./res/Imagenes/Vida_Full_3.png");
			}
			if (vidacount <= 2)
			{
				texturaVida.loadFromFile("./res/Imagenes/Vida_Full_2.png");
			}
			if (vidacount <= 1)
			{
				texturaVida.loadFromFile("./res/Imagenes/Vida_Full_1.png");
			}
			if (vidacount <= 0)
			{

				musica_juego.stop();

				mapa.setTexture(texturamapaBW);
				player.setTexture(pjtextura_muerte);
				cofre.setTexture(texturachestBW);
				coinpunt.setTexture(texturacoinpuntBW);
			
				for (int i = 0; i < coin.size(); i++)
				{
					coin[i].setTexture(texturacoinBW);
				}

				sonido_muerte_personaje.play();
				clock_muerte.restart();
				opacidadmuerte = 0;

				state = 3;
			}

			puntos.setString(std::to_string(cuenta));

			player.setColor(sf::Color::Color(255, 255, 255, 255));
			//Metodos encargados de gestionar el movimiento y colision del personaje principal con el resto de objetos y paredes del juego.

			hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				player.move(0.f, -veloc);
				hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));
				if (hitbox.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
					player.move(0.f, veloc);
					vidaanim.restart();
					if (invframes.getElapsedTime().asSeconds() >= 1.f)
					{
						sonido_daño_personaje.play();
						vidacount = vidacount - 1;
						invframes.restart();
					}
					if (invframes.getElapsedTime().asSeconds() <= 0.1f)
					{
						texturaVida.loadFromFile("./res/Imagenes/Vida_Anim.png");
						player.setColor(sf::Color::Color(255, 0, 0, 255));
					}
				}
				if (hitbox.getGlobalBounds().intersects(mapa.conjParedes[0].getGlobalBounds())) {

					player.move(0.f, veloc);

					if (invframes.getElapsedTime().asSeconds() >= 0.8f)
					{
						sonido_pared.play();
						invframes.restart();
					}

				}
				if (player.anim == 3)
				{
					player.animd = 2;
				}
				if (player.anim == 0)
				{
					player.animd = 1;
				}

				player.Update(player.animd, player.deltatiempo, player.timer, player);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				player.move(0.f, veloc);
				hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));
				if (hitbox.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
					player.move(0.f, -veloc);
					vidaanim.restart();
					if (invframes.getElapsedTime().asSeconds() >= 1)
					{
						sonido_daño_personaje.play();
						vidacount = vidacount - 1;
						invframes.restart();
					}
					if (invframes.getElapsedTime().asSeconds() <= 0.1f)
					{
						texturaVida.loadFromFile("./res/Imagenes/Vida_Anim.png");
						player.setColor(sf::Color::Color(255, 0, 0, 255));
					}
				}
				if (player.getGlobalBounds().intersects(mapa.conjParedes[2].getGlobalBounds())) {
					player.move(0.f, -veloc);

					if (invframes.getElapsedTime().asSeconds() >= 0.8f)
					{
						sonido_pared.play();
						invframes.restart();
					}
				}
				if (player.anim == 3)
				{
					player.animd = 2;
				}
				if (player.anim == 0)
				{
					player.animd = 1;
				}
				player.Update(player.animd, player.deltatiempo, player.timer, player);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				player.move(-veloc, 0.f);
				hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));
				if (hitbox.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
					player.move(veloc, 0.f);
					vidaanim.restart();
					if (invframes.getElapsedTime().asSeconds() >= 1)
					{
						sonido_daño_personaje.play();
						vidacount = vidacount - 1;
						invframes.restart();
					}
					if (invframes.getElapsedTime().asSeconds() <= 0.1f)
					{
						texturaVida.loadFromFile("./res/Imagenes/Vida_Anim.png");
						player.setColor(sf::Color::Color(255, 0, 0, 255));
					}
				}
				if (hitbox.getGlobalBounds().intersects(mapa.conjParedes[1].getGlobalBounds())) {
					player.move(veloc, 0.f);
					if (invframes.getElapsedTime().asSeconds() >= 0.8f)
					{
						sonido_pared.play();
						invframes.restart();
					}
				}

				player.Update(2, player.deltatiempo, player.timer, player);

				player.anim = 3;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				player.move(veloc, 0.f);
				hitbox.setPosition(Vector2f(player.getPosition().x, player.getPosition().y));
				if (hitbox.getGlobalBounds().intersects(cofre.getGlobalBounds())) {
					player.move(-veloc, 0.f);
					vidaanim.restart();
					if (invframes.getElapsedTime().asSeconds() >= 1)
					{
						sonido_daño_personaje.play();
						vidacount = vidacount - 1;
						invframes.restart();
					}
					if (invframes.getElapsedTime().asSeconds() <= 0.1f)
					{
						texturaVida.loadFromFile("./res/Imagenes/Vida_Anim.png");
						player.setColor(sf::Color::Color(255, 0, 0, 255));
					}
				}
				if (hitbox.getGlobalBounds().intersects(mapa.conjParedes[3].getGlobalBounds())) {
					player.move(-veloc, 0.f);
					if (invframes.getElapsedTime().asSeconds() >= 0.8f)
					{
						sonido_pared.play();
						invframes.restart();
					}
				}
				player.Update(1, player.deltatiempo, player.timer, player);

				player.anim = 0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{

				player.Update(player.anim, player.deltatiempo, player.timer, player);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{

				player.Update(player.anim, player.deltatiempo, player.timer, player);
			}

			cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));


			//Limpiar la pantalla principal
			window.clear();

			//Dibujar el fondo y los objetos, enemigos y personaje de la pantalla.
			window.draw(mapa);
			window.draw(coinpunt);
			window.draw(vida);
			window.draw(puntos);

			for (size_t i = 0; i < disparos.size(); i++)
			{
				window.draw(disparos[i]);
			}

			for (size_t i = 0; i < coin.size(); i++)
			{
				window.draw(coin[i]);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				animaexpl.tiempotot -= timer2.getElapsedTime().asSeconds();
				animaexpl.Update(0, deltatiempo2);
				explosion.setTextureRect(animaexpl.uvRect);
				window.draw(explosion);
			}
			Enemigo e2(Vector2f(700.0f, 700.0f), 0, 0, 10, texturaEn);

			//	std::thread hilodisp{};
			//	hilodisp.join();
			e2.disparoe();//Esto va a un hilo
		//	e2.limpiarbal(cofre,mapa);
		//	window.draw(e2.disparoRe);
			window.draw(text);
			window.draw(cofre);
			window.draw(text);
			window.draw(player);
			window.draw(efectodaño);
			window.draw(e2);
			//window.draw(cursor);
			//window.draw(hitbox);

			//Mostrar en la ventana creada los objetos dibujados.
			window.display();

		}

		while (state == 3)
		{

			sf::Event event;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			if (clock_muerte.getElapsedTime().asSeconds() >= 8)
			{
				state = 0;

				window.close();

				main();
			}

			if (opacidadmuerte < 255.f)
			{
				opacidadmuerte += 3;
				you_died.setColor(sf::Color::Color(255, 255, 255, opacidadmuerte));
			}

			window.draw(mapa);
			window.draw(coinpunt);
			window.draw(vida);
			window.draw(puntos);

			for (size_t i = 0; i < disparos.size(); i++)
			{
				window.draw(disparos[i]);
			}

			for (size_t i = 0; i < coin.size(); i++)
			{
				window.draw(coin[i]);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				animaexpl.tiempotot -= timer2.getElapsedTime().asSeconds();
				animaexpl.Update(0, deltatiempo2);
				explosion.setTextureRect(animaexpl.uvRect);
				window.draw(explosion);
			}

			window.draw(text);
			window.draw(cofre);
			window.draw(text);
			window.draw(player);
			window.draw(you_died);
			//window.draw(cursor);

			//Mostrar en la ventana creada los objetos dibujados.
			window.display();

		}

		while (state == 2)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			sf::Event event;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
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
						animacoin.tiempotot -= timercoin.getElapsedTime().asSeconds();
						mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();

						state = 0;
					}

					if (opciones_pprincipal.getGlobalBounds().contains(mousePosF))
					{
						opciones_pprincipal.setPosition(2000.f, 2000.f);
						salir_pprincipal.setPosition(2000.f, 2000.f);
					}

					if (salir_pprincipal.getGlobalBounds().contains(mousePosF))
					{
						window.close();
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
							animacoin.tiempotot -= timercoin.getElapsedTime().asSeconds();
							mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();

							state = 0;
						}
						if (seleccion == 2)
						{
							opciones_pprincipal.setPosition(2000.f, 2000.f);
							salir_pprincipal.setPosition(2000.f, 2000.f);
						}
						if (seleccion == 3)
						{
							window.close();
						}
						break;
					}
					break;
				}
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				cursortexture.loadFromFile("./res/Imagenes/pressed_cursor.png");
			}
			else
			{
				cursortexture.loadFromFile("./res/Imagenes/cursor.png");
			}

			if (seleccion == 1)
			{
				play_pprincipal.setFillColor(sf::Color(163, 131, 55));
				opciones_pprincipal.setFillColor(sf::Color::White);
				salir.setFillColor(sf::Color::White);
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
		

	}
}
