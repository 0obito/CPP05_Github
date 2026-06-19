#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void performExecution() const;
};

#endif /*SHRUBBERYCREATIONFORM_HPP*/
