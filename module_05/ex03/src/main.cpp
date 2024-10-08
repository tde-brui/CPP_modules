#include "../inc/Bureaucrat.hpp"
#include "../inc/Aform.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
    try{
        Bureaucrat b1("Bureaucrat1", 1);
        Bureaucrat b2("Bureaucrat2", 50);
        Intern alex;

        Aform *ppf = alex.makeForm("presidential pardon", "target1");
        Aform *scf = alex.makeForm("shrubbery creation", "target2");
        Aform *rrf = alex.makeForm("robotomy request", "target3");
        //Aform *random = alex.makeForm("random", "target4");


        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << *ppf << std::endl;
        std::cout << *scf << std::endl;
        std::cout << *rrf << std::endl;

        b1.signForm(*ppf);
        b1.signForm(*scf);
        b1.signForm(*rrf);

        b1.executeForm(*ppf);
        b1.executeForm(*scf);
        b1.executeForm(*rrf);

        b2.signForm(*scf);
        b2.signForm(*rrf);
        b2.signForm(*rrf);

        delete ppf;
        delete scf;
        delete rrf;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}