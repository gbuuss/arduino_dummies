
#include <SPI.h>
#include <SD.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10, 0, 0, 10);
EthernetServer server(80);

File webFile;

void setup(){
    Ethernet.begin(mac, ip);
    server.begin();
    Serial.begin(9600);

    Serial.println("Inicializando memoria SD");
    delay(2000);

    // Verificando si se puede leer la memoria SD
    if(!SD.begin(4)){
        Serial.println("Problemas al leer la tarjeta SD.");
        return;
    }else{
        Serial.println("Leyendo la memoria SD....");
        delay(2000);
    }

    // Verificando que el archivo index.htm exista en la memoria
    if(!SD.exists("index.htm")){
        Serial.println("No se pudo encontrar el archivo de inicio");
        return;
    }else{
        Serial.println("Abriendo archivo de inicio");
        delay(2000);
    }

}

void loop(){
    EthernetClient client = server.available();

    if(client){
        
    }else{
        Serial.println("No hay clientes conectados.");
    }
}