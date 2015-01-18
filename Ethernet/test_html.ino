

#include <SPI.h>
#include <SD.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(10, 0, 0, 10);
EthernetServer server(80);

void setup() {
    Ethernet.begin(mac, ip);
    server.begin();

    if(!SD.begin(4)){
        return;
    }
}

void loop() {
    // listen for incoming clients
    EthernetClient client = server.available();

    if (client) {
        while (client.connected()) {
            if (client.available()) {
                client.println("HTTP/1.1 200 OK");
                client.println("Content-Type: text/html");
                client.println();

                File file = SD.open("heart.txt");

                if(file){
                    while(file.available()){
                        client.print("<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><title>Leyendo archivos</title></head><body><h1>Leyendo archivo desde SD</h1><blockquote>");
                        client.write(file.read());
                        client.print("</blockquote></body></html>");
                    }
                    
                    file.close();
                }

                break;
            }
        }
        // Stop conecction
        client.stop();
    }
}