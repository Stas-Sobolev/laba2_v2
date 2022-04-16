#include"ConcretBody.h"
#include<iostream>
#include<fstream>

#define MAX_TIME 200
using namespace std;
int main()
{
	Location location(100000, 100000, 10, list<Sprite*>());
	location.add_sprite(new ConcretBody(&location, 0, 0, 0, 0));

	double V;
	cout << " V: ";
	cin >> V;
	double alpha;
	cout << " alpha: ";
	cin >> alpha;
	double t;
	cout << " t: ";
	cin >> t;

	ofstream fout("test");

	for (unsigned long long int _t = 0; _t < MAX_TIME; _t++)
	{
		if (t == _t)
			location.fly(V, alpha);
		auto result = location.tick(1);
		fout << _t<<": ";
		for (auto body : result)
		{
			fout << body<<"\t";
		}
		fout << endl;

		location.stop();
	}
	return 0;
}