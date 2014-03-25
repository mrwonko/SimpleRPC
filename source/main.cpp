#include <iostream>

void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void HelloI( int i )
{
	std::cout << "Hello " << i << std::endl;
}

int Get42()
{
	return 42;
}

int GetI( const int i )
{
	return i;
}

int main( int argc, char** argv )
{
	return 0;
}
