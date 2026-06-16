#include "Bureaucrat.hpp"

int main() {

    try {
        Bureaucrat  mrA("mr A", 150);
        Bureaucrat  obito("obito", 1);
        Bureaucrat  jude("jude", 2);

        std::cout << mrA << std::endl;
        std::cout << obito << std::endl;
        std::cout << jude << std::endl;

        mrA.incrementGrade();
        std::cout << mrA << std::endl;
        mrA.decrementGrade();
        std::cout << mrA << std::endl;
        mrA.decrementGrade();
        std::cout << mrA << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "End of program." << std::endl;
    return (0);
}
