//
//  main.cpp
//  CSCi375 proj2p2
//
//  Created by Abul Azad on 11/14/17.
//  Copyright © 2017 Group 2. All rights reserved.
//
//*************CODE ONLY ACCEPTS 1 READER OR 1 WRITER INTO CRITICAL SECTION*************
#include <iostream>
#include <time.h>
using namespace std;
int r1counter=1,r2counter=1,r3counter=1,w1counter=1,w2counter=1;//used for switch statments inside of r/p function
int rCount=0,wCount=0; //rCount/wCount tracks readers/writers in critical section
bool l = false;//lock value
//TEST AND SET FUNCTION
bool TaS(bool *lock){
    int Newlock = *lock;
    *lock= true;
    return Newlock;
}

//Random number generator
//generates number between 1 & 5
int rGenerator(){
    return rand()%(5) + 1;
}
//Panic message
//outputs panic message if critical section rules are broken
void panic(){
    cout<<"Panic!! More than maximum writer or reader present";
}

//Reader 1
void reader1(){
    switch (r1counter){
            //NON-CRITICAL SECTION
        case 1:cout<<"(r1N)I am reader 1 in the noncritical section, I am New Orleans weather channel"<<endl;r1counter++;break;
        case 2:cout<<"(r1N)New Orleans Weather 10/14/2017:Sunny"<<endl;r1counter++;break;
        case 3:cout<<"(r1N)New Orleans Weather 10/15/2017:partly cloudy"<<endl;r1counter++;break;
            //entering critical section
            //Runs test and set operation, if test and set operation works,switch counter increases
        case 4:if(l==true) {} else {cout<<"(r1C)r1 in critical section\n";TaS(&l);rCount++;r1counter++;};break;

            //
            //CRITICAL SECTION
            //outputs panic message if critical section rules are broken,else outputs who is in the critical section
        case 5:if(rCount-1>1||wCount>0){panic();} else{cout<<"I am reader 1,I see "<<rCount-1<<" readers and "<<wCount<< " writers\n";}r1counter++;break;
        case 6:cout<<"(r1C)WEATHER ALERT"<<endl;r1counter++;break;
        case 7:cout<<"(r1C)ALERT:Hurricane katrina is approaching"<<endl;r1counter++;break;
        case 8:cout<<"(r1C)Alert:Everyone Please go to safer destination"<<endl;r1counter++;break;
        case 9:cout<<"(r1C)Alert:Call police if you are having issues"<<endl;r1counter++;break;
        case 10:cout<<"(r1C)Alert:Please do not stay in your house"<<endl;r1counter++;break;
            //exiting critical section
            //changes to lock value to false to allow other function to enter critical section
        case 11:cout<<"(r1N)End READER 1 CRITICAL SECTION "<<endl;l= false;rCount--;r1counter++;break;
            //
            //NON-CRITICAL SECTION
        case 12:cout<<"(r1N)New Orleans Weather 11/16/2017:rainy"<<endl;r1counter++;break;
        case 13:cout<<"(r1N)New Orleans Weather 11/17/2017:slushy"<<endl;r1counter++;break;
        case 14:cout<<"(r1N)New Orleans Weather 11/18/2017:snowy"<<endl;r1counter++;break;
        case 15:cout<<"(r1N)New Orleans Weather 11/19/2017:thunderstorm"<<endl;r1counter++;break;
        case 16:cout<<"(r1N)New Orleans Weather 11/20/2017:snowy"<<endl;r1counter++;break;
        case 17:cout<<"(r1N)New Orleans Weather 11/21/2017:snowy"<<endl;r1counter++;break;
        case 18:cout<<"(r1N)New Orleans Weather 11/22/2017:partly cloudy"<<endl;r1counter++;break;
        case 20:cout<<"(r1N)New Orleans Weather 11/23/2017:cloudy"<<endl;r1counter++;break;
        case 21:cout<<"(r1N)New Orleans Weather 11/24/2017:sunny"<<endl;r1counter++;break;
        case 22:cout<<"(r1N)New Orleans Weather 11/25/2017:sunny"<<endl;r1counter++;break;
        case 23:cout<<"(r1N)New Orleans Weather 11/26/2017:sunny"<<endl;r1counter++;break;
        case 24:cout<<"(r1N)New Orleans Weather 11/27/2017:cloudy"<<endl;r1counter++;break;
        case 25:cout<<"(r1N)New Orleans Weather 11/28/2017:snowy"<<endl;r1counter++;break;
        case 26:cout<<"(r1N)New Orleans Weather 11/29/2017:snowy"<<endl;r1counter++;break;
        case 27:cout<<"(r1N)New Orleans Weather 11/30/2017:rainy"<<endl;r1counter++;break;
        case 28:cout<<"(r1N)New Orleans Weather 12/1/2017:cloudy"<<endl;r1counter++;break;
        case 29:cout<<"(r1N)New Orleans Weather 12/2/2017:cloudy"<<endl;r1counter++;break;
        case 30:cout<<"(r1N)New Orleans Weather 12/3/2017:cloudy"<<endl;r1counter++;break;
        default: break;
    }
}
//Reader 2
void reader2(){
    switch(r2counter){
            //NON-CRITICAL SECTION
        case 1:cout<<"(r2N)I am reader 2 in the noncritical section, I am Miami weather channel"<<endl;r2counter++;break;
        case 2:cout<<"(r2N)Miami Weather 10/14/2017:Sunny"<<endl;r2counter++;break;
        case 3:cout<<"(r2N)Miami Weather 10/15/2017:partly cloudy"<<endl;r2counter++;break;
            //entering critical section
            //Runs test and set operation, if test and set operation works,switch counter increases
        case 4:if(l==true) {} else {cout<<"(r2C)r2 in critical section\n";TaS(&l);rCount++;r2counter++;};break;
            //
            //CRITICAL SECTION
            //outputs panic message if critical section rules are broken,else outputs who is in the critical section
        case 5:if(rCount-1>1||wCount>0){panic();} else{cout<<"I am reader 2,I see "<<rCount-1<<" readers and "<<wCount<< " writers\n";}r2counter++;break;
        case 6:cout<<"(r2C)WEATHER ALERT"<<endl;r2counter++;break;
        case 7:cout<<"(r2C)ALERT:Hurricane John is approaching"<<endl;r2counter++;break;
        case 8:cout<<"(r2C)Alert:Everyone Please go to safer destination"<<endl;r2counter++;break;
        case 9:cout<<"(r2C)Alert:Call police if you are having issues"<<endl;r2counter++;break;
        case 10:cout<<"(r2C)Alert:Please do not stay in your house"<<endl;r2counter++;break;
            //exiting critical section
            //changes to lock value to false to allow other function to enter critical section
        case 11:cout<<"(r2N)End READER 2 CRITICAL SECTION "<<endl;l = false;rCount--;r2counter++;break;
            //
            //NON-CRITICAL SECTION
        case 12:cout<<"(r2N)Miami Weather 11/16/2017:rainy"<<endl;r2counter++;break;
        case 13:cout<<"(r2N)Miami Weather 11/17/2017:slushy"<<endl;r2counter++;break;
        case 14:cout<<"(r2N)Miami Weather 11/18/2017:snowy"<<endl;r2counter++;break;
        case 15:cout<<"(r2N)Miami Weather 11/19/2017:thunderstorm"<<endl;r2counter++;break;
        case 16:cout<<"(r2N)Miami Weather 11/20/2017:snowy"<<endl;r2counter++;break;
        case 17:cout<<"(r2N)Miami Weather 11/21/2017:snowy"<<endl;r2counter++;break;
        case 18:cout<<"(r2N)Miami Weather 11/22/2017:partly cloudy"<<endl;r2counter++;break;
        case 20:cout<<"(r2N)Miami Weather 11/23/2017:cloudy"<<endl;r2counter++;break;
        case 21:cout<<"(r2N)Miami Weather 11/24/2017:sunny"<<endl;r2counter++;break;
        case 22:cout<<"(r2N)Miami Weather 11/25/2017:sunny"<<endl;r2counter++;break;
        case 23:cout<<"(r2N)Miami Weather 11/26/2017:sunny"<<endl;r2counter++;break;
        case 24:cout<<"(r2N)Miami Weather 11/27/2017:cloudy"<<endl;r2counter++;break;
        case 25:cout<<"(r2N)Miami Weather 11/28/2017:snowy"<<endl;r2counter++;break;
        case 26:cout<<"(r2N)Miami Weather 11/29/2017:snowy"<<endl;r2counter++;break;
        case 27:cout<<"(r2N)Miami Weather 11/30/2017:rainy"<<endl;r2counter++;break;
        case 28:cout<<"(r2N)Miami Weather 12/1/2017:cloudy"<<endl;r2counter++;break;
        case 29:cout<<"(r2N)Miami Weather 12/2/2017:cloudy"<<endl;r2counter++;break;
        case 30:cout<<"(r2N)Miami Weather 12/3/2017:cloudy"<<endl;r2counter++;break;
        default: break;
    }
}
//Reader 3
void reader3(){
    switch(r3counter){
            //NON-CRITICAL SECTION
        case 1:cout<<"(r3N)I am reader 3 in the noncritical section, I am NYC weather channel"<<endl;r3counter++;break;
        case 2:cout<<"(r3N)NYC Weather 10/14/2017:Sunny"<<endl;r3counter++;break;
        case 3:cout<<"(r3N)NYC Weather 10/15/2017:partly cloudy"<<endl;r3counter++;break;
            //entering critical section
            //Runs test and set operation, if test and set operation works,switch counter increases
        case 4:if(l==true) {} else {cout<<"(r3C)r3 in critical section\n";TaS(&l);rCount++;r3counter++;};break;
            //
            //CRITICAL SECTION
            //outputs panic message if critical section rules are broken,else outputs who is in the critical section
        case 5:if(rCount-1>1||wCount>0){panic();} else{cout<<"I am reader 3,I see "<<rCount-1<<" readers and "<<wCount<< " writers\n";}r3counter++;break;
        case 6:cout<<"(r3C)WEATHER ALERT"<<endl;r3counter++;break;
        case 7:cout<<"(r3C)ALERT:Hurricane Urma is approaching"<<endl;r3counter++;break;
        case 8:cout<<"(r3C)Alert:Everyone Please go to safer destination"<<endl;r3counter++;break;
        case 9:cout<<"(r3C)Alert:Call police if you are having issues"<<endl;r3counter++;break;
        case 10:cout<<"(r3C)Alert:Please do not stay in your house"<<endl;r3counter++;break;
            //exiting critical section
            //changes to lock value to false to allow other function to enter critical section
        case 11:cout<<"(r3N)End READER 3 CRITICAL SECTION "<<endl;l = false;rCount--;r3counter++;break;
            //
            //NON-CRITICAL SECTION
        case 12:cout<<"(r3N)NYC Weather 11/16/2017:rainy"<<endl;r3counter++;break;
        case 13:cout<<"(r3N)NYC Weather 11/17/2017:slushy"<<endl;r3counter++;break;
        case 14:cout<<"(r3N)NYC Weather 11/18/2017:snowy"<<endl;r3counter++;break;
        case 15:cout<<"(r3N)NYC Weather 11/19/2017:thunderstorm"<<endl;r3counter++;break;
        case 16:cout<<"(r3N)NYC Weather 11/20/2017:snowy"<<endl;r3counter++;break;
        case 17:cout<<"(r3N)NYC Weather 11/21/2017:snowy"<<endl;r3counter++;break;
        case 18:cout<<"(r3N)NYC Weather 11/22/2017:partly cloudy"<<endl;r3counter++;break;
        case 20:cout<<"(r3N)NYC Weather 11/23/2017:cloudy"<<endl;r3counter++;break;
        case 21:cout<<"(r3N)NYC Weather 11/24/2017:sunny"<<endl;r3counter++;break;
        case 22:cout<<"(r3N)NYC Weather 11/25/2017:sunny"<<endl;r3counter++;break;
        case 23:cout<<"(r3N)NYC Weather 11/26/2017:sunny"<<endl;r3counter++;break;
        case 24:cout<<"(r3N)NYC Weather 11/27/2017:cloudy"<<endl;r3counter++;break;
        case 25:cout<<"(r3N)NYC Weather 11/28/2017:snowy"<<endl;r3counter++;break;
        case 26:cout<<"(r3N)NYC Weather 11/29/2017:snowy"<<endl;r3counter++;break;
        case 27:cout<<"(r3N)NYC Weather 11/30/2017:rainy"<<endl;r3counter++;break;
        case 28:cout<<"(r3N)NYC Weather 12/1/2017:cloudy"<<endl;r3counter++;break;
        case 29:cout<<"(r3N)NYC Weather 12/2/2017:cloudy"<<endl;r3counter++;break;
        case 30:cout<<"(r3N)NYC Weather 12/3/2017:cloudy"<<endl;r3counter++;break;
            
        default:break;
    }
}
//writer 1
void writer1(){
    switch(w1counter){
            //NON-CRITICAL SECTION
        case 1:cout<<"(w1N)I am writer 1 in the noncritical section,I am CNN\n";w1counter++;break;
        case 2:cout<<"(w1N)CNN Headline: Republicans lose Virginia\n";w1counter++;break;
        case 3:cout<<"(w1N)CNN Headline: Can drinking too much coffee kill you?\n";w1counter++;break;
        case 4:cout<<"(w1N)CNN Headline: GQ names Kaepernick Citizen of the Year\n";w1counter++;break;
        case 5:cout<<"(w1N)CNN Headline: UK government: Rohingya crisis 'looks like ethnic cleansing'\n";w1counter++;break;
        case 6:cout<<"(w1N)CNN Headline: Trump picks ex-pharma exec to lead HHS\n";w1counter++;break;
        case 7:cout<<"(w1N)CNN Headline: Biden leaves door open to 2020 bid\n";w1counter++;break;
        case 8:cout<<"(w1N)CNN Headline: US puts on 3-carrier show of force\n";w1counter++;break;
        case 9:cout<<"(w1N)CNN Headline: Bernie Sanders: Global oligarchy must end\n";w1counter++;break;
            //entering critical section
            //Runs test and set operation, if test and set operation works,switch counter increases
        case 10:if(l==true) {} else {cout<<"(w1C)W1 in critical section\n";TaS(&l);wCount++;w1counter++;};break;
            //
            //CRITICAL SECTION
            //outputs panic message if critical section rules are broken,else outputs who is in the critical section
        case 11:if(rCount>0||wCount-1>0){panic();} else{cout<<"I am writer 1,I see "<<rCount<<" readers and "<<wCount-1<<" writers\n";}w1counter++;break;
        case 12:cout<<"(w1C)BEGIN WRITER 1 CRITICAL SECTION\n";w1counter++;break;
        case 13:cout<<"(w1C)This is CNN Breaking News\n";w1counter++;break;
        case 14:cout<<"(w1C)TRUMP TRUSTS PUTIN\n";w1counter++;break;
        case 15:cout<<"(w1C)On Trumps trip to Vietnam,Trump says that he believes that\n";w1counter++;break;
        case 16:cout<<"(w1C)Putin did not meddle in U.S elections.\n";w1counter++;break;
        case 17:cout<<"(w1C)Despite confirmation from the NSA and the CIA,\n";w1counter++;break;
        case 18:cout<<"(w1C)Trump is ademant on believing that \n";w1counter++;break;
        case 19:cout<<"(w1C)Russia had no ties in Rigging the 2016 U.S election. \n";w1counter++;break;
        case 20:cout<<"(w1C)This is very concerning news. \n";w1counter++;break;
            //exiting critical section
            //changes to lock value to false to allow other function to enter critical section
        case 21:cout<<"(w1C)END OF CRITICAL SECTION"<<endl;l=false;wCount--;w1counter++;break;
            //
            //NON-CRITICAL SECTION
        case 22:cout<<"(w1N)CNN Headline: Did Trump and Duterte discuss human rights?\n";w1counter++;break;
        case 23:cout<<"(w1N)CNN Headline: Inside the site of the Texas mass shooting\n";w1counter++;break;
        case 24:cout<<"(w1N)CNN Headline: Lyft is coming to Canada\n";w1counter++;break;
        case 25:cout<<"(w1N)CNN Headline: Powerful Iran-Iraq earthquake is deadliest of 2017\n";w1counter++;break;
        case 26:cout<<"(w1N)CNN Headline: Eminem drops song with Beyonce\n";w1counter++;break;
        case 27:cout<<"(w1N)CNN Headline: Is Jerry Jones starting an NFL civil war? bid\n";w1counter++;break;
        case 28:cout<<"(w1N)CNN Headline: The island where people forget to die\n";w1counter++;break;
        case 29:cout<<"(w1N)CNN Headline: How to prevent Alzheimer's disease\n";w1counter++;break;
        default:break;
    }
}
//writer 2
void writer2(){
    switch(w2counter){
            //NON-CRITICAL SECTION
        case 1:cout<<"(w2N)I am writer 2 in the noncritical section,I am FOX\n";w2counter++;break;
        case 2:cout<<"(w2N)FOX Headline: New York Times photographer's 'revenge' on Trump/n";w2counter++;break;
        case 3:cout<<"(w2N)FOX Headline: Trump says Comey 'totally protected' Clinton, swipes at DOJ as new documents confirm claims\n";w2counter++;break;
        case 4:cout<<"(w2N)FOX Headline: Myanmar envoy denies genocide against Rohingya Muslims’\n";w2counter++;break;
        case 5:cout<<"(w2N)FOX Headline: UK government: Rohingya crisis 'looks like ethnic cleansing'\n";w2counter++;break;
        case 6:cout<<"(w2N)FOX Headline: Trump nominates Alex Azar for HHS secretary, replacing Tom Price\n";w2counter++;break;
        case 7:cout<<"(w2N)FOX Headline: Man helping neighbor with yardwork dies after falling into woodchipper\n";w2counter++;break;
        case 8:cout<<"(w2N)FOX Headline: GREGG JARRETT: Did Comey obstruct justice by protecting Hillary from prosecution?\n";w2counter++;break;
        case 9:cout<<"(w1N)FOX Headline: Supreme Court to hear crisis pregnancy centers' appeal\n";w2counter++;break;
            //entering critical section
            //Runs test and set operation, if test and set operation works,switch counter increases
        case 10:if(l==true) {} else {cout<<"(w2C)w2 in critical section\n";TaS(&l);wCount++;w2counter++;};break;
            //
            //CRITICAL SECTION
            //outputs panic message if critical section rules are broken,else outputs who is in the critical section
        case 11:if(rCount>0||wCount-1>0){panic();} else{cout<<"I am writer 2,I see "<<rCount<<" readers and "<<wCount-1<<" writers\n";}w2counter++;break;
        case 12:cout<<"(w2C)BEGIN CRITICAL SECTION"<<endl;w2counter++;break;
        case 13:cout<<"This is CNN Breaking News\n";w2counter++;break;
        case 14:cout<<"UPDATE ON BENGHAZI\n";w2counter++;break;
        case 15:cout<<"(w2C)New emails have been discovered from Hillary Clinton.\n";w2counter++;break;
        case 16:cout<<"(w2C)These were found on a house of representative's email.\n";w2counter++;break;
        case 17:cout<<"(w2C)The representative in question is Anthony Weiner.\n";w2counter++;break;
        case 18:cout<<"(w2C)Nothing can be said for sure what is in these emails,\n";w2counter++;break;
        case 19:cout<<"(w2C)but the FBI is sifting through these email to find anything incriminating\n";w2counter++;break;
        case 20:cout<<"(w2C)Could this finally mean Crooked Hillay is going to get locked up?\n";w2counter++;break;
            //exiting critical section
            //changes to lock value to false to allow other function to enter critical section
        case 21:cout<<"(w2C)END OF CRITICAL SECTION"<<endl;l=false;wCount--;w2counter++;break;
            //
            //NON-CRITICAL SECTION
        case 22:cout<<"(w2N)FOX Headline: Trump meets Australian, Japanese leaders to talk about China, North Korea?\n";w2counter++;break;
        case 23:cout<<"(w2N)FOX Headline: How Hillary Clinton’s 2020 hopes were ruined by Donna Brazile\n";w2counter++;break;
        case 24:cout<<"(w2N)FOX Headline: Dems mum on whether Menendez should step down if convicted\n";w2counter++;break;
        case 25:cout<<"(w2N)FOX Headline: Powerful Iran-Iraq earthquake is deadliest of 2017\n";w2counter++;break;
        case 26:cout<<"(w2N)FOX Headline: Iran-Iraq earthquake kills more than 400, officials say\n";w2counter++;break;
        case 27:cout<<"(w2N)FOX Headline: Actress Bijou Phillips accused by actor Daniel Franzese of assault, bullying bid\n";w2counter++;break;
        case 28:cout<<"(w2N)FOX Headline: George Takei told Howard Stern he grabbed men to 'persuade' them for sex\n";w2counter++;break;
        case 29:cout<<"(w2N)FOX Headline: Hate crimes rose for 2nd year in a row in 2016, FBI reports\n";w2counter++;break;
        default: break;
    }
}




//Main Function
int main(int argc, const char * argv[]) {
    int global_count;//Used to determine how long to run program
    srand((unsigned) time(NULL));//used for random number generator
    int n = 0,x;
    cout<<"How many times will you like to run the switch statement?:";
    cin >>x;
    while(global_count<x){//runs main switch statement based on user input
        n= rGenerator();
        //cout<<"rCount:"<<rCount<<"wCount:"<<wCount<<" n:"<<n<<endl;
        switch(n){//Uses random number generator to decide which function to run
            case 1:reader1();break;//runs function, breaks out to decide which function to run next
            case 2:reader2();break;
            case 3:reader3();break;
            case 4:writer1();break;
            case 5:writer2();break;
        }
        global_count++;
    }
    cout<<"Number of readers still in critical section:"<<rCount<<endl;
    cout<<"Number of writers still in critical section:"<<wCount<<endl;
    return 0;
}


