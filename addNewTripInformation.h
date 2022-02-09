#include "mainHeaderFiles.h"

class addNewTrip{
 private:
  string tripNumber;
  int passangerNumber;
  string takeOffPlace;
  string takeOffTime;
  string tripDistination;
  string tripDuration;
  string currencyType;
  int businessPrice,economyPrice,firstPrice;
 public:

  void addTripInformations(string dir){
      cout<<"\nTrip Information: \n"
              "=================\n";
      cout<<"Trip Number: ";
      scanf("\n");
      getline(cin,tripNumber);
      cout<<"-------------------------\n";
       cout<<"Number of Passagers: ";
       cin>>passangerNumber;
       cout<<"Take off place: ";
       scanf("\n");
       getline(cin,takeOffPlace);
       cout<<"Take off time[houre:minute]: ";
       cin>>takeOffTime;
       cout<<"Trip distination: ";
       scanf("\n");
       getline(cin,tripDistination);
       cout<<"Trip duration[ex: 2h]: ";
       cin>>tripDuration;
       addPrices();
       dir="trips";
       mkdir(dir.c_str()); // some compilers you must add the pemission number like that mkdir(dir.c_str,0777);
       dir+="//"+tripNumber;
       mkdir(dir.c_str()); // some compilers you must add the pemission number like that mkdir(dir.c_str,0777);
       string tripInformation=dir;
       tripInformation+="//tripInformation.txt";
       ofstream tripNumberFile(tripInformation);
       tripNumberFile<<"Trip Number "<<tripNumber<<" informations:\n";
       tripNumberFile<<"-----------------\n";
       tripNumberFile<<"Number of passangers: "<<passangerNumber<<endl;
       tripNumberFile<<"Take off place: "<<takeOffPlace<<endl;
       tripNumberFile<<"Take off time: "<<takeOffTime<<endl;
       tripNumberFile<<"Trip distination: "<<tripDistination<<endl;
       tripNumberFile<<"Trip duration: "<<tripDuration<<endl;
       tripNumberFile.close();
   } //addTripInformations()

   void addPrices(){
      cout<<"\nPrices:\n";
       cout<<"Currency name: ";
       scanf("\n");
       getline(cin,currencyType);
       cout<<"Economy price: ";
       cin>>economyPrice;
       cout<<"Business price: ";
       cin>>businessPrice;
       cout<<"First price: ";
       cin>>firstPrice;
   }

   int getBusinessPrice(){
     return businessPrice;
   } //getBusinessPrice()
   
   int getEconomyPrice(){
     return economyPrice; 
   } //getEconomyPrice()

   int getFirstPrice(){
     return firstPrice;
   } //getFirstPrice()

   int getPassangerNumber(){
     return passangerNumber;
   }  //getPassangerNumber()

   string getTripNumber(){
     return tripNumber;
   } //getTripNumber()
   
   string getCurrencyName(){
     return currencyType;
   }// getCurrencyName()

}; //addNewTrip class
