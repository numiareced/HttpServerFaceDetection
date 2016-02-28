#ifndef REGISTERCONTROLLER_H
#define REGISTERCONTROLLER_H
#include "httprequesthandler.h"

class RegisterController : public HttpRequestHandler {
    Q_OBJECT
public:
    RegisterController(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // REGISTERCONTROLLER_H
