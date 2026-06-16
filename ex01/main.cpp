#include "Bureaucrat.hpp"
#include "Form.hpp"

// A simple macro-like print for clean test separation
void printTestHeader(const std::string& testName) {
    std::cout << "\n--- [ TEST: " << testName << " ] ---\n";
}

int main() {
    
    printTestHeader("1. Valid Form Creation & Getters");
    try {
        Form taxForm("Tax_28B", 50, 20);
        std::cout << "Name: " << taxForm.getName() << "\n";
        std::cout << "Is Signed: " << (taxForm.getIsSigned() ? "Yes" : "No") << "\n";
        std::cout << "Grade to Sign: " << taxForm.getGradeToSign() << "\n";
        std::cout << "Grade to Execute: " << taxForm.getGradeToExec() << "\n";
        
        // Testing the << operator overload
        std::cout << taxForm << "\n"; 
    } catch (const std::exception& e) {
        std::cerr << "Unexpected Error: " << e.what() << "\n";
    }

    printTestHeader("2. Invalid Form Creation (Grade to Sign Too High)");
    try {
        Form topSecret("Top_Secret", 0, 50); // Should throw
        std::cout << topSecret << "\n"; // This line should never print
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught successfully: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Generic catch: " << e.what() << "\n";
    }

    printTestHeader("3. Invalid Form Creation (Grade to Execute Too Low)");
    try {
        Form trashForm("Trash_Log", 100, 151); // Should throw
        std::cout << trashForm << "\n";
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught successfully: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Generic catch: " << e.what() << "\n";
    }

    printTestHeader("4. Orthodox Canonical Form (Copies)");
    try {
        Form original("Original_Doc", 42, 42);

        // Copy Constructor
        Form copyConstructed(original);
        std::cout << "Copy Constructed Form -> " << copyConstructed << "\n";

        // Assignment Operator
        Form assigned("Temp_Doc", 150, 150);
        assigned = original; 
        std::cout << "Assigned Form -> " << assigned << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error during copy tests: " << e.what() << "\n";
    }

    std::cout << "\n--- [ ALL TESTS COMPLETED ] ---\n";
    return 0;
}