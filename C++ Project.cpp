#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;

struct Member{ string name; float due; };
vector<Member> members;

void addMember(){
    Member newMember;
    string name;
    cout<<"\nEnter Member Name: ";
    cin.ignore();
    getline(cin,name);
    newMember.name = name;
    newMember.due = 0;
    members.push_back(newMember);
}

void listMembers(){
    cout<<"\nMembers List\n";
    cout<<"-----------------\n";
    for(int i=0; i<members.size(); i++){
        cout<<i+1<<". "<<members[i].name<<endl;
    }
    cout<<"-----------------\n";
}

void addExpense(){
    listMembers();
    string payer;
    float amount;
    cout<<"\nEnter Payer Name: ";
    cin.ignore();
    getline(cin,payer);
    cout<<"Enter Amount: ";
    cin>>amount;
    int due = -(amount / members.size());
    for(int i=0; i<members.size(); i++){
        if(members[i].name != payer){
            members[i].due +=  due;
        }
    }
    cout<<"\n \"Expense Added Successfully\" \n";
}

vector<Member> calculateNetBal(vector<Member> members)
{
    for (int i = 0; i < members.size(); i++) {
    for (int j = 0; j < members.size(); j++) {
      if (i != j) {
        if (members[i].due > members[j].due) {
          float diff = members[i].due - members[j].due;
          members[i].due -= diff;
          members[j].due += diff;
        }
      }
    }
  }
  return members;
}

void storeExpense(){
    ofstream outfile;
    outfile.open("Expense.txt");
             outfile<<"-----------------\n";
             outfile<<"-----------------\n";
                for (int i =0 ; i<members.size() ; i++){
            outfile << "\t" << members[i].name  ; }
            outfile << endl;
    for(int i=0; i<members.size(); i++){
        outfile << members[i].name <<  " :   " ;

            for(int j=0; j<members.size(); j++){
                    if(members[i].name==members[j].name ){
                        outfile << 0 ;
                        outfile <<"\t" ;}
                    else outfile << members[i].due <<"\t" ;
    }
    outfile<< endl;
    }
    outfile<<"-----------------\n";
    outfile<<"-----------------\n";
    outfile.close();
    cout<<"\n \" Expenses Stored in File Successfully \" \n";
}
void Expense_History()
{
    char a;
   ifstream read("Expense.txt");
   string text;
   while(getline(read,text)){
    cout<<text<<endl;
   } read.close();
}


int main(){
    system("color B1");
    int choice;
    char c;
    cout<<"\t\t\t*Implementation of Shared Expenses Management System*" <<endl;
    cout<<"\t\t\t\t\t\t*(SEMS)*"<<endl;
    do{
        cout<<"\n Select your desired option"<<endl;
        cout<<"1. Add Member\n";
        cout<<"2. Add Expense\n";
        cout<<"3. Calculate Net Balance\n";
        cout<<"4. Store Expense\n";
        cout<<"5. Expense History\n";
        cout<<"6. List all Members\n";
        cout<<"7. Exit\n";
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        switch(choice){
            case 1: addMember(); break;
            case 2: addExpense(); break;
            case 3: calculateNetBal(members); break;
            case 4: storeExpense(); break;
            case 5: Expense_History(); break;
            case 6: listMembers(); break;
            case 7:  break;
            default: cout<<"Invalid Choice\n";
        }
    }while(choice<7);
    return 0;
}
