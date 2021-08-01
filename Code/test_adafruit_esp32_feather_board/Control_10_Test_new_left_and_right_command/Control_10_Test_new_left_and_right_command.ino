#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "cLUKk5penym7JGnFxo61dvNzG5p4y4Za";

// Your WiFi credentials.
//  Set password to "" for open networks.
char ssid[] = "lemur";
char pass[] = "lemur9473";

// Attach virtual serial terminal to Virtual Pin V1
WidgetTerminal terminal(V3);

String command = "";
// You can send commands from Terminal to your hardware. Just use
// the same Virtual Pin as your Terminal Widget
BLYNK_WRITE(V3)
{
  command = param.asStr();
  
  // Serial.write(command[2]);
  if (command[8] == 'N'){
    Serial.println("command has not been confirmed");
  }else if(command[8] == 'C'){
    Serial.println("command has been confirmed!");
  }else{
    Serial.println("Command has errors!!!");
  }
 /*
  if (command[9] == "1" || command[9] == "2" || command[9] == "3" || command[9] == "4"){
    int a = command[9].toInt();
    Serial.print("The channel is:");
    Serial.print(a);
  }else if(command[8] =='C' && (command[9] != "L" || command[9] != "R")){
    Serial.println("No direction has been specified");
  }
   */
   if (command[9] == '1'){
     int a = command[9] - '0';
     Serial.print("The channel is:");
     Serial.print(a);
   }
  // Ensure everything is sent
  terminal.flush();
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Clear the terminal content
  terminal.clear();

  // This will print Blynk Software version to the Terminal Widget when
  // your hardware gets connected to Blynk Server
  terminal.println(F("Blynk v" BLYNK_VERSION ": Device started"));
  terminal.println(F("-------------"));
  terminal.println(F("Type the command to "));
  terminal.println(F("For example: <1F2F3U4DN> or <1F2B3U4DC1L2R>"));
  terminal.flush();
}

void loop()
{
  Blynk.run();
}
