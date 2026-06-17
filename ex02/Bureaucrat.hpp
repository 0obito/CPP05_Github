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

        const std::string& getName(void) const;
        int getGrade(void) const;
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm& f);

        class GradeTooLowException  : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Bureaucrat grade is too low. (Lowest possible grade is 150)");
                }
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Bureaucrat grade is too high. (Highest possible grade is 1)");
                }
        };

};

std::ostream& operator<<(std::ostream& s, const Bureaucrat& b);

#endif  /*BUREAUCRAT_HPP*/
