#include "Mapa.h"
#include "SFML/Graphics.hpp"

Mapa::Mapa(Texture &textura, RectangleShape paredes[4], RectangleShape puertas[4]) {
	setTexture(textura);

	for (size_t i = 0; i < 4; i++) 
{
		conjParedes[i] = paredes[i];
		conjPuertas[i] = puertas[i];
	}

}
RectangleShape Mapa:: getPuertaAr() {
	return conjPuertas[0];
}
RectangleShape Mapa::getPuertaDe() {
	return conjPuertas[1];
}
RectangleShape Mapa::getPuertaAb() {
	return conjPuertas[2];
}
RectangleShape Mapa::getPuertaIz() {
	return conjPuertas[3];
}

Mapa::~Mapa()
{
}
