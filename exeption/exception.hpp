#include <string>

class Exception {
public:
    Exception();
    Exception(std::string message);
    std::string getMessage();

protected:
    std::string exception_message;
};