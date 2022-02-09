#include "mainHeaderFiles.h"

class addPassangersInfo{
 private:
  map<string,string>passangersInfo; //first string passanger name | second string passanger class
  map<string,string>::iterator it; //it is an iterator
 public:

  string classNameCorrector(string arg){ //return passanger class name
     if( arg == "e" || arg =="economy" || arg=="Economy"){
       return "economy";
      }
      else if( arg == "b" || arg =="business" || arg =="Business"){
        return "business";
      }
      else if( arg == "f" || arg =="first" || arg =="First"){
         return "first";
      }
      return "Default class";
   }

   void addPassangersInformations(int passangerNumber){
     cout<<"\nPassangers informations: \n";
     cout<<"---------------------------------\n";
     string name;
     string className;
     for(int i=0; i <passangerNumber ; i++){
       cout<<endl;
       cout<<"Passanger number "<<i+1<<":\n"<<endl;
       cout<<"Name: ";
       scanf("\n");
       getline(cin,name);
       className:
       cout<<"Class[Economy(e)/Business(b)/First(f)]: ";
       scanf("\n");
       getline(cin,className);
       className=classNameCorrector(className);
       if(className== "Default class"){
         cout<<endl<<"The class name is inccorect please repeat entering class name\n";
         goto className;
       }
       passangersInfo[name]=className;
     }
   } //addPassangersInformations

    void printPassangersInformations(string dir,int i,string tripNumber,int cheak,string currencyType,int economyPrice,int businessPrice,int firstPrice){ // cheak the caller of this method
     string passangerInformation=dir;
     passangerInformation+="//"+tripNumber;
     passangerInformation+="//passangerInformation.txt";
     ofstream passangerInformationFile(passangerInformation);
     if(cheak == 0){
       passangerInformationFile<<"Passanger Information:\n";
       passangerInformationFile<<"--------------------------------------------"; 
     }
     int count=i;
     passangerInformationFile<<endl<<endl;
     for(it=passangersInfo.begin() ; it!=passangersInfo.end() ; it++){
       passangerInformationFile<<"Passanger Number "<<count<<":"<<endl;
       passangerInformationFile<<"Name: "<<(*it).first<<endl;
       passangerInformationFile<<"Class: "<<(*it).second<<endl;
       if(  (*it).second =="economy" ){
         passangerInformationFile<<"Ticket price: "<<economyPrice<<" "<<currencyType<<endl;
        }
       else if(  (*it).second =="business" ){
         passangerInformationFile<<"Ticket price: "<<businessPrice<<" "<<currencyType<<endl;
       }
       else if(  (*it).second =="first" ){
         passangerInformationFile<<"Ticket price: "<<firstPrice<<" "<<currencyType<<endl;
        }
       passangerInformationFile<<endl;
       count++;
     } //end for
     passangerInformationFile.close(); // close passanger information file
     passangersInfo.clear();//clear the map
   }

   void addNewPassangerInformation(string dir,string tripNumber,int i,string currencyType,int economyPrice,int businessPrice,int firstPrice){
     dir+="//"+tripNumber+"//passangerInformation.txt";
     FILE *file=fopen(dir.c_str(),"a+");
     int count=i;
     for(it=passangersInfo.begin() ; it!=passangersInfo.end() ; it++){
       fprintf(file,"Passanger Number %d:\n",count);
       fprintf(file,"Name: %s\n",(*it).first.c_str());
       fprintf(file,"Class: %s\n",(*it).second.c_str());
       if(  (*it).second =="economy" ){
         fprintf(file,"Ticket price: %d %s\n",economyPrice,currencyType.c_str());
        }
       else if(  (*it).second =="business" ){
         fprintf(file,"Ticket price: %d %s\n",businessPrice,currencyType.c_str());
       }
       else if(  (*it).second =="first" ){
         fprintf(file,"Ticket price: %d %s\n",firstPrice,currencyType.c_str());
        }
       fprintf(file,"\n");
       count++;
     } //end for
     fclose(file); // close passanger information file
     passangersInfo.clear();//clear the map
   }
}; // class addPassangersInformation