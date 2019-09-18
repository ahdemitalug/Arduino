#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  WiFi.begin("OnePlus 6", "medha123"); //Connect to your router
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("Type this IP in your browser:");
  Serial.println((WiFi.localIP().toString()));                  //Your IP address, the URL to visit
  
  server.on ( "/", handleRoot );                                //Event handling function attachment
  server.onNotFound ( handleNotFound );

  server.begin();                                               //Begin the server
  Serial.println("HTTP server started");
}

void loop() {
 server.handleClient();       
}

void handleRoot() {
  server.send ( 200, "text/html", getPage() );
}

String getPage() {
  String page ="<!DOCTYPE html>\n<html>\n<title>W3.CSS Template</title>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n<link rel=\"stylesheet\" href=\"https://www.w3schools.com/w3css/4/w3.css\">\n<link rel='stylesheet' href='https://fonts.googleapis.com/css?family=Roboto'>\n<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css\">\n<style>\nhtml,body,h1,h2,h3,h4,h5,h6 {font-family: \"Roboto\", sans-serif}\n</style>\n<body class=\"w3-light-grey\">\n\n<!-- Page Container -->\n<div class=\"w3-content w3-margin-top\" style=\"max-width:1400px;\">\n\n  <!-- The Grid -->\n  <div class=\"w3-row-padding\">\n  \n    <!-- Left Column -->\n    <div class=\"w3-third\">\n    \n      <div class=\"w3-white w3-text-grey w3-card-4\">\n        <div class=\"w3-display-container\">\n          <img src=\"/w3images/avatar_hat.jpg\" style=\"width:100%\" alt=\"Avatar\">\n          <div class=\"w3-display-bottomleft w3-container w3-text-black\">\n            <h2>Jane Doe</h2>\n          </div>\n        </div>\n        <div class=\"w3-container\">\n          <p><i class=\"fa fa-briefcase fa-fw w3-margin-right w3-large w3-text-teal\"></i>Designer</p>\n          <p><i class=\"fa fa-home fa-fw w3-margin-right w3-large w3-text-teal\"></i>London, UK</p>\n          <p><i class=\"fa fa-envelope fa-fw w3-margin-right w3-large w3-text-teal\"></i>ex@mail.com</p>\n          <p><i class=\"fa fa-phone fa-fw w3-margin-right w3-large w3-text-teal\"></i>1224435534</p>\n          <hr>\n\n          <p class=\"w3-large\"><b><i class=\"fa fa-asterisk fa-fw w3-margin-right w3-text-teal\"></i>Skills</b></p>\n          <p>Adobe Photoshop</p>\n          <div class=\"w3-light-grey w3-round-xlarge w3-small\">\n            <div class=\"w3-container w3-center w3-round-xlarge w3-teal\" style=\"width:90%\">90%</div>\n          </div>\n          <p>Photography</p>\n          <div class=\"w3-light-grey w3-round-xlarge w3-small\">\n            <div class=\"w3-container w3-center w3-round-xlarge w3-teal\" style=\"width:80%\">\n              <div class=\"w3-center w3-text-white\">80%</div>\n            </div>\n          </div>\n          <p>Illustrator</p>\n          <div class=\"w3-light-grey w3-round-xlarge w3-small\">\n            <div class=\"w3-container w3-center w3-round-xlarge w3-teal\" style=\"width:75%\">75%</div>\n          </div>\n          <p>Media</p>\n          <div class=\"w3-light-grey w3-round-xlarge w3-small\">\n            <div class=\"w3-container w3-center w3-round-xlarge w3-teal\" style=\"width:50%\">50%</div>\n          </div>\n          <br>\n\n          <p class=\"w3-large w3-text-theme\"><b><i class=\"fa fa-globe fa-fw w3-margin-right w3-text-teal\"></i>Languages</b></p>\n          <p>English</p>\n          <div class=\"w3-light-grey w3-round-xlarge\">\n            <div class=\"w3-round-xlarge w3-teal\" style=\"height:24px;width:100%\"></div>\n          </div>\n          <p>Spanish</p>\n          <div class=\"w3-light-grey w3-round-xlarge\">\n            <div class=\"w3-round-xlarge w3-teal\" style=\"height:24px;width:55%\"></div>\n          </div>\n          <p>German</p>\n          <div class=\"w3-light-grey w3-round-xlarge\">\n            <div class=\"w3-round-xlarge w3-teal\" style=\"height:24px;width:25%\"></div>\n          </div>\n          <br>\n        </div>\n      </div><br>\n\n    <!-- End Left Column -->\n    </div>\n\n    <!-- Right Column -->\n    <div class=\"w3-twothird\">\n    \n      <div class=\"w3-container w3-card w3-white w3-margin-bottom\">\n        <h2 class=\"w3-text-grey w3-padding-16\"><i class=\"fa fa-suitcase fa-fw w3-margin-right w3-xxlarge w3-text-teal\"></i>Work Experience</h2>\n        <div class=\"w3-container\">\n          <h5 class=\"w3-opacity\"><b>Front End Developer / w3schools.com</b></h5>\n          <h6 class=\"w3-text-teal\"><i class=\"fa fa-calendar fa-fw w3-margin-right\"></i>Jan 2015 - <span class=\"w3-tag w3-teal w3-round\">Current</span></h6>\n          <p>Lorem ipsum dolor sit amet. Praesentium magnam consectetur vel in deserunt aspernatur est reprehenderit sunt hic. Nulla tempora soluta ea et odio, unde doloremque repellendus iure, iste.</p>\n          <hr>\n        </div>\n        <div class=\"w3-container\">\n          <h5 class=\"w3-opacity\"><b>Web Developer / something.com</b></h5>\n          <h6 class=\"w3-text-teal\"><i class=\"fa fa-calendar fa-fw w3-margin-right\"></i>Mar 2012 - Dec 2014</h6>\n          <p>Consectetur adipisicing elit. Praesentium magnam consectetur vel in deserunt aspernatur est reprehenderit sunt hic. Nulla tempora soluta ea et odio, unde doloremque repellendus iure, iste.</p>\n          <hr>\n        </div>\n        <div class=\"w3-container\">\n          <h5 class=\"w3-opacity\"><b>Graphic Designer / designsomething.com</b></h5>\n          <h6 class=\"w3-text-teal\"><i class=\"fa fa-calendar fa-fw w3-margin-right\"></i>Jun 2010 - Mar 2012</h6>\n          <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. </p><br>\n        </div>\n      </div>\n\n      <div class=\"w3-container w3-card w3-white\">\n        <h2 class=\"w3-text-grey w3-padding-16\"><i class=\"fa fa-certificate fa-fw w3-margin-right w3-xxlarge w3-text-teal\"></i>Education</h2>\n        <div class=\"w3-container\">\n          <h5 class=\"w3-opacity\"><b>W3Schools.com</b></h5>\n          <h6 class=\"w3-text-teal\"><i class=\"fa fa-calendar fa-fw w3-margin-right\"></i>Forever</h6>\n          <p>Web Development! All I need to know in one place</p>\n          <hr>\n        </div>\n        <div class=\"w3-container\">\n          <h5 class=\"w3-opacity\"><b>London Business School</b></h5>\n          <h6 class=\"w3-text-teal\"><i class=\"fa fa-calendar fa-fw w3-margin-right\"></i>2013 - 2015</h6>\n          <p>Master Degree</p>\n          <hr>\n        </div>\n        <div class=\"w3-container\">\n          <h5 class=\"w3-opacity\"><b>School of Coding</b></h5>\n          <h6 class=\"w3-text-teal\"><i class=\"fa fa-calendar fa-fw w3-margin-right\"></i>2010 - 2013</h6>\n          <p>Bachelor Degree</p><br>\n        </div>\n      </div>\n\n    <!-- End Right Column -->\n    </div>\n    \n  <!-- End Grid -->\n  </div>\n  \n  <!-- End Page Container -->\n</div>\n\n<footer class=\"w3-container w3-teal w3-center w3-margin-top\">\n  <p>Find me on social media.</p>\n  <i class=\"fa fa-facebook-official w3-hover-opacity\"></i>\n  <i class=\"fa fa-instagram w3-hover-opacity\"></i>\n  <i class=\"fa fa-snapchat w3-hover-opacity\"></i>\n  <i class=\"fa fa-pinterest-p w3-hover-opacity\"></i>\n  <i class=\"fa fa-twitter w3-hover-opacity\"></i>\n  <i class=\"fa fa-linkedin w3-hover-opacity\"></i>\n  <p>Powered by <a href=\"https://www.w3schools.com/w3css/default.asp\" target=\"_blank\">w3.css</a></p>\n</footer>\n\n</body>\n</html>\n";
  return page;
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }

  server.send ( 404, "text/plain", message );
}
