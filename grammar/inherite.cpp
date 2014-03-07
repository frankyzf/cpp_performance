#include<iostream>

using namespace std;

class fri_base
{
};


class base
{
	public:
		void pub() { cout << "base::pub" << endl;}
	protected:
		void pro() {cout << "base::protected" << endl;}
	friend class fri_base;
//	friend class fri_sub;
};

class fri_sub: public fri_base
{
	public:
 	void		getpro(base& b)
		{
			b.pro();
		}
};



int main()
{
	base b;
	fri_sub f;
	f.getpro(b);
	return 1;
}
