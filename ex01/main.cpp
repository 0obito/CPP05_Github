#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void printHeader(const std::string& text) {
    std::cout << "\n--- [ " << text << " ] ---\n";
}

int main() {
    printHeader("1. Form Initialization & Overloads");
    try {
        Form a("Tax_28B", 50, 20);
        Bureaucrat bob("Bob", 40);
        
        std::cout << a << "\n";
        std::cout << bob << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    printHeader("2. Bureaucrat Signs Form Successfully");
    try {
        Form b("NDA", 100, 50);
        Bureaucrat alice("Alice", 99); // Grade 99 is better than 100
        
        alice.signForm(b);
        std::cout << "Status Check -> " << b << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    printHeader("3. Bureaucrat Fails to Sign Form");
    try {
        Form c("Top_Secret", 10, 5);
        Bureaucrat intern("Intern", 150); // Lowest grade
        
        intern.signForm(c);
        std::cout << "Status Check -> " << c << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    printHeader("4. Form Invalid Instantiation");
    try {
        Form d("Impossible", 0, 50); // Should throw GradeTooHigh
        std::cout << "You shouldn't see this.\n";
    } catch (const std::exception& e) {
        std::cerr << "Caught successfully: " << e.what() << "\n";
    }

    std::cout << "\n--- [ END OF TESTS ] ---\n";
    return 0;
}