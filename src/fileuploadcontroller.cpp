#include "fileuploadcontroller.h"

FileUploadController::FileUploadController()
{}

void FileUploadController::service(HttpRequest& request, HttpResponse& response)
{
   qDebug() << "here:" << request.getHeader("Content-type");
   if (QTemporaryFile* image = request.getUploadedFile("userfile") ) {
       qDebug() << "image exists"<< image->size() << image->fileName();

       if (QFile::exists("D:/qt/MyFirstWebApp/docroot/files/file1.png"))
       {
           QFile::remove("D:/qt/MyFirstWebApp/docroot/files/file1.png");
       }
       bool rc = image->copy("D:/qt/MyFirstWebApp/docroot/files/file1.png");
       qDebug() << "result is:" << rc ;
       if (rc ){
           //some magic face detection here
           response.write("true", true);
           //or false, true if face is not detected
       }
   }
   else {
       qDebug() << "doesnt exists";
   }
}

