/* 
 * File:   main.cpp
 * Author: Eloisa Ruelas
 * Created on November 11th, 2021, 08:00 AM
 * Purpose:  Stub to use for calculating/comparing the Arithmetic Mean
 *           and the Geometric Mean
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
#include <cmath>      //Math Library
#include <iomanip>    //Format Library
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void fillAry(char [],int);
void chkSame(char[], char[], int, int, int);
 

//Functions you are to write and use to show the Theorem


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    int codeSize=4;
    int rightN =0;
    int rightW=0;
    int sum =0;
   
    //validate user input

    int perLine = codeSize;//used for display of hint output.
    char array[codeSize];// stores the mastermind code
    char guess[codeSize] = {'0','0','0','0'};//the guess array counter
    //char contPly;// if the user wants to continue playing
    
    
    fillAry(array,codeSize);// fills the master code
    cout<< "Code "<< setw(5) <<"Guess "<< setw(7)<<"#right "<<setw(15)
            <<"#right in wrong spot "<<setw(5)<<"Sum "<<endl;
    chkSame(guess,array,rightN,rightW,sum);
    
    //cout <<array<< setw(5)<< guess << endl;
    

        for(int i=0; i<=9; i++)
        {
            for(int j=0; j<=9;j++)
            {
                for(int k=0; k<=9;k++)
                {
                    for(int m=0; m<=9; m++)
                    {
                        guess[0]=48+i;
                        guess[1]=48+j;
                        guess[2]=48+k;
                        guess[3]=48+m;

                        cout <<array<< setw(5)<< guess<< setw(7)<< rightN<<setw(15)
            <<rightW<<setw(5)<< sum <<endl;
                        
                    }
                }
            }
        }

        
        
        
     *
            

        


    

    //Display the results
       
    cout << "End Game " << endl;
    //Map inputs to outputs here, i.e. the process
    

    return 0;
}

 void chkSame(char guess[], char array[], int rightN, int rightW, int sum)
 {
  
     for(int i = 0; i<=4;i++)
     {
         if( guess[i] == array[i])
         {
             rightN+=1;
         }
         
     }
     
    unordered_set<char> check[4];
    
    
    for (int j = 0; j <= 4; j++) 
    {
        char a[]={0};
        a[0]=array[j]
        check.insert(a);
    }
    for (int k = 0; k <=4; k++) {
        if(check.find(guess[k]) == set.end() && guess[k] != array[k])
        {
            rightW+=1;
        }
    }

    sum = rightN + rightW;
     
     
     
 }
      


void fillAry(char a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%9+'0';//[0,9]
    }
}
/*
char rndDgit(){
    return rand()%10+'0';//Ascii Code for numbers '0'=48 and '9'=57
    //return rand()%10+48;//Ascii Code for numbers '0'=48 and '9'=57
}*/