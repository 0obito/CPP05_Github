#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();
        const std::string& getName(void);
        const int getGrade(void);
        // void assignGrade(int grade);
        class GradeTooLowException public std::exception {
            ;
        };
        class GradeTooHighException : public std::exception {
            GradeTooHighException();
            ~GradeTooHighException();
        };
        void assignGrade(int grade);
};

#endif  /*BUREAUCRAT_HPP*/
