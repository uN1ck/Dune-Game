#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cWorld.h"
#include <vector>
#include "iDrawable.h"
#include "iUpdateble.h"

using namespace std;

cWorld *world;

int main()
{
	world = new cWorld();
	world->Generate(string{ 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, false);

	int ended = 1;
	while (ended < 10)
	{
		string res = "Debugged" + to_string(ended) + ".log";
		freopen(res.c_str(), "w", stdout);
		cout << "\nITERATION\n\n";
		world->Update();
		cout << world->toString();

		//system("pause");
		//cin >> ended;
		//system("cls");
		ended++;
		
	}
	return 0;
}