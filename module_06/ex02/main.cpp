#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>

static Base *generate(void)
{
	switch (std::rand() % 3)
	{
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	case 2:
		return new C();
		break;
	default:
		perror("Error with the random generator");
		return (NULL);
	}
}

static void identify(Base *p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

static void identidy(Base &p)
{
	try
	{
		// Don't use the result
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast &) {}

	try
	{
		// Don't use the result
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast &) {}

	try
	{
		// Don't use the result
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast &) {}

	std::cout << "Unknown type" << std::endl;
}

int main(void)
{
	std::srand(static_cast<unsigned>(std::time(0)));
	Base *base(generate());
	identify(base);
	identidy(*base);
	identidy(nullptr);
	delete base;
	return 0;
}