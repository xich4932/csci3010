#include <iostream>
#include <string>

#include "Emotion.h"

Emotion::counter = 0;

std::ostream& operator<<(std::ostream &os, const Emotion &d) {
    os << d.get_name();
    // TODO: print out more information if you want to
    return os;
}

