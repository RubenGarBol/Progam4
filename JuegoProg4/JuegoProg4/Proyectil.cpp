#include "Proyectil.h"



Proyectil::Proyectil(float x, float y)
{
	setFillColor(Color::White);
	setRadius(5.f);

	dirx = x;
	diry = y;

	move(x, y);
}

Proyectil::~Proyectil()
{
}
