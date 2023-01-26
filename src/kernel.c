#include "../include/kb.h"
#include "../include/isr.h"
#include "../include/shell.h"


int kmain()
{
	isr_install(); //interrupt service routin
	clearScreen();
	//int a = 5/0;  //برای آزمایش وقفه- ۷
	print("Salam\nWelcome to OSFS 0.0.10\n  Hi Mohammad \nthanks\n\nPlease Enter a command \n");
	
	launch_shell(0);
	/*  برای قسمت ۲ تا ۹ بود- به جای پوسته
	while(1){
		print ("\nOSFS> ");
		
		string ch = readStr();
		if(strEql(ch, "cmd")){
			print("\nYou are allready in cmd");
		}
		else if(strEql(ch, "clear")){
			clearScreen();
		}
		else{
			print("\nBad command!");
		}
		print("\n");
		
	
	}
	 برای آموزش قسمت اول بود
	char* vidmem=(char *)0xb8000;
	vidmem[0] = 'A';
	vidmem[1] = 0x02;
	vidmem[2] = 'L';
	vidmem[3] = 0x02;
	vidmem[4] = 'I';
	vidmem[5] = 0x02;

    */ 
    return 0;  
} 
