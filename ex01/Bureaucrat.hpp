#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName(void) const;
        int getGrade(void) const;
        void incrementGrade();
        void decrementGrade();

        void signForm(Form& f);

        class GradeTooLowException  : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Bureaucrat grade is too low");
                }
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Bureaucrat grade is too high");
                }
        };

};

std::ostream& operator<<(std::ostream& s, const Bureaucrat& b);

#endif  /*BUREAUCRAT_HPP*/
