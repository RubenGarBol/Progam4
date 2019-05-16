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

	tCruz_1.loadFromFile("./res/Imagenes/Mapas/Cruces/Cruz_1.png");
	tCruz_2.loadFromFile("./res/Imagenes/Mapas/Cruces/Cruz_2.png");
	tCruz_3.loadFromFile("./res/Imagenes/Mapas/Cruces/Cruz_3.png");
	tCruz_4.loadFromFile("./res/Imagenes/Mapas/Cruces/Cruz_4.png");
	tCruz_5.loadFromFile("./res/Imagenes/Mapas/Cruces/Cruz_5.png");

	tAbajoDerecha_1.loadFromFile("./res/Imagenes/Mapas/AbajoDerecha/AbajoDerecha_1.png");
	tAbajoDerecha_2.loadFromFile("./res/Imagenes/Mapas/AbajoDerecha/AbajoDerecha_2.png");
	tAbajoDerecha_3.loadFromFile("./res/Imagenes/Mapas/AbajoDerecha/AbajoDerecha_3.png");
	tAbajoDerecha_4.loadFromFile("./res/Imagenes/Mapas/AbajoDerecha/AbajoDerecha_4.png");
	tAbajoDerecha_5.loadFromFile("./res/Imagenes/Mapas/AbajoDerecha/AbajoDerecha_5.png");

	tAbajoIzquierda_1.loadFromFile("./res/Imagenes/Mapas/AbajoIzquierda/AbajoIzquierda_1.png");
	tAbajoIzquierda_2.loadFromFile("./res/Imagenes/Mapas/AbajoIzquierda/AbajoIzquierda_2.png");
	tAbajoIzquierda_3.loadFromFile("./res/Imagenes/Mapas/AbajoIzquierda/AbajoIzquierda_3.png");
	tAbajoIzquierda_4.loadFromFile("./res/Imagenes/Mapas/AbajoIzquierda/AbajoIzquierda_4.png");
	tAbajoIzquierda_5.loadFromFile("./res/Imagenes/Mapas/AbajoIzquierda/AbajoIzquierda_5.png");

	tArribaDerecha_1.loadFromFile("./res/Imagenes/Mapas/ArribaDerecha/ArribaDerecha_1.png");
	tArribaDerecha_2.loadFromFile("./res/Imagenes/Mapas/ArribaDerecha/ArribaDerecha_2.png");
	tArribaDerecha_3.loadFromFile("./res/Imagenes/Mapas/ArribaDerecha/ArribaDerecha_3.png");
	tArribaDerecha_4.loadFromFile("./res/Imagenes/Mapas/ArribaDerecha/ArribaDerecha_4.png");
	tArribaDerecha_5.loadFromFile("./res/Imagenes/Mapas/ArribaDerecha/ArribaDerecha_5.png");

	tArribaIzquierda_1.loadFromFile("./res/Imagenes/Mapas/ArribaIzquierda/ArribaIzquierda_1.png");
	tArribaIzquierda_2.loadFromFile("./res/Imagenes/Mapas/ArribaIzquierda/ArribaIzquierda_2.png");
	tArribaIzquierda_3.loadFromFile("./res/Imagenes/Mapas/ArribaIzquierda/ArribaIzquierda_3.png");
	tArribaIzquierda_4.loadFromFile("./res/Imagenes/Mapas/ArribaIzquierda/ArribaIzquierda_4.png");
	tArribaIzquierda_5.loadFromFile("./res/Imagenes/Mapas/ArribaIzquierda/ArribaIzquierda_5.png");

	tPAbajo_1.loadFromFile("./res/Imagenes/Mapas/PuertaAbajo/PAbajo_1.png");
	tPAbajo_2.loadFromFile("./res/Imagenes/Mapas/PuertaAbajo/PAbajo_2.png");
	tPAbajo_3.loadFromFile("./res/Imagenes/Mapas/PuertaAbajo/PAbajo_3.png");
	tPAbajo_4.loadFromFile("./res/Imagenes/Mapas/PuertaAbajo/PAbajo_4.png");
	tPAbajo_5.loadFromFile("./res/Imagenes/Mapas/PuertaAbajo/PAbajo_5.png");

	tPArriba_1.loadFromFile("./res/Imagenes/Mapas/PuertaArriba/PArriba_1.png");
	tPArriba_2.loadFromFile("./res/Imagenes/Mapas/PuertaArriba/PArriba_2.png");
	tPArriba_3.loadFromFile("./res/Imagenes/Mapas/PuertaArriba/PArriba_3.png");
	tPArriba_4.loadFromFile("./res/Imagenes/Mapas/PuertaArriba/PArriba_4.png");
	tPArriba_5.loadFromFile("./res/Imagenes/Mapas/PuertaArriba/PArriba_5.png");

	tPDerecha_1.loadFromFile("./res/Imagenes/Mapas/PuertaDerecha/PDerecha_1.png");
	tPDerecha_2.loadFromFile("./res/Imagenes/Mapas/PuertaDerecha/PDerecha_2.png");
	tPDerecha_3.loadFromFile("./res/Imagenes/Mapas/PuertaDerecha/PDerecha_3.png");
	tPDerecha_4.loadFromFile("./res/Imagenes/Mapas/PuertaDerecha/PDerecha_4.png");
	tPDerecha_5.loadFromFile("./res/Imagenes/Mapas/PuertaDerecha/PDerecha_5.png");
	
	tPIzquierda_1.loadFromFile("./res/Imagenes/Mapas/PuertaIzquierda/PIzquierda_1.png");
	tPIzquierda_2.loadFromFile("./res/Imagenes/Mapas/PuertaIzquierda/PIzquierda_2.png");
	tPIzquierda_3.loadFromFile("./res/Imagenes/Mapas/PuertaIzquierda/PIzquierda_3.png");
	tPIzquierda_4.loadFromFile("./res/Imagenes/Mapas/PuertaIzquierda/PIzquierda_4.png");
	tPIzquierda_5.loadFromFile("./res/Imagenes/Mapas/PuertaIzquierda/PIzquierda_5.png");

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

	puertaNull.setPosition(sf::Vector2f(0.f, 0.f));
	puertaNull.setSize(sf::Vector2f(1.f, 1.f));

	paredArribaPasilloH.setPosition(sf::Vector2f(0.f,192.f));
	paredArribaPasilloH.setSize(sf::Vector2f(1056.f, 116.f));

	paredAbajoPasilloH.setPosition(sf::Vector2f(0.f, 578.f));
	paredAbajoPasilloH.setSize(sf::Vector2f(1056.f, 116.f));

	paredIzquierdaPasilloV.setPosition(sf::Vector2f(355.f, 0.f));
	paredIzquierdaPasilloV.setSize(sf::Vector2f(31.f, 887.f));

	paredDerechaPasilloV.setPosition(sf::Vector2f(674.f, 0.f));
	paredDerechaPasilloV.setSize(sf::Vector2f(31.f, 887.f));

	puertasCruces[0] = puertaAr;
	puertasCruces[1] = puertaDr;
	puertasCruces[2] = puertaAb;
	puertasCruces[3] = puertaIz;

	puertasAbajoDerecha[0] = puertaAr;
	puertasAbajoDerecha[1] = puertaNull;
	puertasAbajoDerecha[2] = puertaNull;
	puertasAbajoDerecha[3] = puertaIz;

	puertasAbajoIzquierda[0] = puertaAr;
	puertasAbajoIzquierda[1] = puertaDr;
	puertasAbajoIzquierda[2] = puertaNull;
	puertasAbajoIzquierda[3] = puertaNull;

	puertasArribaDerecha[0] = puertaNull;
	puertasArribaDerecha[1] = puertaNull;
	puertasArribaDerecha[2] = puertaAb;
	puertasArribaDerecha[3] = puertaIz;

	puertasArribaIzquierda[0] = puertaNull;
	puertasArribaIzquierda[1] = puertaDr;
	puertasArribaIzquierda[2] = puertaAb;
	puertasArribaIzquierda[3] = puertaNull;

	puertasPAbajo[0] = puertaNull;
	puertasPAbajo[1] = puertaNull;
	puertasPAbajo[2] = puertaAb;
	puertasPAbajo[3] = puertaNull;

	puertasPArriba[0] = puertaAr;
	puertasPArriba[1] = puertaNull;
	puertasPArriba[2] = puertaNull;
	puertasPArriba[3] = puertaNull;

	puertasPIzquierda[0] = puertaNull;
	puertasPIzquierda[1] = puertaNull;
	puertasPIzquierda[2] = puertaNull;
	puertasPIzquierda[3] = puertaIz;

	puertasPDerecha[0] = puertaNull;
	puertasPDerecha[1] = puertaDr;
	puertasPDerecha[2] = puertaNull;
	puertasPDerecha[3] = puertaNull;

	paredesCruz[0] = pared1;
	paredesCruz[1] = pared2;
	paredesCruz[2] = pared3;
	paredesCruz[3] = pared4;

	paredesPasilloH[0] = paredArribaPasilloH;
	paredesPasilloH[1] = pared2;
	paredesPasilloH[2] = paredAbajoPasilloH;
	paredesPasilloH[3] = pared4;

	paredesPasilloV[0] = pared1;
	paredesPasilloV[1] = paredIzquierdaPasilloV;
	paredesPasilloV[2] = pared3;
	paredesPasilloV[3] = paredDerechaPasilloV;

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

	//mapaActual = Mapa(texturaFondo, paredesCruz, puertas);

	AbajoDerecha_1 = Mapa(tAbajoDerecha_1, paredesCruz, puertasAbajoDerecha, coin);
	AbajoDerecha_2 = Mapa(tAbajoDerecha_2, paredesCruz, puertasAbajoDerecha, coin);
	AbajoDerecha_3 = Mapa(tAbajoDerecha_3, paredesCruz, puertasAbajoDerecha, coin);
	AbajoDerecha_4 = Mapa(tAbajoDerecha_4, paredesCruz, puertasAbajoDerecha, coin);
	AbajoDerecha_5 = Mapa(tAbajoDerecha_5, paredesCruz, puertasAbajoDerecha, coin);

	AbajoIzquierda_1 = Mapa(tAbajoIzquierda_1, paredesCruz, puertasAbajoIzquierda, coin);
	AbajoIzquierda_2 = Mapa(tAbajoIzquierda_2, paredesCruz, puertasAbajoIzquierda, coin);
	AbajoIzquierda_3 = Mapa(tAbajoIzquierda_3, paredesCruz, puertasAbajoIzquierda, coin);
	AbajoIzquierda_4 = Mapa(tAbajoIzquierda_4, paredesCruz, puertasAbajoIzquierda, coin);
	AbajoIzquierda_5 = Mapa(tAbajoIzquierda_5, paredesCruz, puertasAbajoIzquierda, coin);

	ArribaDerecha_1 = Mapa(tArribaDerecha_1, paredesCruz, puertasArribaDerecha, coin);
	ArribaDerecha_2 = Mapa(tArribaDerecha_2, paredesCruz, puertasArribaDerecha, coin);
	ArribaDerecha_3 = Mapa(tArribaDerecha_3, paredesCruz, puertasArribaDerecha, coin);
	ArribaDerecha_4 = Mapa(tArribaDerecha_4, paredesCruz, puertasArribaDerecha, coin);
	ArribaDerecha_5 = Mapa(tArribaDerecha_5, paredesCruz, puertasArribaDerecha, coin);

	ArribaIzquierda_1 = Mapa(tArribaIzquierda_1, paredesCruz, puertasArribaIzquierda, coin);
	ArribaIzquierda_2 = Mapa(tArribaIzquierda_1, paredesCruz, puertasArribaIzquierda, coin);
	ArribaIzquierda_3 = Mapa(tArribaIzquierda_1, paredesCruz, puertasArribaIzquierda, coin);
	ArribaIzquierda_4 = Mapa(tArribaIzquierda_1, paredesCruz, puertasArribaIzquierda, coin);
	ArribaIzquierda_5 = Mapa(tArribaIzquierda_1, paredesCruz, puertasArribaIzquierda, coin);

	cruz_1 = Mapa(tCruz_1, paredesCruz, puertasCruces, coin);
	cruz_2 = Mapa(tCruz_2, paredesCruz, puertasCruces, coin);
	cruz_3 = Mapa(tCruz_3, paredesCruz, puertasCruces, coin);
	cruz_4 = Mapa(tCruz_4, paredesCruz, puertasCruces, coin);
	cruz_5 = Mapa(tCruz_5, paredesCruz, puertasCruces, coin);

	PAbajo_1 = Mapa(tPAbajo_1, paredesPasilloV, puertasPAbajo, coin);
	PAbajo_2 = Mapa(tPAbajo_2, paredesPasilloV, puertasPAbajo, coin);
	PAbajo_3 = Mapa(tPAbajo_3, paredesPasilloV, puertasPAbajo, coin);
	PAbajo_4 = Mapa(tPAbajo_4, paredesPasilloV, puertasPAbajo, coin);
	PAbajo_5 = Mapa(tPAbajo_5, paredesPasilloV, puertasPAbajo, coin);

	PArriba_1 = Mapa(tPArriba_1, paredesPasilloV, puertasPArriba, coin);
	PArriba_2 = Mapa(tPArriba_2, paredesPasilloV, puertasPArriba, coin);
	PArriba_3 = Mapa(tPArriba_3, paredesPasilloV, puertasPArriba, coin);
	PArriba_4 = Mapa(tPArriba_4, paredesPasilloV, puertasPArriba, coin);
	PArriba_5 = Mapa(tPArriba_5, paredesPasilloV, puertasPArriba, coin);

	PDerecha_1 = Mapa(tPDerecha_1, paredesPasilloH, puertasPDerecha, coin);
	PDerecha_2 = Mapa(tPDerecha_2, paredesPasilloH, puertasPDerecha, coin);
	PDerecha_3 = Mapa(tPDerecha_3, paredesPasilloH, puertasPDerecha, coin);
	PDerecha_4 = Mapa(tPDerecha_4, paredesPasilloH, puertasPDerecha, coin);
	PDerecha_5 = Mapa(tPDerecha_5, paredesPasilloH, puertasPDerecha, coin);

	PIzquierda_1 = Mapa(tPIzquierda_1, paredesPasilloH, puertasPIzquierda, coin);
	PIzquierda_2 = Mapa(tPIzquierda_2, paredesPasilloH, puertasPIzquierda, coin);
	PIzquierda_3 = Mapa(tPIzquierda_3, paredesPasilloH, puertasPIzquierda, coin);
	PIzquierda_4 = Mapa(tPIzquierda_4, paredesPasilloH, puertasPIzquierda, coin);
	PIzquierda_5 = Mapa(tPIzquierda_5, paredesPasilloH, puertasPIzquierda, coin);

	AbajoDerecha[0] = AbajoDerecha_1;
	AbajoDerecha[1] = AbajoDerecha_2;
	AbajoDerecha[2] = AbajoDerecha_3;
	AbajoDerecha[3] = AbajoDerecha_4;
	AbajoDerecha[4] = AbajoDerecha_5;

	AbajoIzquierda[0] = AbajoIzquierda_1;
	AbajoIzquierda[1] = AbajoIzquierda_2;
	AbajoIzquierda[2] = AbajoIzquierda_3;
	AbajoIzquierda[3] = AbajoIzquierda_4;
	AbajoIzquierda[4] = AbajoIzquierda_5;

	ArribaDerecha[0] = ArribaDerecha_1;
	ArribaDerecha[1] = ArribaDerecha_2;
	ArribaDerecha[2] = ArribaDerecha_3;
	ArribaDerecha[3] = ArribaDerecha_4;
	ArribaDerecha[4] = ArribaDerecha_5;

	ArribaIzquierda[0] = ArribaIzquierda_1;
	ArribaIzquierda[1] = ArribaIzquierda_2;
	ArribaIzquierda[2] = ArribaIzquierda_3;
	ArribaIzquierda[3] = ArribaIzquierda_4;
	ArribaIzquierda[4] = ArribaIzquierda_5;

	Cruces[0] = cruz_1;
	Cruces[1] = cruz_2;
	Cruces[2] = cruz_3;
	Cruces[3] = cruz_4;
	Cruces[4] = cruz_5;

	PuertaAbajo[0] = PAbajo_1;
	PuertaAbajo[1] = PAbajo_2;
	PuertaAbajo[2] = PAbajo_3;
	PuertaAbajo[3] = PAbajo_4;
	PuertaAbajo[4] = PAbajo_5;

	PuertaArriba[0] = PArriba_1;
	PuertaArriba[1] = PArriba_2;
	PuertaArriba[2] = PArriba_3;
	PuertaArriba[3] = PArriba_4;
	PuertaArriba[4] = PArriba_5;

	PuertaDerecha[0] = PDerecha_1;
	PuertaDerecha[1] = PDerecha_2;
	PuertaDerecha[2] = PDerecha_3;
	PuertaDerecha[3] = PDerecha_4;
	PuertaDerecha[4] = PDerecha_5;

	PuertaIzquierda[0] = PIzquierda_1;
	PuertaIzquierda[1] = PIzquierda_2;
	PuertaIzquierda[2] = PIzquierda_3;
	PuertaIzquierda[3] = PIzquierda_4;
	PuertaIzquierda[4] = PIzquierda_5;

	mapaCompleto = generarMapa(ArribaIzquierda,ArribaDerecha,AbajoIzquierda,AbajoDerecha,PuertaDerecha,PuertaIzquierda,PuertaAbajo,PuertaArriba,Cruces);

	posicion = 12;
	mapaActual = mapaCompleto[posicion];

	Personaje player(pjtextura);

}

