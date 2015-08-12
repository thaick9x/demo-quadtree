#pragma once

#include "QObject.h"
#include <list>

using namespace std;

enum QNODE_POSITION
{
	PARENT = -1,
	LEFTTOP = 0,
	RIGHTTOP = 1,
	LEFTBOTTOM = 4,
	RIGHTBOTTOM = 3
};

class QNode
{


public:
	unsigned int maxLevel;
	unsigned int currentLevel;
	unsigned int maxObjectNum;
	

	int left;
	int right;
	int top;
	int bottom;

	QNode* childNodes;

	list<QObject*> listQObject;	/// ??? co can * ko

	QNode(void);
	~QNode(void);

	void addQObject(QObject* qObj);
	void removeQObject(int id);
	int getQNodePosition(QObject* qObj);
	void clear();	// clear all object
	void split(); // co index
	// vector<QOj> getAllObjectsByArea();


};

