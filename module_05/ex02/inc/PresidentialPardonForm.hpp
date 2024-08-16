#include "Aform.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Aform
{
    private:
        std::string target;

    public:
        std::string getTarget();
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

        void executeForm(void) const override;
};