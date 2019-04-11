#include "SFML/Graphics.hpp"
#include "Animacion.h"

using namespace sf;

class Personaje : public Sprite, public Animacion {
	public:

		Texture texture;

		Vector2f posicion;
		float deltatiempo = 0.0f;
		Clock timer;
		double velocidad;
		int anim;
		int animd;

	Personaje(sf::Texture &textura);
	
};

