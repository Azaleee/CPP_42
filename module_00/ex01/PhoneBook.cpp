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
	if (getContactNumber() < LIMIT_CONTACT)
		setContactNumber(getContactNumber() + 1);
}

void	PhoneBook::displayContact(int contact_index)
{
	std::cout 	<< "\n--------------------\n"
				<< "Contact number " << contact_index << " :\n"
				<< "--------------------\n"
				<< "First name : " << contactList[contact_index].getName() << "\n"
				<< "Last name : " << contactList[contact_index].getLastName() << "\n"
				<< "Nickname : " << contactList[contact_index].getNickName() << "\n"
				<< "Phone Number : " << contactList[contact_index].getPhoneNumber() << "\n"
				<< "Darkest secret MWAA : " << contactList[contact_index].getDarkestSecret() << std::endl;
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
				std::cout << "Invalid index !!\n";
				break ;
			}
		}
		if (i == line.length())
		{
			std::stringstream(line) >> contact_index;
			if (contact_index >= 0 && contact_index < getContactNumber())
			{
				displayContact(contact_index);
				return ;
			}
			else
			{
				std::cout << "Invalid index !!\n";
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
	if (getContactNumber() == 0)
	{
		std::cout << "No contact found add contact NOW" << std::endl;
		return ;
	}
	for (int i = 0; i < getContactNumber(); i++)
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

int 	PhoneBook::getContactNumber()
{
	return (this->contactNumber);
}

void 	PhoneBook::setContactNumber(int contactNumber)
{
	this->contactNumber = contactNumber;
}