void PantallaJuego::Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player, GestorSonido& audio)
{
	sf::Event event;


	//Funci�n para cerrar la aplicaci�n al pulsar el boton X de la parte superior derecha.
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
		audio.sonido_da�o_personaje.play();
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

	for (size_t i = 0; i < mapa.coin.size(); i++)
	{
		deltacoin = timercoin.restart().asSeconds();
		animacoin.Update(0, deltacoin);
		mapa.coin[i].setTextureRect(animacoin.uvRect);

		if (player.getGlobalBounds().intersects(mapa.coin[i].getGlobalBounds()))
		{
			mapa.coin[i].setPosition(2000.f, 2000.f);
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
				audio.sonido_da�o_personaje.play();
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
		if (hitbox.getGlobalBounds().intersects(mapa.conjPuertas[0].getGlobalBounds())) 
		{
			printf("Puerta Ar");
			posicion = posicion - 5;
			mapaActual = mapaCompleto[posicion];
			player.setPosition(494, 630);
			player.tiempotot -= player.timer.getElapsedTime().asSeconds();
			mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();

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
				audio.sonido_da�o_personaje.play();
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
		if (player.getGlobalBounds().intersects(mapa.conjPuertas[2].getGlobalBounds()))
		{
			player.setPosition(494, 60);
			printf("Puerta Ab");
			posicion = posicion + 5;

			
			//std::cout << mapa.coin[0].getPosition().x;
			mapaActual = mapaCompleto[posicion];	
		
			player.tiempotot -= player.timer.getElapsedTime().asSeconds();
			mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();

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
				audio.sonido_da�o_personaje.play();
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
		if (hitbox.getGlobalBounds().intersects(mapa.conjPuertas[3].getGlobalBounds())) 
		{
			printf("Puerta Iz");
			posicion = posicion - 1;
			mapaActual = mapaCompleto[posicion];
			
			player.setPosition(945, 380);
			player.tiempotot -= player.timer.getElapsedTime().asSeconds();
			mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();
			animacoin.tiempotot -= timercoin.getElapsedTime().asSeconds();

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
				audio.sonido_da�o_personaje.play();
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
		if (hitbox.getGlobalBounds().intersects(mapa.conjPuertas[1].getGlobalBounds())) 
		{
			printf("Puerta Dr");
			posicion = posicion + 1;
			mapaActual = mapaCompleto[posicion];
			player.setPosition(25, 375);
			player.tiempotot -= player.timer.getElapsedTime().asSeconds();
			mapa.tiempotot -= mapa.timer.getElapsedTime().asSeconds();

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

	for (size_t i = 0; i < mapa.coin.size(); i++)
	{
		window.draw(mapa.coin[i]);
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
	//window.draw(efectoda�o);
	//window.draw(e2);
	//window.draw(cursor);
	//window.draw(hitbox);

	//Mostrar en la ventana creada los objetos dibujados.
	window.display();
}

std::vector<Mapa> PantallaJuego::generarMapa(Mapa esArIz[5], Mapa esArDr[5], Mapa esAbIz[5], Mapa esAbDr[5],
	Mapa derecha[5], Mapa izquierda[5], Mapa abajo[5], Mapa arriba[5], Mapa central[5]) {
	std::vector<Mapa> arrayMapa(25);

	int aleatorios[13];
	for (int i = 0; i < 13; i++) {
		int numero = rand() % ((5 - 1) + 1);
		printf("%i",numero);
		aleatorios[i] = numero;
	}
	arrayMapa[2] = abajo[aleatorios[0]];
	arrayMapa[6] = esArIz[aleatorios[1]]; 
	arrayMapa[7] = central[aleatorios[2]]; 
	arrayMapa[8] = esArDr[aleatorios[3]];
	arrayMapa[10] = derecha[aleatorios[4]];
	arrayMapa[11] = central[aleatorios[5]];
	arrayMapa[12] = central[aleatorios[6]];
	arrayMapa[13] = central[aleatorios[7]];
	arrayMapa[14] = izquierda[aleatorios[8]];
	arrayMapa[16] = esAbIz[aleatorios[9]];
	arrayMapa[17] = central[aleatorios[10]];
	arrayMapa[18] = esAbDr[aleatorios[11]];
	arrayMapa[22] = arriba[aleatorios[12]];

	return arrayMapa;
}

PantallaJuego::~PantallaJuego()
{
}
