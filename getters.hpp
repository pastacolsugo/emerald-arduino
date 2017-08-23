void getSerial (black_magic_data* response){
//	Serial.println("sending request");
		
	char payload[32];

	Serial1.write("R");

	// wait for the data to come through
	while (Serial1.available() < 16) { }

	// read data into string
	for (usi i=0; i<16; i++){
		payload[i] = Serial1.read();
	}

	// convert back to number
	usi minute = 0;
	minute += (payload[0]-'0') * 10;
	minute += payload[1]-'0';

	usi hour = 0;
	hour += (payload[3]-'0') * 10;
	hour += payload[4]-'0';

	usi day = 0;
	day += (payload[6]-'0') * 10;
	day += payload[7]-'0';

	usi month = 0;
	month += (payload[9]-'0') * 10;
	month += payload[10]-'0';

	usi temperature = 0;
	temperature += (payload[12]-'0') * 100;
	temperature += (payload[13]-'0') * 10;
	temperature += (payload[14]-'0');

	// debug: print stuff to check conversion

	// Serial.println ("min hour day month");
	// Serial.println (minute);
	// Serial.println (hour);
	// Serial.println (day);
	// Serial.println (month);
	// Serial.print ("temperature: ");
	// Serial.println (temperature);

	// Serial.println ("delay 2 sec");
	// delay (2000);

	response -> time.minute = minute;
	response -> time.hour = hour;
	response -> time.day = day;
	response -> time.month = month;

	response -> temperature_inside = temperature;
}

void getTime (TIME* res){
	DateTime rtc_time = rtc.now();

	res->month = rtc_time.Month;
	res->day = rtc_time.Day;
	res->hour = rtc_time.Hour;
	res->minute = rtc_time.Minute;

 	if (res->month > 12 || res->day > 31 || res->hour > 24 || res->minute > 59){
 		res->month = 0;
 		res->day = 0;
 		res->hour = 0;
 		res->minute = 0;
 	}
}

// void packItUp (TIME* time_now, usi* temperature_in,
// 	usi* temperature_out, usi* hum, black_magic_data* res){

// 	res->time = *time_now;
// 	res->temperature_inside =  *temperature_in;
// 	res->temperature_outside = *temperature_out;
// 	res->humidity = *hum;	

// }

void getData (black_magic_data* response, bool SERIAL_ENABLE){
//	Serial.print("getData: ");
//	Serial.println(SERIAL_ENABLE);

	if (SERIAL_ENABLE){
		getSerial (response);

	} else {
		// reading time from the RTC
		getTime (&(response->time));
	}
}
