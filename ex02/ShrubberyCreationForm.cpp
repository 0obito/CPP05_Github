#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
    _target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::doItYourself (const Bureaucrat& executor) const {
    ;
}
