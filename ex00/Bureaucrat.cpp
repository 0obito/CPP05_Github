#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    assignGrade(grade);
    std::cout << "matalan Bureaucrat: " << _name << " with grade: " << _grade << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    this->_name = other._name;
    this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (*this != other) {
        this->_name = other._name;
        this->_grade = other._name;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    ;
}

const std::string& Bureaucrat::getName(void) {
    return _name;
}

const int Bureaucrat::getGrade(void) {
    const int grade;
    grade = _grade;
    return grade;
}

void Bureaucrat::assignGrade(int grade) {
    if (grade < 1) {
        throw GradeTooLowException();
    }
    else if (grade > 150) {
        throw GradeTooHighException();
    }
    else {
        _grade = grade;
    }
}
