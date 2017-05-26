/* ESP Libraries */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <time.h>
#include "Webpage.h"
//#include "SetupHTML.h"
#include "LEDDefs.h"
//#include <FS.h>


const char* ssid		= "YOURSSID";
const char* password	= "YOURWIFIPASSWORD";
const char* host		= "time.nist.gov"; 

struct tm * ptm;
time_t t;
bool bAlarmActive		= false;
uint8_t wakeUpHour		= 6;
uint8_t wakeUpMinute	= 40;


ESP8266WebServer webserver(80);
//String web = String(website);
//String setuphtml = String(setup_html);


void handleNotFound() {
	 String message = "File Not Found\n\n";
	 message += "URI: ";
	 message += webserver.uri();
	 message += "\nMethod: ";
	 message += (webserver.method() == HTTP_GET) ? "GET" : "POST";
	 message += "\nArguments: ";
	 message += webserver.args();
	 message += "\n";
	 for (uint8_t i = 0; i<webserver.args(); i++) {
		 message += " " + webserver.argName(i) + ": " + webserver.arg(i) + "\n";
	 }
	 webserver.send(404, "text/html", message);
 }

void Index_html()
 {
	
	webserver.send(200, "text/html", website);
	//	webserver.send(200, "text/html", setuphtml);
 }

void Setup_html()
{
	//webserver.send(200, "text/html", setuphtml);
	webserver.send(200, "text/html", "TEST");
}

void handleRequest()
{
	String message = "";
	lastHSV = currentHSV;

	for (uint8_t i = 0; i<webserver.args(); i++) {

		message += webserver.argName(i) + ": " + webserver.arg(i) + "\n";
		
		uint8_t nCurrentValue	= (uint8_t)webserver.arg(i).toInt();
		String strArgument		= webserver.argName(i);
	
		if (strArgument == "hsv" && webserver.arg(i) == "?")
		{
			webserver.send(200, "application/json",     "{ \"h\" : " + String(currentHSV.hue, 10) + 
														",\"s\" : " + String(currentHSV.sat, 10) + 
													    ",\"v\" : " + String(currentHSV.val, 10) + 
													    "}");
		}
		else if (strArgument == "hue")
		{
				currentHSV.hue = nCurrentValue;
				webserver.send(200, "text/plain", message);
		}
		else if (strArgument == "sat")
		{
				currentHSV.sat = nCurrentValue;
				webserver.send(200, "text/plain", message);
		}
		else if (strArgument == "val")
		{

				currentHSV.val = nCurrentValue;
				webserver.send(200, "text/plain", message);
		}
		else if(strArgument == "ChangeState")
		{
			if (webserver.arg(i) == "Sunrise")
			{
				nSpeed = SPEED_SEC;
				nSteps = 0;
				currentLightState = Sunrise;
				sunTransitionState = Sunrise;
				webserver.send(200, "text/plain", message);
			}
			else if (webserver.arg(i) == "Sunset")
			{
				nSpeed = SPEED_SEC;
				nSteps = 0;
				currentLightState = Sunset;
				sunTransitionState = Sunset;
				webserver.send(200, "text/plain", message);
			}
			else if (webserver.arg(i) == "Off")
			{
				currentLightState = Off;
				nSpeed = 1;
				webserver.send(200, "text/plain", message);
			}
			else
			{

			}
			Serial.println(message);
		}
		else if (strArgument == "Wecker")
		{
			String wecker = webserver.arg(i);
			int idx = wecker.indexOf(":");
			if (wecker.indexOf("?") == -1)
			{
				if (idx != -1)
				{
					wakeUpHour = (uint8_t)wecker.substring(0, idx).toInt();
					wakeUpMinute = (uint8_t)wecker.substring(idx + 1).toInt();
					bAlarmActive = true;
					Serial.println("Wecker stellen auf:" + String(wakeUpHour, 10) + ":" + String(wakeUpMinute, 10) + "Uhr");
					webserver.send(200, "text/plain", message);
				}
				else
				{
					bAlarmActive = false;
					webserver.send(200, "text/plain", message);
				}
			}
			else
			{
				webserver.send(200, "application/json","{ \"hour\" : " +  String(wakeUpHour, 10) + ",\"minute\" : " + String(wakeUpMinute, 10) + "}");
			}
			

		}
		else if (strArgument == "Nachtlicht")
		{
			if (webserver.arg(i) == "Sybi")
			{
				nSpeed = SPEED_SEC;
				nSteps = 0;
				currentLightState = ReadingLightSybi;
				webserver.send(200, "text/plain", message);
			}
			else if (webserver.arg(i) == "Michi")
			{
				nSpeed = SPEED_SEC;
				nSteps = 0;
				currentLightState = ReadingLightMichi;
				webserver.send(200, "text/plain", message);
			}
		}
	}

	

	if (lastHSV != currentHSV)
	{
		currentLightState = DoNothing;
		fill_solid(&(leds[0]), NUM_LEDS, currentHSV);
		FastLED.show();

		Serial.println("H = " + String(currentHSV.hue, DEC));
		Serial.println("S = " + String(currentHSV.sat, DEC));
		Serial.println("V = " + String(currentHSV.val, DEC));
	}



}

