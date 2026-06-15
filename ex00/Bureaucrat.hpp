#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();
        const std::string& getName(void);
        int getGrade(void);
        void incrementGrade();
        void decrementGrade();
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

#endif  /*BUREAUCRAT_HPP*/
