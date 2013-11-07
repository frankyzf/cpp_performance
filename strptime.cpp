#include<iostream>

using namespace std;

int main ()
{
	const char* strtime="20131104-19:26:22";
	struct tm tt;
	strptime(strtime, "%Y%m%d-%H:%M:%S", &tt);
	time_t t = mktime(&tt);
	cout << t << endl;	

	return 1;
}
