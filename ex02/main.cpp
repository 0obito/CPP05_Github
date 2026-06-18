#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printHeader(const std::string& text) {
    std::cout << "\n--- [ " << text << " ] ---\n";
}

int main() {
    srand(time(0));

    printHeader("1. Initialization & Valid Executions");
    try {
        Bureaucrat boss("The_Boss", 1);
        
        ShrubberyCreationForm shrub("Backyard");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur_Dent");

        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);

        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);

        std::cout << "\nCheck your directory for 'Backyard_shrubbery'!\n";

    } catch (const std::exception& e) {
        std::cerr << "Unexpected Error: " << e.what() << "\n";
    }

    printHeader("2. The Robotomy 50/50 Gauntlet");
    try {
        Bureaucrat scientist("Dr_Frankenstein", 10);
        RobotomyRequestForm testSubject("Monster");

        scientist.signForm(testSubject);
        
        for (int i = 0; i < 5; i++) {
            scientist.executeForm(testSubject);
        }
    } catch (const std::exception& e) {
        std::cerr << "Unexpected Error: " << e.what() << "\n";
    }

    printHeader("3. The Unsigned Form Execution Error");
    try {
        Bureaucrat eagerGuy("Eager", 1);
        PresidentialPardonForm unsignedForm("Nobody");

        eagerGuy.executeForm(unsignedForm);
        
        std::cout << "You shouldn't see this.\n";
    } catch (const std::exception& e) {
        std::cerr << "Caught successfully: " << e.what() << "\n";
    }

    printHeader("4. The 'Grade Too Low To Execute' Error");
    try {
        Bureaucrat midManager("Manager", 140);
        ShrubberyCreationForm sneakyShrub("Secret_Garden");

        midManager.signForm(sneakyShrub);
        midManager.executeForm(sneakyShrub);

        std::cout << "You shouldn't see this.\n";
    } catch (const std::exception& e) {
        std::cerr << "Caught successfully: " << e.what() << "\n";
    }

    std::cout << "\n--- [ ALL TESTS COMPLETED ] ---\n";
    return 0;
}
