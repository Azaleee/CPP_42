#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->target = other.target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw ShrubberyCreationForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::ofstream output;
	std::string fileName = this->target;
	fileName.append("_shrubbery");
	output.open(fileName.c_str());
	if (!output.is_open())
		std::cout << "Error with output file" << std::endl;
	else
	{
		output << "                                                         ." << std::endl;
		output << "                                              .         ;  " << std::endl;
		output << "                 .              .              ;%     ;;   " << std::endl;
		output << "                   ,           ,                :;%  %;   " << std::endl;
		output << "                    :         ;                   :;%;'     .,   " << std::endl;
		output << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
		output << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
		output << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
		output << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		output << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		output << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		output << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
		output << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
		output << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
		output << "                          `@%%. `@%%    ;@@%;        " << std::endl;
		output << "                            ;@%. :@%%  %@@%;       " << std::endl;
		output << "                              %@bd%%%bd%%:;     " << std::endl;
		output << "                                #@%%%%%:;;" << std::endl;
		output << "                                %@@%%%::;" << std::endl;
		output << "                                %@@@%(o);  . '         " << std::endl;
		output << "                                %@@@o%;:(.,'         " << std::endl;
		output << "                            `.. %@@@o%::;         " << std::endl;
		output << "                               `)@@@o%::;         " << std::endl;
		output << "                                %@@(o)::;        " << std::endl;
		output << "                               .%@@@@%::;         " << std::endl;
		output << "                               ;%@@@@%::;.          " << std::endl;
		output << "                              ;%@@@@%%:;;;. " << std::endl;
		output << "                          ...;%@@@@@%%:;;;;,.." << std::endl;
	}
}