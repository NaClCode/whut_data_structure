#include "../../include/exception/gameException.h"
GameException::GameException(QString exception){
    this->exception = exception;
};
const char * GameException::what () const throw (){
    return this->exception.toUtf8().constData();
};
