/*
 Eloisa Rueals
    CSC 7 Mastermind AI
  December 12th, 2021
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

//Function Prototypes
string AI(char,char);
bool eval(string,string,char &,char &);
string setCode();


int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    
    //Initialize Values
    nGuess=0;
    code=setCode();
    rr=rw=0;
    
    //Loop until solved and count to find solution
    do{
       nGuess++;
       guess=AI(rr,rw);
       
      //cout<<code<<" "<<guess << " " <<endl;
    }while( eval(code,guess,rr,rw));
    //Check evaluation
    //cout << "This is the guess " << endl;
    cout<<nGuess<<" "<<code<<" "<<guess<<endl;
    guess=AI(rr,rw);
    
  /*  for(int i=0;i<10000;i++){
        guess=AI(0,0);
        eval(code,guess,rr,rw);
        cout<<setw(5)<<code<<setw(5)<<guess
                <<setw(2)<<static_cast<int>(rr)
                <<setw(2)<<static_cast<int>(rw)<<endl;
    }
    */
    //Exit the program
    return 0;
}

string AI(char rr,char rw){
    //Define helper functions here



    //Save the historical values of guesses and results
    static const int SIZE=10000;//How many guesses to save
    static string aGuess[SIZE]; //Save the guesses
    static int guess=0;         //Increment the guess number
    string sGuess= "1122";       //Size the guest string
    static set<string> guessed;
    vector<string> num;

    //fill set of all possible guesses at first guess.
    if(guess == 0)
    {
        string temp="0000";
        for(int i =0; i < 10; i++)
        {
            for(int j =0; j < 10; j++)
            {
                for(int k= 0; k< 10; k++)
                {
                    for(int m = 0; m<10; m++)
                    {
                        temp[0]= i+'0';
                        temp[1]= j+'0';
                        temp[2]= k+'0';
                        temp[3]= m+'0';
                        guessed.insert(guessed.end(),temp);
                 
                    }
                }
            }
        }
       
       
    }
    //after the first guess, check new guess against rr and rw
    else{
        char prr= 0;
        char prw= 0;
        sGuess = aGuess[guess-1];
        //cout << "we are in else " <<endl;
        //cout <<"What is sGuess " << sGuess << endl;
        for (auto itA = guessed.begin(); itA != guessed.end(); ++itA)//iterate through the set of guesses
        {   //*itA;
            
           eval(sGuess,*itA,prr,prw);//check each guess in the set and update prr and prw
           //cout << "PRR " << prr-0 << " " << "PRW " << prw-0;
           //cout << " RR " << rr-0<< " " << "RW " << rw-0 << endl;
           if(prr != rr || prw != rw)// compare prr/prw against rr/rw, if prr/prw != rr/rw then guess is incorrect.
           {
               num.push_back(*itA);
           }
           
        }
        
        for(int y =0; y< num.size(); y++)
        {
            std::set<string>::iterator it = guessed.find(num[y]);
            guessed.erase(it);
            
        }
        //check what is in the guessed set
       /* 
        for(auto itC=guessed.begin(); itC!=guessed.end(); ++itC)
        {
          cout << ' ' << *itC;
        }
        */
        int r = rand()%guessed.size();
       
        
        auto itB = next(guessed.begin(),r);
        //cout << "what is IT " << *itB << " " << endl;
        //auto itB = guessed.begin();
        sGuess = *itB;
        //cout << "What is new guess " << sGuess << endl;
               
        }
    
    aGuess[guess] = sGuess;
    //guessed.insert(sGuess);
    guess++;

   
    return sGuess;

    //Return the result
    //return sGuess;
}

bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    //Found or not
    if(rr==4)return false;
    return true;
}

string setCode(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}