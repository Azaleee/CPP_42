#include "Serializer.hpp"

int main(void)
{
	Data test;
	test.id = 10;
	test.name = "mosmont";

	uintptr_t raw = Serializer::serialize(&test);
	std::cout << "Serialized value : " << raw << std::endl;

	Data *dp = Serializer::deserialize(raw);

	if (dp == &test)
		std::cout << "Deserialized pointer is valid" << "\n"
		<< "Data contents : id = " << dp->id << " name = " << dp->name << std::endl;

	return 0;
}
