#ifndef LIMITEATTEINTE_H
#define LIMITEATTEINTE_H
#include <iostream>
using namespace std;


class LimiteAtteinte : public exception{
  private :
    const char* message;
  public :
    explicit LimiteAtteinte(const char* message) noexcept;
    const char *what() const noexcept override;

};



#endif //LIMITEATTEINTE_H
