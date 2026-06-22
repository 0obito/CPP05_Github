#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::performExecution() const {
    std::cout << "* BZAJHDSUHJAT ... ZZZRRVVVV ... BAM!!! * (Intense drilling noises)\n";
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully!\n";
    }
    else {
        std::cout << "The robotomy on " << _target << " has failed!\n";
    }
}
