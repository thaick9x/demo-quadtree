#pragma once

#include "QObject.h"
#include <list>
#include <vector>

using namespace std;

enum QNODE_POSITION
{
	ROOT = -1,
	LEFTTOP = 0,
	RIGHTTOP = 1,
	LEFTBOTTOM = 3,
	RIGHTBOTTOM = 2
};

const int MAX_QUADTREE_DEPTH = 5;
const int MAX_OBJECT_CONTAIN = 10;	// low priority

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
	int position;

	QNode* parent;
	QNode* lt;
	QNode* rt;
	QNode* lb;
	QNode* rb;


	list<QObject*> listQObject;	/// ??? co can * ko

	QNode(void);
	QNode(int curLvl, int l, int r, int t, int b, int pos, list<QObject*> listObj, QNode* childrent);
	~QNode(void);

	void addQObject(QObject* qObj);
	void removeQObject(QObject* qObj);
	int getChildQNodePosition(QObject* qObj);
	void clear();	// clear all object

	/**
	*	method splits the node into four subnodes by dividing the node into four equal parts and initializing the four subnodes with the new bounds
	**/
	void split(); // co index
	vector<QObject*> getAllObjectsByArea();


};

