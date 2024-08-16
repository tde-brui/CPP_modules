#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Aform
{
    private:
        const       std::string name;
        bool        isSigned;
        const int   requiredGradeToSign;
        const int   requiredGradeToExecute;
    
    public:
        Aform();
        Aform(const Aform &aform);
        Aform(std::string name, bool isSigned, int requiredGradeToSign, int requiredGradeToExecute);
        Aform &operator=(const Aform &aform);
        virtual ~Aform();

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
        class FormNotSignedException : public std::exception
        {
            public:
                const char *what() const noexcept;
        };
        void execute(Bureaucrat const &executor) const;
        virtual void executeForm(void) const = 0;

};

std::ostream &operator<<(std::ostream &out, const Aform &aform);

#endif