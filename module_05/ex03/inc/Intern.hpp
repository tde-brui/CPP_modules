#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Aform.hpp"
# include <vector>
# include <algorithm>


class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		Aform *makeForm(std::string formName, std::string target);

};

#endif