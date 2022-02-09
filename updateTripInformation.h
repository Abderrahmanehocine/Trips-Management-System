#include "mainHeaderFiles.h"

class updateTripInformation{
 private:
  string tripNumber;
  short int choice; // choice take 2 byte beacause we declare it as a short integer
  struct stat test; // cheak if the directory exist or not
 public:
  string updateTripInformations(string dir){ // dir="trips"; directory
      enter:
      cout<<"\nEnter trip number: ";
      cin>>tripNumber;
      string trip=dir;
      trip+="//"+tripNumber;
      if(stat (trip.c_str(), &test) == 0){  // if the function return 0 means the directory exist
          cout<<"\n\n1) add new passanger\n"
                "2) update passanger information\n"
                "3) update trip information\n";
          repeat:
          cout<<"choose a number: ";
          cin>>choice;
          if(choice == 1){
            return "add";
          }
          else if(choice == 2){
              return "updatePassangerInfo";
          }
          else if(choice == 3){
              return "updateTripInfo";
          }
          else{ //if the user enter the wrong choice number
              cout<<"\nPlease choose the correct number\n";
              goto repeat;
          }
      }
      else{ // else the directory doesn't exist print a messange and repeat the method
         cout<<"\nThere is no trip information in this trip number please try again\n";
         goto enter;
      }
  }

  void getTripInformation(){

  }

  string getTripNumber(){
      return tripNumber;
  } 
  
  int getPassangerNumber(string dir){
      dir+="//"+tripNumber;
      string getPassangerInfo=dir;
      getPassangerInfo+="//passangerInformation.txt";
      FILE *getPassangerInfoFile;
      getPassangerInfoFile=fopen(getPassangerInfo.c_str(),"r");
      int count=0;
      char scan[50];
      while(fscanf(getPassangerInfoFile,"%s",scan)!=EOF){
        if(strcmp(scan,"Passanger")==0){
            count++; // count number of passangers
        }
      }
      fclose(getPassangerInfoFile);
     return count;
  }
}; // class updateTripInformation