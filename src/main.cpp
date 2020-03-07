/*
 *     06-dht.cpp
 *         Se trata de obtener los valores de humedad y temperatura
 *         de sensores de la serie DHTxx
 *
 *         Requiere las siguientes bibliotecas:
 *         - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
 *         - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
 */

#include <Adafruit_Sensor.h>
#include <DHT.h>

/*
 *  Definiciones de constantes
 *      Definiciones en platformio.ini
 *      DHTPIN      IOPort donde DHTxx data esta conectado
 *      DHTTYPE     Constante que define el tipo de sensor:
 *          DHT11 o DHT21 o DHT22
 *      SERIAL_BAUD Baud rate del port serie
 */

DHT dht(DHTPIN, DHTTYPE); // Inicializacion sensor DHT

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    Serial.printf( "\n\r\nDHT%d test!\n\r", DHTTYPE);
    dht.begin();
}

void
loop()
{
    float h, t, f;

    delay(2000); // Las lecturas en este sensor son muy lentas

    h = dht.readHumidity();
    t = dht.readTemperature();     // en grados Celsius
    f = dht.readTemperature(true); // en grados Fahrenheit

    if (isnan(h) || isnan(t) || isnan(f)) //    verificar si cualquiera de las lecturas fracasaron
        Serial.printf("Error de lectura del sensor DHT%d\n\r", DHTTYPE );
    else
        Serial.printf( "DHT%d -> Humedad: %5.1f %% Temperatura: %5.1f °C | %5.1f °F\n\r", DHTTYPE, h, t, f );
}
