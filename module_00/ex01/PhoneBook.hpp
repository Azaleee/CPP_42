#ifndef CPP_42_PHONEBOOK_HPP
# define CPP_42_PHONEBOOK_HPP

# include "Contact.hpp"

# define LIMIT_CONTACT 8

class PhoneBook
{
public:
	PhoneBook();
	void	addContact();
	void	searchCommand();
	void	getIndexContact();

//	GETTER
	int 	getContactNumber();

//	SETTER
	void 	setContactNumber(int contactNumber);
private:
	void	displayContact(int contact_index);

	Contact	contactList[LIMIT_CONTACT];
	int 	index;
	int 	contactNumber;
};

#endif //CPP_42_PHONEBOOK_HPP
