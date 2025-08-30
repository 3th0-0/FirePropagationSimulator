#include "Field.h"

Field::Field(int field_size_x, int field_size_y) : _field_size_x(field_size_x), _field_size_y(field_size_y)
{
	for (int i = 0; i < _field_size_x * _field_size_y; i++)
		field_organization.push_back(1);

	float posX = 2.f;
	float posY = 2.f;

	for (int i = 0; i < _field_size_x; i++)
	{
		for (int j = 0; j < _field_size_y; j++)
		{
			if (field_organization[i] == 1)
				standart_field.push_back(Tree(posX, posY, 48.f));
			posY += 50.f;
		}
		posY = 2.f;
		posX += 50.f;
	}
}

Field::~Field()
{
}

std::vector<Tree> Field::getSTDField() const
{
	return standart_field;
}

int Field::getSizeX() const
{
	return _field_size_x;
}

int Field::getSizeY() const
{
	return _field_size_y;
}
