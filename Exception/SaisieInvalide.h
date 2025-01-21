
# ifndef SAISIEINVALIDE_H
#define SAISIEINVALIDE_H

#include <iostream>

using namespace std;

class SaisieInvalide final : public exception {
    private:
    const char* message;
    public:
        explicit SaisieInvalide(const char* txt) noexcept;
        const char *what() const noexcept override;
};



#endif
