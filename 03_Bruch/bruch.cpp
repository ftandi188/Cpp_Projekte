#include "bruch.h"

Bruch::Bruch(int z, int n)
        :Zaehler(z), Nenner(n)
    {}


void Bruch::print(std::ostream& os){
    os << "(" << Zaehler << "/" << Nenner << ")" << std::endl;
}
