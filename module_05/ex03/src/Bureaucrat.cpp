#include "../inc/Bureaucrat.hpp"
#include "../inc/Aform.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string initname, int initgrade) : name(initname), grade(initgrade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(int grade) : name("default")
{
    this->grade = grade;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name)
{
    this->grade = bureaucrat.grade;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this != &bureaucrat)
        this->grade = bureaucrat.grade;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::increaseGrade(int amount)
{
    this->grade -= amount;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::decreaseGrade(int amount)
{
    this->grade += amount;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Error: Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Error: Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade() << std::endl;
    return (out);
}

void Bureaucrat::signForm(Aform &form)
{
    if (form.getSignedStatus() == true)
    {
        std::cout << this->name << " couldnt sign " << form.getName() << " because it is already signed" << std::endl;
        return;
    }
    else
    if (this->getGrade() <= form.getRequiredGradeToSign())
    {
        std::cout << this->name << " signed " << form.getName() << std::endl; 
        form.setTrue();
    }
    else
    {
        std::cout << this->name << " could not sign " << form.getName() << " because it's grade is too low" << std::endl;
        return;
    }
}

void Bureaucrat::executeForm(Aform const &form) const
{
    if (form.getSignedStatus() == false)
    {
        std::cout << this->name << "could not execute " << form.getName() << " because it has not been signed yet" << std::endl;
        return;
    }
    else if (form.getRequiredGradeToExecute() < this->getGrade())
    {
        std::cout << this->name << " could not execute " << form.getName() << " because it's grade is too low" << std::endl;
        return;
    }
    else
    {
        std::cout << this->name << " executes " << form.getName() << std::endl;
        form.execute(*this);
    }
}