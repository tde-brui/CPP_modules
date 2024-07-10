#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Aform;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const std::string initname, int initgrade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat &operator=(const Bureaucrat &bureacrat);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void increaseGrade(int amount);
        void decreaseGrade(int amount);
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const noexcept;
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const noexcept;
        };

        void signForm(Aform &form);
        void executeForm(Aform const &form) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif