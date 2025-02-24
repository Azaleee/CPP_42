#include "Contact.hpp"
#include <iostream>

void	Contact::setField(std::string fieldName, std::string &field)
{
	while (true)
	{
		std::cout << fieldName;
		std::getline(std::cin, field);
		if (std::cin.eof())
			break ;
		if (!field.empty())
			break ;
		else
			std::cout << "Fields cannot be empty !!!!\n";
	}
}

void	Contact::setContactInfos()
{
	setField("First name : ", this->name);
	setField("Last name : ", this->lastName);
	setField("Nickname : ", this->nickName);
	setField("Phone Number : ", this->phoneNumber);
	setField("Darkest secret : ", this->darkSecret);
}

std::string	Contact::getTruncField(std::string field)
{
	if (field.length() >= 9)
		return (field.substr(0, 9) + '.');
	else
		return (field);
}

//GETTER
std::string	Contact::getName()
{
	return (this->name);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}

std::string	Contact::getNickName()
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (this->darkSecret);
}