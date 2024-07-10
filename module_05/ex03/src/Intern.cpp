#include "Intern.hpp"

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
}

Aform* Intern::makeForm(std::string formName, std::string target)
{
	if (std::find(formNames.begin(), formNames.end(), formName) == formNames.end())
	{
		std::cout << "Form name not found" << std::endl;
		return nullptr;
	}
	
}