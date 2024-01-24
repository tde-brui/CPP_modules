#include "../inc/Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat1(50);

        Bureaucrat bureaucrat2(-12);
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