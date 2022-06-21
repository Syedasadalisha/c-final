#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;

class bas 
{
  public:
  
  
  virtual void display_menu()=0;
};
class college:public bas{
	private:
		int id;
		char* name;
		string location;
		string degree;
	public:
		//constructor
		string date;
		college(int id=0,char *nam=(char*)"NO name",string location="tetova",string degree="none",string date="14/3/2003")
		{
			this->id=id;
		   int n=strlen(name);
		   name=new char[n+1];
		   strcpy(name,nam);
		   name[n]='\0';
		   this->location=location;
		   this->degree=degree;
		   this->date=date;
		}
		//copy constructor
		college(college &m)
		{
			this->id=id;
			int n=strlen(m.name);
		   name=new char[n+1];
		   strcpy(name,m.name);
		   name[n]='\0';
		   this->location=m.location;
		   this->degree=m.degree;
		   this->date=m.date;
		   //destructor	
		}
		//getfunction
		int getId()
		{
			return id;
		}
		char *getName(){
			return name;
		}
		string getlocation()
		{
			return location;
		}
		string getDegree()
		{
			return degree;
		}
		//setFunction
		void setName(char *nam)
		{
			this->id=id;
			int n=strlen(nam);
		   name=new char[n+1];
		   strcpy(name,nam);
		   name[n]='\0';
			
				}	
		void setId(int id)
		{
			this->id=id;
			}	
		void setLocation(string location)
		{
			this->location=location;
			
		}
		void setDegree(string degree)
		{
			this->degree=degree;
		}
		void input()
		{
		    cout<<"\n\t\t\tAffiliated college data Entry:";
		cout<<"\n Date:";
			cin>>date;
			cout<<"College-id :";
			cin>>id;
			cout<<"Name :";
			cin>>name;
			cout<<"Lacation :";
			cin>>location;
			cout<<"Degree :";
			cin>>degree;	
		}
		virtual void display_menu()
		{
		    fstream file;
		    input();
		    file.open("collegerecord.txt",ios::app |ios::out);
		    
		    
		    file<<left<<setw(13)<<date<<setw(13)<<id<<setw(13)<<name<<setw(13)<<location
		    <<setw(13)<<degree<<endl;
		    file.close();
		    
		    
		}
};
class full:public college
{
   public:
   int n;
   virtual void display_menu()
   {    
       cout<<"\n\t\t University Managment system:";
       cout<<"\n\n\t\t 1.College Affiliated: "
           <<"\n\t\t 2.Students";
       
       cout<<"\n\n\n Where you want to go:";
       cin>>n;
       if(n==1)
       college::display_menu();
   }
    
};
int main()
{ full f1;
   f1.display_menu();
    return 0;
}
