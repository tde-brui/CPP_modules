#include "../inc/Bureaucrat.hpp"

int main()
{
    try {
        //Bureaucrat tooHighBureau("Too High Bureau", 0); //GradeTooHighException
        //Bureaucrat tooLowBureau("Too Low Bureau", 151); //GradeTooLowException

        Bureaucrat b1("Bureaucrat1", 1);
        Bureaucrat b2("Bureaucrat2", 150);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        //b1.increaseGrade(1); //GradeTooHighException
        //b2.decreaseGrade(1); //GradeTooLowException

        Bureaucrat b3;
        Bureaucrat b4(100);
        
        std::cout << b3 << std::endl;
        std::cout << b4 << std::endl;


        //Demonstrating copy constructor and assignment operator
        Bureaucrat b5(b1);
        Bureaucrat b6 = b2;

        std::cout << b5 << std::endl;
        std::cout << b6 << std::endl;
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