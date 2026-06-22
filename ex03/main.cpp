#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void printHeader(const std::string& text) {
    std::cout << "\n========================================\n";
    std::cout << "  " << text << "\n";
    std::cout << "========================================\n";
}

int main() {
    // Seed the RNG once for the Robotomy form
    srand(time(0));

    Intern someRandomIntern;
    Bureaucrat boss("The_CEO", 1);
    AForm* rrf;

    printHeader("Test 1: The Non-Existent Form");
    // Should print an error and return NULL
    rrf = someRandomIntern.makeForm("some fake form", "Ghost");
    if (rrf == 0) {
        std::cout << "-> Successfully caught invalid form generation!\n";
    }

    printHeader("Test 2: Shrubbery Creation Form");
    rrf = someRandomIntern.makeForm("shrubbery creation", "Backyard");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; // CRITICAL: The Intern used 'new', so we must 'delete'
    }

    printHeader("Test 3: Robotomy Request Form");
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    printHeader("Test 4: Presidential Pardon Form");
    rrf = someRandomIntern.makeForm("presidential pardon", "Arthur_Dent");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; 
    }

    printHeader("All Memory Cleaned. Tests Complete.");
    return 0;
}