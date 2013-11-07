#include <iostream>

using namespace std;


int main ()
{
	const char* ch = "20131311-12:22";
	long i = atol(ch);
	cout << i << endl;
	return 1;
	char buf[8];
	snprintf(buf, 4, ch);
	snprintf(buf+3, 4, ch+4);
	cout << buf << endl;
	return 1;
}
