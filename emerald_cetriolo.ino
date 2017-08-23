#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"		// RTC LIBRARY
#include "shortcuts.hpp"
#include "control.hpp"
#include "pin.hpp"
#include "data_struct.hpp"
#include "programma.hpp"
#include "getters.hpp"
#include "finder_1.hpp"
#include "lcd.hpp"
#include "output.hpp"

bool SERIAL_ENABLE = false;

// D8 RS - D9 Enable - D4 Data4 - D5 Data 5 - D6 Data6 - D7 Data7
// A0 keypad
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

RTC_DS1307 rtc;

usi index = 0;
usi year = 2017;
	// create output configuration
	// output1 is the one that will be applied
	// output2 is the one that has last been applied
OUT output1, output2 = {0, 0, 0, 0, 0};
usi season = 0;

OUT black_magic_box (black_magic_data req, usi* seas){
	// find current season
	usi current_season = findSeason (&req.time);

	// pass the current season to a given location, to be used in the LCD
	*seas = current_season;	

	OUT res = {false, false, false, false, false, false, false, false};
	
	// compute light status
	
	if (CONTROL_LIGHT1){
		res.light 	= findLight (&req.time, &current_season);
	}
	
	if (CONTROL_LIGHT2) {
		res.light2  = findLight2 (&req.time, &current_season);
	}

	if (CONTROL_WATER) {
		res.water 	= findWater (&req.time, &current_season);
	}

	if (CONTROL_FAN) {
		res.fan = findFan (&req.time, &current_season);		
	}

	return res;
}

void emerald_control (){
	// Serial.println("emerald_control");
	black_magic_data input;

	getData(&input, SERIAL_ENABLE);	

	input.output = output2;
	
	if (input.time.month == 0){
		return ;
	}
	
	// black_magic_box is going to compute the next output configuration
	// taking the actual state as input
	output1 = black_magic_box (input, &season);


	// printout (output1, input);

	// 
	// apply output1
	// 
	applyOutput(&output1);


	// update screen
	screen lcd_data = {
		input.time,
		output1,
		season, 
		input.temperature_inside
	};
	// screen lcd_data = {
	// 	{5, 6, 11, 16},
	// 	{1, 0, 0, 0, 0, 0, 0, 0},
	// 	2,
	// 	153
	// };

	showTime (&lcd_data, &lcd, &year);

	output2 = output1;

	index++;
}

void setup(){
	// Serial.begin(9600);
	// Serial1.begin(115200);
	// Serial1.begin(250000);
  
	lcd.begin(16, 2);

	if (!rtc.begin()) {
		lcd.clear();
		lcd.setCursor (0, 0);
		lcd.print ("RTC not found");
		delay(2000);
	}
  
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);

	pinMode (PIN_LIGHT1, OUTPUT);
	pinMode (PIN_LIGHT2, OUTPUT);
	pinMode (PIN_WATER, OUTPUT);
	pinMode (PIN_HEATER, OUTPUT);
	pinMode (PIN_FAN, OUTPUT);
	pinMode (PIN_HUMI, OUTPUT);
	pinMode (PIN_AIR_SOURCE, OUTPUT);

	pinMode(SERIAL_SWITCH, INPUT);
  
	lcd.setCursor(0, 0);
	lcd.print("  Emerald Core");
	lcd.setCursor(0,1);
	lcd.print("v2.1 Cetriolo Ed");
  
	delay(2000);
}

void loop (){
//	SERIAL_ENABLE = digitalRead(SERIAL_SWITCH);
	// Serial.println("kaffe");

	emerald_control();

	// while (Serial.available() == 0){}
	// Serial.read();
}
