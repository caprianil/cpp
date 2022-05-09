#include <iostream>
#include <vector>
using namespace std;

class Test
{
	int i;
    string s;
    
	public:
    Test(string name)
    	:i(0),
    	s(name)
    {
    	
	}
    
    Test(const Test &rhs)
    {
    	this->i = rhs.i;
        this->s = rhs.s;
        cout << "Test Copy Constructor" << this->s << endl;
    }
    
    Test(Test &&rhs)
    {
    	this->i = rhs.i;
        this->s = rhs.s;
        rhs.i = -1;
        rhs.s = "";
        cout << "Test Move Constructor &rhs " << &rhs << " " << this->s << endl;
    }
    
    string operator*()
    {
    	string s = this->s + std::to_string(this->i);
        return s;
	}

    friend ostream & operator << (ostream &out, const Test &c);
    friend istream & operator >> (istream &in,  Test &c);
};


class Base
{
	int i_b;
	string s_b;
	vector<int> v_b;
	
	public:
	Base(int i, string s, vector<int> v):
	i_b(i),
	s_b(s),
	v_b(v)
	{
	}
	
	virtual ~Base()
	{
	}
};

class Derived : public Base
{
	string s_der;
	vector<int> v_der;
	
	public:
	Derived(int i, string s, vector<int> v, string s_d, vector<int> v_d):
		Base(i, s, v),
		s_der(s_d),
		v_der(v_d)
	{
	}
};
    
ostream & operator << (ostream &out, const Test &c)
{
  out << c.i << endl;
  out << c.s << endl;
  return out;
}

int main() {

	vector<int> vec;
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(20);
    
    for(vector<int>::iterator itr1 = vec.begin(); itr1 != vec.end(); ++itr1) {
    	cout << *itr1 << endl;
    }
    
    Test test("test"), test2("test2");
    vector<Test*> testVec;
    
    testVec.push_back(&test);
    testVec.push_back(&test2);
    
    for(vector<Test*>::iterator itr1 = testVec.begin(); itr1 != testVec.end(); ++itr1) 		{
    	cout << *itr1 << endl;
    }
    
    vector<Test> testVec2;
    
    testVec2.push_back(std::move(test));
    testVec2.push_back(std::move(test2));
    
    cout << "After move " << test << endl;
    cout << "After move " << test2 << endl;
    
    for(vector<Test>::iterator itr1 = testVec2.begin(); itr1 != testVec2.end(); ++itr1) 	{
    	cout << &(*itr1) << endl;
    }
    
  	cout << "Hello World!";
  	return 0;
}