void timer0_ISR (void) {
  
    
    t   = time(NULL);
    ptm = gmtime( &t );

    switch(currentLightState) 
    {
      case Sunrise:
		
		//TODO: Smooth transition to start values 
		if (currentHSV.hue >= HUE_SUNRISE_TARGET) currentHSV.hue = HUE_SUNRISE_TARGET;
        if(currentHSV == SUNRISE_TARGET) {
          currentLightState = DoNothing;
          Serial.println("Sunrise Target Reached.");
        } 
        else
        {
			lastLightState	  = currentLightState;
			currentLightState = Set;
			nSteps++;
			lastHSV = currentHSV;
			if ((nSteps % 1) == 0 && currentHSV.hue != HUE_SUNRISE_TARGET) currentHSV.hue++;
			if ((nSteps % 16) == 0 && currentHSV.sat != SAT_SUNRISE_TARGET) currentHSV.sat--;
			if ((nSteps % 2) == 0 && currentHSV.val != VAL_SUNRISE_TARGET) currentHSV.val++;

        }
      break;
      case Sunset:
		 //TODO: Smooth transition to start values 
		if (currentHSV.hue <= HUE_SUNSET_TARGET) currentHSV.hue = HUE_SUNSET_TARGET;

        if(currentHSV == SUNSET_TARGET) {
            currentLightState = DoNothing;
            Serial.println("Sunset Target Reached.");
        } 
        else
        {
			lastLightState = currentLightState;
			currentLightState = Set;
			nSteps++;
			lastHSV = currentHSV;
			if ((nSteps % 4) == 0 && currentHSV.hue != HUE_SUNSET_TARGET) currentHSV.hue--;
			if ((nSteps % 1) == 0 && currentHSV.sat != SAT_SUNSET_TARGET) currentHSV.sat++;
			if ((nSteps % 1) == 0 && currentHSV.val != VAL_SUNSET_TARGET) currentHSV.val--;
        }
      break;   
      case Set:
           // TODO: Transition ....
          currentLightState = lastLightState;

		  fill_solid(&(leds[0]), NUM_LEDS, currentHSV);
		  FastLED.show();

		  //Serial.print("H:");   Serial.print(currentHSV.hue);
		  //Serial.print(" S:");  Serial.print(currentHSV.sat);
		  //Serial.print(" V:");  Serial.print(currentHSV.val);
		  //Serial.print("\n");
		  //Serial.print(nSteps); Serial.print("\n");

          break;        
      
      case DoNothing:

		if (((ptm->tm_hour + 1) % 24 == wakeUpHour) && (ptm->tm_min >= wakeUpMinute) && bAlarmActive == true) {
		  nSpeed = SPEED_SEC;
          currentLightState  = Sunrise;
          sunTransitionState = currentLightState;
		  bAlarmActive = false;
        }
		/*
		if ((ptm->tm_hour + 1) % 24 == wakeUpHour + 1)
		{
			bAlarmStarted = false;
		}
		*/
        nSteps = 0;
        break;

	  case ReadingLightSybi:
		  currentLightState = DoNothing;
		  Serial.println("ReadingLightSybi");
		  fill_gradient(&(leds[0]), 15, CHSV(10, 255, 100), CHSV(20, 200, 100));
		  fill_gradient(&(leds[16]), 15, CHSV(20, 200, 100), CHSV(10, 255, 100));
		  FastLED.show();

		  break;

	  case ReadingLightMichi:
		  currentLightState = DoNothing;
		  Serial.println("ReadingLightMichi");
		  fill_gradient(&(leds[NUM_LEDS-32]), 15, CHSV(10, 255, 100), CHSV(20, 200, 100));
		  fill_gradient(&(leds[NUM_LEDS-16]), 15, CHSV(20, 200, 100), CHSV(10, 255, 100));
		  FastLED.show();
		  break;
      case Off:
		lastHSV = currentHSV;
        if(currentHSV.val == 0) {
          currentLightState = DoNothing;
		  lastLightState = DoNothing;
		  currentHSV = SUNSET_TARGET;
        }
		else
		{
			currentHSV.val--;
			currentLightState = Set;
			lastLightState = Off;
		}
        break; 
           
      default:
        break;
      
    }


	/*fill_solid( &(leds[0]),NUM_LEDS,CHSV(hue,sat,val));
	blur1d(&(leds[0]), NUM_LEDS, 64);
    FastLED.show();
	*/

    timer0_write(ESP.getCycleCount() +  nSpeed * 5000000L); // 80MHz == 1sec
    
}

void setup() {
  noInterrupts();

  
  Serial.begin(115200);
  delay(10);
 
  FastLED.addLeds<WS2812B,PIN, GRB>(leds, NUM_LEDS);
  // prepare GPIO2
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, 0);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  WiFi.printDiag(Serial);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    digitalWrite(BUILTIN_LED, !digitalRead(BUILTIN_LED));
  }
  digitalWrite(BUILTIN_LED, 1);

  if (MDNS.begin("AmbientESP2")) {
	  Serial.println("MDNS responder started");
  }

 
  // Start the server
  webserver.onNotFound(handleNotFound);
  webserver.on("/", Index_html);
  //webserver.on("/setup.html", Setup_html);
  webserver.on("/set.php", HTTP_POST, handleRequest);
  webserver.begin();
  Serial.println("HTTP server started");

  // Print the IP address
  Serial.println(WiFi.localIP());

  currentLightState = Set;
  lastLightState	= DoNothing;
  nSpeed			= SPEED_SEC;
  
  /* Konfiguriere Uhrzeit */
  configTime(86400, 0, "time.windows.com", "de.pool.ntp.org", "time.nist.gov");

  timer0_isr_init();
  timer0_attachInterrupt(timer0_ISR);
  timer0_write(ESP.getCycleCount() + 640000000L); // 80MHz == 1sec

  interrupts();
}

void loop() {

  webserver.handleClient();
 
}

