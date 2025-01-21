
# include "SaisieInvalide.h"

SaisieInvalide::SaisieInvalide(const char* txt) noexcept{
  this->message = txt;
 }

const char *SaisieInvalide::what() const noexcept{
  return message;
  }

