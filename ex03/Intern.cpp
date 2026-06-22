#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return (*this);
}

Intern::~Intern() {
}

AForm* Intern::makeShrubbery(const std::string& target) const {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(const std::string& target) const {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(const std::string& target) const {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) const {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formFuncs[3])(const std::string& target) const = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    for (int i = 0 ; i < 3 ; i++) {
        if (formNames[i] == name) {
            std::cout << "Intern creates " << name << ".\n";
            return (this->*formFuncs[i])(target);
        }
    }

    std::cerr << "Intern couldn't create " << name << ". No such form!"<< std::endl;
    return (0);
}
