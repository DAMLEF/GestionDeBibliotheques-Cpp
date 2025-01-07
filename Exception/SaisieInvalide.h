//
// Created by tsalomon on 07/01/25.
//

#ifndef SAISIEINVALIDE_H
#define SAISIEINVALIDE_H
#include <iostream>
using namespace std;

class SaisieInvalide : public exception {
    private:
        const char* message;
    public:
        SaisieInvalide(const char* txt) throw();
        virtual const char* what() const throw();
};



#endif //SAISIEINVALIDE_H
