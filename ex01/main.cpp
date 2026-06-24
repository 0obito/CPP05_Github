#include "Bureaucrat.hpp"
#include "Form.hpp"

void printHeader(const std::string& text) {
    std::cout << "\n========================================\n";
    std::cout << "  " << text << "\n";
    std::cout << "========================================\n";
}

int main() {

    // 1
    printHeader("Test1: Attempts to create a valid Form and print its details. Works perfectly fine");
    try {
        Form nda("NDA", 50, 20);
        std::cout << nda << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 2
    printHeader("Test2: Attempts to create a Form with a sign grade of 0. Fails");
    try {
        Form topSecret("TopSecret", 0, 50);
        // won't print
        std::cout << topSecret << "\n";
    }
    catch(const std::exception& e) {
        // comes here, grade too high
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 3
    printHeader("Test3: Attempts to create a Form with an exec grade of 151. Fails");
    try {
        Form publicDoc("PublicDoc", 100, 151);
        // won't print
        std::cout << publicDoc << "\n"; 
    }
    catch(const std::exception& e) {
        // comes here, grade too low
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 4
    printHeader("Test4: Bureaucrat successfully signs a form");
    try {
        Bureaucrat ceo("The_CEO", 1);
        Form contract("Contract", 10, 10);

        std::cout << ceo << "\n";
        std::cout << contract << "\n";

        std::cout << "Attempting to sign the form...\n";
        ceo.signForm(contract);

        std::cout << contract << "\n"; 
    }
    catch(const std::exception& e) {
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 5
    printHeader("Test5: Bureaucrat attempts to sign a form with a grade too low. Fails gracefully");
    try {
        Bureaucrat flan("Flan", 150);
        Form taxReturn("TaxReturn", 50, 50);

        std::cout << flan << "\n";
        std::cout << taxReturn << "\n";

        std::cout << "Attempting to sign the form...\n";
        // Bureaucrat handles the exception internally and prints the error message
        flan.signForm(taxReturn); 

        // not signed
        std::cout << taxReturn << "\n"; 
    }
    catch(const std::exception& e) {
        // signForm swallows the error, won't come here
        std::cerr << "caught exception in main: " << e.what() << "\n";
    }

    printHeader("End of program");
    return (0);
}