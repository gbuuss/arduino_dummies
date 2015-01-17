
#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;
int cont = 0;

void setup(){
    Serial.begin(9600);
    Serial.println("Inicializando tarjeta SD.");

    if(!SD.begin(chipSelect)){
        Serial.println("Problemas al cargar la tarjeta SD.");
        return;
    }else{
        Serial.println("Se carga la tarjeta SD correctamente.");
    }
}

void loop(){
    cont ++;
    String dataString = String(cont) + ", " + String(millis());
    File dataFile     = SD.open("test.txt", FILE_WRITE);

    if(dataFile){
        dataFile.println(dataString);
        dataFile.close();
        Serial.println(dataString);
    }else{
        Serial.println("Error al abrir el archivo.");
    }
}