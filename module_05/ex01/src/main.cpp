#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    try
    {
        Form form1("Form1", false, 150, 150);
        Form form2("Form2", false, 1, 1);
        Form form3("Form3", false, 75, 75);
        //Form form4("Form4", false, 0, 0); //throws exception
        //Form form5("Form5", false, 151, 151); //throws exception

        std::cout << form1 << std::endl << form2 << std::endl << form3 << std::endl;

        Bureaucrat bureaucrat1("Bureaucrat1", 1);
        Bureaucrat bureaucrat2("Bureaucrat2", 150);
        
        std::cout << bureaucrat1 << std::endl << bureaucrat2 << std::endl;

        bureaucrat1.signForm(form1);
        bureaucrat2.signForm(form2);
        bureaucrat2.signForm(form3);

        form2.beSigned(bureaucrat1);
        form3.beSigned(bureaucrat1);
        form2.beSigned(bureaucrat2); // already signed

        Form form6("Form6", false, 75, 75);
        Bureaucrat bureaucrat3("Bureaucrat3", 76);

        form6.beSigned(bureaucrat3); // will throw GradeTooLowException

    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}