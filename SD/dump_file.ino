
#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;

void setup(){
    Serial.begin(9600);
    Serial.println("Inicializando tarjeta SD.");

    if(!SD.begin(chipSelect)){
        Serial.println("Problemas al cargar la tarjeta SD.");
        return;
    }else{
        Serial.println("Se carga la tarjeta SD correctamente.");
    }

    File file = SD.open("test.txt");

    if(file){
        while(file.available()){
            Serial.write(file.read());
        }
        file.close();
    }else{
        Serial.println("Error al abrir el archivo");
    }
}

void loop(){
    
}