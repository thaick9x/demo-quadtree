#include "QObject.h"


QObject::QObject(void)
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	entity = NULL;
}

QObject::QObject(int ox, int oy, int ow, int oh, GameObject* destEntity)
{
	x = ox;
	y = oy;
	width = ow;
	height = oh;
	entity = destEntity;
}

QObject::~QObject(void)
{
}

void QObject::init(int left, int right, int top, int bottom, GameObject* destEntity)
{
	if ((left >= right) || (top <= bottom))
	{
		return;
	}
	this->x = left;
	this->y = bottom;
	this->width = right - left;
	this->height = top - bottom;
	this->entity = destEntity;
}

void QObject::init(RECT bound, GameObject* destEntity)
{
	return init(bound.left, bound.right, bound.top, bound.bottom, destEntity);
}

int QObject::left()
{
	return x;
}

int QObject::right()
{
	return x + width;
}

int QObject::top()
{
	return y + height;
}

int QObject::bottom()
{
	return y;
}
