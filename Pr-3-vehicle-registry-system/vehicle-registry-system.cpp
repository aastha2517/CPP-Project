 #include<iostream>
using namespace std;

class Vehicle{
	
	private:
		int vehicle_id;
		string manufacturer;
		string model;
		int year;
		
	public:
		string type;
		
		// static Variable
		static int totalVehicles;
		
		// Defult Constructor
		Vehicle(){
			
		}
		
		// Perametrized Constructor
		Vehicle(int id,string manufacturer,string model,int year,string type){
			this->vehicle_id=id;
			this->manufacturer=manufacturer;
			this->model=model;
			this->year=year;
			this->type=type;	
		}
		
		// Setter
		void setVehicleinfo(int id,string manufacturer,string model,int year,string type){
			this->vehicle_id=id;
			this->manufacturer=manufacturer;
			this->model=model;
			this->year=year;
			this->type=type;	
		}
		
		// Getter
		void getVehicleinfo(){
			cout<<endl;
			cout<<"Vehicle ID :"<<vehicle_id<<endl<<"Vehicle Manufacturer :"<<manufacturer<<endl
			<<"Vehicle Model :"<<model<<endl<<"Vehicle Year :"<<year<<endl;
		}
		
		string getType(){
			return type; 
		}
		int getId(){
			return vehicle_id; 
		}
		
		//Deconstrutor
		~Vehicle(){
			
		}
};

class Car : public Vehicle{
	private:
		string fuelType;
	public:
		
		// Defult Constructor
		Car(){
			
		}
		
		// Perametrized Constructor
		Car(int id,string manufacturer,string model,int year,string type,string fuelType)
		:Vehicle(id,manufacturer,model,year,type){
			this->fuelType=fuelType;	
		}
		
		// Setter
		void setCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType)
		{
			Vehicle::setVehicleinfo(id,manufacturer,model,year,type);
			this->fuelType=fuelType;	
		}
		
		// Getter
		void getCarinfo(){
			Vehicle::getVehicleinfo();
			cout<<"Fuel Type :"<<fuelType<<endl;
		}
	
		//Deconstrutor
		~Car(){
			
		}
};

class ElectricCar : public Car{
	private:
		int battery_capacity;
	public:
		
		// Defult Constructor
		ElectricCar(){
			
		}
		
		// Perametrized Constructor
		ElectricCar(int id,string manufacturer,string model,int year,string type,string fuelType,int battery)
		:Car(id, manufacturer, model, year,type, fuelType){
			this->battery_capacity=battery;	
		}
		
		// Setter
		void setElectricCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType,int battery)
		{
			Car::setCarinfo(id,manufacturer,model,year,type,fuelType);
			this->battery_capacity=battery;	
		}
		
		// Getter
		void getElectricCarinfo(){
			Car::getCarinfo();
			cout<<"Battery Capacity :"<<battery_capacity<<endl;
		}
		
		//Deconstrutor
		~ElectricCar(){
			
		}
};
class AirCraft{
	private:
		int flightRange;
	public:
		
		// Defult Constructor
		AirCraft(){
			
		}
		
		// Perametrized Constructor
		AirCraft(int range)
		{
			this->flightRange=range;	
		}
		
		// Setter
		void setAirCraftinfo(int range)
		{
			this->flightRange=range;	
		}
		
		// Getter
		void getAirCraftinfo(){
			cout<<endl;
			cout<<"Fight Range :"<<flightRange<<endl;
		}
	
		//Deconstrutor
		~AirCraft(){
			
		}
};
class FlyingCar : public Car, public AirCraft{
	private:
	public:
		
		// Defult Constructor
		FlyingCar(){
			
		}
		
		// Perametrized Constructor
		FlyingCar(int id,string manufacturer,string model,int year,string type,string fuelType,int range)
		:Car(id, manufacturer, model, year,type, fuelType),
		AirCraft(range)
		{
			
		}
		
		// Setter
		void setFlyingCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType,int range)
		{
			Car::setCarinfo(id,manufacturer,model,year,type,fuelType);
			AirCraft::setAirCraftinfo(range);
		}
		
		// Getter
		void getFlyingCarinfo(){
			Car::getCarinfo();
			AirCraft::getAirCraftinfo();
		}
		
		//Deconstrutor
		~FlyingCar(){
			
		}
	
};
class SportsCar : public ElectricCar{
	private:
		int Topspeed;
	public:
		
		// Defult Constructor
		SportsCar(){
			
		}
		
		// Perametrized Constructor
		SportsCar(int id,string manufacturer,string model,int year,string type,string fuelType,int battery,int speed)
		:ElectricCar(id,manufacturer,model,year,type,fuelType,battery){
			this->Topspeed=speed;	
		}
		
		// Setter
		void setSportsCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType,int battery,int speed)
		{
			setElectricCarinfo(id,manufacturer,model,year,type,fuelType,battery);
			this->Topspeed=speed;	
		}
		
		// Getter
		void getSportsCarinfo(){
			ElectricCar::getElectricCarinfo();
			cout<<"Top Speed :"<<Topspeed<<endl;
		}
	
		//Deconstrutor
		~SportsCar(){
			
		}
};
class Sedan: public Car{

