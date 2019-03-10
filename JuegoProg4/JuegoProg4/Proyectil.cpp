#include "Proyectil.h"



Proyectil::Proyectil(int x, int y)
{
	setFillColor(Color::White);
	setRadius(5.f);

	dirx = x;
	diry = y;

	move(x, y);
}


Vector2f Proyectil::getDirUp() {
	Vector2f vectorUp(0.f, -10.f);
	return vectorUp;
}
Vector2f Proyectil::getDirDown() {
	Vector2f vectorDown(0.f, 10.f);
	return vectorDown;
}
Vector2f Proyectil::getDirLeft() {
	Vector2f vectorRight(-10.f, 0.f);
	return vectorRight;
}
Vector2f Proyectil::getDirRight() {
	Vector2f vectorRight(10.f, 0.f);
	return vectorRight;
}

Proyectil::~Proyectil()
{
}
