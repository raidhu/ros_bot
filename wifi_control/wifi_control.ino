#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "AndroidAP5F79";   //WIFI SSID //AndroidAP5F79
const char* password = "ufqg4888";    //WIFI PASSWORD //ufqg4888

/* data received from application */
String  data =""; 


/* define L298N or L293D motor control pins */
int Relay1 = 12;    //D6
int Relay2 = 16;    //D0


void setup()
{
  /* initialize motor control pins as output */
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT); 

  digitalWrite(Relay1,LOW);
  digitalWrite(Relay2,LOW);

  /* start server communication */
  Serial.begin(115200);
  connectWiFi();
  server.begin();
}

void loop()
{
    /* If the server available, run the "checkClient" function */  
    client = server.available();
    if (!client) return; 
    data = checkClient ();
Serial.print(data);
/************************ Run function according to incoming data from application *************************/

    
    if (data == "Relay1ON")
    { 
      digitalWrite(Relay1,HIGH);
      Serial.println("relay will need to on");
      }
    
    else if (data == "Relay1OFF")
    {
      digitalWrite(Relay1,LOW);
      Serial.println("relay will need to off");
      }

    else if (data == "Relay2ON")
    {
      digitalWrite(Relay2,HIGH);
      Serial.println("relay will need to on");
      }
      
    else if (data == "Relay2OFF")
    {
      digitalWrite(Relay2,LOW);
      Serial.println("relay will need to on");
      }     
} 

void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}
/********************************** RECEIVE DATA FROM the APP ******************************************/
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
