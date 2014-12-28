#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cWorld.h"
#include <vector>
#include "iDrawable.h"
#include "iUpdateble.h"
#include "cPosited.h"

using namespace std;

cWorld *world;
vector< vector<int> >counts;


int main()
{
	world = new cWorld();
	world->Generate(string{ 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1);

	int ended = 1;

	while (ended < 25)
	{
		string res = "Debugged" + to_string(ended) + ".log";
		freopen(res.c_str(), "w", stdout);
		world->Update();
		//cout << world->toString();
		
		counts = vector< vector<int> >(4, vector<int>(2, 0));
		int baseindex = 0;

		for each(cBase *current in *world->getBases())
		{
			for each(cObject* value in *current->getAllUnits())
			{
				if (dynamic_cast<cTanker*>(value))
				{
					counts[baseindex][0]++;
				}
				if (dynamic_cast<cGunner*>(value))
				{
					counts[baseindex][1]++;
				}
			}
			baseindex++;
		}

		for (int i = 0; i < counts.size(); i++)
			cout << "Base #" << i << " WarUnits: " << counts[i][1] << " HarvestUnits: " << counts[i][0] << endl;
		
		ended++;
		
	}
	return 0;
}