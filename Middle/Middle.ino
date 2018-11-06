
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Wire.h>
#include <SPI.h>
#include "SSD1306Wire.h"

SSD1306Wire  display(0x3c, 21, 22);
//
//const char* ssid = "Sapido_RB-1602G3_d526bf";
//const char* password = "";
const char* ssid = "AndroidAP0B53";
const char* password = "123456788";
//const char* ssid = "thomas";
//const char* password = "1qaz2wsx";

const String daysOfTheWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const char * months[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
const int mounthday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
String date;
String t;
int year = 0;
int month = 0;
int week = 0;
int d = 0;
int h = 0;
int m = 0;
int s = 0;
unsigned long timer = 1000;
unsigned long count = 0;

String website;

bool ledstate = 0;

int color = 0;

WebServer server(80);

const int led[] = {4, 16, 17};
int buttonpin = 13;
int buttonstate = 1;

int ledcount = 3;
bool curbutton = 0;

void createSite() {
  website += "<!DOCTYPE html><html lang=\"en\"><head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>小夜燈世界</title> <script src=\"https://code.jquery.com/jquery-3.3.1.js\"></script> <script>$(document).ready(function(){$(\"[type=range]\").change(function(){var ledvalue=$(\"#led\").val(); $(\".ledvalue\").text(ledvalue);});}); $(document).ready(function(){$(\"[type=select]\").change(function(){var Hourvalue=$(\"#Hour\").val(); $(\".Hourvalue\").text(Hourvalue);});}); $(document).ready(function(){$(\"[type=select]\").change(function(){var Minvalue=$(\"#Date\").val(); $(\".Minvalue\").text(Minvalue);});}); $(document).ready(function(){$(\"[type=select]\").change(function(){var Monthvalue=$(\"#Month\").val(); $(\".Monthvalue\").text(Monthvalue);});}); $(document).ready(function(){$(\"[type=select]\").change(function(){var Dayvalue=$(\"#Day\").val(); $(\".Dayvalue\").text(Dayvalue);});}); </script><style>.whole1{margin:20px 10px 10px 10px; padding:10px; color:yellow; text-align:center;}.whole2{margin:30px 10px 10px 10px; padding:10px; color:yellow; text-align:center;}.whole3{margin:20px 10px 5px 10px; padding:10px; color:yellow; text-align:center;}body{background-color: black;}.container{display: flex; flex-direction: column; align-items: center;}.btn{padding: 0.3em 0.5em; font-size: 1.5em;}.btn6{padding: 0.3em 0.5em; font-size: 1.5em;}.btn7{padding: 0.3em 0.5em; font-size: 1.5em;}.btn8{padding: 0.1em 0.5em; font-size: 1.5em;}.btn9{padding: 0.1em 0.5em; font-size: 1.5em;}.btn10{padding: 0.1em 0.5em; font-size: 1.5em;}.title3{text-align: center;color:yellow;text-shadow:0px 3px 5px #000;margin-bottom:50px;}.title4{text-align: center;color:yellow;text-shadow:0px 3px 5px #000;margin-bottom:50px;}.title5{text-align: center;color:yellow;text-shadow:0px 3px 5px #000;margin-bottom:50px;}.title1{text-align:center;color:yellow;text-shadow:0px 3px 5px #000; margin-bottom: 40px;}a{display:block;text-decoration:none;background-color:#FFFFFF;radius:3px;width:150px;text-align:center;margin:0 auto;margin-bottom:30px;font-size:2em;box-shadow: 0px 3px 6px #000;}.btn1{color:black;background-color: white}.btn2{color:black;background-color: gray}.title2{text-align:center;color:yellow;text-shadow:0px 3px 5px #000; margin-bottom: 50px;}a{display:block;text-decoration:none;background-color:#FFFFFF;radius:3px;width:150px;text-align:center;margin:0 auto;margin-bottom:30px;font-size:2em;box-shadow: 0px 3px 6px #000;}.btn3{color:white;background-color: red}.btn4{color:white;background-color: rgb(252, 122, 30)}.btn5{color:white;background-color: blue}.topic{font-size: 3em; color: rgb(99, 146, 255);}</style></head> <body> <div class=\"container\"> <h1 class=\"topic\"><!-- <form> <lable> --> 小夜燈</h1> <h1 style=\"color:white;\">Time Setting</h1> <form class=\"whole1\"> <lable> <h2>日期:</h2> </lable> </form> <table> <thead> <tr> <th> <form action=\"MonDiming\" method=\"get\" id=\"Month\"> <select type=\"option\" name=\"Months\" class=\"Monthvalue\"> <option value=\"1\">01</option> <option value=\"2\">02</option> <option value=\"3\">03</option> <option value=\"4\">04</option> <option value=\"5\">05</option> <option value=\"6\">06</option> <option value=\"7\">07</option> <option value=\"8\">08</option> <option value=\"9\">09</option> <option value=\"10\">10</option> <option value=\"11\">11</option> <option value=\"12\">12</option> </select> </form> </th> <th> <lable style=\"color:white;\"> / </lable> </th> <th> <form action=\"DayDiming\" method=\"get\" id=\"Day\"> <select type=\"option\" name=\"Days\" class=\"Dayvalue\"> <option value=\"1\">01</option> <option value=\"2\">02</option> <option value=\"3\">03</option> <option value=\"4\">04</option> <option value=\"5\">05</option><!DOCTYPE html> <option value=\"6\">06</option> <option value=\"7\">07</option> <option value=\"8\">08</option> <option value=\"9\">09</option> <option value=\"10\">10</option> <option value=\"11\">11</option> <option value=\"12\">12</option> <option value=\"13\">13</option> <option value=\"14\">14</option> <option value=\"15\">15</option> <option value=\"16\">16</option> <option value=\"17\">17</option> <option value=\"18\">18</option> <option value=\"19\">19</option> <option value=\"20\">20</option> <option value=\"21\">21</option> <option value=\"22\">22</option> <option value=\"23\">23</option> <option value=\"24\">24</option> <option value=\"25\">25</option> <option value=\"26\">26</option> <option value=\"27\">27</option> <option value=\"28\">28</option> <option value=\"29\">29</option> <option value=\"30\">30</option> <option value=\"31\">31</option> </select> </form> </th> </tr></thead> </table> <br><table> <tr> <th><button type=\"submit\" form=\"Month\" value=\"MonthSubmit\" class=\"btn9\">月</button> </th> <th><button type=\"submit\" form=\"Day\" value=\"DaySubmit\" class=\"btn10\">日</button> </th> </tr></table> <form class=\"whole2\"> <lable> <h2>星期:</h2> </lable><!-- <h3 style=\"color:black;\"> <input type=\"radio\" id=\"week\" name=\"week1\" value=\"1\"> <lable for=\"1\">一</lable> <input type=\"radio\" id=\"week\" name=\"week1\" value=\"2\"> <lable for=\"2\">二</lable> <input type=\"radio\" id=\"week\" name=\"week1\" value=\"3\"> <lable for=\"3\">三</lable> <input type=\"radio\" id=\"week\" name=\"week1\" value=\"4\"> <lable for=\"4\">四</lable> <input type=\"radio\" id=\"week\" name=\"week1\" value=\"5\"> <lable for=\"5\">五</lable> <input type=\"radio\" id=\"week\" name=\"week1\" value=\"6\"> <lable for=\"6\">六</lable> <input type=\"radio\" id=\"week\" name=\"week1\" value=\"0\"> <lable for=\"7\">日</lable> </h3> --><!-- <form action=\"weekDiming\" method=\"get\" id=\"week\"> <select type=\"option\" name=\"weeks\" class=\"weekvalue\"> <option value=\"0\">Sun</option> <option value=\"1\">Mon</option> <option value=\"2\">Tue</option> <option value=\"3\">Wed</option> <option value=\"4\">Thu</option> <option value=\"5\">Fri</option> <option value=\"6\">Sat</option> </select> </form> --> <a class=\"btn8\" href=\"/week\">week</a> <form class=\"whole3\"> <lable> <h2>時間:</h2> </lable> </form> <table> <tr> <th> <form action=\"HourDiming\" method=\"get\" id=\"Hour\"> <select type=\"option\" name=\"Hours\" class=\"Hourvalue\"> <option value=\"0\">00</option> <option value=\"1\">01</option> <option value=\"2\">02</option> <option value=\"3\">03</option> <option value=\"4\">04</option> <option value=\"5\">05</option> <option value=\"6\">06</option> <option value=\"7\">07</option> <option value=\"8\">08</option> <option value=\"9\">09</option> <option value=\"10\">10</option> <option value=\"11\">11</option> <option value=\"12\">12</option> <option value=\"13\">13</option> <option value=\"14\">14</option> <option value=\"15\">15</option> <option value=\"16\">16</option> <option value=\"17\">17</option> <option value=\"18\">18</option> <option value=\"19\">19</option> <option value=\"20\">20</option> <option value=\"21\">21</option> <option value=\"22\">22</option> <option value=\"23\">23</option> </select> </form> </th> <th> <lable style=\"color:white;\"> ： </lable> </th> <th> <form action=\"timeDiming\" method=\"get\" id=\"Date\"> <select type=\"option\" name=\"Mins\" class=\"Minvalue\"> <option value=\"0\">00</option> <option value=\"1\">01</option> <option value=\"2\">02</option> <option value=\"3\">03</option> <option value=\"4\">04</option> <option value=\"5\">05</option> <option value1=\"6\">06</option> <option value=\"7\">07</option> <option value=\"8\">08</option> <option value=\"9\">09</option> <option value=\"10\">10</option> <option value=\"11\">11</option> <option value=\"12\">12</option> <option value=\"13\">13</option> <option value=\"14\">14</option> <option value=\"15\">15</option> <option value=\"16\">16</option> <option value=\"17\">17</option> <option value=\"18\">18</option> <option value=\"19\">19</option> <option value=\"20\">20</option> <option value=\"21\">21</option> <option value=\"22\">22</option> <option value=\"23\">23</option> <option value=\"24\">24</option> <option value=\"25\">25</option> <option value=\"26\">26</option> <option value=\"27\">27</option> <option value=\"28\">28</option> <option value=\"29\">29</option> <option value=\"30\">30</option> <option value=\"31\">31</option> <option value=\"32\">32</option> <option value=\"33\">33</option> <option value=\"34\">34</option> <option value=\"35\">35</option> <option value=\"36\">36</option> <option value=\"37\">37</option> <option value=\"38\">38</option> <option value=\"39\">39</option> <option value=\"40\">40</option> <option value=\"41\">41</option> <option value=\"42\">42</option> <option value=\"43\">43</option> <option value=\"44\">44</option> <option value=\"45\">45</option> <option value=\"46\">46</option> <option value=\"47\">47</option> <option value=\"48\">48</option> <option value=\"49\">49</option> <option value=\"50\">50</option> <option value=\"51\">51</option> <option value=\"52\">52</option> <option value=\"53\">53</option> <option value=\"54\">54</option> <option value=\"55\">55</option> <option value=\"56\">56</option> <option value=\"57\">57</option> <option value=\"58\">58</option> <option value=\"59\">59</option> </select> </form> </th> </tr></table> <br><table> <tr> <th> <button type=\"submit\" form=\"Hour\" value=\"HourSubmit\" class=\"btn7\">時</button> </th> <th><button type=\"submit\" form=\"Date\" value=\"timeSubmit\" class=\"btn6\">分</button></th> </tr></table> <br><br><br><h1 style=\"color:white;\">LED Setting</h1> <br><h2 style=\"color:yellow;\">亮度=<span class='ledvalue'>128</span></h2> <form action=\"ledDiming\" method=\"get\" id=\"form1\"> <input type=\"range\" name=\"ledval\" id=\"led\" min=\"0\" max=\"255\"> </form> <br><button type=\"submit\" form=\"form1\" value=\"Submit\" class=\"btn\">Submit</button> <br><br><br><h2 class=\"title1\">開關</h2> <a class=\"btn1\" href=\"/H\">ON</a> <a class=\"btn2\" href=\"/L\">OFF</a> <br><br><br><h2 class=\"title2\">顏色</h2> <a class=\"btn3\" href=\"/RED\">RED</a> <a class=\"btn4\" href=\"/ORANGE\">ORANGE</a> <a class=\"btn5\" href=\"/BLUE\">BLUE</a> </div></table></body> </html>";
}

void handleRoot() {
  server.send(200, "text/html", website);

}
void ledDiming() {
  int led_Diming = server.arg("ledval").toInt();
  ledcWrite(0, led_Diming);
  server.send(200, "text/html", website);
}
void LEDON() {
  digitalWrite(led[color], HIGH);
  server.send(200, "text/html", website);
  ledstate = 1;
  for (int i = 0; i < ledcount; i++) {
    ledcAttachPin(led[i], 1);
    if (i == color) {
      ledcAttachPin(led[i], 0);
    }
  }
}
void LEDOFF() {
  server.send(200, "text/html", website);
  digitalWrite(led[color], LOW);
  ledstate = 0;
  for (int i = 0; i < ledcount; i++) {
    ledcAttachPin(led[i], 1);
  }
}

void ledRED() {
  server.send(200, "text/html", website);
  for (int i = 0; i < ledcount; i++) {
    digitalWrite(led[i], LOW);
    if (i == 0) {
      if (ledstate) {
        digitalWrite(led[i], HIGH);
        for (int i = 0; i < ledcount; i++) {
          ledcAttachPin(led[i], 1);
          if (i == 0) {
            ledcAttachPin(led[i], 0);
          }
        }
      }
      color = i;
    }
  }
}

void ledORANGE() {
  server.send(200, "text/html", website);
  for (int i = 0; i < ledcount; i++) {
    digitalWrite(led[i], LOW);
    if (i == 1) {
      if (ledstate) {
        digitalWrite(led[i], HIGH);
        for (int i = 0; i < ledcount; i++) {
          ledcAttachPin(led[i], 1);
          if (i == 1) {
            ledcAttachPin(led[i], 0);
          }
        }
      }
      color = i;
    }
  }
}

void ledBLUE() {
  server.send(200, "text/html", website);
  for (int i = 0; i < ledcount; i++) {
    digitalWrite(led[i], LOW);
    if (i == 2) {
      if (ledstate) {
        digitalWrite(led[i], HIGH);
        for (int i = 0; i < ledcount; i++) {
          ledcAttachPin(led[i], 1);
          if (i == 2) {
            ledcAttachPin(led[i], 0);
          }
        }
      }
      color = i;
    }
  }
}

void TimeCount() {
  if (millis() - count > timer) {
    s++;
    count = millis();
  }
  t = "";
  date = "";
  if (s == 60) {
    s = 0;
    m++;
  }
  if (m == 60) {
    m = 0;
    h++;
  }
  if (h == 24) {
    h = 0;
    d++;
    week++;
  }
  if (week == 7) {
    week = 0;
  }
  if (d > mounthday[month]) {
    d = 1;
    month++;
  }
  if (month == 12) {
    month = 0;
    year++;
  }

  date += String(year);
  date += "/";
  date += String(months[month]);
  date += "/";
  if (d < 10) {
    date += "0";
  }
  date += String(d);
  date += "   ";
  date += daysOfTheWeek[week];

  if (h < 10) {
    t += "0";
  }
  t += String(h);
  t += ":";
  if (m < 10) {
    t += "0";
  }
  t += String(m);
}

void draw() {
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0 , date);
  display.setFont(ArialMT_Plain_24);
  display.drawString(35, 30 , t);
}

