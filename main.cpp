#include <windows.h>//soley used for void clrscr();
#include <iostream>//To output our clock
#include <time.h>//soley used for void waid(seconds);

using namespace std;

void wait ( int seconds )
{
   clock_t endwait;
   endwait = clock () + seconds * CLK_TCK ;
   while (clock() < endwait) {}
   }//using time.h, it makes a clock and an end wait. The seconds inputed, in this case, 1, will tell how long the clock waits.

void clrscr()
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD coord = {0, 0};
   DWORD count;

   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(hStdOut, &csbi);

   FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
   //note that you can use this function to
   //position the cursor in the console.
   SetConsoleCursorPosition(hStdOut, coord);

  }//This clears the console to refresh the clock for every second.

  void printIt(int hours, int outM, int outS); //Used later to print out the clock

int main()
{

	int second=0;//Can be set to any variable
	int minutes=0;//Make sure it coresponds to seconds
	int hours=0;//Make sure it coresponds to minutes

	do {//Is told to do everything between here{

	int outS = second % 60;//Is made so it won't go past 60
	int outM = minutes % 60;//made so that it won't go past 60
	int hourCounter = second % 3600;//Important variable! Could really mess up the hour equation if you mess with it.

	second=second+1;//Adds one to seconds

	if (outS==59){
	  minutes = minutes + 1 ;
	}//Of course, as explained in modulus, 59 will repeat itself every time the variable second reaches a multiple of 60

	if(hourCounter==59){

		hours = hours+1;
	}

	if (hourCounter==3599){
		printIt(hours, outM, outS);//Prints the current values of hours, minutes, and seconds
		wait(1);//waits one second exactly
		hours = hours + 1;//adds an hour
		clrscr();//clears the screen for the next time it prints
	} /*The reason it has all that code is because of an error that I had, where it got an hour a second early. I fixed this by adding the rest of the code later in this if and making an if to make the second instance of that code null.*/

	if (hourCounter!=3599){//Made as != to counteract the hour adding one.
		printIt(hours, outM, outS);//prints the current values of hour, minute, and time
		wait(1);//waits one second

		clrscr();//Clears the console for the next printing
	}//To here!
	} while (hours<12);//Does the entire "do" code until hours is not less than 24

  return 0;
}

  void printIt(int hours, int outM, int outS){//This is the printing code
	/*The following code is used because you can't get two zeros if you print it as a normal variable. So, I made sure that if a particular variable is less than ten, that variable gets a zero before it.*/
	cout << "________________" << endl;
	cout << "| Disital Clock |" << endl;
	cout << "________________" << endl;


	if (hours<10){
		if (outM<10){
			if (outS<10){

				std::cout<<"    0"<<hours<<":0"<<outM<<":0"<<outS;
			} else {
				std::cout<<"    0"<<hours<<":0"<<outM<<":"<<outS;
				}
		} else {
			std::cout<<"    0"<<hours<<":"<<outM<<":"<<outS;
			}
	} else {
		std::cout<<hours<<"    :"<<outM<<":"<<outS;
		}



 }
