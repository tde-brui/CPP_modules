#include "Aform.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Aform
{
    private:
        std::string target;
    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const &executor) const;
};