#pragma once
#include "SFML/Graphics.hpp"
#include "Mapa.h"
#include "Personaje.h"
#include "Coin.h"
#include "Cofre.h"
#include "Proyectil.h"
#include "GestorSonido.h"

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
	sf::RectangleShape puertaIz;
	sf::RectangleShape puertaAr;
	sf::RectangleShape puertaDr;
	sf::RectangleShape puertaAb;

	RectangleShape puertas[4];
	RectangleShape paredesCruz[4];
	Mapa mapa;

	Personaje player;

	sf::Texture texturaVida;
	sf::Sprite vida;
	int vidacount = 6;

	//Genera un cofre en la posición establecida
	sf::Vector2f vectorCofre;
	Cofre cofre;

	int cuenta = 0;

	std::vector<Coin> coin = std::vector<Coin>(7);
	Coin moneda;
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
	void Update(sf::RenderWindow& window, int *state, Mapa& mapa, Personaje& player, GestorSonido& audio);
	~PantallaJuego();
};

