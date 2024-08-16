#include "Aform.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Aform
{
    private:
        std::string target;
    
    public:
        std::string getTarget();
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();

        void executeForm(void) const override;

};