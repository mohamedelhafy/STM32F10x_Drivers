/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 23 FEB 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/
 




#include "MQTT.h"





uint8_t 	packet[200] = {0};
uint8_t 	packetInd 	= 0;

uint16_t	packetID 	= 1;


static void writeUTFStr(uint8_t* strUtf){
	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(strUtf);
	strcpy( (packet+packetInd) , strUtf);
	packetInd += strlen(strUtf);
}
void MQTT_Connect(uint8_t* clientID){
	uint8_t remLen = ( 12 + strlen(clientID));
	packetInd = 0;
	packet[packetInd++] = 0x10;
	packet[packetInd++] = remLen;

	writeUTFStr("MQTT");

	packet[packetInd++] = 0x04;
	packet[packetInd++] = 0x02;
	packet[packetInd++] = 0xFF;
	packet[packetInd++] = 0xFF;

	writeUTFStr(clientID);
	// send packet to uart
	// your sned func here
}
void MQTT_Publish(uint8_t* topic, uint8_t* msg, uint32_t len, uint8_t QoS){
	uint8_t remLen = (2 + strlen(topic) + len );
	uint8_t ind = 0;
	packetInd = 0;
	if(QoS > 0){
		remLen += 2;
	}
	packet[packetInd++] = (0x30 | (((0x3)&QoS) << 1));
	packet[packetInd++] = remLen;
	writeUTFStr(topic);
	if(QoS > 0){
		packet[packetInd++] = ((uint8_t)(packetID >> 8)); // MSB
		packet[packetInd++] = ((uint8_t)(packetID)); // LSB
		packetID++;
	}
	for (ind = 0; ind < len; ++ind) {
		packet[packetInd++] = msg[ind];
	}
	// send packet to uart
	// your sned func here
}
void MQTT_Subscribe(uint8_t* topic){
	uint8_t remLen = (5 + strlen(topic));

	packetInd = 0;

	packet[packetInd++] = 0x82;
	packet[packetInd++] = remLen;

	packet[packetInd++] = ((uint8_t)(packetID >> 8)); // MSB
	packet[packetInd++] = ((uint8_t)(packetID)); // LSB
	packetID++;

	writeUTFStr(topic);
	packet[packetInd++] = 0x01;

	// send packet to uart
	// your sned func here
}
