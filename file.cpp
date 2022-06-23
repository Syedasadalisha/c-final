

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

class student:public bas{
    private:
    int studentid;
    string studentname;
    string fathername;
    string address;
    string faculty;
    public:
    student(int i=1,string n="no",string fn="No",string ad="no",string fa="cs")
    {
        studentid=i;
        studentname=n;
        fathername=fn;
        address=ad;
        faculty=fa;
    }
    //getfunction
    int getsid()
    {
        return studentid;
    }
    string getsname()
    {
        return studentname;
    }
    string getsfathername()
    {
        return fathername;
    }
    string getaddress()
    {
        return address;
    }
    string getfaculty()
    {
        return faculty;
    }
    //set setfunction
   void setsid(int i)
   {
       studentid=i;
   }
   void setsname(string n)
   {
       studentname=n;
   }
   void setfathername(string fa)
   {
       fathername=fa;
   }
   void setaddress(string add)
   {
       address=add;
   }
   void setfaculty(string f)
   {
       faculty=f;
   }
  
   void display_menu()
   {
       fstream s_file;
      cout<<"\n\t\t student data Entry ";
      cout<<"\n\t\t  student Id : ";cin>>studentid;
      cout<<"\n\t\t Student Name: ";cin>>studentname;
      cout<<"\n\t\t  Father Name ";cin>>fathername;
      cout<<"\n\t\t Address : ";cin>>address;
      cout<<"\n\t\t Faculty : ";cin>>faculty;
      s_file.open ("studentrecord.txt", ios::app | ios::out);
    
 
 
s_file << left << setw (13) << studentid << setw (13) << studentname << setw (13) <<
      fathername << setw (13) << address
 <<setw (13) << faculty;
    
s_file << endl;
    
s_file.close ();
   }
     void disp()
   {
       ifstream output("studentrecord.txt",ios::in);
       if(!output)
       {
           cerr<<"\n NOt opening";
           exit(1);
       }
           
           while(output>>studentid>>studentname>>fathername>>address>>faculty)
           {
               cout<< left << setw (13) << studentid << setw (13) << studentname << setw (13) <<
      fathername << setw (13) << address
 <<setw (13) << faculty;
           }
       
      output.close(); 
   }
  
   
};


void set()
{
    student s;
    college *c;
    int n;
      cout<<"\n\t\t University Managment system:";
       cout<<"\n\n\t\t 1.College Affiliated: "
           <<"\n\t\t 2.Students"
           <<"\n\t\t 3.Display student data";
       
       cout<<"\n\n\n Where you want to go:";
       cin>>n;
       if(n==1)
       c->display_menu();
       if(n==2)
       s.display_menu();
       if(n==3)
       s.disp();
        else
       {
           cout<<"\n  select again:";
       set();
       }
    
}

int main()
{ 
     set(); 
       
}
