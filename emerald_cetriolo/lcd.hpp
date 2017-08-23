
void firstLine (char* first_line, screen* data, usi* year){

	// insert day
	if (data->time.day < 10){
		first_line[0] = '0';
	} else {
		first_line[0] = ((data->time.day/10)%10) + '0';
	}
	first_line[1] = (data->time.day%10) + '0';

	// insert month
	if (data->time.month < 10){
		first_line[3] = '0';
	} else {
		first_line[3] = ((data->time.month/10)%10) + '0';
	}
	first_line[4] = (data->time.month%10) + '0';

	// insert year
	first_line[6] = ((*year/10)%10) + '0';
	first_line[7] = ((*year)%10) + '0';

	// insert hours
	if (data->time.hour < 10) {
		first_line[11] = '0';
	} else {
		first_line[11] = ((data->time.hour/10)%10) + '0';
	}
	first_line[12] = (data->time.hour%10) + '0';

	// insert minutes	
	if (data->time.minute < 10){
		first_line[14] = '0';
	} else {
		first_line[14] = ((data->time.minute/10)%10) + '0';
	}
	first_line[15] = (data->time.minute%10) + '0';

}

void secondLine (char* second_line, screen* data){

	// // second_line[2] = ((data->temperature/100)%10) + '0';
	// // second_line[3] = ((data->temperature/10)%10) + '0';

	// if (data->out.water){
	// 	second_line[7] = '1';
	// } else {
	// 	second_line[7] = '0';
	// }

	// if (data->out.light){
	// 	second_line[11] = '1';
	// } else {
	// 	second_line[11] = '0';
	// }

	// second_line[15] = data->stag + '0';

}

void update (char* first_line, char* second_line, LiquidCrystal* lcd_p){
	lcd_p -> setCursor(0, 0);
	lcd_p -> print(first_line);

	lcd_p -> setCursor (0, 1);
	lcd_p -> print(second_line);
}

void showTime (screen* data, LiquidCrystal* lcd_p, usi* year){
	// Serial.println("showTime");
	char first_line[]  = "gg/mm/aa   hh:mm";
	char second_line[] = "T:__ W:_ L:_ S:_";

	firstLine (first_line, data, year);

	secondLine (second_line, data);

	// Serial.println(first_line);
	// Serial.println(second_line);
	// delay(800);
  
	update(first_line, second_line, lcd_p);
}

/*

##################
#gg/mm/aa   hh:mm#
#T:23 W:1 L:0 S:1#
##################

*/
