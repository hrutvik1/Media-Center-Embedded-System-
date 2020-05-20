/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher and Graphic Demo
 * Note(s): 
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2008-2011 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/
                  
#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include "string.h"
#include "GLCD.h"
#include "LED.h"

#include "KBD.h"


#include "usbdmain.h"
#include <stdlib.h>


//#include "ie.c"
//#include "spongebob.c"
#include "papper.c"
#include "scissorsIcon.c"
#include "rockIcon.c"

extern int audio_main (void);


void _delay_ms(uint16_t ms) {
	uint16_t delay;
	volatile uint32_t i;
	
	for(delay = ms; delay > 0; delay--) {
		for(i = 3500; i > 0; i--) {
		}
	}
}
void loading(){
  GLCD_Clear  (Black);
	GLCD_SetBackColor(Yellow);
  GLCD_SetTextColor(Black);
	GLCD_DisplayString (4, 3, 1, "Loading ");
	_delay_ms(1000);
		GLCD_DisplayString (4, 3, 1, "Loading. ");
		_delay_ms(1000);
		GLCD_DisplayString (4, 3, 1, "Loading. .");
		_delay_ms(1000);
	GLCD_DisplayString (4, 3, 1, "Loading. . .");
}


void rps(){

	int loopTemp=0;
	int game=0;
	int joystick_prev=0;

	
	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");

	while(loopTemp==0){ //Best of 3 
				 int computerSelect= (rand() % 3)+1; // 1 is min, 3 is max, 1=rock, 2=paper, 3=scisors
	
		 int rpsSelect= get_button();
		

		// srand(time(0));

	 
 			
			if (rpsSelect !=joystick_prev)	//this means that the user used the joystick
			  {
					
			 if(computerSelect==1 && rpsSelect==8){ //comp rock vs you rock [up] , tie
				 	  GLCD_Clear(Red);
				 				 GLCD_DisplayString (0, 0, 1, "Computer = rock");

				 				 	 GLCD_DisplayString (4, 5, 1, "TIE");
_delay_ms(1500);
				 	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");

			 }
			 if(computerSelect==1 && rpsSelect==16){ //comp rock vs you paper [right] , you win
	  GLCD_Clear(Red);
				 				 GLCD_DisplayString (0, 0, 1, "Computer = rock");

				 GLCD_DisplayString (4, 0, 1, "YOU WIN THIS ROUND");
				 game++;
		_delay_ms(1500);

				 //		  		  GLCD_DisplayString(4, 0, 1, (unsigned char*)joystick_value); //when nothing, joystick value is 0
	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");
			 }
			 if(computerSelect==1 && rpsSelect==KBD_LEFT){ //comp rock vs you scissor [down] , comp win
	  GLCD_Clear(Red);
				 				 GLCD_DisplayString (0, 0, 1, "Computer = rock");

				 GLCD_DisplayString (4, 0, 1, "COMPUTER WINS THIS ROUND");
				 game++;
_delay_ms(1500);

				 	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320

	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");
			 }
			 
			 			
			 if(computerSelect==2 && rpsSelect==8){ //comp paper vs you rock [up], comp win
	  GLCD_Clear(Red);
				 				 GLCD_DisplayString (0, 0, 1, "Computer = paper");

				 GLCD_DisplayString (4, 0, 1, "COMPUTER WINS THIS ROUND");
				 game++;
_delay_ms(1500);

				 	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");
			 }
			 if(computerSelect==2 && rpsSelect==16){ //comp paper vs you paper [right], tie
	  GLCD_Clear(Red);
				 				 GLCD_DisplayString (0, 0, 1, "Computer = paper");

				 GLCD_DisplayString (4, 5, 1, "TIE");
_delay_ms(1500);

				 	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");
			 }
			 if(computerSelect==2 && rpsSelect==KBD_LEFT){ //comp paper vs you scissor [down], you win
	  GLCD_Clear(Red);
				 				 GLCD_DisplayString (0, 0, 1, "Computer = paper");

				 GLCD_DisplayString (4, 0, 1, "YOU WIN THIS ROUND");
				 game++;
_delay_ms(1500);

				 	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");
			 }
			 

			 if(computerSelect==3 && rpsSelect==8){ //comp scissor vs you rock [up], you win
	  GLCD_Clear(Red);
				 				 GLCD_DisplayString (0, 0, 1, "Computer = scissors");

				 GLCD_DisplayString (4, 0, 1, "YOU WIN THIS ROUND");
				 game++;
_delay_ms(1500);

	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");				 
			 }
			 if(computerSelect==3 && rpsSelect==16){ //comp scissor vs you paper [right], comp win
	  GLCD_Clear(Red);

				 				 				 GLCD_DisplayString (0, 0, 1, "Computer = scissors");

				 GLCD_DisplayString (4, 0, 1, "COMPUTER WINS THIS ROUND");
				 game++;
_delay_ms(1500);

	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");				 
			 }
			 if(computerSelect==3 && rpsSelect==KBD_LEFT){ //comp scissor vs you scissor [down], tie
	  GLCD_Clear(Red);

				 				 GLCD_DisplayString (0, 0, 1, "Computer = scissors");

				 GLCD_DisplayString (4, 5, 1, "TIE");
_delay_ms(1500);

	  GLCD_Clear(Red);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);

	 GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
	 GLCD_Bitmap(256,144,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
	 GLCD_Bitmap(128,0,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320


	 GLCD_DisplayString (3, 8, 1, "^^^ ");
	 GLCD_DisplayString (7, 11, 1, ">>>");
	 GLCD_DisplayString (7, 7, 1, "<<<");				 
			 }
 		
	
			 
			 if(game==5){
				 loading();
				 GLCD_Clear(Black);
		break;
		}

			 
			 						joystick_prev = rpsSelect;	 

				} //if joypre

	} //loop
	 
}
		


 
void photoGallery(){
	 
	 
	 int currentPhoto=0;
 
	 int spongebob=1;
	 int ie=2;
	 int flappy=3;

	 int loopTemp=1;
	 
	 int photoSelect = 0;   //track the current joystick value
	 int joystick_prev = 0;  //track the previous value for the joystick
	 
	 GLCD_Clear(White);
	 GLCD_SetBackColor(White);
	 GLCD_SetTextColor(Blue);
	 GLCD_DisplayString (0, 0, 1, "PHOTO GALLERY: ");
	 GLCD_DisplayString (1, 0, 1, "PRESS RIGHT TO SCROLL THROUGH");
	 GLCD_DisplayString (2, 0, 1, "PRESS SELECT TO EXIT");

	 while(loopTemp==1){
		 
		 			photoSelect = get_button();	//read the joystick
			
			if (photoSelect !=joystick_prev)	//this means that the user used the joystick
			  {
	 
			switch(photoSelect) {
 

			case 16: //Bitmask when joystick is right
 
			if(currentPhoto==0){
	
GLCD_Clear(White);
 							GLCD_Bitmap(0,144,64,48, (unsigned char*) SCISSORSICON_pixel_data); //before arrya 240 320 ()
			}
			if(currentPhoto==1){
 

GLCD_Clear(White);
				GLCD_Bitmap(256,144,64,48, (unsigned char*) ROCKICON_pixel_data); //before arrya 240 320
			}
			if(currentPhoto==2){
				
GLCD_Clear(White);
			GLCD_Bitmap(128,0,64,48, (unsigned char*) PAPPER_pixel_data); //before arrya 240 320
			}
			
			currentPhoto++;
			break;
 
			
			
			case 1: //pressed == exit
				
			loading();
							 GLCD_Clear(Black);

			 loopTemp=0;
			break;	
			


			}
			
						joystick_prev = photoSelect;	//we good
 
				}

	 }	
	 
 }



/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) 
{  	/* Main Program                       */
	int selector = 0; //selector to see which program is user the choosing
										//'1' for photo viewer, '2' for audio file, '3' for game
	int joystick_val = 0;   //track the current joystick value
	int joystick_prev = 0;  //track the previous value for the joystick
	
	KBD_Init();

  LED_Init ();
  GLCD_Init();
	
	
loading();

	
  GLCD_Clear  (Black);
  SysTick_Config(SystemCoreClock/100); 
	GLCD_SetBackColor(Yellow);
  GLCD_SetTextColor(Black);
	GLCD_DisplayString (0, 0, 1, "COE 718 Project Demo");
	GLCD_DisplayString (1, 6, 1, "MAIN MENU");

  for (;;)		//loop forever
	{
			joystick_val = get_button();	//read the joystick
			
			if (joystick_val !=joystick_prev)	//this means that the user used the joystick
			  {
					if (joystick_val == KBD_DOWN)
						{
							selector +=1;	//we are have only 3 modes so only 3 values of selector
							selector = selector %5;		//are accepted, overflow is mapped back to beginning
						}
					else if (joystick_val == KBD_UP)
						{
							selector -=1;
							if (selector <=0)
									selector = 1;
						}
					else if(joystick_val == 1)
							{
								if (selector == 1) //photogallery
								{
									//photo_viewer(1);	//start the photo viewer function
									photoGallery();
									selector = 0;
								}
								else if (selector == 2) //audio
								{
									audio_main();
									loading();
									GLCD_Clear(Black);
									GLCD_SetBackColor(Black);
									GLCD_SetTextColor(Yellow);
									GLCD_DisplayString (0, 0, 1, "COE 718 Project Demo");
									GLCD_DisplayString (1, 6, 1, "MAIN MENU");									
									selector =0;
								}
								else if (selector == 3) //game
								{

									rps();
									

									selector = 0;
								}
								else if(selector ==4)
								{
									GLCD_Clear(Black);
 									GLCD_SetBackColor(Black);
									GLCD_SetTextColor(Yellow);
									GLCD_DisplayString (0, 0, 1, "COE 718 Project Demo");
									GLCD_DisplayString (1, 6, 1, "MAIN MENU");
									selector = 0;
								}
							}
					joystick_prev = joystick_val;	//we good
			}
			
			/*this is to update the LCD each time the user interfaces with the joystick*/
			if (selector == 1)	//for displaying now
				{
						GLCD_SetBackColor(Red);
						GLCD_SetTextColor(Black);
						GLCD_DisplayString(4,0,1, "Photo Gallery");
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Yellow);
						GLCD_DisplayString(5,0,1, "Audio player");
						GLCD_DisplayString(6,0,1, "Rock Paper Scissors");
						
				}
			else if(selector == 2)
				{
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Yellow);
						GLCD_DisplayString(4,0,1, "Photo Gallery");
						GLCD_SetBackColor(Red);
						GLCD_SetTextColor(Black);
						GLCD_DisplayString(5,0,1, "Audio player");
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Yellow);
						GLCD_DisplayString(6,0,1, "Rock Paper Scissors");
				}
			else if(selector == 3)
				{
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Yellow);
						GLCD_DisplayString(4,0,1, "Photo Gallery");
						GLCD_DisplayString(5,0,1, "Audio player");
						GLCD_SetBackColor(Red);
						GLCD_SetTextColor(Black);
						GLCD_DisplayString(6,0,1, "Rock Paper Scissors");
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Yellow);
				}
			else if (selector == 4)
			{
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Yellow);
						GLCD_DisplayString(4,0,1, "Photo Gallery");
						GLCD_DisplayString(5,0,1, "Audio player");
						GLCD_DisplayString(6,0,1, "Rock Paper Scissors");
						GLCD_SetBackColor(Red);
						GLCD_SetTextColor(Black);
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Yellow);
			}
			else
				{
						GLCD_DisplayString (0, 0, 1, "COE 718 Project Demo");
	GLCD_DisplayString (1, 6, 1, "MAIN MENU");
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Yellow);
						GLCD_DisplayString(4,0,1, "Photo Gallery");
						GLCD_DisplayString(5,0,1, "Audio player");
						GLCD_DisplayString(6,0,1, "Rock Paper Scissors");
				}
	}
}


