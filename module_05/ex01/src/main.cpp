#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    try
    {
        Form form1("Police form", false, 50, 50);
        std::cout << form1 << std::endl;


        Bureaucrat bureaucrat2("Piet", 50);
        bureaucrat2.signForm(form1);

        std::cout << form1 << std::endl;
        Bureaucrat bureaucrat1("Henk", 150);
        bureaucrat1.signForm(form1);

        std::cout << std::endl;

        form1.beSigned(bureaucrat1);

        std::cout << form1 << std::endl;

        Form form2("School form", false, 5, 5);
        std::cout << form2 << std::endl;

        Bureaucrat bureaucrat3("Kees", 10);
        bureaucrat3.signForm(form2);
    }
    catch(const Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}