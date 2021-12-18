/****************************************************************************
**	SAKARYA UNIVERSITY
**	BILGISAYAR MUHENDISLIGI BOLUMU
**	PROGRAMLAMAYA GIRIS
**
**	ÖĞRENCİ ADI......:Poqob
**	ÖĞRENCİ NUMARASI.:b20-----
**	DERS GRUBU…………………:C
****************************************************************************/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <time.h>

#define MAX 50
using namespace std;

class Character
{
public:
   // this function will generate number for alphabeth from 65=a to 90=z
   // and the other way it will generate number for colors from 9 to 14
   int randomNum(int start, int range)
   {
      range -= start;
      srand((unsigned)time(0) * rand());
      int result = start + (rand() % range);
      return result;
   }
   // this function generates different characters and returns them (character codes)--> for example char 65 is A .
   char characterGen()
   {
      char c;
      c = randomNum(65, 90);
      return c;
   }
   // this function generates diferent colors between 9-14 color codes then returns them.
   int colorGen()
   {
      int color = randomNum(9, 14);
      return color;
   }
};

class Katar : public Character
{

private:
   // this store character number
   short characterNum;
   // this array stores characters
   char characterArray[MAX];
   // this array stores characters color codes as num
   short characterColorArray[MAX];
   // this is count variable for characters
   short count = 0;
   // this is count variable for character colors
   short countColor = 0;

public:
   // these are katar's line codes
   char DUZCIZGI = 205;
   char SOLUSTKOSE = 201;
   char SAGUSTKOSE = 187;
   char DIKEYCIZGI = 186;
   char ASAGIAYRAC = 203;
   char SOLALTKOSE = 200;
   char SAGALTKOSE = 188;
   char YUKARIAYRAC = 202;

public:
   // constructer for Katar
   Katar(){};
   // ready everyone , now write function comessss
   void writerChatar(short num)
   {
      cout << SOLUSTKOSE;
      // for first line
      for (short i = 0; i < num-1; i++)
      {
         cout << DUZCIZGI << ASAGIAYRAC; //<<endl;
      }
      cout <<DUZCIZGI << SAGUSTKOSE;
      // finish first line
      cout << endl;
      // for second line
      cout << DIKEYCIZGI;
      for (short i = 0; i < num; i++)
      {
         
         // fetch character and character color data from characterArray and characterColorArray then cout them.
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), characterColorArray[i]);
         cout << characterArray[i];

         // reset console text color
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
         cout << DIKEYCIZGI;
      }
      // finish second line
      cout << endl;
      // for third line
      cout << SOLALTKOSE;
      for (short i = 0; i < num-1; i++)
      {
         cout  << DUZCIZGI << YUKARIAYRAC; //<< endl;
      }
      cout<<DUZCIZGI<< SAGALTKOSE;
      // storing printed character number in characterNum
      characterNum = num;
      cout << endl;
      cout << "--this chatar contains:" << characterNum << " elements" << endl;
      // printing screen operations
      screenOperations();
   }

   void addCharacter()
   {
      // define local variables
      char character;
      int color;
      // character variable equal to random character
      character = characterGen();

      // add character to count array
      if (count != MAX)
      {
         characterArray[count] = character;
         count++;
      }
      // color variable equal to random color
      color = colorGen();
      // add color to countColorAray
      if (countColor != MAX)
      {
         characterColorArray[countColor] = color;
         countColor++;
      }

      writerChatar(count);
      screenOperations();
   }
   void removeCharacter()
   {
      // this function minus count and countColor from characterArray and characterColorArray
      // this means writer func will work count-1 times (last character and color removed).
      if (count != 0) // minus char count
         count--;
      if (countColor != 0) // minus char color count
         countColor--;
      // cout removed situation
      writerChatar(count);
      // then ofcourse list operations
      screenOperations();
   }

   void screenOperations()
   {
      short choosem;

      cout << "\n*choose one"
           << "\n\n--add character(1)\n--remove character(2)\n--exit program(3)\n---------";
      cin >> choosem;
      switch (choosem)
      {
      case 1:
         addCharacter();

         break;

      case 2:
         removeCharacter();

         break;
      case 3:
         exit(1);
         break;
      default:
         cout << "make true choice !" << endl;
         writerChatar(count);
         break;
      }
   }
};

int main()
{
   // create an Katar object
   Katar katar;
   // acces katar object's operations
   katar.screenOperations();
}

// Hope you like it.
