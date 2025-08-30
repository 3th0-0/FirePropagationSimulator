#include "Tree.h"

Tree::Tree(float pos_x, float pos_y, float size) : Cells(pos_x, pos_y, size)
{
	_cells_body.setFillColor(sf::Color::Green);
}

Tree::~Tree()
{
}