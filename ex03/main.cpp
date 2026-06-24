#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

void printHeader(const std::string& text) {
    std::cout << "\n========================================\n";
    std::cout << "  " << text << "\n";
    std::cout << "========================================\n";
}

int main() {
    srand(time(0));

    Intern someRandomIntern;
    Bureaucrat boss("The_Boss", 1);
    AForm* formPtr;

    // 1
    printHeader("Test 1: Intern attempts to create an unknown form. Fails gracefully");
    formPtr = someRandomIntern.makeForm("some fake form", "Ghost");
    if (formPtr == 0) {
        std::cout << "-> Intern correctly returned a NULL pointer for an unknown form.\n";
    }

    // 2
    printHeader("Test 2: Intern creates a ShrubberyCreationForm");
    formPtr = someRandomIntern.makeForm("shrubbery creation", "Backyard");
    if (formPtr) {
        std::cout << *formPtr << "\n";
        boss.signForm(*formPtr);
        boss.executeForm(*formPtr);
        delete formPtr;
    }

    // 3
    printHeader("Test 3: Intern creates a RobotomyRequestForm");
    formPtr = someRandomIntern.makeForm("robotomy request", "Bender");
    if (formPtr) {
        std::cout << *formPtr << "\n";
        boss.signForm(*formPtr);
        boss.executeForm(*formPtr);
        delete formPtr;
    }

    // 4
    printHeader("Test 4: Intern creates a PresidentialPardonForm");
    formPtr = someRandomIntern.makeForm("presidential pardon", "Arthur_Dent");
    if (formPtr) {
        std::cout << *formPtr << "\n";
        boss.signForm(*formPtr);
        boss.executeForm(*formPtr);
        delete formPtr;
    }

    printHeader("End of program");
    return 0;
}
