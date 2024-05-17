#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class STNODE
{
    int number;
    string name;
    int progarming_score;
    int english_score;
    STNODE*ptr;
    
    
    public:
    void writeno(int a) { number = a; }
    int  readno() { return number; }
    
    void writeptr(STNODE* b) {  ptr = b; }
    STNODE* readptr() {
        return ptr;}
        
    void writename(string c ) {name= c;
//        for(int i=0;i<9;i++)
//        name[i]=c[i];
        //name=c;//use string
       
    }
    string readname(){
        return name;
    }
    
    void writeprg(int d) { progarming_score = d; }
    int readprg(){
        return progarming_score;
    }

    void writeeng(int e) {english_score = e; }
    int readeng(){
        return english_score;
    }
    STNODE(){progarming_score=0;english_score=0;}
    
};

class MENU{
    int select;
    public:
        void show(){cout<<"MENU"<<endl<<"1.Insertion"<<endl<<"2.Search"<<endl<<"3.Deletion"<<endl<<"4.Print List Data\n"<<"5.Transcript"<<endl<<"0.Exit"<<endl<<"Please select one\n";}
        int readselect(){return select;
        }
        void writeselect(int s){select=s;}
        MENU(){select=1;}
        
    
};

class linklist {
    
    STNODE *head;
    public:
        linklist(){ head=NULL;}
        bool Isempty(){
            return head;
        }
        void printlist();
        void add();
        void search();
        void Delete ();
        void printNode(STNODE *head);
        //bool mycompare(STNODE front,STNODE back);
        void transcript();
        
        
    
};//end

void linklist::printlist()
{
    cout << "head->";
    STNODE* a=head;
    while (a) {
        cout << a->readno() << "->";
        a = a->readptr();
    }
    cout << "||" << endl;
}

void linklist::add()
{
    STNODE* end =head;
    STNODE* current;
    STNODE* back;
    STNODE* front=NULL;
    int n;
    string name;//Êîπstring ÁúãÁúã
    int score1;
    int score2;
    cout << "please input number: ";
    cin >> n;
    while (n<=0)
    {
        cout<<"number is not exist"<<endl;
        cout<<"please input number again:"<<endl;
        cin>>n;
     }
            
            if(1){
            
                
    
                if (head == NULL)
                {
                    current = new STNODE;
                    current->writeno(n);
                    head = current;
                    current->writeptr(NULL);
                    end = current;
                    cout<<"please input name(less than 20 words):";
                    cin.get();
                    getline(cin,name);
                    
                    current->writename(name);
                    
                    
                    cout<<"please input score_prg :";
                    cin>>score1;
                    while (score1<0||score1>100)
                    {
                        cout<<"please input again:";
                        cin>>score1;
                        
                    }
                    current->writeprg(score1);
                    
                    
                    cout<<"please input score_cmp:";
                    cin>>score2;
                    while (score2<0||score2>100)
                    {
                        cout<<"please input again";
                        cin>>score2;
                        
                    }
                    current->writeeng(score2);
                    cout<<endl;

                    
                    

                }
                else
                  {
                      back=head;
                      front=NULL;
    
                      while (back->readptr()&&back->readno()<n)
                      {
                          front=back;
                          back=back->readptr();
                      }
                    if(back->readno()==n)
                    {cout<<"this number has aready existed\n";
                    
                        
                    }
                    else{
                    
                        current = new STNODE;
                        current->writeno(n);
                      cout<<"please input name(less than 20 words):";
                    cin.get();
                    getline(cin,name);
                      current->writename(name);
                      
                      
                      cout<<"please input score_prg :";
                      cin>>score1;
                      while (score1<0||score1>100)
                      {
                          cout<<"please input again:";
                          cin>>score1;
                          
                      }
                      current->writeprg(score1);
                      
                      
                      cout<<"please input score_eng:";
                      cin>>score2;
                      while (score2<0||score2>100)
                      {
                          cout<<"please input again:";
                          cin>>score2;
                          
                      }
                      current->writeeng(score2);
                      cout<<endl;
                        
                        back=head;
                        front=NULL;
                        if((back->readno())>n)//fornt
                        {
                          
                          current->writeptr(head);
                          head=current;
                        }
                      
                        while((back->readno())<=n&&back->readptr())
                        {
                            front=back;
                            back=back->readptr();
                        
    
                        if((back->readno())>=n)//middle
                        {
    
                            
                                front->writeptr(current);
                                current->writeptr(back);
                                break;
                        }
    
    
                      }
    
                      if((back->readno())<=n&&back->readptr()==NULL) //back
                        {
                            back->writeptr(current);
                            current->writeptr(NULL);
                        }
                }

       }}

    }
    
