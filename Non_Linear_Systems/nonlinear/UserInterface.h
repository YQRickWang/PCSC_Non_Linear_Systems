//
// Created by Rick Wang on 2019/12/9.
//

#ifndef NON_LINEAR_SYSTEMS_USERINTERFACE_H
#define NON_LINEAR_SYSTEMS_USERINTERFACE_H

/**
 * It will display some info about the program and give some guidance about how to use this program
 *
 */
void UserInterface();

/**
 * It shows the user the available mode of usage of the program(use existing test cases, use test cases stored in some other
 * file, or use the test case by the keyboard input)
 */
void WelcomeInfo();

/**
 * It's for the case when the user choose the existing test cases created by the developers. It has access to several examples
 * stored in the program and allows the user to choose which case to study
 */
void TestCaseInterface();

/**
 * It shows some basic information and leaves the user to choose a stored example to analyze
 */
void TestCaseWelcomeInfo();

/**
 * It works when the user choose the enter the input by the keyboard, a basic guidance about how to enter the input
 */
void KeyboardInterface();

/**
 * It works when the user chooses to enter the input by reading the txt files, while the user can change the content of
 * the txt files respecting the limit given by the developer. It's a basic guidance about how to enter the input.
 */
void TestFileInterface();

#endif //NON_LINEAR_SYSTEMS_USERINTERFACE_H
