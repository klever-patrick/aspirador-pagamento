void atualizarEvento()
{
  lerAnalogicoD1();
  lerAnalogicoD2();
  lerAnalogicoD2();

  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    entregaEventoPino();
  }
}

void consultaEvento()
{
  WiFiClient client;
  HTTPClient http;
  Serial.print("[HTTP] begin entrega...\n");
  String host ="http://fribrilld.atwebpages.com/public/api/evento/apagar/teste/" + String(globalEventoAPI);
  Serial.print(host);
  if (http.begin(client, host.c_str())) {  // HTTP
      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          globalEventoAPI = payload.toInt();
          globalEventoEntregar = 0;
          Serial.println(payload);
        }
      } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  } else {
    Serial.printf("[HTTP} Unable to connect\n");
  }
}

void entregaEvento()
{
  WiFiClient client;
  HTTPClient http;
  Serial.print("[HTTP] begin...\n");
  if (http.begin(client, "http://fribrilld.atwebpages.com/public/api/evento/proximo/teste")) {  // HTTP
    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();
        globalEventoAPI = payload.toInt();
        if(!(globalEventoAPI == 0)){
          globalEventoEntregar = 1;
        }
        Serial.println(payload);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  } else {
    Serial.printf("[HTTP} Unable to connect\n");
  }
}


void entregaEventoPino()
{
  //WiFiClient client;
  //HTTPClient http;
  //Serial.print("[HTTP] begin entrega...\n");
  //String host ="https://admin.lowhanna.com.br/equipamento/1.php?token=t1t2t3&d1=" 
  //+ String(globalPinoD1) + "&d2=" + String(globalPinoD2)+ "&d3=" + String(globalPinoD3);
  //Serial.print(host);
  //if (http.begin(client, host.c_str())) {  // HTTP
    
      
    
  //} else {
  //  Serial.printf("[HTTP} Unable to connect\n");
  //}



  HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");
        String d1 = String(globalPinoD1);
        String d2 = String(globalPinoD2);
        String d3 = String(globalPinoD3);
        String host ="https://admin.lowhanna.com.br/equipamento/1.php?token=t1t2t3&d1=" +
        d1 +
        "&d2=" + d2 + 
        "&d3=" + d1;

        //char host[]= "https://admin.lowhanna.com.br/equipamento/1.php?token=t1t2t3&d1=" 
        //sprintf(host,"d1%",globalPinoD1);
        //"&d2=" + d2
        //"&d3=" + d1;
        
        // configure traged server and url
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        USE_SERIAL.println(host);
        http.begin(host); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                USE_SERIAL.println(payload);
                USE_SERIAL.print("d1 = ");
                USE_SERIAL.print(d1);
                USE_SERIAL.print(" d2 = ");
                USE_SERIAL.print(d2);
                USE_SERIAL.print(" d3 = ");
                USE_SERIAL.println(d3);
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
}
