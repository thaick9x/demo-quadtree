#pragma once
class QObject // wrapper 
{
public:
	int x;
	int y;

	int width;
	int height;

	QObject(void);
	QObject(int ox, int oy, int ow, int oh);
	~QObject(void);

	// Methods involve QuadTree
};

