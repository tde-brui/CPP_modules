#include "../inc/Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat1;
        Bureaucrat bureaucrat2;

        Bureaucrat bureaucrat3(129);
        Bureaucrat bureaucrat4(1);

        Bureaucrat bureaucrat5("Willem", 50);
        Bureaucrat bureaucrat6("John", 50);

        Bureaucrat bureaucrat7 = bureaucrat1;
        Bureaucrat bureaucrat8(bureaucrat5);
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}