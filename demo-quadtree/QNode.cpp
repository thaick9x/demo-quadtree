#include "QNode.h"

QNode::QNode(void)
{
	currentLevel = 0;

	left = 0;
	right = 0;
	top = 0;
	bottom = 0;
	position = ROOT;

	parent = NULL;
	children = NULL;

	listQObject = list<QObject*>();	/// ??? co can * ko

}

QNode::QNode(int curLvl, int l, int r, int t, int b, int pos, QNode* pa, list<QObject*> listObj)
{
	currentLevel = curLvl;

	left = l;
	right = r;
	top = t;
	bottom = b;
	position = pos;

	parent = pa;
	children = NULL;

	listQObject = listObj;

}

QNode::~QNode(void)
{
	delete(children);
	delete(parent);
	listQObject.~list();
}

void QNode::addQObject(QObject* qObj)
{
	// if this NODE has SubNodes, find position and add obj to correct SubNode
	if (children != NULL)
	{
		int index = getChildQNodePosition(qObj);
		if (index != -1)
		{
			children[index]->addQObject(qObj);
		} else {
			listQObject.push_back(qObj);
		}
	} else // if not has SubNode,
	{
		listQObject.push_back(qObj);
		printBound();

		// if pass to MAX_OBJECTS, split NODE to 4 SubNodes
		if (listQObject.size() > MAX_OBJECTS)
		{
			// if MAX_LEVEL, do nothing
			if (this->currentLevel < MAX_LEVEL)
			{
				this->split();
			}
		}
	}
}

void QNode::removeQObject(QObject* qObj)
{
	listQObject.remove(qObj);
}

int QNode::getChildQNodePosition(QObject* qObj)
{
	//if (listQObject.size() <= MAX_OBJECTS)
	//{
	//	return ROOT;
	//}
	
	if (currentLevel >= MAX_LEVEL)
	{
		return ROOT;
	}
	
	

	if (qObj->x > centerX()) // obj belong to right area
	{
		if (qObj->y > centerY()) // obj belong to top area
		{
			return RIGHTTOP;
		} else if (qObj->y + qObj->height < centerY())	// obj belong to bottom area
		{
			return RIGHTBOTTOM;
		} else
		{
			return ROOT;	// obj belong to this Node area (add to parent node)
		}
	} else if (qObj->x + qObj->width < centerX())	// obj belong to left area
	{
		if (qObj->y > centerY()) // obj belong to top area
		{
			return LEFTTOP;
		} else if (qObj->y + qObj->height < centerY())	// obj belong to bottom area
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

void QNode::clear() // clear this NODE and SubNodes
{
	listQObject.empty();
	if (this->children != NULL)
	{
		for(int i = 0; i < 4; i++)
		{
			children[i]->clear();
		}
		children = NULL;
	}
	
}

void QNode::split()
{
	children = new QNode*[4];
	children[LEFTTOP] = new QNode(currentLevel + 1, left, centerX(), top, centerY(), LEFTTOP, this);
	children[RIGHTTOP] = new QNode(currentLevel + 1, centerX(), right, top, centerY(), RIGHTTOP, this);
	children[LEFTBOTTOM] = new QNode(currentLevel + 1, left, centerX(), centerY(), bottom, LEFTBOTTOM, this);
	children[RIGHTBOTTOM] = new QNode(currentLevel + 1, centerX(), right, centerY(), bottom, RIGHTBOTTOM, this);

	list<QObject *> tempList = listQObject;
	
	listQObject.clear();

	for (list<QObject*>::iterator ite = tempList.begin(); ite != tempList.end(); ite++)
	{
		addQObject(*ite);	
	}

}

list<QObject*> QNode::getAllObjectsByArea(list<QObject*> &returnObjects, int x, int y, int w, int h)
{
	int index = getChildQNodePosition(new QObject(x, y, w, h));
	if (index != ROOT && children != NULL) // if not leafNode && object area is contained in one of quadrant
	{
		children[index]->getAllObjectsByArea(returnObjects, x, y, w, h);
	}

	returnObjects.merge(listQObject);


	return returnObjects;
}

list<QObject*> QNode::getAllObjects()
{
	list<QObject *> result;
	result.merge(listQObject);

	// recursion
	for (int i = 0; i < 4; i++)
	{
		result.merge(children[i]->getAllObjects());
	}


	return result;
}

int QNode::centerX()
{
	return (this->left + this->right)>>1;
}

int QNode::centerY()
{
	return (this->top + this->bottom)>>1;
}

void QNode::printBound()
{
	cout<< currentLevel <<":"<< left<< ","<<right<< ","<< top<< ","<< bottom<< "," <<endl;
}

