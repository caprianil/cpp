#include <iostream>
using namespace std;

template <typename T>
T Square(T arg)
{
	T val = arg*arg;
	return(val);
}

template <typename T>
class BOVector
{
	T arr[1000];
    int size;
    
    public:
    BOVector()
    :size(0)
    {
    }
    
    BOVector(BOVector &rhs)
    {
    	for(int i = 0; i < rhs.size; i++)
        	this->arr[i] = rhs.arr[i];
        
        this->size = rhs.size;
	}
    
    BOVector(BOVector &&rhs)
    {
    	this->size = rhs.size;
        
     	for(int i = 0; i < rhs.size; i++)
        	this->arr[i] = rhs.arr[i];      
    }
    
    void push(T arg)
    {
    	arr[size] = arg;
        size++;
	}
    
    T get(int index)
    {
    	return arr[index];
	}
    
    int getsize()
    {
    	return size;
    }
    
};

template <typename T>
BOVector<T> operator*(BOVector<T>& lhs, BOVector<T>& rhs)
{
	BOVector<T> ret;
    for(int i = 0; i < rhs.getsize(); i++)
    {
    	ret.push(lhs.get(i)*rhs.get(i));
    }
    
    return ret;
}

int main() {
	
    BOVector<int> b1;
    BOVector<int> b2;
    
    b1.push(2);
    b2.push(3);
 	cout << Square(2) << endl;
    Square(b1);
  	cout << "Hello World!";
  	return 0;
}
