#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){};

PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Aform("PresidentialPardonForm", false, 25, 5), target(target){};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Aform(other), target(other.target){};

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}   
