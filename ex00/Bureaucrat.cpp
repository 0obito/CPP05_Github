#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("NPC"), _grade(150) {
    std::cout << "bureaucrat with default name: " << _name << " and with default grade: " << _grade << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
    std::cout << "bureaucrat with name: " << _name << " and with grade " << _grade << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) {
    // assigning the name here should fail, i think
    // this->_name = other.getName();
    this->_grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other) {
    if (this != &other) {
        // assigning the name here should fail as well, i think
        // this->_name = other.getName();
        this->_grade = other.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    ;
}

const std::string& Bureaucrat::getName(void) {
    return _name;
}

int Bureaucrat::getGrade(void) {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade == 1) {
        throw GradeTooHighException();
    }
    _grade -= 1;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150) {
        throw GradeTooLowException();
    }
    _grade += 1;
}
