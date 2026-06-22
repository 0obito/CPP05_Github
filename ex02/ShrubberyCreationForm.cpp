#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::performExecution() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream outFile(filename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: couldn't open file: " << filename << std::endl;
        return ;
    }
    outFile << "       _-_" << "\n";
    outFile << "    /~~   ~~\\" << "\n";
    outFile << " /~~         ~~\\" << "\n";
    outFile << "{               }" << "\n";
    outFile << " \\  _-     -_  /" << "\n";
    outFile << "   ~  \\\\ //  ~" << "\n";
    outFile << "_- -   | | _- _" << "\n";
    outFile << "  _ -  | |   -_" << "\n";
    outFile << "      // \\\\" << "\n";
    outFile.close();
}
