#pragma once

#include "QObject.h"
#include <list>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

enum QNODE_POSITION
{
	ROOT = -1,
	LEFTTOP = 0,
	RIGHTTOP = 1,
	LEFTBOTTOM = 3,
	RIGHTBOTTOM = 2
};

class QNode
{

public:
	static const int MAX_OBJECTS = 3;
	static const int MAX_LEVEL = 5;
	unsigned int currentLevel;
	
	int left;
	int right;
	int top;
	int bottom;
	int position;

	QNode* parent;
	QNode** children;

	list<QObject*> listQObject;	/// ??? co can * ko

	QNode(void);
	QNode(int curLvl, int l, int r, int t, int b, int pos = ROOT, QNode* pa = NULL, list<QObject*> listObj = list<QObject*>());
	~QNode(void);

	void addQObject(QObject* qObj);
	void removeQObject(QObject* qObj);
	int getChildQNodePosition(QObject* qObj);
	void clear();	// clear all object

	/**
	*	method splits the node into four subnodes by dividing the node into four equal parts and initializing the four subnodes with the new bounds
	**/
	void split();
	// return an array 4 elements
	bool* getIntersectChild(RECT bound);
	
	list<QObject*> getAllObjectsByArea(list<QObject*> &returnObjects, int x, int y, int w, int h);
	list<QObject*> getAllObjects();

	int centerX();
	int centerY();

	// func for unit test
	void printBound();
};

