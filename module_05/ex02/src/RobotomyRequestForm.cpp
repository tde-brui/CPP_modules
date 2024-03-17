#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Aform("RobotomyRequestForm", false, 72, 45), target(target){};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Aform(other), target(other.target){};

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    srand(time(NULL));
    std::cout << "Bzzzzzzzzz\nWhirrrrrrrrrrr\nClank Clank\n";
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully\n";
    else
        std::cout << this->target << " robotomization failed\n";
}