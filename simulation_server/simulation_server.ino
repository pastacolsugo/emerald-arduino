char buffer[128];

unsigned int year = 2017;
unsigned int month = 1;
unsigned int day = 1;
unsigned int hour = 0;
unsigned int minute = 0;

unsigned int temperature = 100;

bool rising = true;

unsigned int counter = 0;

char data[256];

// minute hour day month temperature\n

void setData (){
//	data = "                  "
	data[0] = ((minute/10)%10) + '0';
	data[1] = (minute%10) + '0';

	data[2] = ' ';
	
  data[3] = ((hour/10)%10) + '0';
	data[4] = (hour%10) + '0';
	
  data[5] = ' ';
	
  data[6] = ((day/10)%10) + '0';
	data[7] = (day%10) + '0';
	
  data[8] = ' ';
	
  data[9] = ((month/10)%10) + '0';
	data[10] = (month%10) + '0';
	
  data[11] = ' ';
	
  data[12] = (temperature/100)%10 + '0';
	data[13] = (temperature/10)%10 + '0';
	data[14] = (temperature%10) + '0';
	
  data[15] = '\n';
}

void setup (){
	Serial.begin(250000);
}

void loop (){
	buffer[0] = ' ';

	if (Serial.available() > 0){
		buffer[0] = Serial.read();
		
		if (buffer[0] == 'R'){
			Serial.write(data);

      if (rising){
        temperature++;
      } else {
        temperature--;
      }

      if (temperature >= 400){
        rising = false;
      }
      if (temperature == 3){
        rising = true;
      }
      
      counter++;

      if (counter >= 10){
        counter = 0;
        minute++;
      }
      
      if (minute >= 60){
        minute = 0;
        hour++;
      }
    
      if (hour >= 24){
        hour = 0;
        day++;
      }
    
      if (day >= 32){
        day = 1;
        month++;
      }
      
      if (month >= 13){
        month = 1;
        year++;
      }
		}
	}

	setData();

}
