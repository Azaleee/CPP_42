//
// Created by mosmont on 3/10/25.
//

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	return (0);
}