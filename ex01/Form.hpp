#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>

class Form {
    private:
        const std::string _name;
        bool              _isSigned;
        const int         _gradeToSign;
        const int         _gradeToExec;

    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Form grade is too high. (Highest possible grade is 1)");
                }
        };
        class GradeTooLowException  : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Form grade is too low. (Lowest possible grade is 150)");
                }
        };

        const std::string& getName()        const;
        bool               getIsSigned()    const;
        int                getGradeToSign() const;
        int                getGradeToExec() const;
};

std::ostream& operator<<(std::ostream& s, const Form& f);

#endif /*FORM_HPP*/
