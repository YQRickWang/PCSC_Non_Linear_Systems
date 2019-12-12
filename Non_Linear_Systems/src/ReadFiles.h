//
// Created by Rick Wang on 2019/12/10.
//

#ifndef NON_LINEAR_SYSTEMS_READFILES_H
#define NON_LINEAR_SYSTEMS_READFILES_H
#include "string"
#include "list"
#include "../exprtk/exprtk.hpp"

/**
 * To read the content of a txt file, store them in a list of strings and send the content to another function to analyze
 */
void ReadFromFiles();

/**
 * To analyze the content of the txt file and store the expression of the functions respectively
 */
void AnalyzeFiles(std::list<std::string>);

/**
 * To read the expression of the functions by the keyboard input
 */
void ReadFromInput();




#endif //NON_LINEAR_SYSTEMS_READFILES_H
