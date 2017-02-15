#ifndef INVALID_NODE_EXCEPTION_HPP
#define INVALID_NODE_EXCEPTION_HPP

#include <string>
#include <exception>

namespace B2W
{
    class InvalidNodeException: public std::exception
    {
    public:
        InvalidNodeException(const std::string& error);
        ~InvalidNodeException() throw();

        virtual const char* what() const throw();
        const char* trace(void) const;
        void append_backtrace(int offset = 1);

    private:
        std::string _error;
        std::string _backtrace;
    };
}

#endif // INVALID_NODE_EXCEPTION_HPP
