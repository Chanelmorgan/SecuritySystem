//
// Created by Chanel Morgan on 26/02/2024.
//

#include "System.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){

    // variables
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<"         Security System   " << endl;
    cout<<"-------------------------------"<< endl;
    cout<<"|        1. Register           |"<< endl;
    cout<<"|        2. Login              |"<< endl;
    cout<<"|        3. Change password    |"<< endl;
    cout<<"|        4. End Program        |"<< endl;
    cout<<"-------------------------------"<< endl<< endl;

    do{
        cout << endl << endl;
        cout << "Enter your choice:- ";
        cin >> a;
        switch(a){
            case 1:{
                cout<<"-------------------------------"<< endl;
                cout<<"           Register            " << endl;
                cout<<"|------------------------------|"<< endl << endl;
                // getting the users variables
                cout<<"Username: ";
                cin>>name;
                cout<<"Password: ";
                cin>>password0;
                cout<<"Age: ";
                cin>>age;

                // writing the users details to a file
                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1 << name<<"\n";
                    of1 << password0 <<"\n";
                    cout << "Registration successful" << endl;
                }

                break;
            }
            case 2: {
                cout<<"-------------------------------"<< endl;
                cout<<"           Login               " << endl;
                cout<<"|------------------------------|"<< endl << endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Username:- ";
                cin>>user;
                cout<<"Password:- ";
                cin>>pass;

                if(of2.is_open()){
                    // this is the end of file function
                    while(!of2.eof()){
                        // reading the file line by line
                        while(getline(of2, text)){
                            istringstream iss(text);
                            iss>>word;
                            creds[i]=word; // first the user name is stored then move to the next pos
                            i++;
                        }
                        // checking the user information matches
                        if(user == creds[0] && pass == creds[1]){
                            cout <<"---- Log in successful ----";
                            cout << endl << endl;
                            cout << "Details: "<<endl;
                            cout << "Username: " + name<<endl;
                            cout <<"Password: " + name<<endl;
                            cout<<"Age: " + age << endl;
                        } else{
                            cout << endl << endl;
                            cout <<"Incorrect Credentials"<< endl;
                            cout <<"|       1. Press 2 to login            |" << endl;
                            cout <<"|       1. Press 3 to change password  |" << endl;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }





}


