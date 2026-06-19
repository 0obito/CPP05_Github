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

    protected:
        virtual void performExecution() const = 0;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        class GradeTooHighException  : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Grade is too high.");
                }
        };
        class GradeTooLowException   : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Grade is too low.");
                }
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Attempted to execute a form that was not signed.");
                }
        };
        const std::string& getName()        const;
        bool               getIsSigned()    const;
        int                getGradeToSign() const;
        int                getGradeToExec() const;

        void beSigned(const Bureaucrat& bur);
        void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& s, const AForm& f);

#endif /*AFORM_HPP*/
