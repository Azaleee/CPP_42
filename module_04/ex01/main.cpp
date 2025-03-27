//
// Created by mosmont on 3/10/25.
//

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* classTab[10];
	for (int i = 0; i < 5; i++)
		classTab[i] = new Cat();
	for (int i = 5; i < 10; i++)
		classTab[i] = new Dog();
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		classTab[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete classTab[i];

	std::cout << std::endl;
	std::cout << "\033[36;4;1m-------------<< Deep copy test >>-------------\033[0m" << std::endl;
	std::cout << std::endl;

	Dog olaf;
	olaf.setIdea(0, "PERTURBE");
	Dog jumper = olaf;
	jumper.setIdea(0, "JOUER JOUER JOUER JOUER");
	std::cout << "\n\033[1m[Olaf idea] ->\033[0m \033[34;3;1m" << olaf.getIdea(0) \
	<< "\033[0m" << std::endl;
	std::cout << "\033[1m[Jumper idea] ->\033[0m \033[34;3;1m" << jumper.getIdea(0) \
	<< "\033[0m\n" << std::endl;

	Cat titi;
	titi.setIdea(0, "CHIIIILLLLLLL");
	Cat mao = titi;
	mao.setIdea(0, "MAOOOOOOOOO THINK");
	std::cout << "\n\033[1m[Titi idea] ->\033[0m \033[34;3;1m" << titi.getIdea(0) \
	<< "\033[0m" << std::endl;
	std::cout << "\033[1m[Mao idea] ->\033[0m \033[34;3;1m" << mao.getIdea(0) \
	<< "\033[0m\n" << std::endl;

	return (0);
}