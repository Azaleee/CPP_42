#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	player1("Player1");

	std::cout << std::endl;
	std::cout << "Energy point test" << std::endl;
	for (int i = 0; i <= 50; i++)
	{
		std::cout << "[" << i << "] "; player1.attack("default");
	}
	std::cout << std::endl;

	FragTrap	player2;

	std::cout << std::endl;
	std::cout << "Death detection" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "[" << i << "] "; player2.takeDamage(50);
	}
	std::cout << std::endl;

	FragTrap	player3("Player3");

	std::cout << std::endl;
	std::cout << "Repair features" << std::endl;
	std::cout << "Default life points -> " << player3.getHitPoint() << std::endl;
	player3.takeDamage(5);
	std::cout << "Remaining life -> " << player3.getHitPoint() << std::endl;
	player3.beRepaired(5);
	std::cout << "Remaining life -> " << player3.getHitPoint() << std::endl;
	std::cout << std::endl;

	FragTrap	player4("Player4");

	std::cout << std::endl;
	player4.highFivesGuys();
	std::cout << std::endl;
	return (0);
}