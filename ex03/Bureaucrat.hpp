#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>

class AForm;

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

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm& f);

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
        void executeForm(const AForm& f) const;
};

std::ostream& operator<<(std::ostream& s, const Bureaucrat& b);

#endif  /*BUREAUCRAT_HPP*/
