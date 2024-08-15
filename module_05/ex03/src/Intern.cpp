#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &intern)
{
	(void)intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	return *this;
}

Aform* Intern::makeForm(std::string formName, std::string target)
{
	const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	const Aform *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (const_cast<Aform*>(forms[i]));
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return nullptr;
}