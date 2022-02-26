/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 20 FEB 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/
 


#Assumptions:
> Packet Len <= 127 + 2, one byte only.
> QoS0/1
> For public brokers.
> No retained packets nor duplicate.
--------------------------------

MQTT Packet Format:
Fixed Header:			All Packets
>	B1: Packet Type in 4bits + Optional Flags in 4bits
>	B2,3,4,5: Remaining Length = sizeof(Variable Header + Payload)
Variable Header:		Some of Packets
> Packet Identifier:
	Two Bytes start from PacketID =1 = MSB: 0x00 LSB: 0x01
Payload:				Some of Packets
> Dependent on Packet.
---------------------------------------------------
Remaining Length
B2					0|1111111 = 127
B2 B3 				1|1111111	0|1111111 = 127 + 128*127
B2 B3 B4			
B2 B3 B4 B5			
-----------------------
Connect Packet:
MQTT_Connect(u8* clientID)
B1:	0x10 		connect type
B2:	( 12 + strlen(clientID))		rem len

B3: 0x00				
B4: 0x04
B5,6,7,8: "MQTT"

B9:  0x04		level/version
B10: 0x02		flags = clean session only, public broker is used.
B11: 0xFF		Keep alive time = Approx. 18 hour 
B12: 0xFF

B13: 0x00
B14: strlen(clientID)
B15 ...: clientID
------------------------------------------------------
CONNACK:
B1:	0x20
B2:	0x02
B3: 0x00		flags (session not present)
B4: 0x00		
--------------------------------------------------------
Publish Packet:
MQTT_Publish(u8* topic, u8* msg, u32 len, u8 QoS)
B1:	0x30/0x32 		QoS0/QoS1 publish type
B2:	( 12 + strlen(clientID))		rem len

B3: 0x00
B4: strlen(topic)
B5 ...: topic

Bn: MSB of packID		if QoS > 0
Bn: LSB of packID

Bn ...: total bytes of msg to len. 
-----------------------------------------------
PUBACK
0x40 0x02 MSB LSB of packId

---------------------------------------------
Subscribe Packet:
MQTT_Subscribe(u8* topic)
B1:	0x82		 type
B2:	rem len
B3: MSB of packID		
B4: LSB of packID

B5: 0x00
B6: strlen(topic)
B7 ...: topic

Bn: 0x01 Requested QoS
----------------------------------------------
