#include "commandline.h"

extern CommandLine cmdline;

extern int speed_usb_0;
extern int speed_usb_1;
extern int desired_speed;


uint16_t cmd_info(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];

	if(argc==1){
//		size+=sprintf(buffer+size, "Microcontroladores 2017\r\n");

		size+=sprintf(buffer+size,"%i\r\n",speed_usb_0);


	}

	else if(argc==2){
			//size+=sprintf(buffer+size, "%s\r\n", argv8[1]);

			desired_speed = atoi((char*)argv8[1]);

			size+=sprintf(buffer+size, "%d\r\n", desired_speed);
		}

	else {
		size+=sprintf(buffer+size, "Syntax: info\r\n");
	}
	return size;
}


CommandLine cmdline({"velocidade"},
					{cmd_info});
