#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        AForm* makeShrubbery(const std::string& target) const;
        AForm* makeRobotomy(const std::string& target) const;
        AForm* makePresidential(const std::string& target) const;
        AForm* makeForm(const std::string &name, const std::string &target) const;
};

#endif /*INTERN_HPP*/
