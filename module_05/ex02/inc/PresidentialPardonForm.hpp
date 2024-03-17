#include "Aform.hpp"

class PresidentialPardonForm : public Aform
{
    private:
        std::string target;

    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

        void execute(Bureaucrat const &executor) const;
};