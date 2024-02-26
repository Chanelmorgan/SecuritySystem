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
            // register
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
            // login
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
            // change password
            case 3:{
                i =0;
                cout<<"-------------------------------"<< endl;
                cout<<"         Change password       " << endl;
                cout<<"|------------------------------|"<< endl << endl;

                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old password: -";
                cin>>old;
                if(of0.is_open()){
                    while(of0.eof()){
                        while(getline(of0, text));
                        istringstream iss(text);
                        iss>> word1;
                        cp[i] = word1;
                        i++; // so that the password will also get stored
                    }
                    if(old ==cp[1]){
                        of0.close();

                        ofstream of1;
                        if(of1.is_open()){
                            cout<<"You have entered an old password. Enter a new password:-  ";
                            cin>>password1;
                            cout<<"Enter your new password again :- ";
                            cin>>password2;
                            if(password1 == password2){
                                of1 <<cp[0]<<"\n";
                                of1 << password1;
                                cout <<"Password change successful!" << endl;
                            } else{
                                of1<<cp[0]<<"\n";
                                of1<<old;
                                cout<<"Password do not match" << endl;
                            }
                        }

                    } else{
                        cout << "Please enter a valid password! " << endl;
                        break;
                    }
                }

                break;
            }
            // end program
            case 4:{
                cout<<"--------- Thank you! ----------" << endl;

                break;
            }
            default:
                cout<<"Enter a valid choice!" << endl;
        }
    }





}


