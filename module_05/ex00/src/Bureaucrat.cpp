#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(int grade)
{
    this->grade = grade;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
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

const std::string Bureaucrat::getName()
{
    return (this->name);
}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

void Bureaucrat::increaseGrade(int amount)
{
    this->grade -= amount;
}

void Bureaucrat::decreaseGrade(int amount)
{
    this->grade += amount;
}
