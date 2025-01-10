#include <exception>
#include <QString>
class GameException: public std::exception{
private:
    QString exception;
public:
    GameException(QString exception);
    const char * what () const throw ();
};