void linklist::search()//s=select number
{
    cout<<"please input search name:";
        string name;
        cin.get();
        getline(cin,name);
        if (head!=NULL)
        {
            
            STNODE*find=head;

            while(find->readptr()&&find->readname()!=name)
            {
                find=find->readptr();
                
            }
            
            if(find->readname()==name)
            {
                cout<<"name:"<<find->readname()<<endl;
                cout<<"number:"<<find->readno()<<endl;
                cout<<"programing's score:"<<find->readprg()<<endl;
                cout<<"english's score:"<<find->readeng()<<endl;


                     while(find->readptr())
                        {
                        find=find->readptr();
                
                   
                        if(find->readname()==name)
                           {
                        cout<<"name:"<<find->readname()<<endl;
                        cout<<"number:"<<find->readno()<<endl;
                        cout<<"programing's score:"<<find->readprg()<<endl;
                        cout<<"computer science's score:"<<find->readeng()<<endl;
                            }
                    }

//
            }
            else
            {
                cout<<" this student is not exist"<<endl;
            }
        }
        else
        {cout<<"this list is empty"<<endl;
        }
}

void linklist::Delete ()
{
    STNODE* back;
    STNODE* front=NULL;
    int n;
    cout << "please input number: ";
    cin >> n;
    while (n<=0)
    {
        cout<<"number is not exist"<<endl;
        cout<<"please input number again:"<<endl;
        cin>>n;
    }
    

        if(head!=NULL)
        {
            back=head;
            
            
            while (back->readptr()&&back->readno()<n)
            {
                front=back;
                back=back->readptr();
            }
            if (back->readno()==n)
            {//Á†çÊéâÈÇ£ÂÄãnode
                if (back==head)
                {
                    if (back->readptr()==NULL)
                    {
                        head=NULL;
                    }
                    else
                    {
                        head=back->readptr();
                    }
                    
                }
                else if(back->readptr()&&back!=head)
                {
                    back=back->readptr();
                    front->writeptr(back);
                    
                }
                else if(back->readptr()==NULL&&back!=head)
                {
                    front->writeptr(NULL);
                    
                }
            cout<<"the number delect successfully\n";
            }
            else
            {
                cout<<"the number is not exist\n";
            }
            
            
            
        }
        else
        {cout<<"the list is empty,please add number first"<<endl;}
}

//void sortrank(STNODE *head,int c){
//int scores[c];
//for(int i=0;i<c;i++)
//{
//  scores[i]=(head->readeng()+head->readprg());
//  }
//sort(scores,scores+c,greater<int>());
//
//}
//
//void printrank(int &scores,int c,int t)
//{
//int rank;
//int ranks[c];
//ranks[0]=1;
//for(int i=1;i<c;i++)
//{rank=rank+1;
//ranks[i]=rank;
//if (scores[i]==scores[i-1])
//{ranks[i]==ranks[i-1];
//}

//
// }
// cout<<"≤ƒ"<<ranks[t]<<"¶W"<<endl;
//}

void linklist::printNode(STNODE *head){

    cout << "================" << endl
         << "Name: "
         << head->readno() << endl
         << "Number: "
         << head->readname()<< endl
         << "Programing Score: "
         << head->readprg()  << endl
         << "English Score: "
         << head->readeng()  << endl
         <<"Total:"
    <<head->readprg()+head->readeng()<<endl
    << "================" << endl;
    
        
}

bool mycompare(STNODE *front,STNODE *back)//depend what do you want to compare
{
//    return (front->readprg())
//           > (back->readprg());
        return (front->readprg()+front->readeng())> (back->readprg()+back->readeng());
        return true;
}

void linklist::transcript()
{
    

    
    if(head==NULL)
    {
        cout << "Database is NULL!" << endl;
    }
    else{
    
    STNODE *times=head;
    int count=0;
    while (times!=NULL) {
        count++;
        times=times->readptr();
        
    }
    times=head;
    STNODE *nodes[count];
    for(int i=0;i<count;i++)
    {
        nodes[i]=times;
        times=times->readptr();
    }
    sort(nodes,nodes+count,mycompare);
//    for(int i=0;i<count;i++)
//    {
//    sortrank(nodes[i],count);
//    }
       

    cout<<"NO1\n";
    printNode(nodes[0]);
    int rank=1;
    int again=0;
    for(int i=1;i<count;i++)
    {
      /*put rank here*/
    if ((nodes[i-1]->readprg()+nodes[i-1]->readeng())==(nodes[i]->readprg()+nodes[i]->readeng()))
    {
    again++;
    cout<<"NO"<<rank<<"\n";
    }
    else
    {
    rank=again+rank+1;
    again=0;
    cout<<"NO"<<rank<<"\n";
    }
// printrank(scores,cout,i);
       printNode(nodes[i]);

    }
}

    
    
}

int main(){
    MENU m;
    //STNODE* head = NULL;
    linklist list1;
    int s;
    while(m.readselect()){
        m.show();
        cin>>s;
        m.writeselect(s);

        if(m.readselect()){
        
        switch(m.readselect()){
            case 1:
                if (m.readselect()==1)
                {
                    list1.add();
                  
                }
                break;
            case 2:
                if (m.readselect()==2)
                {
                  
                 list1.search();
                }

                break;
            case 3:
                if (m.readselect()==3)
                {
                    list1.Delete();
                    
                }
                break;
            case 4:
                if (m.readselect()==4)
                {
                 list1.printlist();
                 cout<<endl;
                }
                break;
            case 5:
                 if (m.readselect()==5)
                {
                list1.transcript();
                }
                break;
            default:
                {
                    cout<<"please select correct number\n";
                }
                
                break;
                
        }
    
    }
    }
    
    
}

