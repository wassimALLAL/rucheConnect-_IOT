/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**
* @file main.cpp
* @brief this file contains all the we used to get data from sensors and send
* send them to sigfox backend throw sigfox module 
* definitions and basic utilities functions.
*
* @author Charles LADZRO / Amadou Dia / Abderrazek Saidane / Wassim ALLAL 
* (EI2I-4, Polytech Sorbonne)
*
* @date 25/09/2020
*/

#include "mbed.h"
#include "platform/mbed_thread.h"
#include "DHT.h"
#include "DS1820.h"
#include "ADXL345_I2C.h"
#include "HX711.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>


/*******************************************************************************
DEFINITION DES PINS A UTILISER
*******************************************************************************/
Serial device(PA_9, PA_10 /*D1 D0*/);  // pour Communication Sigfox
ADXL345_I2C accelerometer(PB_7, PB_6 /*D4 D5*/); /*blanc et jaune */
DHT sensor(PA_11,DHT22 /*D10*/); // Use the SEN11301P sensor
DigitalIn anemo(PB_1 /*D6*/);
DigitalOut capt_dht22(PB_5 /*D11*/);
DigitalOut led_temoin(PA_0 /*A0*/);
DigitalOut capt_ds18b20(PB_0 /*D3*/);
DigitalOut capt_sigfox(PA_12 /*D2*/);
DigitalOut capt_acc(PA_8 /*D9*/);
DigitalOut capt_poids(PA_5 /*A4*/);
DS1820 ds1820(PA_1 /*A1*/);
DigitalOut gpo(PB_4 /*D12*/); 
AnalogIn scaleRaw(PA_4 /*A3*/);
HX711 scale(PA_4, PB_4 /*A3 D12*/);

/*******************************************************************************
VARIABLES GLOBALES
*******************************************************************************/
int readings[3] = {0, 0, 0};
int t = 0, h = 0;
float vitesse = 0, temp = 0, poids = 0;

/*******************************************************************************
DECLARATION DES FONCTIONS
*******************************************************************************/

void choixCapteur(int choix);
void envoieSurSigfox(int t, int h, float temp, int readings[3], float vitesse, float poids);

/**
* This method is the main of the code
* @author Charles LADZRO / Amadou Dia / Abderrazek Saidane / Wassim ALLAL 
* (EI2I-4, Polytech Sorbonne)
* @date 25/09/2020
*/
int main() {
    
    led_temoin = 1;
    wait(5);
    led_temoin = 0;
    
    capt_dht22 = 0;
    capt_ds18b20 = 0;
    capt_sigfox = 0;
    capt_acc = 1;
    capt_poids = 0;
    
    scale.setScale(10740);
    scale.tare(); //Reset the scale to 0
    
    // creation du baud
    device.baud(9600);
    
    printf("\r\nRuche Connectee Test program");
    printf("\r\n******************\r\n");
    
    scale.tare(); //Reset the scale to 0
    
    while(1) {
        
        choixCapteur(1);
        choixCapteur(2);
        //choixCapteur(3);
        choixCapteur(4); 
        choixCapteur(5); 
        
        // envoie sur Sigfox
        envoieSurSigfox(t, h, temp, readings, vitesse, poids);
        
        /**
        * this wait is used to send data to sigfox backend every 30 minutes
        */
        wait(1800); // 600 pour 10 min ==> 1800 for 30 min
    }
    
}

/**
* This method is used to create and send the message which will be send to 
* the sigfox backend 
* @param t = temperature give by dht22 device
* @param h = humidity give by dht22 device
* @param temp = temperature give by ds18b20 device
* @param readings = the coordinates x, y, z given by the accelometer in the form 
* of an array of three integers
* @param vitesse = ththe speed given by the anemometer
* @param poids = the weight given by the weight sensor
* @author Charles LADZRO / Amadou Dia / Abderrazek Saidane / Wassim ALLAL 
* (EI2I-4, Polytech Sorbonne)
* @date 25/09/2020
*/
void envoieSurSigfox(int t, int h, float temp, int readings[3], float vitesse, float poids) {
    
    // allumage du sigfox
    capt_sigfox = 1;
    wait(1);                     
    
    device.printf("AT$SF=%02X", t);
    device.printf("%02X", h);
    device.printf("%02X", (int)temp);
    
    /**
    * The part of the following code used to send the accelerometer data has 
    * been commented because there is an integration problem with the other 
    * sensors
    */
    /*device.printf("%04"PRIX16, (uint16_t)readings[0]);
    device.printf("%04"PRIX16, (uint16_t)readings[1]);
    device.printf("%04"PRIX16, (uint16_t)readings[2]);*/
    device.printf("%02X", (int)vitesse);
    device.printf("%02X\r\n", (int)poids);
        
    /*printf("\r\n%d %d %d %d %d %d %d %d\r\n",
        t, h, (int)temp, (int)readings[0], (int)readings[1], (int)readings[2], (int)vitesse, (int)poids);*/
        
    printf("\r\n%d %d %d %d %d\r\n",
        t, h, (int)temp, (int)vitesse, (int)poids);
        
    printf("\r\n%02X", t);
    printf(" %02X", h);
    printf(" %02X", (int)temp);
    /*printf(" %04"PRIX16, (uint16_t)readings[0]);
    printf(" %04"PRIX16, (uint16_t)readings[1]);
    printf(" %04"PRIX16, (uint16_t)readings[2]);*/
    printf(" %02X", (int)vitesse);
    printf(" %02X\r\n", (int)poids);
    
    // attendre 1 min
    wait(60);
    
    // eteindre sigfox
    capt_sigfox = 0;
    wait(1);
}

