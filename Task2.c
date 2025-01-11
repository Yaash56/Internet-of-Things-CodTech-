#define BLYNK_TEMPLATE_ID &quot;YourTemplateId&quot; //blynk template ID
#define BLYNK_TEMPLATE_NAME &quot;YourTemplateName &quot; //blynk template  name
#define BLYNK_AUTH_TOKEN &quot;4ANo-vG6TpPOvyXdbZgxBBLCVz976NmB&quot; // enter your blynk auth token
 
#define BLYNK_PRINT Serial
#include &lt;gpio.h&gt;
#include &lt;ESP8266WiFi.h&gt;
#include &lt;BlynkSimpleEsp8266.h&gt;
 
char auth[] = BLYNK_AUTH_TOKEN;
 
char ssid[] = &quot;YouWifiName&quot;; // Your Wifi Name
char pass[] = &quot;YourWifiPasword&quot;; // Your Wifi Password
 
//in the below code, we have set all values reverse
//For value==1, digitalWrite is &quot;LOW&quot; as the realy module is active &quot;LOW&quot; to turn device ON.
//For value==0, digitalWrite is &quot;HIGH&quot; as Optocoupler based relay is turned OFF when HIGH Input is given
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D0, LOW); 
    Serial.println(&quot;LED ON&quot;); //Setting Digital PIN as LOW to turn ON Device if relay module is &quot;active low&quot;
  }
  if(value == 0)
  {
     digitalWrite(D0, HIGH);
     Serial.println(&quot;LED OFF&quot;);//Setting Digital PIN as HIGH to turn OFF Device if relay module is &quot;active low&quot;
  }
}
 
BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D1, LOW);
    Serial.println(&quot;LED ON&quot;);
  }
  if(value == 0)
  {
     digitalWrite(D1, HIGH);  
     Serial.println(&quot;LED OFF&quot;);
  }
}
 
BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D2, LOW);
    Serial.println(&quot;LED ON&quot;);
  }
  if(value == 0)
  {
     digitalWrite(D2, HIGH);
     Serial.println(&quot;LED OFF&quot;);
  }
}
 
BLYNK_WRITE(V4)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D3, LOW);
    Serial.println(&quot;LED ON&quot;);
  }
  if(value == 0)
  {
     digitalWrite(D3, HIGH);
     Serial.println(&quot;LED OFF&quot;);
  }
}
 
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT); //GPIO 16 (equivalent to PIN 16 of Arduino)
  pinMode(D1,OUTPUT); //GPIO 05 (equivalent to PIN 05 of Arduino)
  pinMode(D2,OUTPUT);//GPIO 04 (equivalent to PIN 16 of Arduino)
  pinMode(D3,OUTPUT);//GPIO 00 (equivalent to PIN 00 of Arduino)
}
 
void loop()
{
  Blynk.run();