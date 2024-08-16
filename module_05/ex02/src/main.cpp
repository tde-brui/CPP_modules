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
        Bureaucrat b3("Bureaucrat3", 150);
        PresidentialPardonForm ppf("target1");
        ShrubberyCreationForm scf("target2");
        RobotomyRequestForm rrf("target3");

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;
        std::cout << ppf << std::endl;
        std::cout << scf << std::endl;
        std::cout << rrf << std::endl;

        //b3 can not sign any forms because his grade is too high;
        b3.signForm(ppf);
        b3.signForm(scf);
        b3.signForm(rrf);

        std::cout << std::endl;
        
        //b2 can sign all forms except PresidentialPardonForm
        b2.signForm(ppf);
        b2.signForm(scf);
        b2.signForm(rrf);

        std::cout << std::endl;

        //b1 can sign all forms, but scf and rrf are already signed.
        b1.signForm(ppf);
        b1.signForm(scf);
        b1.signForm(rrf);

        std::cout << std::endl;

        //b1 can execute all forms
        ppf.execute(b1);
        scf.execute(b1);
        rrf.execute(b1);

        //b2 can only execute scf.
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