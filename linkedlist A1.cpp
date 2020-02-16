#include<iostream>
#include<fstream>
#include<conio.h>
#include<ctime>
#include<cctype>
#include<iomanip>
#include<string.h>
using namespace std;
struct date
{
	int dd, mm, yyyy;
	void display()
	{
		cout<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<yyyy<<"\t";
	}
	
};
int datecmpi(date a, date b)
{
	if(a.yyyy>=b.yyyy)
		return a.yyyy-b.yyyy;
	else
		{
			if(a.mm>=b.mm)
				return a.mm-b.mm;
				else
				{
					if(a.dd>=b.dd)
						return a.dd-b.dd;
					else
						return -1;
				}
		}
}
int count=1;

fstream fil;
ofstream o;
fil.open("datab.dat",ios::in| ios::binary);
if(!fil)
{
	count=0;
}
else
{	
	while(!fil.eof())
	{
		fil.read((char*)&s, sizeof(s));
		count++;
	}
}
fil.close();
class student
{	
	public:
	int roll;
	char name[30], fname[30], addr[100];
	struct date dob, doj;
	void heading()
	{
		cout<<setw(10)<<left<<"Roll no."<<setw(25)<<left<<"Name"<<setw(25)<<left<<"Father's Name"<<setw(15)<<left<<"D.O.B"<<setw(15)<<left<<"D.O.J"<<"Address"<<endl;
		
	}
	void show()
	{
			cout<<setw(10)<<left<<roll<<setw(25)<<left<<name<<setw(25)<<left<<fname;
			dob.display();
			doj.display();
			cout<<addr<<endl;
	}
	int getrecuser(int c)
	{
		roll=c;
		cout<<"Enter the name(Only alphabets and spaces):"<<endl;
//		cin>>name;
		cin.getline(name, 30);
		if(!checkname(name))
		{
			cout<<"Invalid Name!!! No special characters or Numerics!";
			return 0;
		}
		cout<<"Enter the Father's name(Only alphabets and spaces):"<<endl;
		cin.getline(fname, 30);
		if(!checkname(fname))
		{
			cout<<"Invalid Name!! No special characters or Numerics!";
			return 0;
		}
		cout<<"Enter the Date of Birth(dd/mm/yyyy):"<<endl;
		scanf("%d/%d/%d", &(dob.dd), &(dob.mm), &(dob.yyyy));
		if(!check(dob, 'b'))
		{
			cout<<"Invalid Date of Birth!!!"<<endl;
			return 0;
		}
		cout<<"Enter the Date of joining(dd/mm/yyyy):"<<endl;
		scanf("%d/%d/%d", &(doj.dd), &(doj.mm), &(doj.yyyy));
		if(!check(doj, 'j'))
		{
			cout<<"Invalid Date of Joining!!!"<<endl;
			return 0;
		}	
		cout<<"Enter the Address:"<<endl;
		cin.getline(addr, 100);
		return 1;

	}
	private:
	bool checkname(char str[30]);
	bool isleap(int y);
	bool check(struct date d, char type);
	int getNumberOfDays(int month,int year);
}s;
void swap(student array[], int y)
{

					
						student temp = array[y+1];
		
						array[y+1] = array[y];
		
						array[y] = temp;
}
void sorteddisplay(int n, int field)
{
	fil.open("datab.dat", ios::in | ios::binary );
	student array[n];
	if(!fil)
	{
		cout<<"File not Found";
	}
	else
	{
		fil.read((char*)array, n*sizeof(s));	
	}
	fil.close();
	
	for(int x=0; x<n; x++)

	{

		for(int y=0; y<n-1; y++)

		{

			switch(field)
			{
				case 1:
					if(strcmpi(array[y].name,array[y+1].name)>0)
					{
						swap(array, y);
					}
					break;
				case 2:
					if(strcmpi(array[y].fname,array[y+1].fname)>0)
					{
						swap(array, y);
					}
					break;
				case 5:
					if(strcmpi(array[y].addr,array[y+1].addr)>0)
					{
						swap(array, y);
					}
					break;
				case 0:
					if(array[y].roll>array[y+1].roll)
					{
						swap(array, y);
					}
					break;
				case 3:
					if(datecmpi(array[y].dob,array[y+1].dob)>0)
					{
						swap(array, y);
					}
					break;
				case 4:
					if(datecmpi(array[y].doj,array[y+1].doj)>0)
					{
						swap(array, y);
					}
					break;
				
			}

		}

	}
	array[0].heading();
	for(int i=0;i<n;i++)
	{
		array[i].show();
	}
}
int student::getNumberOfDays(int month,int year){ 
   switch(month){
      case 1 : return(31);
      case 2 : if(isleap(year))
		 return(29);
	       else
		 return(28);
      case 3 : return(31);
      case 4 : return(30);
      case 5 : return(31);
      case 6 : return(30);
      case 7 : return(31);
      case 8 : return(31);
      case 9 : return(30);
      case 10: return(31);
      case 11: return(30);
      case 12: return(31);
      default: return(-1);
   }
}
bool student::check(struct date d, char type)
{
	if(type=='j')
	{
		time_t t=time(0);
		struct tm *now= localtime(&t);
		if((now->tm_year)%100<d.yyyy%100 || 2002>d.yyyy)
		{
				  	return 0;
		}
		else if(now->tm_year==d.yyyy)
		{
			if(now->tm_mon<d.mm)
			{
					return 0;

			}
			else if(now->tm_mon==d.mm)
				if(now->tm_mday<d.dd)
				  {

					return 0;
					}
		}
	}
	else
	{
		if(d.yyyy>=2001 || d.yyyy<=1984)
			return 0;
	}
	if(d.dd<=getNumberOfDays(d.mm, d.yyyy) && d.dd>0)
		return 1;
	return 0;
	
}
bool student::isleap(int y)
{
	if(y%4==0)
	{
		if(y%100==0)
		{
			if(y%400==0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}
bool student::checkname(char str[30])
{
	int i=0;
	while(str[i]!='\0')
	{
		if(!isalpha(str[i]) && str[i]!=' ')
			return 0;
		i++;
	}
		return 1;	
}

int main()
{	
    	int roll;
    	int flag=0;
		char choice;
		int sch=0;

    while(1){
        system("cls");
        printf("1.Add a student's record.\n");
        printf("2. Delete a student's record.\n");
        printf("3. Update a student's record'\n");
        printf("4. Print all Records.\n");
        printf("5. Print a particular Record.\n");
        printf("6.Sort the list.\n");
        
        printf("7. EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        choice=getche();
        system("cls");
        switch(choice){
            case '1':
				if(s.getrecuser(++count))
				{
					fstream f("datab.dat", ios::binary | ios::out |ios::app);
					f.write((char*)&s, sizeof(s));
					f.close();
					cout<<"Records successfully added!!";
				}
				else
					cout<<"Records couldn't be added."<<endl;
                printf("\nPress any key to continue......");
                getch();
                break;
            case '2' :
				cout<<"Enter the Roll no. to delete the record:\n";
				cin>>roll;
				flag=0;
				o.open("new.dat",ios::out|ios::binary);
				fil.open("datab.dat",ios::in| ios::binary);
				if(!fil)
				{
					cout<<"File not Found";
					exit(0);
				}
				else
				{
					fil.read((char*)&s, sizeof(s));
					while(!fil.eof())
					{
						if(s.roll!=roll)
						{
							o.write((char*)&s, sizeof(s));
							flag=1;
						}
		
						fil.read((char*)&s, sizeof(s));
					}
				}
				if(flag)
					cout<<"Record Deleted!!!\n";
				else
					cout<<"Record not found!!";
				o.close();
				fil.close();
				remove("datab.dat");
				rename("new.dat", "datab.dat");			
                break;
            case '3':
					
					cout<<"Enter the Roll no. to update the record:\n";
					cin>>roll;
					flag=0;
					fil.open("datab.dat",ios::in| ios::out|ios::binary);
					if(!fil)
					{
						cout<<"File not Found";
						exit(0);
					}
					else
					{
						fil.read((char*)&s, sizeof(s));
						while(!fil.eof())
						{
							if(s.roll==roll)
							{
								fil.seekg(0,ios::cur);
								cout<<" RECORD FOUND!! Enter New Record..\n"<<endl;
								s.getrecuser(roll);
								fil.seekp(fil.tellg() - sizeof(s));
								fil.write((char*)&s, sizeof(s));
								flag=1;
							}
							
							fil.read((char*)&s, sizeof(s));
						}
						if(flag)
							cout<<"Record Updated!!!\n";
						else
							cout<<"Record not found!!";
					}
					getch();
					fil.close();
				break;
            case '4':
				    fil.open("datab.dat",ios::in| ios::binary);
					if(!fil)
					{
						cout<<"File not Found";
					}
					else
					{	s.heading();
						fil.read((char*)&s, sizeof(s));
						while(!fil.eof())
						{
							s.show();
							fil.read((char*)&s, sizeof(s));
						}
					}
					fil.close();
					getch();
                break;
            case '5':
            	cout<<"Enter the roll no. to fetch the details:";
            	cin>>roll;
            	flag=0;
				            	fil.open("datab.dat",ios::in| ios::binary);
					if(!fil)
					{
						cout<<"File not Found";
						exit(0);
					}
					else
					{
						fil.read((char*)&s, sizeof(s));
						while(!fil.eof())
						{
							if(s.roll==roll)
							{							
								s.heading();
								s.show();
								flag=1;
								cout<<"Press Any Key...."<<endl;
								getch();
							}
							fil.read((char*)&s, sizeof(s));
						}
					}
					if(!flag)
						cout<<"Records not found!!!"<<endl;
					fil.close();
					getch();
                break;
            case '6':
            	 cout<<"Which field to be considered while sorting?"<<endl;
            	 cout<<"0 for roll no."<<endl;
            	 cout<<"1 for name"<<endl;
            	 cout<<"2 for Father's name"<<endl;
            	 cout<<"3 for Date of Birth"<<endl;
            	 cout<<"4 for Date of Joining"<<endl;
            	 cout<<"5 for Address"<<endl;
            	 cout<<"Enter your choice:";
            	 cin>>sch;
            	 sorteddisplay(count, sch);
                 getch();
			    break;
            case '7' :
                exit(0);
                break;
        }
    }
	return 1;
}