	private:
	public:
		
		// Defult Constructor
		Sedan(){
			
		}
		
		// Perametrized Constructor
		Sedan(int id,string manufacturer,string model,int year,string type,string fuelType)
		:Car(id, manufacturer, model, year,type, fuelType){
				
		}
		
		// Setter
		void setSedaninfo(int id,string manufacturer,string model,int year,string type,string fuelType){
			Car::setCarinfo(id, manufacturer, model, year,type, fuelType);
		}
		
		// Getter
		void getSedaninfo(){
			Car::getCarinfo();
		}
		
		//Deconstrutor
		~Sedan(){
			
		}
	
};
class SUV: public Car{

	private:
	public:

		
		// Defult Constructor
		SUV(){
			
		}
		
		// Perametrized Constructor
		SUV(int id,string manufacturer,string model,int year,string type,string fuelType)
		:Car(id, manufacturer, model, year,type, fuelType){
				
		}
		
		// Setter
		void setSUVinfo(int id,string manufacturer,string model,int year,string type,string fuelType){
			Car::setCarinfo(id, manufacturer, model, year,type, fuelType);
		}
		
		// Getter
		void getSUVinfo(){
			Car::getCarinfo();
		}

		//Deconstrutor
		~SUV(){
			
		}
	
};

class VehicleRegistry:public ElectricCar,public SportsCar,public Sedan,public SUV{
	private:
		Vehicle *vehicleArr[100];
		int index=0;
	public:
		
