#include "GestorSonido.h"




GestorSonido::GestorSonido()
{
	if (!buffer_moneda.loadFromFile("./res/Sonidos/Find_Money.wav"))
	{
		std::cout << "No se ha encontrado el sonido: Find_Money.wav\n";
	}
	sonido_moneda.setBuffer(buffer_moneda);
	sonido_moneda.setVolume(80);

	if (!buffer_daño_personaje.loadFromFile("./res/Sonidos/Hero_Hurt.wav"))
	{
		std::cout << "No se ha encontrado el sonido: Hero_Hurt.wav\n";
	}
	sonido_daño_personaje.setBuffer(buffer_daño_personaje);
	sonido_daño_personaje.setVolume(80);

	if (!buffer_muerte_personaje.loadFromFile("./res/Sonidos/Hero_Dies.wav"))
	{
		std::cout << "No se ha encontrado el sonido: Hero_Dies.wav\n";
	}
	sonido_muerte_personaje.setBuffer(buffer_muerte_personaje);
	sonido_muerte_personaje.setVolume(80);

	if (!buffer_pared.loadFromFile("./res/Sonidos/Wall_Collision.wav"))
	{
		std::cout << "No se ha encontrado el sonido: Wall_Collision.wav\n";
	}
	sonido_pared.setBuffer(buffer_pared);
	sonido_pared.setVolume(80);

	musica_juego.openFromFile("./res/Sonidos/mountainoftrials.wav");
	musica_juego.setLoop(true);
	musica_juego.play();

	musica_menu.openFromFile("./res/Sonidos/mountainoftrials_muffled.wav");
	musica_menu.setLoop(true);
	musica_menu.play();
}


GestorSonido::~GestorSonido()
{
}
