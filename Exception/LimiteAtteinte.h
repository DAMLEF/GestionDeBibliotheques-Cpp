//
// Created by tsalomon on 07/01/25.
//

#ifndef LIMITEATTEINTE_H
#define LIMITEATTEINTE_H
#include <iostream>
using namespace std;


class LimiteAtteinte : public exception{
  private :
    const char* message;
  public :
    LimiteAtteinte(const char* message) throw();
    virtual const char* what() const throw();

};



#endif //LIMITEATTEINTE_H
