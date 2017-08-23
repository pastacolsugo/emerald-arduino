void printOutput (OUT* data){
	char out_buf[60] = "light1:  \nlight2:  \nwater:  \nFAN:  \n-------------\n";

	out_buf[8] 	= data->light 	+ '0';
	out_buf[18] = data->light2 	+ '0';
	out_buf[27] = data->water 	+ '0';
	out_buf[34] = data->fan 	+ '0';

	Serial.print(out_buf);
}

void applyOutput (OUT* data){
	// printOutput (data);

	if (CONTROL_LIGHT1) {
		dw (PIN_LIGHT1, (PIN_LIGHT1_INV)? !(data->light) : (data->light));
	}

	if (CONTROL_LIGHT2) {
		dw (PIN_LIGHT2, (PIN_LIGHT2_INV)? !(data->light2) : (data->light2));
	}

	if (CONTROL_WATER) {
		dw (PIN_WATER, (PIN_WATER_INV)? !(data->water) : (data->water));
	}

	if (CONTROL_FAN) {
		dw (PIN_FAN, (PIN_FAN_INV)? !(data->fan) : (data->fan));
	}
}