		//Electric Car
		void addElectricCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType,int battery){
			ElectricCar *e=new ElectricCar(); //pointer-> address
			vehicleArr[index]=e; // [0]
			e->setElectricCarinfo(id,manufacturer,model,year,type,fuelType,battery);
			index++;
		}
		
		void addFlyingCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType,int range){
			FlyingCar *f=new FlyingCar();
			vehicleArr[index]=f; // SUV -> Vehcile
			f->setFlyingCarinfo(id,manufacturer,model,year,type,fuelType,range);
			index++;
		}
		
		void addSportsCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType,int battery,int speed){
			SportsCar *sp=new SportsCar();
			vehicleArr[index]=sp; // SUV -> Vehcile
			sp->setSportsCarinfo(id,manufacturer,model,year,type,fuelType,battery,speed);
			index++;
		}
		
		void addSedanCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType){
			Sedan *s=new Sedan();
			vehicleArr[index]=s; // SUV -> Vehcile
			s->setSedaninfo(id,manufacturer,model,year,type,fuelType);
			index++;
		}
		
		void addSUVCarinfo(int id,string manufacturer,string model,int year,string type,string fuelType){
			SUV *suv=new SUV();
			vehicleArr[index]=suv; // SUV -> Vehcile
			suv->setSUVinfo(id,manufacturer,model,year,type,fuelType);
			index++;
		}

		void displayinfo(){
			for(int i=0;i<index;i++){
				if(vehicleArr[i]->getType() == "ElectricCar"){
					((ElectricCar*)vehicleArr[i])->getElectricCarinfo();
					cout<<"-------------------------------------------"<<endl;
			
				}else if(vehicleArr[i]->getType() == "FlyingCar"){
					((FlyingCar*)vehicleArr[i])->getFlyingCarinfo();
					cout<<"-------------------------------------------"<<endl;
					
				}else if(vehicleArr[i]->getType() == "SportsCar"){
					((SportsCar*)vehicleArr[i])->getSportsCarinfo();
					cout<<"-------------------------------------------"<<endl;
					
				}else if(vehicleArr[i]->getType() == "SUV"){
					((SUV*)vehicleArr[i])->getSUVinfo();
					cout<<"-------------------------------------------"<<endl;
					
				}else if(vehicleArr[i]->getType() == "Sedan"){
					((Sedan*)vehicleArr[i])->getSedaninfo();
					cout<<"-------------------------------------------"<<endl;
					
				}
			}	
		}
		
		void search_id(int number){
			for(int i=0;i<index;i++){
				if(vehicleArr[i]->getId()==number){
					if(vehicleArr[i]->getType() == "ElectricCar"){
						((ElectricCar*)vehicleArr[i])->getElectricCarinfo();
						cout<<"-------------------------------------------"<<endl;
						return;
				
					}else if(vehicleArr[i]->getType() == "FlyingCar"){
						((FlyingCar*)vehicleArr[i])->getFlyingCarinfo();
						cout<<"-------------------------------------------"<<endl;
						return;
						
					}else if(vehicleArr[i]->getType() == "SportsCar"){
						((SportsCar*)vehicleArr[i])->getSportsCarinfo();
						cout<<"-------------------------------------------"<<endl;
						return;
						
					}else if(vehicleArr[i]->getType() == "SUV"){
						((SUV*)vehicleArr[i])->getSUVinfo();
						cout<<"-------------------------------------------"<<endl;
						return;
						
					}else if(vehicleArr[i]->getType() == "Sedan"){
						((Sedan*)vehicleArr[i])->getSedaninfo();
						cout<<"-------------------------------------------"<<endl;
						return;
						
					}
				}
				
			}
			cout<<"There is no Vehicle Registered from this ID......"<<endl;
			cout<<"-------------------------------------------"<<endl;
				
				
		}
		
		~VehicleRegistry(){
			for(int i=0;i<index;i++){
				delete vehicleArr[i];
			}
		}
		
		
};
int Vehicle ::totalVehicles=0;
int main(){
	
	int id,year,battery,speed,range,choice,v_choice;
	string model,manufacturer,fuel_type,type;
	VehicleRegistry r1;
	do{	
		cout<<"-------------------------------------------"<<endl;
		cout<<"Press 1 for Add Vehicle"<<endl;
		cout<<"Press 2 for Display Vehicles"<<endl;
		cout<<"Press 3 for Search Vechicle By Id"<<endl;
		cout<<"Press 4 for Exiting system...."<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"Enter Your Choice :";
		cin>>choice;
		switch(choice){
			case 1:	
			
				cout<<"-------------------------------------------"<<endl;
				cout<<"Press 1 for Add Electric Car"<<endl;
				cout<<"Press 2 for Add Flying Car"<<endl;
				cout<<"Press 3 for Add Sports Car"<<endl;
				cout<<"Press 4 for Add Sedan Car"<<endl;
				cout<<"Press 5 for Add SUV Car"<<endl;
				cout<<"-------------------------------------------"<<endl;
				cout<<"Enter Your Choice :";
				cin>>v_choice;
				
				switch(v_choice){
					case 1 :
						cout<<"Enter Vehicle Id :";
						cin>>id;
						cout<<"Enter Vehicle Manufacturer :";
						cin>>manufacturer;
						cout<<"Enter Vehicle Model :";
						cin>>model;
						cout<<"Enter Vehicle Year :";
						cin>>year;
						type="ElectricCar";
						cout<<"Enter Vehicle Fuel Type :";
						cin>>fuel_type;
						cout<<"Enter Vehicle Battery Capacity :";
						cin>>battery;
						
						r1.addElectricCarinfo(id,manufacturer,model,year,type,fuel_type,battery);							
						break;
					
					case 2 :
						cout<<"Enter Vehicle Id :";
						cin>>id;
						cout<<"Enter Vehicle Manufacturer :";
						cin>>manufacturer;
						cout<<"Enter Vehicle Model :";
						cin>>model;
						cout<<"Enter Vehicle Year :";
						cin>>year;
						type="FlyingCar";
						cout<<"Enter Vehicle Fuel Type :";
						cin>>fuel_type;
						cout<<"Enter Vehicle Range :";
						cin>>range;
						
						r1.addFlyingCarinfo(id,manufacturer,model,year,type,fuel_type,range);
						break;
					
					case 3 :
						cout<<"Enter Vehicle Id :";
						cin>>id;
						cout<<"Enter Vehicle Manufacturer :";
						cin>>manufacturer;
						cout<<"Enter Vehicle Model :";
						cin>>model;
						cout<<"Enter Vehicle Year :";
						cin>>year;
						type="SportsCar";
						cout<<"Enter Vehicle Fuel Type :";
						cin>>fuel_type;
						cout<<"Enter Vehicle Battery Capacity :";
						cin>>battery;
						cout<<"Enter Vahicle Speed :";
						cin>>speed;
						
						r1.addSportsCarinfo(id,manufacturer,model,year,type,fuel_type,battery,speed);
					
						break;
					
					case 4 :
						cout<<"Enter Vehicle Id :";
						cin>>id;
						cout<<"Enter Vehicle Manufacturer :";
						cin>>manufacturer;
						cout<<"Enter Vehicle Model :";
						cin>>model;
						cout<<"Enter Vehicle Year :";
						cin>>year;
						type="Sedan";
						cout<<"Enter Vehicle Fuel Type :";
						cin>>fuel_type;
						
						r1.addSedanCarinfo(id,manufacturer,model,year,type,fuel_type);
						break;
					
					case 5 :
						cout<<"Enter Vehicle Id :";
						cin>>id;
						cout<<"Enter Vehicle Manufacturer :";
						cin>>manufacturer;
						cout<<"Enter Vehicle Model :";
						cin>>model;
						cout<<"Enter Vehicle Year :";
						cin>>year;
						type="SUV";
						cout<<"Enter Vehicle Fuel Type :";
						cin>>fuel_type;
						
						r1.addSUVCarinfo(id,manufacturer,model,year,type,fuel_type);
						break;
					
					
					default :
						cout<<"Invalid Choice....";
						break;
					
				}
				break;
				
			case 2:
				r1.displayinfo();
				break;
				
			case 3:
				int num;
				cout<<"Enter Vehicle ID :";
				cin>>num;
				r1.search_id(num);
				break;
				
			default:
				cout<<"Exited From System......";
				break;
		}	
	}while(choice!=4);

	return 0;
}