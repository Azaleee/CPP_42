#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main(int ac, char **av)
{
	PhoneBook	phoneBook;
	std::string	line;

	(void)av;
	if (ac == 1)
	{
		while (true)
		{
			std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
			std::getline(std::cin, line);
			if (std::cin.eof())
			{
				std::cout << "CTRL-D detected\nGood bye !" << std::endl;
				break ;
			}
			if (line == "ADD")
				phoneBook.addContact();
			else if (line == "SEARCH")
				phoneBook.searchCommand();
			else if (line == "EXIT")
			{
				if (phoneBook.getContactNumber() == 1)
					std::cout << "Good bye, your only contact will be deleted\n";
				else if (phoneBook.getContactNumber() > 1)
					std::cout << "Good bye, your " << phoneBook.getContactNumber() << " contacts will be deleted !";
				else
					std::cout << "Good bye no contact add :(\n";
				break;
			}
			else
				std::cout << "Invalid command. Try again !!" << std::endl;
		}
	}
	return (0);
}