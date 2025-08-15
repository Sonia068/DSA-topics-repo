#include <iostream>
using namespace std;
class node {
public:
    string data;
    node* next;
    node(){
        data=" ";
        next=0;
    }
    node(string song){
        data = song;
        next = NULL;
    }
};
class playlist {
public:
    node* head;

    playlist() {
        head = NULL;  
    }
    void insertend(string song);
    void insertbeg(string song);
    void delbeg();
    void delend();
    void delpos(int pos);
    void navigate(string key);
    void print();
};
    void playlist:: insertend(string song) {
        node* newnode = new node(song);
         if(head == NULL) {
            head = newnode;
           return; 
        }
        node* t = head;
        while (t->next != NULL) {  
            t = t->next;
        }
        t->next = newnode;  
    }
    void playlist::insertbeg(string song)
    {
        node* newnode = new node(song);
        if(head==NULL)
        {
            head=newnode;
        }
        else{
        newnode-> next =head;
        head=newnode;
    }}
    void playlist::delbeg(){
        if (head==NULL){
            cout<<"Playlist is empty";
        }
        else{

            node* temp = head;
            head = head->next;
            delete temp;
    }}
    void playlist::delend(){
        if(head==NULL){
            cout<<"Playlist is empty";
        }
        else
        {
            node* t = head;
            while(t->next->next != NULL) {
            t = t->next;
            }
            delete t->next;
             t->next = NULL;
        }}
    void playlist::delpos(int pos) {
    if (head == NULL) {
        cout << "LL is empty" << endl;
        return;
    }

    if (pos < 0) {
        cout << "Invalid pos!" << endl;
        return;
    }

    if (pos == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* prev = head;
    node* temp = head->next;

    for (int i = 1; i < pos; i++) {
        if (temp == NULL) { 
            cout << "Index out of bounds." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) { 
        cout << "Index out of bounds." << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void playlist::navigate(string key) {
    if (head == NULL) {
        cout << "Playlist is empty" << endl;
        return;
    }

    node* temp = head;
    node* prev = NULL;


    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Song not found" << endl;
        return;
    }
    if (prev != NULL)
        cout <<"Previous Song:"<<prev->data << endl;
    else
        cout << "Previous song is not found (Key is at head)" << endl;
    if (temp->next != NULL)
        cout <<"NEXT SONG :"<< temp->next->data << endl;
    else
        cout << "Next song is not found (Key is at tail)" << endl;
}
 void playlist::print() {
        if (head == NULL) {
            cout << "Playlist is empty"<<endl;
           return;
        }
        node* t = head;
        while (t  != NULL) {
            cout << t->data << "->";
            t = t->next;
        }
            cout<<"NULL";
            cout<<endl;
    }

int main(){
      playlist obj;
    int choice;
    string song;
    string  key;
    int pos;
    do{
        cout<<"------------------------------"<<endl;
        cout<<"SELECT YOUR CHOICE"<<endl;
        cout<<"1.Songs can be added at the  beginning:\n";
        cout<<"2.Songs can be added at the  end:\n";
        cout<<"3.Songs can be deleted from the end:\n";
        cout<<"4.Songs can be deleted from the beginning:\n";
        cout<<"5.Songs can be deleted from a particular position:\n";
        cout<<"6.Navigate the previous and next song:\n";
        cout<<"7.Print the list\n";
        cout<<"8.EXIT\n";

        cout<<"Enter your choice:\n";
        cin>>choice;
        switch(choice) {
            case 1:
                cout << "Enter song to insert at beginning: ";
                cin.ignore();
                getline(cin,song);
                obj.insertbeg(song);

                break;
            case 2:
                cout << "Enter song to insert at end: ";
                cin.ignore();
                getline(cin,song);
                obj.insertend(song);
                break;
            case 3:
                obj.delend();
                break;
            case 4:
                obj.delbeg();
                break;
            case 5:
                cout<<"Enter the song's position you want to delete:\n";
                cin>>pos;
                obj.delpos( pos);
                break;
            case 6:
                cout<<"Enter the song or key which is  used to navigate previous and next song :\n";
                cin.ignore();
                getline(cin,key);
                obj.navigate( key);
                break;
            case 7:
                obj.print();
                break;
            case 8:
                cout<<"EXIT"<<endl;
                break;
            default:
                cout << "Invalid choice\n";
                break;
        } } while(choice != 8);

return 0;
}


    


   

