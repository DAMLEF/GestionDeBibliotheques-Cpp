//
// Created by tsalomon on 07/01/25.
//

#include "SaisieInvalide.h"

    SaisieInvalide::SaisieInvalide(const char* txt) throw(){
      this->message = txt;
     }

    const char* SaisieInvalide::what() const throw(){
      return message;
      }

