#include "QNode.h"


QNode::QNode(void)
{
	maxLevel = MAX_QUADTREE_DEPTH;
	currentLevel = 0;
	maxObjectNum = MAX_OBJECT_CONTAIN;

	left = 0;
	right = 0;
	top = 0;
	bottom = 0;
	position = ROOT;

	childNodes = NULL;

	listQObject = list<QObject*>();	/// ??? co can * ko

}

QNode::QNode(int curLvl, int l, int r, int t, int b, int pos = , list<QObject*> listObj = list<QObject*>(), QNode* childrent = NULL)
{
	maxLevel = MAX_QUADTREE_DEPTH;
	currentLevel = curLvl;
	maxObjectNum = MAX_OBJECT_CONTAIN;

	left = l;
	right = r;
	top = t;
	bottom = b;
	position = pos;

	childNodes = childrent;

	listQObject = listObj;	/// ??? co can * ko

}

QNode::~QNode(void)
{
	delete(childNodes);
	listQObject.~list();
}

void QNode::addQObject(QObject* qObj)
{
	listQObject.push_back(qObj);
}

void QNode::removeQObject(QObject* qObj)
{
	listQObject.remove(qObj);
}

int QNode::getChildQNodePosition(QObject* qObj)
{
	if (listQObject.size() <= maxObjectNum)
	{
		return ROOT;
	}
	
	if (currentLevel >= maxLevel)
	{
		return ROOT;
	}
	
	int qNodeCenterX = (this->left + this->right)/2;
	int qNodeCenterY = (this->top + this->bottom)/2;

	if (qObj->x > qNodeCenterX) // obj belong to right area
	{
		if (qObj->y > qNodeCenterY) // obj belong to top area
		{
			return RIGHTTOP;
		} else if (qObj->y + qObj->height < qNodeCenterY)	// obj belong to bottom area
		{
			return RIGHTBOTTOM;
		} else
		{
			return ROOT;	// obj belong to this Node area (add to parent node)
		}
	} else if (qObj->x + qObj->width < qNodeCenterX)	// obj belong to left area
	{
		if (qObj->y > qNodeCenterY) // obj belong to top area
		{
			return LEFTTOP;
		} else if (qObj->y + qObj->height < qNodeCenterY)	// obj belong to bottom area
		{
			return LEFTBOTTOM;
		} else
		{
			return ROOT;	// obj belong to this Node area (add to parent node)
		}
	} else 
	{
		return ROOT;	// obj belong to this Node area (add to parent node)
	}
}

void QNode::clear()
{
	listQObject.empty();
	if (this->childNodes != NULL)
	{
		for(int i = 0; i < 4; i++)
		{
			childNodes[i]->clear();
		}
		childNodes->clear();
		childNodes = NULL;
	}
	
}

void QNode::split()
{
	
}

vector<QObject*> QNode::getAllObjectsByArea()
{
	
}