void buttonset() {
  if (ledstate == 0) {
    if (buttonstate == 1 && curbutton == 0) {
      Serial.println("1111");
      digitalWrite(led[color], HIGH);
      //server.send(200, "text/html",website);
      ledstate = 1;
      for (int i = 0; i < ledcount; i++) {
        ledcAttachPin(led[i], 1);
        if (i == color) {
          ledcAttachPin(led[i], 0);
        }
      }
      curbutton = buttonstate;
    }
  }

  if (ledstate == 1) {
    if (buttonstate == 1 && curbutton == 0) {
      Serial.println("0000");
      // server.send(200, "text/html",website);
      digitalWrite(led[color], LOW);
      ledstate = 0;
      for (int i = 0; i < ledcount; i++) {
        ledcAttachPin(led[i], 1);
      }
      curbutton = buttonstate;
    }
  }

  if (buttonstate == 0 && curbutton == 1) {
    curbutton = buttonstate;
  }
}

void timeset() {
  Serial.println("1");
  m = server.arg("Mins").toInt();
  //ledcWrite(0,led_Diming);
  server.send(200, "text/html", website);
  //   h=server.arg("Hours").toInt();
  //  //ledcWrite(0,led_Diming);
  //  server.send(200,"text/html",website);
  //
}

void hourset() {
  Serial.println("2");
  h = server.arg("Hours").toInt();
  //ledcWrite(0,led_Diming);
  server.send(200, "text/html", website);

}
void Monset() {
  Serial.println("4");
  month = server.arg("Months").toInt() - 1;
  //ledcWrite(0,led_Diming);
  server.send(200, "text/html", website);

}
void Dayset() {
  Serial.println("5");
  d = server.arg("Days").toInt();
  //ledcWrite(0,led_Diming);
  server.send(200, "text/html", website);

}
void weekset() {
  Serial.println("3");
  week++;
  if (week == 7) {
    week = 0;
  }
  //ledcWrite(0,led_Diming);
  server.send(200, "text/html", website);

}

