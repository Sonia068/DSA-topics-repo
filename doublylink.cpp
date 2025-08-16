// Doubly Linked List 
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(){
        data=0;
        next=NULL;
        prev=NULL;
    }

    node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }
};

class list{
    public:
    node*head;
    list(){
        head=NULL;
    }

    void insertend(int v);
    void insertbeg(int v);
    void insertMid(int v,int p);
    void insertindex(int v,int index);
    void navigate(int k);
    void display();
    void del_beg();
    void del_end();
    void del_mid(int pos);
    void del_pos(int pos);

};

    void list:: insertend(int value){
        node*newnode=new node(value);
        if(head==NULL){
            head=newnode;
        }
        else{
            node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            newnode->prev=temp;
            temp->next=newnode;

        }
    }

    void list ::insertbeg(int value){
        node*newnode=new node(value);
        if(head==NULL){
             head=newnode;
        }
        else{
          newnode->next=head;
          head->prev=newnode;
          head=newnode;
        }
    }

    void list ::insertMid(int value,int pos){
        node*newnode=new node(value);
        if(head==NULL){
            head=newnode;
        }
        else{
            node*temp=head;
            for(int i=1;i<pos-1&& temp->next!=NULL;i++){
                temp=temp->next;
            }
        
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
        }  }
      

        void list:: insertindex(int value,int index){
            node* newnode=new node(value);
            if(index<=0){
                cout<<"Invalid choice!"<<endl;
                return;
            }
            if(index==1){
                if(head!=NULL){
                newnode->next=head;
                head->prev=newnode;
            }
                head=newnode;    
                return;
            }

            if(head==NULL){
              head=newnode;
              return;
           }    

            else{
                node* temp=head;
            for(int i=1;i<index-1 && temp->next!=NULL;i++){
                temp=temp->next;
            }
        
            newnode->next=temp->next;
            if(temp->next!=NULL){
            temp->next->prev=newnode;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
    }

    void list::navigate(int key) {
    if (head == NULL) {
        cout << "LL is empty" << endl;
        return;
    }
    node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with key " << key << " not found" << endl;
        return;
    }
    if (temp->prev != NULL)
        cout << "Previous node: " << temp->prev->data << endl;
    else
        cout << "Previous node is not found (Key is at head)" << endl;

    if (temp->next != NULL)
        cout << "Next node: " << temp->next->data << endl;
    else
        cout << "Next node is not found (Key is at tail)" << endl;
}

    void list::del_beg(){
            if(head==NULL){
                cout<<"ll is empty";
            }
            else{
               node*temp=head;
               head=head->next;
               head->prev=NULL;
               delete temp;
            }
        }

    void list:: del_end(){
           if(head==NULL){
               cout<<"ll is empty";
           }
           else{
               node*temp=head;
               while(temp->next!=NULL){
                temp=temp->next;
               }
               temp->prev->next=NULL;
               delete temp;
            }
       }
            
    void list::del_mid(int pos){
            if(head==NULL){
                cout<<"LL is empty";
            }
            else{
                node*temp=head;
                for(int i=1;i<pos &&temp!=NULL;i++){
             
                  temp=temp->next;
            }
             temp->prev->next = temp->next;
             temp->next->prev = temp->prev;
             delete temp; 
       }
   }

void list::del_pos(int pos) {
    if (head == NULL) {
        cout << "LL is empty" << endl;
        return;
    }

    if (pos <= 0) {
        cout << "Invalid pos!" << endl;
        return;
    }

    node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Index out of bounds." << endl;
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
        return;
    }


    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    delete temp;
}



   void list:: display(){
        if(head==NULL){
           cout<<"DLL is empty";
        }

        else{
            node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
        cout<<"NULL"<<endl;
    }


 int main(){
    list obj;

    int value;
    int pos;
    int key;
    int ch;
    do{
    cout<<"\n MENU:"<<endl;
    cout<<"1) INSERT AT START:"<<endl;
    cout<<"2) INSERT AT END:"<<endl;
    cout<<"3) INSERT AT POSITION:"<<endl;
    cout<<"4) INSERT IN BETWEEN:"<<endl;
    cout<<"5) AFTER NAVIGATE KEY,GIVE PREVIOUS AND NEXT NODE:"<<endl;
    cout<<"6) DELETE FROM BEGINNING:"<<endl;
    cout<<"7) DELETE FROM END:"<<endl;
    cout<<"8) DELETE FROM MID:"<<endl;
    cout<<"9) DELETE FROM POSITION:"<<endl;
    cout<<"10)DISPLAY THE LINKED LIST:"<<endl;
    cout<<"11) EXIT:"<<endl;

    cout<<"\n Enter the choice:"<<endl;
    cin>>ch;

 
    switch(ch){
        case 1:
        cout<<" Enter the node:"<<endl;
        cin>>value;
        obj.insertbeg(value);
        break;
        
        case 2:
        cout<<"Enter the node:"<<endl;
        cin>>value;
        obj.insertend(value);
        break;

        case 3:
       cout<<"Enter the node and position you want to insert:"<<endl;
       cin>>value>>pos;
        obj.insertindex(value,pos);
        break;

        case 4:
        cout<<"Enter the node and position you want to insert:"<<endl;
        cin>>value>>pos;
        obj.insertMid(value,pos);
        break;

        case 5:
        cout<<"Enter the data of the node(key) you want to navigate:"<<endl;
        cin>>key;
        obj.navigate(key);
        break;

        case 6:
        obj.del_beg();
        break;

        case 7:
         obj.del_end();
         break;

        case 8:
        cout<<"Enter the position of node you want to delete :"<<endl;
        cin>>pos;
        obj.del_mid(pos);
         break;

        case 9:
        cout<<"Enter the position of node you want to delete :"<<endl;
        cin>>pos;
        obj.del_pos(pos);
         break;

        case  10:
        obj.display();
        break;

        case 11:
        cout<<"EXIT"<<endl;
        break;

        default:
        cout<<"Invalid choice"<<endl;
    
       }   }while(ch!=11);


    return 0;

 }
    






