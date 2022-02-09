#include "mainHeaderFiles.h"
#include "addNewTripInformation.h"
#include "addPassangersInformation.h"
#include "updateTripInformation.h"
#include "seeTripInformations.h"

class generateCode{
  private:
   int choice;
   string dir="trips"; //directory 
  public:
   void genetrateCodeClasses(){
       cout<<"Welcome to flight managment system\n";
       cout<<"----------------------------------------------------------------\n";
       cout<<endl;
       start:
       cout<<"1) add new trip information\n";
       cout<<"2) update privous trip information\n";
       cout<<"3) see privous trip information\n";
       cout<<"choose a number: ";
       cin>>choice;
       if(choice == 1){
         addNewTrip addTrip; // object from class situated in addNewTripInformation.h
         addPassangersInfo addPassangers; // object from class situated in addPassangersInformation.h
         addTrip.addTripInformations(dir); 
         addPassangers.addPassangersInformations(addTrip.getPassangerNumber());
         addPassangers.printPassangersInformations(dir,1,addTrip.getTripNumber(),0,addTrip.getCurrencyName(),addTrip.getEconomyPrice(),addTrip.getBusinessPrice(),addTrip.getFirstPrice());
       }
       else if(choice == 2){
         updateTripInformation update; // object from class situated in updateTripInformation.h
         if(update.updateTripInformations(dir) == "add"){
          addPassangersInfo addPassangers; // object from class situated in addPassangersInformation.h
          addNewTrip addTrip;
           addTrip.addPrices();
           addPassangers.addPassangersInformations(1);// 1 is number of passangers the user will add in the trip
           addPassangers.addNewPassangerInformation(dir,update.getTripNumber(),update.getPassangerNumber(dir),addTrip.getCurrencyName(),addTrip.getEconomyPrice(),addTrip.getBusinessPrice(),addTrip.getFirstPrice());
         }
         else if(update.updateTripInformations(dir) == "updatePassangerInfo"){

         }
         else if(update.updateTripInformations(dir) == "updateTripInfo"){

         }
       }
       else if(choice == 3){
          seeTripInformation seeTripInfo; // object from class situated in seeTripInformations.h
          seeTripInfo.seeTripIformations(dir); 
       } 
       cout<<endl;
       goto start;
   }

}; //class generateCode