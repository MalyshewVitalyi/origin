#ifndef GEOMETRIC_EXCEPTION_H
#define GEOMETRIC_EXCEPTION_H

#include <stdexcept>
#include <string>

class GeometricException : public std::domain_error {
public:
    explicit GeometricException(const std::string& message) : std::domain_error(message) {}
};

#endif