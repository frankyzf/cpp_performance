#include <iostream>

using namespace std;



int i = 0;
class element
{
	public:
		element()
		{
			cout << "element is constructed: " << i++ << endl;
		}
		int content;
};


class calc
{
	public:
		element& get()
		{
			return e;
		}
	private:
		element e;
};



int main()
{
	calc c;
	cout << "calc class is inited" << endl;
	element e = c.get();
	e.content = 2;
	cout << e.content << endl;
	
	return 1;
}
