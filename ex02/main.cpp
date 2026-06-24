#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

void printHeader(const std::string& text) {
    std::cout << "\n========================================\n";
    std::cout << "  " << text << "\n";
    std::cout << "========================================\n";
}

int main() {
    srand(time(0));

    // 1
    printHeader("Test 1: ShrubberyCreationForm - Sign and Execute");
    try {
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm shrub("Home");

        std::cout << gardener << "\n";
        std::cout << shrub << "\n";

        gardener.signForm(shrub);
        gardener.executeForm(shrub);

        std::cout << "-> Check directory for 'Home_shrubbery'!\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 2
    printHeader("Test 2: RobotomyRequestForm - 50/50 Chance");
    try {
        Bureaucrat scientist("Dr. Frankenstein", 40);
        RobotomyRequestForm robot("Bender");

        std::cout << scientist << "\n";
        std::cout << robot << "\n";

        scientist.signForm(robot);

        for (int i = 0; i < 4; i++) {
            std::cout << "\nAttempt " << i + 1 << ":\n";
            scientist.executeForm(robot);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 3
    printHeader("Test 3: PresidentialPardonForm - Sign and Execute");
    try {
        Bureaucrat president("Zaphod", 5);
        PresidentialPardonForm pardon("Arthur_Dent");

        std::cout << president << "\n";
        std::cout << pardon << "\n";

        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 4
    printHeader("Test 4: Attempt to execute an unsigned form");
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm unsignedForm("Nobody");

        // Boss has the grade, form isn't signed 
        boss.executeForm(unsignedForm);
        // Bureaucrat catches the exception internally
    }
    catch (const std::exception& e) {
        // shouldn't come here
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 5
    printHeader("Test 5: Attempt to execute with grade too low");
    try {
        Bureaucrat flan("Flan", 140); 
        ShrubberyCreationForm sneakyShrub("Secret_Garden");

        // flan can sign, can't execute
        flan.signForm(sneakyShrub);
        // Bureaucrat catches this internally
        flan.executeForm(sneakyShrub);
    }
    catch (const std::exception& e) {
        // shouldn't come here
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    printHeader("End of program");
    return 0;
}