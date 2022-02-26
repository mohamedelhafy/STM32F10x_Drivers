/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 23 FEB 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/
 

#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H




void MQTT_Connect(uint8_t* clientID);



void MQTT_Publish(uint8_t* topic, uint8_t* msg, uint32_t len, uint8_t QoS);





void MQTT_Subscribe(uint8_t* topic);









#endif