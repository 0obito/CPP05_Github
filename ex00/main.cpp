#include "Bureaucrat.hpp"

void printHeader(const std::string& text) {
    std::cout << "\n========================================\n";
    std::cout << "  " << text << "\n";
    std::cout << "========================================\n";
}

int main() {

    // 1
    printHeader("Test1: Attempts to create a bureaucrat and increment his grade. Works perfectly fine");
    try {
        Bureaucrat flan("Flan", 47);
        std::cout << flan << "\n";
        std::cout << "Attempting to increase Flan's grade\n";
        flan.incrementGrade();
        std::cout << "Flan's new grade is " << flan.getGrade() << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 2
    printHeader("Test2: Attempts to create a bureaucrat and increment her grade. Fails");
    try {
        Bureaucrat flana("Flana", 1);
        std::cout << flana << "\n";
        std::cout << "Attempting to increase Flana's grade\n";
        flana.incrementGrade();
        // won't print
        std::cout << "Flana's new grade is " << flana.getGrade() << "\n";
    }
    catch(const std::exception& e) {
        // comes here, grade too high
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 3
    printHeader("Test3: Attempts to create a bureaucrat and decrement her grade. Works perfectly fine");
    try {
        Bureaucrat judy("Judy", 2);
        std::cout << judy << "\n";
        std::cout << "Attempting to decrease Judy's grade\n";
        judy.decrementGrade();
        std::cout << "Judy's new grade is " << judy.getGrade() << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 4
    printHeader("Test4: Attempts to create a bureaucrat and decrement his grade. Fails");
    try {
        Bureaucrat jamie("Jamie", 150);
        std::cout << jamie << "\n";
        std::cout << "Attempting to decrease Jamie's grade\n";
        jamie.decrementGrade();
        // won't print
        std::cout << "Jamie's new grade is " << jamie.getGrade() << "\n";
    }
    catch(const std::exception& e) {
        // comes here, grade too low
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 5
    printHeader("Test5: Attempts to create a bureaucrat with grade 151. Fails");
    try {
        Bureaucrat noOne("noOne", 151);
        // won't continue
        std::cout << noOne << "\n";
        std::cout << "Attempting to decrease noOne's grade\n";
        noOne.decrementGrade();
        std::cout << "noOne's new grade is " << noOne.getGrade() << "\n";
    }
    catch(const std::exception& e) {
        // comes here, grade too low
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    // 6
    printHeader("Test6: Attempts to create a bureaucrat with grade 0. Fails");
    try {
        Bureaucrat noOne("noOne", 0);
        // won't continue
        std::cout << noOne << "\n";
        std::cout << "Attempting to decrease noOne's grade\n";
        noOne.decrementGrade();
        std::cout << "noOne's new grade is " << noOne.getGrade() << "\n";
    }
    catch(const std::exception& e) {
        // comes here, grade too high
        std::cerr << "caught exception: " << e.what() << "\n";
    }

    printHeader("End of program");
    return (0);
}
