//
// Created by Rick Wang on 2019/12/10.
//

#ifndef NON_LINEAR_SYSTEMS_READFILES_H
#define NON_LINEAR_SYSTEMS_READFILES_H
#include "string"
#include "list"
#include "exprtk/exprtk.hpp"

//the input functions should follow a specific standard
//do i need to check the balance of brackets

void ReadFromFiles();
void AnalyzeFiles(std::list<std::string>);
void ReadFromInput();
void AnalyzeFunction(std::string function);



#endif //NON_LINEAR_SYSTEMS_READFILES_H
