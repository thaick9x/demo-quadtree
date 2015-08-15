#include <iostream>
#include <vector>
#include <list>
#include "QNode.h"

using namespace std;

int main()
{
	// create a vector to store int
/*   vector<int> vec; 
   list<int> lists;

   

   list<int> listTest;
   for (int i = 0; i < 10; i++)
   {
	   listTest.push_back(i);
   }
   
   list<int>::iterator it = listTest.begin();
   for (int i = 0; i < 10; i++)
   {
		cout<< *it <<endl;
		it++;
   }
   */

	QNode* root = new QNode(0, 0, 500, 500, 0);
	
	int l;
	int r;
	int b;
	int t;

	root->addQObject(new QObject(68, 59, 116-68, 91-59));
	root->addQObject(new QObject(323, 81, 406-323, 125-81));
	root->addQObject(new QObject(82, 176, 348-82, 325-176));
	root->addQObject(new QObject(326, 367, 397-326, 430-367));
	root->addQObject(new QObject(107, 11, 27, 22));
	root->addQObject(new QObject(19, 10, 20, 36));
	root->addQObject(new QObject(21, 145, 17, 12));

	list<QObject *> result;

	root->getAllObjectsByArea(result, 72, 118, 300, 300);

/*	while (true)
	{
		cin>>l>>b>>r>>t;
		root->addQObject(new QObject(l, b, r-l, t-b));
	}*/
   system("pause");

   return 0;
}