/**
* This method is used get the value of the different sensors
* @param choix = this parameter allows you to select the sensor from which you 
* want to retrieve the data
* @li 1 - dht22 sensor
* @li 2 - ds18b20 sensor
* @li 3 - accelometer
* @li 4 - anemometer
* @li 5 - weight sensor
* @author Charles LADZRO / Amadou Dia / Abderrazek Saidane / Wassim ALLAL 
* (EI2I-4, Polytech Sorbonne)
* @date 25/09/2020
*/
void choixCapteur(int choix) {
    if (choix == 1) {
        printf("\r\nDonnées du capteur DHT22\r\n");
        capt_dht22 = 1;
        wait(1);
        int err = sensor.readData();
        if (err == 0) {
           t = (int) sensor.ReadTemperature(CELCIUS);
           h = (int) sensor.ReadHumidity();
           printf("\rtemperature = %d, humidité = %d\r\n", t, h);
        }
        wait(5);
        capt_dht22 = 0;
        wait(1);
    }
    
    else if (choix == 2) {
        printf("\r\nDonnées du capteur DS18B20 (temperature longue)\r\n");
        capt_ds18b20 = 1;
        wait(1);
        // put your main code here, to run repeatedly:
        if (ds1820.begin()) {
          ds1820.startConversion();
          wait(2.0);                  // let DS1820 complete the temperature conversion
          temp = ds1820.read();
          printf("\rTemperature DS1820 = %3.1f Grad C\r\n", temp);
        } else {
          printf("\rDS1820 wait for working!\r\n");
        }
        capt_ds18b20 = 0;
        wait(1);
    }
    
    else if (choix == 3) {
        printf("\r\nDonnées du capteur accelerometre\r\n");
        //capt_acc = 1;
        //wait(1);
        
        wait(.001);
        printf("\rDevice ID is: 0x%02x\n", accelerometer.getDeviceID());
        wait(.001);
        // These are here to test whether any of the initialization fails. It will print the failure
        if (accelerometer.setPowerControl(0x00)){
            printf("\rdidn't intitialize power control\n"); 
            return;  
        }
        //Full resolution, +/-16g, 4mg/LSB.
        wait(.001);
        if(accelerometer.setDataFormatControl(0x0B)){
            printf("\rdidn't set data format\n");
            return;  
        }
        wait(.001);
        //3.2kHz data rate.
        if(accelerometer.setDataRate(ADXL345_3200HZ)){
            printf("\rdidn't set data rate\n");
            return;    
        }
        wait(.001);
        //Measurement mode.
        if(accelerometer.setPowerControl(MeasurementMode)) {
            printf("\rdidn't set the power control to measurement\n"); 
            return;   
        } 
        wait(0.1);
        accelerometer.getOutput(readings);
        printf("\r%i, %i, %i\n", (int16_t)readings[0], (int16_t)readings[1], (int16_t)readings[2]);
        //capt_acc = 0;
        //wait(1);
    }
    
    else if (choix == 4) {
        printf("\r\nDonnées de la station meteo (Anemometre)\r\n");
        int value = 0;
        int NBMAXCOUNT = 10000000;
        // declaration du timer
        Timer t;

        // detection du premier front montant
        int nMax = NBMAXCOUNT;
        while (value == 0){
            if(anemo) {
                value = 1;
                break;
            }
            else{
                value = 0;
            }
            nMax = nMax - 1;
            //printf("\r\n1 - %d\r\n", nMax);
            if (nMax == 0){
                return;
            }
        }
        
        // detection du premier front descendant
        nMax = NBMAXCOUNT;
        while (value == 1){
            if(anemo) {
                value = 1;
            }
            else{
                value = 0;
                break;
            }
            nMax = nMax - 1;
            //printf("\r\n2 - %d\r\n", nMax);
            if (nMax == 0){
                return;
            }
        }
        t.start();
        
        // detection du deuxieme front montant
        nMax = NBMAXCOUNT;
        while (value == 0){
            if(anemo) {
                value = 1;
                break;
            }
            else{
                value = 0;
            }
            nMax = nMax - 1;
            //printf("\r\n3 - %d\r\n", nMax);
            if (nMax == 0){
                return;
            }
        }
        t.stop();
        
        vitesse = (1.0/t.read())*2.4;
        printf("\rAnemometre (vitesse) = %f km/s, \n", vitesse);
    }
    
    else if (choix == 5) {
        printf("\r\nDonnées du capteur Poids\r\n");
        capt_poids = 1;
        wait(1);
        
        float calibration_factor = 10740; //27390; //10740; //-7050 worked for my 440lb max scale setup
        scale.setScale(calibration_factor);
        poids = scale.getGram() - 8; // 8 kg
        printf("\rPoids = %f kg, \n", poids);
        
        capt_poids = 0;
        wait(1);
    }
}