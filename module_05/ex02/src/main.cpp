#include "../inc/Bureaucrat.hpp"
#include "../inc/Aform.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main()
{
    try{
        //Aform a1("Aform1", 1, 1);
        Bureaucrat b1("Bureaucrat1", 1);
        Bureaucrat b2("Bureaucrat2", 50);
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

        ppf.execute(b1);
        scf.execute(b1);
        rrf.execute(b1);

        b2.executeForm(ppf);
        b2.executeForm(scf);
        b2.executeForm(rrf);

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}