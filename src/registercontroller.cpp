#include "registercontroller.h"

RegisterController::RegisterController(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void RegisterController::service(HttpRequest &request, HttpResponse &response) {
    response.write("Hello World",true);
}

