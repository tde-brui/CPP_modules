#include "../inc/Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat1;
        Bureaucrat bureaucrat2;

        std::cout << bureaucrat1 << bureaucrat2;

        Bureaucrat bureaucrat3(100);
        Bureaucrat bureaucrat4(1);

        std::cout << bureaucrat3 << bureaucrat4;

        Bureaucrat bureaucrat5("Willem", 50);
        Bureaucrat bureaucrat6("John", 50);

        std::cout << bureaucrat5 << bureaucrat6;

        Bureaucrat bureaucrat7 = bureaucrat1;
        Bureaucrat bureaucrat8(bureaucrat5);

        std::cout << bureaucrat7 << bureaucrat8;

        bureaucrat8.decreaseGrade(50);

        std::cout << bureaucrat8;

        bureaucrat8.decreaseGrade(50);
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