#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook() : index(0), contactNumber(0) {}

void	PhoneBook::addContact()
{
	contactList[index].setContactInfos();
	index = (index + 1) % 8;
	if (contactNumber < LIMIT_CONTACT)
		contactNumber++;
}

void	PhoneBook::displayContact(int contact_index)
{
	std::cout 	<< "\n------------------\n"
				<< "\033[1;4mContact number " << contact_index << "\033[0m:\n"
				<< "------------------\n"
				<< "\033[1mFirst name \033[0m: " << contactList[contact_index].getName() << "\n"
				<< "\033[1mLast name \033[0m: " << contactList[contact_index].getLastName() << "\n"
				<< "\033[1mNickname \033[0m: " << contactList[contact_index].getNickName() << "\n"
				<< "\033[1mPhone Number \033[0m: " << contactList[contact_index].getPhoneNumber() << "\n"
				<< "\033[1mDarkest secret\033[0m \033[30;41;1;3;4mMWAA\033[0m : " << contactList[contact_index].getDarkestSecret() << std::endl;
}

void	PhoneBook::getIndexContact()
{
	size_t 		i;
	std::string	line;
	int			contact_index;

	while (true)
	{
		std::cout << "Index of contact : ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			break ;
		for (i = 0; i < line.length(); i++)
		{
			if (!std::isdigit(line[i]))
			{
				std::cout << "\033[30;41;1mInvalid index !!\033[0m" << std::endl;
				break ;
			}
		}
		if (i == line.length())
		{
			std::stringstream(line) >> contact_index;
			if (contact_index >= 0 && contact_index < contactNumber)
			{
				displayContact(contact_index);
				return ;
			}
			else
			{
				std::cout << "\033[30;41;1mInvalid index !!\033[0m" << std::endl;
			}
		}
	}
}
void	PhoneBook::searchCommand()
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|"
				<< std::setw(10) << "Phone Nbr" << "|" << std::endl;
	std::cout 	<< "--------------------------------------------" << std::endl;
	if (contactNumber == 0)
	{
		std::cout << "No contact found add contact NOW" << std::endl;
		return ;
	}
	for (int i = 0; i < contactNumber; i++)
	{
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << contactList[i].getTruncField(contactList[i].getName()) << "|"
					<< std::setw(10) << contactList[i].getTruncField(contactList[i].getLastName()) << "|"
					<< std::setw(10) << contactList[i].getTruncField(contactList[i].getNickName()) << "|"
					<< std::setw(10) << contactList[i].getTruncField(contactList[i].getPhoneNumber()) << "|"
					<< std::endl;
	}
	getIndexContact();
}

int	PhoneBook::getContactNumber()
{
	return (this->contactNumber);
}