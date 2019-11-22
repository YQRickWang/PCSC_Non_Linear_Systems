//
// Created by Rick Wang on 2019/11/22.
//

#ifndef NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
#define NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H


class NonLinearSolver {
private:
    double (*funPtr)(double);
    double (*dfunPtr)(double);
public:
    NonLinearSolver();
    NonLinearSolver();
};


#endif //NON_LINEAR_SYSTEMS_NONLINEARSOLVER_H
