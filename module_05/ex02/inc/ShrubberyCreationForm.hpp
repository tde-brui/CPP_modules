#include "Aform.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Aform
{
    private:
        std::string target;

    public:
        std::string getTarget();
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        ~ShrubberyCreationForm();

        void executeForm(void) const override;

};