//#include <msp430fr5739.h>
//EDIT: Have made enum bool for button state and added clarity for if loops. Should work on a larger range of boards now.
#include "lift1lib.h"

#define LEDon 0x20
#define LEDoff 0x00

int main()
{
    uc_8 buttonstat, old_lvlstat, current_lvlstat;
    enum bool flag;
	//1)Initialising the lift system
    Initialise();
	liftInit();
	//2)Moving the lift up, down and stopping it.
        //lift1Down();
        //Delay1(3e6);
        //lift1Stop();
	//3)Detecting a button press and returning the button identity to the calling routine
	//4)Detecting a level in the shaft and returning the level identity to the calling routine
	//5)Switching on or off a specified LED associated with buttons etc
	//6)Delaying an approximate time period
	//7)Opening and closing the lift doors (simulated by time delay operations)
    while (1)
    {
	/*
	if(floorGet(&current_lvlstat))
	{
		
	}
	*/
      flag=buttonGet(&buttonstat);
		if(flag==true)
		{
			//WriteLed1(6, LEDon);
			if (buttonstat%2==1)
			{
				lift1Up();
				//Delay1(25000000);
				//lift1Stop();
				while(floorGet(&current_lvlstat)==false){}
				lift1Stop();
			}
			else if  (buttonstat%2==0)
			{
				lift1Down();
				//Delay1(25000000);
				//lift1Stop();
				while(floorGet(&current_lvlstat)==false){}
				lift1Stop();
			}
		}
	//Delay1(25000000);
	//WriteLed1(buttonstat, LEDoff);
    }
	return 0;
}
