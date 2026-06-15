#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

int main() {

    try {
        Bureaucrat  npc1;
        Bureaucrat  npc2;
        Bureaucrat  npc3;
        Bureaucrat  npc4("a", 1500000);
        Bureaucrat  him1("obito", 1);
        Bureaucrat  him2("jobito", 2);
    }
    catch(const Bureaucrat::GradeTooHighException& tooHigh) {
        std::cerr << "caught specific exception: " << tooHigh.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& tooLow) {
        std::cerr << "caught standard exception: " << tooLow.what() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "caught standard exception: " << e.what() << std::endl;
    }
    std::cout << "End of program." << std::endl;
    return (0);
}
