#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Form::Form() : name("default"), isSigned(false), requiredGradeToSign(150), requiredGradeToExecute(150)
{
    if (requiredGradeToSign < 1)
        throw Form::GradeTooHighException();
    if (requiredGradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(std::string newName, bool newisSigned, int newRequiredGradeToSign, int newRequiredGradeToExecute) : name(newName), requiredGradeToSign(newRequiredGradeToSign), requiredGradeToExecute(newRequiredGradeToExecute)
{
    if (requiredGradeToSign < 1)
        throw Form::GradeTooHighException();
    if (requiredGradeToSign > 150)
        throw Form::GradeTooLowException();
    this->isSigned = newisSigned;
}

Form::Form(const Form &form) : name(form.name), isSigned(form.isSigned), requiredGradeToSign(form.requiredGradeToSign), requiredGradeToExecute(form.requiredGradeToExecute)
{
    if (requiredGradeToSign < 1)
        throw Form::GradeTooHighException();
    if (requiredGradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &form)
{
    if (requiredGradeToSign < 1)
        throw Form::GradeTooHighException();
    if (requiredGradeToSign > 150)
        throw Form::GradeTooLowException();
    if (this != &form)
        this->isSigned = form.isSigned;
    return (*this);
}

Form::~Form()
{
}

const std::string Form::getName() const
{
    return this->name;
}
bool Form::getSignedStatus() const
{
    return (this->isSigned);
}

int Form::getRequiredGradeToSign() const
{
    return (this->requiredGradeToSign);
}

int Form::getRequiredGradeToExecute() const
{
    return (this->requiredGradeToExecute);
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    std::cout << "*FORM INFO*" << std::endl;
    if (form.getSignedStatus() == true)
    {
        out << form.getName() << " is already signed" << std::endl;
    }
    else
    {
        out << form.getName() << " has not yet been signed." << std::endl;
        out << "You need a grade of " << form.getRequiredGradeToSign() << " to sign this form and a grade of " << form.getRequiredGradeToExecute() << " to execute this form" << std::endl;
    }
    return (out);
}

const char *Form::GradeTooLowException::what() const noexcept
{
    return "Error: Form::GradeTooLowException!";
}

const char *Form::GradeTooHighException::what() const noexcept
{
    return "Error: Form::GradeTooHighException!";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->isSigned == true)
    {
        std::cout << "Bureaucrat " << bureaucrat.getName() << " couldnt sign " << this->getName() << " because it is already signed" << std::endl;
        return;
    }
    else if (bureaucrat.getGrade() <= this->getRequiredGradeToSign())
    {
        this->isSigned = true;
        std::cout << bureaucrat.getName() << " signs " << this->getName() << std::endl;
    }
    else
        throw Form::GradeTooLowException();
}

void Form::setTrue()
{
    this->isSigned = true;
}