#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

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
        Form &operator=(const Form &form);
        ~Form();

};
#endif