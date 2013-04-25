/**
 * ArduPhone main program for 12-Key Keypad + GPRS Shield Build
 *  
 * Copyright 2013 ZachWick <zach@zachwick.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *    
**/

#include <SoftwareSerial.h>
//#define AP_SERIAL_RATE = 19200; 

SoftwareSerial apSerial(7,8);

void setup()
{
	apSerial.begin(19200);  // GPRS BAUD
	Serial.begin(19200);    // GPRS BAUD
	delay(500);
}

void loop()
{
	if (Serial.available()) 
		{
			switch(Serial.read())
				{
				case 't':
					SMS();
					break;
				case 'd':
					VoiceCall();
					break;
				}
			if (apSerial.available())
				{
					Serial.write(apSerial.read());
				}
		}
}

/**
 * GetRecipientNumber
 * @description  returns the recipient's number in E.123 format
 * @param none
 * @return (String) recipientNumber
 **/
String GetRecipientNumber()
{
	// Short-circuited for now
	String recipientNumber = String("+14192808089");
	return recipientNumber;
}

/**
 * GetSMSMessage
 * @description returns a message to send as a SMS
 * @param none
 * @return (String) message
 **/
String GetSMSMessage()
{
	// Short-circuited for now
	String message = String("Test SMS message from ArduPhone");
	return message;
}

/**
 * SMS()
 * @description Send a SMS message to a number 
 * @param none
 * @return none
 **/
void SMS()
{
	String recipientNumber = GetRecipientNumber();
	String message = GetSMSMessage();
	String smsCommand = String("AT+CMGS=\"");
	smsCommand += recipientNumber;
	smsCommand += String("\"");

	apSerial.print("AT+CMGF=1\r");  // Set the GSM Module SMS in text/ASCII mode
	delay(100);
	apSerial.println(smsCommand);
	delay(100);
	apSerial.println(message);
	delay(100);
	apSerial.println((char)26);    // End the serial.write with an ASCII Ctrl+z
	delay(100);
	apSerial.println();
}

/**
 * VoiceCall
 * @description Initiates a voice call to a number
 * @param none
 * @return none
 **/
void VoiceCall()
{
	String recipientNumber = GetRecipientNumber();
	String callCommand = String("ATD +");
	callCommand += recipientNumber;
	callCommand += String(";");

	apSerial.println(callCommand);
	delay(100);
	apSerial.println();
}
