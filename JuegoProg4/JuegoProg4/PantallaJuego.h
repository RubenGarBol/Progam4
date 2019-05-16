#pragma once
#include "SFML/Graphics.hpp"
#include "Mapa.h"
#include "Personaje.h"
#include "Coin.h"
#include "Cofre.h"
#include "Proyectil.h"
#include "GestorSonido.h"
#include <algorithm>
class PantallaJuego
{
public:
	//Carga de texturas desde los .png, si no se encuentran avisar al usuario mediante una excepción.
	sf::Texture texturaFondo;
	
	//Carga del spritesheet de las animaciones del personaje principal
	sf::Texture pjtextura;

	sf::Texture texturamapaBW;
	sf::Texture texturachestBW;
	sf::Texture texturacoinBW;
	sf::Texture texturacoinpuntBW;
	sf::Texture pjtextura_muerte;

	//Hitbox del personaje para colisiones con objetos
	sf::RectangleShape hitbox;

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
	sf::RectangleShape pared2;
	sf::RectangleShape pared3;
	sf::RectangleShape pared4;

	sf::RectangleShape paredArribaPasilloH;
	sf::RectangleShape paredAbajoPasilloH;

	sf::RectangleShape paredIzquierdaPasilloV;
	sf::RectangleShape paredDerechaPasilloV;

	sf::RectangleShape puertaIz;
	sf::RectangleShape puertaAr;
	sf::RectangleShape puertaDr;
	sf::RectangleShape puertaAb;

	sf::RectangleShape puertaNull;

	RectangleShape puertasCruces[4];
	RectangleShape puertasArribaIzquierda[4];
	RectangleShape puertasArribaDerecha[4];
	RectangleShape puertasAbajoIzquierda[4];
	RectangleShape puertasAbajoDerecha[4];
	RectangleShape puertasPArriba[4];
	RectangleShape puertasPAbajo[4];
	RectangleShape puertasPIzquierda[4];
	RectangleShape puertasPDerecha[4];

	RectangleShape paredesCruz[4];
	RectangleShape paredesPasilloH[4];
	RectangleShape paredesPasilloV[4];

	//Mapa mapaCompleto[posicion];

	Texture tCruz_1;
	Texture tCruz_2;
	Texture tCruz_3;
	Texture tCruz_4;
	Texture tCruz_5;

	Texture tAbajoDerecha_1;
	Texture tAbajoDerecha_2;
	Texture tAbajoDerecha_3;
	Texture tAbajoDerecha_4;
	Texture tAbajoDerecha_5;

	Texture tAbajoIzquierda_1;
	Texture tAbajoIzquierda_2;
	Texture tAbajoIzquierda_3;
	Texture tAbajoIzquierda_4;
	Texture tAbajoIzquierda_5;

	Texture tArribaDerecha_1;
	Texture tArribaDerecha_2;
	Texture tArribaDerecha_3;
	Texture tArribaDerecha_4;
	Texture tArribaDerecha_5;

	Texture tArribaIzquierda_1;
	Texture tArribaIzquierda_2;
	Texture tArribaIzquierda_3;
	Texture tArribaIzquierda_4;
	Texture tArribaIzquierda_5;

	Texture tPAbajo_1;
	Texture tPAbajo_2;
	Texture tPAbajo_3;
	Texture tPAbajo_4;
	Texture tPAbajo_5;

	Texture tPArriba_1;
	Texture tPArriba_2;
	Texture tPArriba_3;
	Texture tPArriba_4;
	Texture tPArriba_5;

	Texture tPDerecha_1;
	Texture tPDerecha_2;
	Texture tPDerecha_3;
	Texture tPDerecha_4;
	Texture tPDerecha_5;

	Texture tPIzquierda_1;
	Texture tPIzquierda_2;
	Texture tPIzquierda_3;
	Texture tPIzquierda_4;
	Texture tPIzquierda_5;

	Mapa cruz_1;
	Mapa cruz_2;
	Mapa cruz_3;
	Mapa cruz_4;
	Mapa cruz_5;

	Mapa AbajoDerecha_1;
	Mapa AbajoDerecha_2;
	Mapa AbajoDerecha_3;
	Mapa AbajoDerecha_4;
	Mapa AbajoDerecha_5;

	Mapa AbajoIzquierda_1;
	Mapa AbajoIzquierda_2;
	Mapa AbajoIzquierda_3;
	Mapa AbajoIzquierda_4;
	Mapa AbajoIzquierda_5;

	Mapa ArribaDerecha_1;
	Mapa ArribaDerecha_2;
	Mapa ArribaDerecha_3;
	Mapa ArribaDerecha_4;
	Mapa ArribaDerecha_5;

	Mapa ArribaIzquierda_1;
	Mapa ArribaIzquierda_2;
	Mapa ArribaIzquierda_3;
	Mapa ArribaIzquierda_4;
	Mapa ArribaIzquierda_5;

	Mapa PAbajo_1;
	Mapa PAbajo_2;
	Mapa PAbajo_3;
	Mapa PAbajo_4;
	Mapa PAbajo_5;

	Mapa PArriba_1;
	Mapa PArriba_2;
	Mapa PArriba_3;
	Mapa PArriba_4;
	Mapa PArriba_5;

	Mapa PDerecha_1;
	Mapa PDerecha_2;
	Mapa PDerecha_3;
	Mapa PDerecha_4;
	Mapa PDerecha_5;

	Mapa PIzquierda_1;
	Mapa PIzquierda_2;
	Mapa PIzquierda_3;
	Mapa PIzquierda_4;
	Mapa PIzquierda_5;

	Mapa AbajoDerecha[5];
	Mapa AbajoIzquierda[5];
	Mapa ArribaDerecha[5];
	Mapa ArribaIzquierda[5];
	Mapa Cruces[5];
	Mapa PuertaAbajo[5];
	Mapa PuertaArriba[5];
	Mapa PuertaDerecha[5];
	Mapa PuertaIzquierda[5];

	std::vector<Mapa> mapaCompleto;
	int posicion;

	Personaje player;

	sf::Texture texturaVida;
	sf::Sprite vida;
	int vidacount = 6;

	//Genera un cofre en la posición establecida
	sf::Vector2f vectorCofre;
	Cofre cofre;

	int cuenta = 0;

	std::vector<Coin> coin = std::vector<Coin>(7);
	sf::Vector2u vectorcoin;
	Animacion animacoin;
	float deltacoin = 0.0f;

	sf::Font font;
	sf::Texture texturapuntos;
	sf::Sprite coinpunt;
	sf::Text puntos;
	sf::Text text;

	//Velocidad personaje principal
	float veloc = 4.f;

	///////////

	Vector2f centrar;

	
	float delaytiro = 0.f;
	
	Proyectil disparoup;
	Proyectil disparodown;
	Proyectil disparoR;
	Proyectil disparoL;
	Proyectil disparoLUp;
	Proyectil disparoLDown;
	Proyectil disparoRUp;
	Proyectil disparoRDown;
	std::vector<Proyectil> disparos;
	
	PantallaJuego(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, int *state, Personaje& player, GestorSonido& audio);
	std::vector<Mapa> generarMapa(Mapa esArIz[5], Mapa esArDr[5], Mapa esAbIz[5], Mapa esAbDr[5],
		Mapa derecha[5], Mapa izquierda[5], Mapa abajo[5], Mapa arriba[5], Mapa central[5]);//En el main hacer srand(time(0));
	~PantallaJuego();
};

