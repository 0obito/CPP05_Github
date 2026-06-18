#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
    _target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::doItYourself (const Bureaucrat& executor) const {
    ;
}
