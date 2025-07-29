#pragma once

#include <iostream>
#include <stdint.h>

typedef struct 	Data
{
	int			id;
	std::string	name;
}				Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &);
		Serializer &operator=(Serializer const &) { return *this; };
		~Serializer() {};

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};