void handleNotFound() {
  //Serial.print("12345");
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  pinMode(buttonpin, INPUT);
  digitalWrite(buttonpin, HIGH);
  for (int i = 0; i < ledcount; i++) {
    pinMode(led[i], OUTPUT);
  }
  ledcSetup(0, 5000, 8);
  ledcWrite(0, 128);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  createSite();
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/timeDiming", timeset);
  server.on("/HourDiming", hourset);
  server.on("/week", weekset);
  server.on("/MonDiming", Monset);
  server.on("/DayDiming", Dayset);
  server.on("/", handleRoot);
  server.on("/H", LEDON);
  server.on("/L", LEDOFF);
  server.on("/RED", ledRED);
  server.on("/ORANGE", ledORANGE);
  server.on("/BLUE", ledBLUE);
  server.on("/ledDiming", ledDiming);
  server.on("/inline", []() {
    server.send(200, "text/html", website);
  });

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");

  display.init();//初始化(init)
  display.setContrast(255); //數值介於0~255，調整對比
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.clear();//清除螢幕和緩衝區(clear)
  display.display();
  year = 2018;
  month = 0;
  d = 1;
  week = 0;
  h = 0;
  m = 0;
  s = 0;

}

void loop(void) {
  buttonstate = digitalRead(buttonpin);
  display.clear();
  TimeCount();
  draw();
  display.display();
  buttonset();
  server.handleClient();


}
