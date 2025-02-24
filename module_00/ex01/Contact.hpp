#ifndef CPP_42_CONTACT_HPP
# define CPP_42_CONTACT_HPP

#include <string>

class Contact {
public:
	void		setContactInfos();
	std::string getTruncField(std::string field);

//	GETTER
	std::string getName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
private:
	void		setField(std::string fieldName, std::string &field);

	std::string name;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkSecret;
};

#endif //CPP_42_CONTACT_HPP
