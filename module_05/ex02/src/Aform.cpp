#include "../inc/Bureaucrat.hpp"
#include "../inc/Aform.hpp"

Aform::Aform() : name("default"), isSigned(false), requiredGradeToSign(150), requiredGradeToExecute(150)
{
}

Aform::Aform(std::string newName, bool newisSigned, int newRequiredGradeToSign, int newRequiredGradeToExecute) : name(newName), requiredGradeToSign(newRequiredGradeToSign), requiredGradeToExecute(newRequiredGradeToExecute)
{
    this->isSigned = newisSigned;
}

Aform::Aform(const Aform &aform) : name(aform.name), isSigned(aform.isSigned), requiredGradeToSign(aform.requiredGradeToSign), requiredGradeToExecute(aform.requiredGradeToExecute)
{
}

Aform &Aform::operator=(const Aform &aform)
{
    if (this != &aform)
        this->isSigned = aform.isSigned;
    return (*this);
}

Aform::~Aform()
{
}

const std::string Aform::getName() const
{
    return this->name;
}
bool Aform::getSignedStatus() const
{
    return (this->isSigned);
}

int Aform::getRequiredGradeToSign() const
{
    return (this->requiredGradeToSign);
}

int Aform::getRequiredGradeToExecute() const
{
    return (this->requiredGradeToExecute);
}

std::ostream &operator<<(std::ostream &out, const Aform &aform)
{
    std::cout << "*Aform INFO*" << std::endl;
    if (aform.getSignedStatus() == true)
    {
        out << aform.getName() << " is already signed" << std::endl;
    }
    else
    {
        out << aform.getName() << " has not yet been signed." << std::endl;
        out << "You need a grade of " << aform.getRequiredGradeToSign() << " to sign this Aform and a grade of " << aform.getRequiredGradeToExecute() << " to execute this Aform" << std::endl;
    }
    return (out);
}

const char *Aform::GradeTooLowException::what() const noexcept
{
    return "Aform can't be signed, Bureaucrat grade is too low";
}

const char *Aform::GradeTooHighException::what() const noexcept
{
    return "Aform can't be signed, Bureaucrat grade is too high";
}

const char *Aform::FormNotSignedException::what() const noexcept
{
    return "Aform can't be executed, it has not been signed yet";
}

void Aform::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() < this->getRequiredGradeToSign())
        this->isSigned = true;
    else
        throw Aform::GradeTooLowException();
}

void Aform::setTrue()
{
    this->isSigned = true;
}



void Aform::execute(Bureaucrat const &executor) const
{
    if (this->getSignedStatus() == false)
        throw Aform::FormNotSignedException();
    if (executor.getGrade() > this->getRequiredGradeToExecute())
        throw Aform::GradeTooLowException();
    std::cout << executor.getName() << " executes " << this->getName() << std::endl;
}
