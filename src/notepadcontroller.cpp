#include "notepadcontroller.h"

notepadController::notepadController(QObject* parent)
    : HttpRequestHandler(parent) {
     email = "";
     data = "";
     action = "";

}

void notepadController::service(HttpRequest& request, HttpResponse& response){
    email = request.getParameter("email");
    action = request.getParameter("action");

    if (action == "get") {

        //open file or create new with email
        //read from file to data
        qDebug() << "sending text to user";
        data = "hello my dear friend! this text is from you notepad";
        response.write(data, true);
    }
    else {
       data = request.getParameter("action");
       if (data != 0){
           //open file
           //write to it
           //close
           response.write("true", true);
           qDebug() << "getting text from user";
       }
    }




}

