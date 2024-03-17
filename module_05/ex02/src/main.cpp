#include "../inc/Bureaucrat.hpp"
#include "../inc/Aform.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat b1("Bureaucrat1", 1);
    Bureaucrat b2("Bureaucrat2", 150);
    PresidentialPardonForm ppf("target1");
    ShrubberyCreationForm scf("target2");
    RobotomyRequestForm rrf("target3");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << ppf << std::endl;
    std::cout << scf << std::endl;
    std::cout << rrf << std::endl;

    b1.signForm(ppf);
    b1.signForm(scf);
    b1.signForm(rrf);

    b1.executeForm(ppf);
    b1.executeForm(scf);
    b1.executeForm(rrf);

    b2.signForm(ppf);
    b2.signForm(scf);
    b2.signForm(rrf);

    b2.executeForm(ppf);
    b2.executeForm(scf);
    b2.executeForm(rrf);

    return 0;
}