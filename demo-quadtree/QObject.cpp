#include "QObject.h"


QObject::QObject(void)
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

QObject::QObject(int ox, int oy, int ow, int oh)
{
	x = ox;
	y = oy;
	width = ow;
	height = oh;
}

QObject::~QObject(void)
{
}
