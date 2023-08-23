
#include <iostream>
using namespace std;
class Student {
	protected:
		string name;
		int rollnumber;
		
	public:
	void set_name(string x){
		
		name=x;
		
	}
	void set_rollnumber(int y){
		
		rollnumber=y;
		
	}
		
};

class Hostel {
protected:
    std::string name;

public:
    //Hostel(const std::string& hostelName) : name(hostelName) {}
    
    Hostel(string name){
    	
    	this->name=name;
	}

    string getName() const {
        return name;
    }
};




class hostalized_student : public Student{
	
	private:
		string room_number;
		int room_rent;
		bool rent_status;
		Hostel* hostel; // Aggregation with Hostel object or student staying in a particular Hostel
		
		
    public:
    	hostalized_student(string room_number,bool rent_status,int room_rent,Hostel* hostel){
    		this->hostel=hostel;
    		this->room_number=room_number;
    		this->rent_status=rent_status;
    		this->room_rent=room_rent;
		}
  
	void display(){
		cout<<"Name of the student is: "<< name<<endl;       
		cout<<"Rollnumber of the student is: "<< rollnumber<<endl;
		cout<<name<<":Staying in:"<<hostel->getName()<<"\n";    // With the help of aggregation we are accessing getname method of hostel class 
		cout<<name<<":Staying in roomnumber:"<<room_number<<"\n";
		cout<<"Room rent is :"<<room_rent<<"\n";     
	}
	
	void pay_rent(){
		
		if(rent_status)	{
			cout<<"rent already paid"<<endl;
		}
		else {
			cout<<"Rent of the current month not paid yet"<<endl;
		}
		
	}
	
};

int main(){	

     Hostel hostelobject=Hostel("Star hostel");    //hostel object of hostel class 
     hostalized_student hostal_detail("1001",false,6000,&hostelobject); 
     
     
     hostal_detail.set_name("Ahmad"); //With the help of inheritence used set name method of student class 
     hostal_detail.set_rollnumber(10);
	

	//hostal_classobject.set_rent_status();            
	hostal_detail.display();
	hostal_detail.pay_rent();
	
			
}
