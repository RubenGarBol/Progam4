#include "PantallaJuego.h"
#include "Mapa.h"
#include "Personaje.h"
#include "Coin.h"
#include "Proyectil.h"
#include "Cofre.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "PantallaMuerte.h"


PantallaJuego::PantallaJuego(sf::RenderWindow& window)
{
	if (!texturaFondo.loadFromFile("./res/Imagenes/PiskelPruebaAnim.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim.png\n";
	}

	if (!pjtextura.loadFromFile("./res/Imagenes/pjtextura.png"))
	{
		std::cout << "No se ha encontrado la textura de: knight_idle.png\n";
	}

	if (!texturamapaBW.loadFromFile("./res/Imagenes/PiskelPruebaAnimBW.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim_BW.png\n";
	}

	if (!texturachestBW.loadFromFile("./res/Imagenes/chestBW.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim_BW.png\n";
	}

	if (!texturacoinBW.loadFromFile("./res/Imagenes/coinBW.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim_BW.png\n";
	}

	if (!texturacoinpuntBW.loadFromFile("./res/Imagenes/coinpuntBW.png"))
	{
		std::cout << "No se ha encontrado la textura de: PiskelPruebaAnim_BW.png\n";
	}

	if (!pjtextura_muerte.loadFromFile("./res/Imagenes/pjtextura_death.png"))
	{
		std::cout << "No se ha encontrado la textura de: pjtextura_death.png\n";
	}

	if (!texturaVida.loadFromFile("./res/Imagenes/Vida_Full_6.png"))
	{
		std::cout << "No se ha encontrado la textura de: Vida_Full_6.png\n";
	}

	if (!font.loadFromFile("./res/pixeled.ttf"))
	{
		std::cout << "No se ha encontrado la fuente de: pixeled.ttf\n";
	}

	if (!texturapuntos.loadFromFile("./res/Imagenes/coinpunt.png"))
	{
		std::cout << "No se ha encontrado la textura de: coinpunt.png\n";
	}

	hitbox.setSize(sf::Vector2f(60.f, 20.f));
	hitbox.setOrigin(-15.f, -95.f);

	pared1.setPosition(sf::Vector2f(0.f, 0.f));
	pared1.setSize(sf::Vector2f(1056.f, 120.f));

	pared2.setPosition(sf::Vector2f(0.f, 0.f));
	pared2.setSize(sf::Vector2f(30.f, 888.f));

	pared3.setPosition(sf::Vector2f(0.f, 768.f));
	pared3.setSize(sf::Vector2f(1056.f, 120.f));

	pared4.setPosition(sf::Vector2f(1026.f, 0.f));
	pared4.setSize(sf::Vector2f(30.f, 888.f));

	puertaIz.setPosition(sf::Vector2f(5.f, 430.f));
	puertaIz.setSize(sf::Vector2f(25.f, 108.f));

	puertaAr.setPosition(sf::Vector2f(482.f, 25.f));
	puertaAr.setSize(sf::Vector2f(92.f, 95.f));

	puertaDr.setPosition(sf::Vector2f(1024.f, 409.f));
	puertaDr.setSize(sf::Vector2f(31.f, 98.f));

	puertaAb.setPosition(sf::Vector2f(492.f, 764.f));
	puertaAb.setSize(sf::Vector2f(86.f, 115.f));

	paredesCruz[0] = pared1;
	paredesCruz[1] = pared2;
	paredesCruz[2] = pared3;
	paredesCruz[3] = pared4;

	puertas[0] = puertaAr;
	puertas[1] = puertaDr;
	puertas[2] = puertaAb;
	puertas[3] = puertaIz;

	vida.setTexture(texturaVida);
	vida.setPosition(840, 820);

	vectorcoin = Vector2u(4, 1);
	animacoin =Animacion(&coin[0].textura, vectorcoin, 0.25);
	float deltacoin = 0.0f;

	coin[0].setPosition(375.f, 750.f);
	coin[1].setPosition(140.f, 275.f);
	coin[2].setPosition(800.f, 300.f);
	coin[3].setPosition(700.f, 500.f);
	coin[4].setPosition(125.f, 500.f);
	coin[5].setPosition(250.f, 650.f);
	coin[6].setPosition(700.f, 700.f);

	coinpunt.setTexture(texturapuntos);
	coinpunt.setPosition(15.f, 830.f);

	puntos.setFont(font);
	puntos.setCharacterSize(25);
	puntos.setStyle(sf::Text::Bold);
	puntos.setFillColor(sf::Color::White);
	puntos.setOutlineColor(sf::Color::Black);
	puntos.setOutlineThickness(2);
	puntos.setPosition(80.f, 845.f);

	text.setFont(font);
	text.setString(": ");
	text.setCharacterSize(25);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
	text.setPosition(60.f, 845.f);
	
	disparoup	= Proyectil(0, -10);
	disparodown	= Proyectil(0, 10);
	disparoR	= Proyectil(10, 0);
	disparoL	= Proyectil(-10, 0);
	disparoLUp	= Proyectil(-7, -7);
	disparoLDown= Proyectil(-7, 7);
	disparoRUp	= Proyectil(7, -7);
	disparoRDown= Proyectil(7, 7);
	
	sf::Vector2f vectorCofre((window.getSize().x / 2) - 56.f, (window.getSize().y / 2) - 40.f);
	Cofre cofre(vectorCofre);

	Mapa mapa(texturaFondo, paredesCruz, puertas);

	Personaje player(pjtextura);

}

void PantallaJuego::Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player, GestorSonido& audio)
{
	sf::Event event;

	//Función para cerrar la aplicación al pulsar el boton X de la parte superior derecha.
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			exit(0);
			break;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		*state = 1;
	}

	centrar = Vector2f(player.getPosition().x + player.getTextureRect().width / 2, player.getPosition().y + player.getTextureRect().height / 2);

	if (delaytiro < 10)
	{
		delaytiro++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left) && delaytiro >= 10)
	{
		disparoLUp.setPosition(centrar);
		disparos.push_back(disparoLUp);
		delaytiro = 0;
		audio.sonido_daño_personaje.play();
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right) && delaytiro >= 10)
	{
		disparoRUp.setPosition(centrar);
		disparos.push_back(disparoRUp);
		delaytiro = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left) && delaytiro >= 10)
	{
		disparoLDown.setPosition(centrar);
		disparos.push_back(disparoLDown);
		delaytiro = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right) && delaytiro >= 10)
	{
		disparoRDown.setPosition(centrar);
		disparos.push_back(disparoRDown);
		delaytiro = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && delaytiro >= 10)
	{
		disparoup.setPosition(centrar);
		disparos.push_back(disparoup);
		delaytiro = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) && delaytiro >= 10)
	{
		disparodown.setPosition(centrar);
		disparos.push_back(disparodown);
		delaytiro = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) && delaytiro >= 10)
	{
		disparoL.setPosition(centrar);
		disparos.push_back(disparoL);
		delaytiro = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right) && delaytiro >= 10)
	{
		disparoR.setPosition(centrar);
		disparos.push_back(disparoR);
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

	mapa.Update(0, mapa.deltatiempo, mapa.timer, mapa);

	player.Update(player.anim, player.deltatiempo, player.timer, player);

	for (size_t i = 0; i < coin.size(); i++)
	{
		deltacoin = timercoin.restart().asSeconds();
		animacoin.Update(0, deltacoin);
		coin[i].setTextureRect(animacoin.uvRect);

		if (player.getGlobalBounds().intersects(coin[i].getGlobalBounds()))
		{
			coin[i].setPosition(2000.f, 2000.f);
			audio.sonido_moneda.play();
			cuenta++;
		}
	}

	////////
	//////// SOLUCIONAR PROBLEMAS RENDIMIENTO
	////////
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
	////////
	//////// SOLUCIONAR PROBLEMAS RENDIMIENTO
	////////

	if (vidacount <= 0)
	{

		audio.musica_juego.stop();

		mapa.setTexture(texturamapaBW);
		player.setTexture(pjtextura_muerte);
		cofre.setTexture(texturachestBW);
		coinpunt.setTexture(texturacoinpuntBW);

		for (int i = 0; i < coin.size(); i++)
		{
			coin[i].setTexture(texturacoinBW);
		}

		audio.sonido_muerte_personaje.play();
		

		*state = 3;
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
				audio.sonido_daño_personaje.play();
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
				audio.sonido_pared.play();
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
				audio.sonido_daño_personaje.play();
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
				audio.sonido_pared.play();
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
				audio.sonido_daño_personaje.play();
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
				audio.sonido_pared.play();
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
				audio.sonido_daño_personaje.play();
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
				audio.sonido_pared.play();
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


	//Enemigo e2(Vector2f(700.0f, 700.0f), 0, 0, 10, texturaEn);

	//std::thread hilodisp{};
	//hilodisp.join();
	//e2.disparoe();//Esto va a un hilo
	//e2.limpiarbal(cofre,mapa);
	//window.draw(e2.disparoRe);
	window.draw(text);
	window.draw(cofre);
	window.draw(text);
	window.draw(player);
	//window.draw(efectodaño);
	//window.draw(e2);
	//window.draw(cursor);
	//window.draw(hitbox);

	//Mostrar en la ventana creada los objetos dibujados.
	window.display();
}


PantallaJuego::~PantallaJuego()
{
}
