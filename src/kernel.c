#include "../include/kb.h"
#include "../include/isr.h"
#include "../include/idt.h"
#include "../include/util.h"
kmain()
{
       isr_install();
       clearScreen();
      
       
       print("Hi and Welcome to NIDOS operating system\nPlease enter a command");
       printch('\n');
       print("NIDOS> ");
       string ch = (string) malloc(200);
       int counter = 0;
       while (1)
       {
                ch = readStr(); //memory_copy(readStr(), ch,100);
                //print(ch);
                
                /*print(ch);
                string ch1 = (string) malloc(10);
                string ch2 = (string) malloc(20);
                ch1 = "hello";
                ch2 = "helli";
                if(strlength(ch1) == 5)
                	print("length is 10");*/
                /*if(strEql(ch1,ch1)) 
                {
                	print("ch1 == ch2");
                }
                else 
                {
                	print("ch2 != ch2");
                }*/
                if(strEql(ch,"cmd"))
                {
                        print("\nYou are allready in cmd\n");
                        print("NIDOS> ");
                }
                else if(strEql(ch,"clear"))
                {
                        clearScreen();
                        print("NIDOS> ");
                }
                
                else
                {
                        print("\nBad command!\n");
                        print("NIDOS> ");
                }  
       }
        
}
