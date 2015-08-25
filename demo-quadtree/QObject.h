#pragma once
#include <windows.h>
#include "GameObject.h"


class QObject // wrapper 
{
public:
	int x;
	int y;
	int width;
	int height;

	GameObject* entity;

	QObject(void);
	QObject(int ox, int oy, int ow, int oh, GameObject* destEntity);
	~QObject(void);

	void init(int left, int right, int top, int bottom, GameObject* destEntity);
	void init(RECT bound, GameObject* destEntity);

	int left();
	int right();
	int top();
	int bottom();

	// Methods involve QuadTree
};

