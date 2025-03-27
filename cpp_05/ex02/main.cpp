#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Test 1: Shrubbery Creation Form - Success
    try {
        Bureaucrat gardener("Alice", 137);
        ShrubberyCreationForm treeForm("Garden");
        
        gardener.signForm(treeForm);
        gardener.executeForm(treeForm); // Should create Garden_shrubbery file
    } 
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Test 2: Robotomy Request Form - 50% Success
    try {
        Bureaucrat engineer("Bob", 45);
        RobotomyRequestForm robotForm("Bender");
        
        engineer.signForm(robotForm);
        for (int i = 0; i < 4; i++) {
            engineer.executeForm(robotForm); // Should show success ~50% of tries
        }
    } 
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Test 3: Presidential Pardon Form - High Level Execution
    try {
        Bureaucrat president("Zaphod", 1);
        PresidentialPardonForm pardonForm("Marvin");
        
        president.signForm(pardonForm);
        president.executeForm(pardonForm); // Should show presidential pardon
    } 
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Test 4: Execution Without Signing
    try {
        Bureaucrat junior("Charlie", 150);
        ShrubberyCreationForm invalidForm("Backyard");
        
        junior.executeForm(invalidForm); // Should throw FormNotSignedException
    } 
    catch (std::exception &e) {
        std::cerr << "Expected error: " << e.what() << "\n";
    }

    // Test 5: Insufficient Execution Grade
    try {
        Bureaucrat midLevel("Dave", 140);
        ShrubberyCreationForm form("Park");
        
        midLevel.signForm(form);
        midLevel.executeForm(form); // Should throw GradeTooLowException (execute grade 137 needed)
    } 
    catch (std::exception &e) {
        std::cerr << "Expected error: " << e.what() << "\n";
    }

    // Test 6: Form Copy and Assignment
    try {
        ShrubberyCreationForm original("Forest");
        ShrubberyCreationForm copy(original);
        ShrubberyCreationForm assigned;
        assigned = original;

        Bureaucrat worker("Eve", 1);
        worker.signForm(copy);
        worker.executeForm(copy); // Should create Forest_shrubbery
    } 
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}