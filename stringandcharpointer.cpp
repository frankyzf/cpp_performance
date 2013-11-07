#include<iostream>
#include<string>
#include<stdio.h>


int main()
{
	using namespace std;
//	string ccylist[] = {"AUD/CAD", "AUD/CHF", "AUD/NZD", "EUR/AUD", "EUR/CAD", "EUR/CHF", "EUR/GBP", "EUR/NZD",	
//						"GBP/AUD",	"GBP/CAD", "GBP/CHF", "GBP/NZD", "NZD/USD",	"USD/CAD", "USD/CHF"};
	string ccylist[] = { string("AUD/CAD"), string("AUD/CHF")};
	int ccynum = sizeof(ccylist);
	char szStd[9];
	snprintf(szStd, sizeof(szStd), "USD/CHF");

	int i = 0;
	for(i = 0; i < ccynum; ++i)
	{
		if(strcmp(ccylist[i].c_str(),  szStd) == 0 )
			break;
	}
	if(i >= ccynum)
		cout << "symbol: " << szStd  << "is not in allowed list";
	else
		cout << "symbol: " << szStd  << "is in allowed list";

	return 1;
}

