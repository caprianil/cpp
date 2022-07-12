// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <memory>
#include <string>

using namespace std;

/*
	Move Constructor.
	Binders
	unique_ptr
	Copy Constructors
	Base Copy from Derived
	Virtual Constructors/Destructors
	Async
	std::thread
	Lamdas
	Algorithms
*/

namespace {

	const uint32_t DEFAULT_VECTOR_SIZE =100;

}

template <class T>
class Base {
private:
	T data;
public:
	Base(T x) :data(x)
	{}

	Base()
	{}

	void set(T &val) { data = val; }
};


template <class T>
class AVector : public Base <T> {

	std::string name;
	uint32_t length;
	std::unique_ptr<T[]> array;

public:
	AVector() :
		name("AVector designed by anil"),
		length(DEFAULT_VECTOR_SIZE),
		array(new T[DEFAULT_VECTOR_SIZE])
	{
	
	}

	// Copy Constructor
	AVector(const AVector &rhs) {
		std::cout << "Copy AVector(const AVector &)" << std::endl;
	}
	
	// Move Constructor
	AVector(const AVector &&rhs) {
		array = nullptr;
		array = rhs.
		std::cout << "Move AVector(const &&)" << std::endl;
	}

	std::string string()
	{
		std::string desc = name + " size=" + std::to_string(DEFAULT_VECTOR_SIZE);
		return desc;
	}

	~AVector() {
		std::cout << "~Avector()" << std::endl;
	}
};

class AObject {

public:
	~AObject() {
		std::cout << "~AObject Destructor" << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	{
		AVector<AObject> aa;
		std::cout << aa.string() << std::endl;
		AVector<AObject> bb(std::move(aa));
	}

	fgetc(stdin);

	return 0;
}

