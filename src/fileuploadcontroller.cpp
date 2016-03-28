#include "fileuploadcontroller.h"

FileUploadController::FileUploadController()
{}

void FileUploadController::service(HttpRequest& request, HttpResponse& response)
{
    //we recieved post with picture to check. Lets get it from temp file
    // and copy it to app files folder in order to check it!
   if (QTemporaryFile* image = request.getUploadedFile("phototocheck") ) {
       if (QFile::exists("D:/qt/MyFirstWebApp/docroot/files/file1.png"))
       {
           QFile::remove("D:/qt/MyFirstWebApp/docroot/files/file1.png");
       }
       bool rc = image->copy("D:/qt/MyFirstWebApp/docroot/files/file1.png");
       qDebug() << "result is:" << rc ;
       if (rc ){
           int randomValue = qrand() % 10;
           if (( randomValue % 2) == 0 ){
           //some magic face detection here
           response.write("true", false);
           }
           else {
               response.write("false", false);
           }
           //or false, true if face is not detected
       }
   }
   else {
       qDebug() << "doesnt exists";
   }
}

