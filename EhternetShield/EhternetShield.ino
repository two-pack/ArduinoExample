#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};  // for local network.
const char server[] = "192.168.11.4"; // local web server
const int LED = 7;

EthernetClient client;

const int BUF_DATA_SIZE = 100;
char buf[BUF_DATA_SIZE];
int pos = 0;

void connectServer() {
  if(client.connect(server, 80)) {
    Serial.println("Connected.");
    client.println("GET /~twopack/cgi-bin/test.cgi HTTP/1.0");
    client.println("Host: 192.168.11.4");
    client.println("Connection: close");
    client.println("");
  } else {
    Serial.println("Failed to connect.");
  }
}

void switchLED(int led) {
  if(led == 0) {
    digitalWrite(LED, LOW);
  } else if(led == 1) {
    digitalWrite(LED, HIGH);
  }
}

int analyze(char *data) {
  Serial.print(data);
  if(strlen(data) == strlen("led:0\n")) {
    char led = data[4];
    data[4] = '\0';
    if(strcmp(data, "led:") == 0) {
      if(led == '0') {
        return 0;
      } else if(led == '1') {
        return 1;
      } 
    }
  }
  return -1;
}

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
  if(Ethernet.begin(mac) == 0) {
    Serial.println("Failed to get ipaddress by DHCP.");
    while(1); // stop
  }
  delay(1000);
}

void loop() {
  if(client.available()) {
    buf[pos] = client.read();
    if(buf[pos] == '\n') {
      buf[pos + 1] = '\0';
      int led = analyze(buf);
      if(led == 1 || led == 0) {
        switchLED(led);
      }
      pos = 0;
    } else {
      pos++;
      if(pos >= BUF_DATA_SIZE) {
        pos = 0;  // through unknown data.
      }
    }
  }     

  if(!client.connected()) {
    Serial.println("Disconnecting.");
    client.stop();
    
    delay(1000);
    connectServer();
  }
}
