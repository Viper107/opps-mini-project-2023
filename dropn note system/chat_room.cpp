//Welcome to drop a note
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const string USER_list="user.txt";
const string CHATROOM="chat.txt";

class chatRoom
{
    public:
    bool authent(string,int);
    void showcontent();
};

class user:public chatRoom
{
    public:
    string username;
    int password;
    void drop_message(string);
    
};

//chatroom functions
bool chatRoom:: authent(string username,int password){
    string cuser;
    string cpassword;
    string nusername="Name:"+username;
    string npassword="password:"+to_string(password);
    bool check;
    ifstream file(USER_list);
    if(file.is_open()){
        while(getline(file,cuser)){
            if(cuser==nusername){
                while(getline(file,cpassword)){
                    if(cpassword==npassword){
                        check=true;
                        return true;
                    }
                }
            }
            
        }
        if(!check){
                cout<<"\n----Invalid credentials-----"<<endl;
                return false;
                }
    } 
    else{
        cout<<"Unable to Authenticate!"<<endl;
        return false;

    }
    file.close();
    
}

void chatRoom::showcontent()
{
    string line;
        ifstream file(CHATROOM);
        if (file.is_open()) {
            // Read and print each line of the file
            while (getline(file,line)) {
                std::cout << line << std::endl;
            }

            file.close(); 
        } 
        else {
        std::cerr << "Unable to open the file.\n";
        }

}

void user::drop_message(string name)
{   
    string message;
    cout<<"Enter you message: "<<endl;
    cin>>ws;
    getline(cin,message);
    ofstream file(CHATROOM,ios::app); // Open file in output mode

    if(file.is_open()) {
        file<<endl<<name<<":"<<message;

        file.close(); // Close the file
        std::cout << "Content written to file successfully.\n";
    } else {
        std::cerr << "Unable to open the file.\n";
    }
}


int main(){

    int choice,ch;
    bool auth;
    user u1;
    c:
    cout<<"\n-----Welcome to drop box--------\n"<<endl;
    cout<<"\n1. Login                        \n"<<endl;
    cout<<"\n2. Exit                         \n"<<endl;
    cout<<"\n--------------------------------\n"<<endl;
    cout<<"\nEnter you choice:\n";
    cin>>ch;
    switch(ch){
        case 1:
        a:
        cout<<"\nEnter username(4 digit):\n"<<endl;
        cin>>u1.username;
        cout<<"\nEnter password:\n"<<endl;
        cin>>u1.password;
        auth = u1.authent(u1.username,u1.password);
        break;

        case 2:
        exit(0);
        break;

        default:
        cout<<"Invalid input!"<<endl;
        break;

    }

    

    if(auth){
        int ch;
        b:
        cout<<"\n------------Menu-------------\n"<<endl;
        cout<<"\n1.Read messages              \n"<<endl;
        cout<<"\n2.drop a message             \n"<<endl;
        cout<<"\n3.Exite                      \n"<<endl;
        cout<<"\n-----------------------------\n"<<endl;

        cout<<"\nEnter your choice:\n"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            u1.showcontent();
            goto b;
            break;

            case 2:
            u1.drop_message(u1.username);
            goto b;
            break;

            case 3:
            goto c;
            break;

            default:
            cout<<"Enter a valid input!"<<endl;
            break;
                    
        }

    }
    else{
        cout<<"\n----Invalid login----\n";
        goto a;
    }

    
    return 0;
}