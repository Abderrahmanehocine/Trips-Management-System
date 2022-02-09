#include "mainHeaderFiles.h"

class seeTripInformation{
 private:
  string tripNumber;
  struct stat test; // cheak if the directory exist or not
  string scan;
 public:
  void seeTripIformations(string dir){ //dir="trips"; directory
      enter:
      cout<<"\nEnter trip Number: ";
      scanf("\n");
      getline(cin,tripNumber);
      cout<<endl;
      string trip=dir;
      trip+="//"+tripNumber;
      if(stat (trip.c_str(), &test) == 0){
         string tripInformation=trip;
         tripInformation+="//tripInformation.txt";
         ifstream takeTripInfoFile(tripInformation);
         while(getline(takeTripInfoFile,scan)){
             cout<<scan<<endl;
         }
         takeTripInfoFile.close();
         string passangerinformation=trip;
         passangerinformation+="//passangerInformation.txt";
         ifstream takePassangerInfoFile(passangerinformation);
         cout<<endl;
         while(getline(takePassangerInfoFile,scan)){
            cout<<scan<<endl;
         }
         takePassangerInfoFile.close();
       } //end if
      else{
        cout<<"\nThere is no trip information in this trip number please try again\n";
        goto enter;
      }
  }
}; //class seeTripINformation