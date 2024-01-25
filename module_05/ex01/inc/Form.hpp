#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form
{
    private:
        const       std::string name;
        bool        isSigned;
        const int   requiredGradeToSign;
        const int   requiredGradeToExecute;
    
    public:
        Form();
        Form(const Form &form);
        Form(std::string name, bool isSigned, int requiredGradeToSign, int requiredGradeToExecute);
        Form &operator=(const Form &form);
        ~Form();

        const std::string getName() const;
        bool  getSignedStatus() const;
        int getRequiredGradeToSign() const;
        int getRequiredGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        void setTrue();

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const noexcept;
        };
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const noexcept;
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif