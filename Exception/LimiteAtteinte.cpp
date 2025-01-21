# include "LimiteAtteinte.h"

LimiteAtteinte::LimiteAtteinte(const char* txt) noexcept{
    this->message = txt;
}

const char *LimiteAtteinte::what() const noexcept{
    return message;
}

