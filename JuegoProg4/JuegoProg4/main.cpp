#include "Conexion.h"
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
#include <thread>
#include "SFML/System.hpp"
#include<vector>
#include <stdlib.h>
#include "PantallaPrincipal.h"
#include "PantallaPausa.h"
#include "PantallaMuerte.h"
#include "PantallaJuego.h"
#include "GestorSonido.h"

int main()
{
	//crearTablas();
	//insertarDatos();
	//seleccionarDatos();
	
	srand(time(0));
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
	

	//Carga del spritesheet de las animaciones del personaje principal
	sf::Texture pjtextura;
	if (!pjtextura.loadFromFile("./res/Imagenes/pjtextura.png"))
	{
		std::cout << "No se ha encontrado la textura de: knight_idle.png\n";
	}

	//Estado del programa (Jugar, Pusa, Principal, Muerte)
	int state = 2;
	
	//Objetos pared para delimitar los bordes jugables de la pantalla.
	
	//Cursor personalizado
	window.setMouseCursorVisible(false);
	sf::Texture cursortexture;
	if (!cursortexture.loadFromFile("./res/Imagenes/cursor.png"))
	{
		std::cout << "No se ha encontrado la textura de: cursor.png\n";
	}
	sf::Sprite cursor(cursortexture);

	//Gestor de los sonidos
	GestorSonido audio;
	audio.musica_juego.setVolume(80);
	audio.musica_menu.setVolume(0);

	//Objeto Mapa
	//Mapa mapa(texturaFondo, paredes, paredes);

	//Objeto Personaje Principal
	Personaje player(pjtextura);

	//Objeto Pantalla Juego
	PantallaJuego pjuego(window);

	//Objeto Pantalla Pausa
	PantallaPausa ppausa(window);

	//Objeto Pantalla Principal
	PantallaPrincipal pprincipal(window);

	//Objeto Pantalla Muerte
	PantallaMuerte pmuerte(window);

	//Bucle ejecutado mientras la pantalla se mantenga abierta.
	while (window.isOpen())
	{
		while (state == 0)
		{
			audio.musica_juego.setVolume(80);
			audio.musica_menu.setVolume(0);

			pjuego.Update(window, &state, player, audio);

			if(pjuego.vidacount<=0)
			{
				pmuerte.clock_muerte.restart();
				pmuerte.opacidadmuerte = 0; pjuego.vidacount;
			}
		}

		while (state == 1)
		{
			audio.musica_juego.setVolume(0);
			audio.musica_menu.setVolume(80);
			ppausa.Update(window, &state, pjuego.mapaCompleto[pjuego.posicion], player);

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				ppausa.opciones.setPosition(ppausa.playboton.getPosition().x, ppausa.playboton.getPosition().y);
				ppausa.salir.setPosition(ppausa.playboton.getPosition().x, ppausa.playboton.getPosition().y + 180);
			}
		}
		
		while (state == 2)
		{
			pprincipal.Update(window, &state, pjuego.mapaCompleto[pjuego.posicion], player, cursortexture, cursor, pjuego);
		}

		while (state == 3)
		{
			pmuerte.Update(window, &state, pjuego.mapaCompleto[pjuego.posicion], player);
			if (pmuerte.clock_muerte.getElapsedTime().asSeconds() > 8.1)
			{
				conseguirID();
				guardarPuntuacion(pjuego.cuenta, 0);
				state = 2;
				window.close();
				main();
			}
		}
	}
}
