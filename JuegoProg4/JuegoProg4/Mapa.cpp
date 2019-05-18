#include "Mapa.h"


Mapa::Mapa(Texture &textura, RectangleShape paredes[4], RectangleShape puertas[4], std::vector<Coin> coin, std::vector<RectangleShape> colisiones, std::vector<RectangleShape> colisiones_daño) : Sprite(textura), Animacion(&textura, Vector2u(3, 1), 0.25) {
	setTexture(textura);
	texture = textura;

	this->coin = coin;
	this->colisiones = colisiones;
	this->colisiones_daño = colisiones_daño;

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

Mapa::Mapa()
{
}

Mapa::~Mapa()
{
}
