#include "Cells.h"

Cells::Cells(float pos_x, float pos_y, float size) : _pos_x(pos_x), _pos_y(pos_y), _size(size)
{
	_cells_body.setSize(sf::Vector2f(_size, _size));
	_cells_body.setPosition(sf::Vector2f(_pos_x, _pos_y));
	_cells_body.setOutlineColor(sf::Color::White);
	_cells_body.setOutlineThickness(2.f);
}

Cells::~Cells()
{
}

sf::RectangleShape Cells::getCells()
{
	return _cells_body;
}

float Cells::getSize()
{
	return _size;
}

float Cells::getPosX()
{
	return _pos_x;
}

float Cells::getPosY()
{
	return _pos_y;
}
