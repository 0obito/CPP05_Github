#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool              _isSigned;
        const int         _gradeToSign;
        const int         _gradeToExec;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("AForm grade is too high. (Highest possible grade is 1)");
                }
        };
        class GradeTooLowException  : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("AForm grade is too low. (Lowest possible grade is 150)");
                }
        };

        const std::string& getName()        const;
        bool               getIsSigned()    const;
        int                getGradeToSign() const;
        int                getGradeToExec() const;

        void beSigned(const Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream& s, const AForm& f);

#endif /*AFORM_HPP*/
