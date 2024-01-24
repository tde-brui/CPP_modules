#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "iostream"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat &operator=(const Bureaucrat &bureacrat);
        ~Bureaucrat();
        const std::string getName();
        int getGrade();
        void increaseGrade(int amount);
        void decreaseGrade(int amount);
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const noexcept
                {
                    return "Error : Grade too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const noexcept
                {
                    return "Error : Grade too low";
                };
        };


};

#endif