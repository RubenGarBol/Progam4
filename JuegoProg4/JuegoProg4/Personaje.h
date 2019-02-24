#include "SFML/Graphics.hpp"

using namespace sf;

class Personaje : public sf::Sprite {
	public:
		Texture textura;
		Vector2f posicion;
		double velocidad;

	Personaje();
	
};

