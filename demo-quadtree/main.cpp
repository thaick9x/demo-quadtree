#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	// create a vector to store int
   vector<int> vec; 
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

   

   system("pause");

   return 0;
}