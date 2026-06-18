#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("Default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
    _target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::doItYourself (const Bureaucrat& executor) const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox;" << std::endl;
}
