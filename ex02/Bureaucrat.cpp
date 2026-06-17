#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("NPC"), _grade(150) {
    // std::cout << "bureaucrat with default name: " << _name << " and with default grade: " << _grade << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
    // std::cout << "bureaucrat with name: " << _name << " and with grade " << _grade << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
}

const std::string& Bureaucrat::getName(void) const {
    return _name;
}

int Bureaucrat::getGrade(void) const {
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

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << "." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& s, const Bureaucrat& b) {
    s << b.getName() << ", " << "bureaucrat grade " << b.getGrade() << ".";
    return s;
}
