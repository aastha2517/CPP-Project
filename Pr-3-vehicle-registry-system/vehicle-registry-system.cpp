#include<iostream>
using namespace std;

class Vehicle{
	private:
		int vehicle_id;
		string manufacturer;
		string model;
		int year;
	public:
		// static Variable
		static int totalVehicles;
		
		// Defult Constructor
		Vehicle(){
			
		}
		
		// Perametrized Constructor
		Vehicle(int id,string manufacturer,string model,int year){
			this->vehicle_id=id;
			this->manufacturer=manufacturer;
			this->model=model;
			this->year=year;	
		}
		
		// Setter
		void setVehicleinfo(int id,string manufacturer,string model,int year){
			this->vehicle_id=id;
			this->manufacturer=manufacturer;
			this->model=model;
			this->year=year;	
		}
		
		// Getter
		void getVehicleinfo(){
			cout<<endl;
			cout<<"Vehicle ID :"<<vehicle_id<<endl<<"Vehicle Manufacturer :"<<manufacturer<<endl
			<<"Vehicle Model :"<<model<<endl<<"Vehicle Year :"<<year <<endl;
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
		Car(int id,string manufacturer,string model,int year,string fuelType):Vehicle(id,manufacturer,model,year){
			this->fuelType=fuelType;	
		}
		
		// Setter
		void setCarinfo(int id,string manufacturer,string model,int year,string fuelType)
//		:Vehicle(id,manufacturer,model,year)
		{
			Vehicle::setVehicleinfo(id,manufacturer,model,year);
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
		ElectricCar(int id,string manufacturer,string model,int year,string fuelType,int battery)
		:Car(id, manufacturer, model, year, fuelType){
			this->battery_capacity=battery;	
		}
		
		// Setter
		void setElectricCarinfo(int id,string manufacturer,string model,int year,string fuelType,int battery)

		{
			Car::setCarinfo(id,manufacturer,model,year,fuelType);
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
		FlyingCar(int id,string manufacturer,string model,int year,string fuelType,int range)
		:Car(id, manufacturer, model, year, fuelType),
		AirCraft(range)
		{
			
		}
		
		// Setter
		void setFlyingCarinfo(int id,string manufacturer,string model,int year,string fuelType,int range)
		{
			Car::setCarinfo(id,manufacturer,model,year,fuelType);
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
		SportsCar(int id,string manufacturer,string model,int year,string fuelType,int battery,int speed)
		:ElectricCar(id,manufacturer,model,year,fuelType,battery){
			this->Topspeed=speed;	
		}
		
		// Setter
		void setSportsCarinfo(int id,string manufacturer,string model,int year,string fuelType,int battery,int speed)
		{
			setElectricCarinfo(id,manufacturer,model,year,fuelType,battery);
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
		Sedan(int id,string manufacturer,string model,int year,string fuelType)
		:Car(id, manufacturer, model, year, fuelType){
				
		}
		
		// Setter
		void setSedaninfo(int id,string manufacturer,string model,int year,string fuelType){
			Car::setCarinfo(id, manufacturer, model, year, fuelType);
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
		SUV(int id,string manufacturer,string model,int year,string fuelType)
		:Car(id, manufacturer, model, year, fuelType){
				
		}
		
		// Setter
		void setSUVinfo(int id,string manufacturer,string model,int year,string fuelType){
			Car::setCarinfo(id, manufacturer, model, year, fuelType);
		}
		
		// Getter
		void getSUVinfo(){
			Car::getCarinfo();
		}
		
		//Deconstrutor
		~SUV(){
			
		}
	
};

class VehicleRegistry:public Car{
	private:
		Car *VehicleArr[100];
		int index=0;
	public:
		void addCarInfo(int id,string manufacturer,string model,int year,string fuelType){

			Car *c=new Car();
			VehicleArr[index]=c;
			c->setCarinfo(id,manufacturer,model,year,fuelType);
//			index++;
		}
		
		void displayCarinfo(){
			VehicleArr[0]->getCarinfo();
		}	
	
};
int Vehicle ::totalVehicles=0;
int main(){
	
	Vehicle v1(101,"abcd","vehicle",2020);
	v1.getVehicleinfo();
	
	Car c1(101,"abc","car",2021,"petrol");
	c1.getCarinfo();
	
	ElectricCar e1(101,"abc","Electriccar",2021,"petrol",78);
	e1.getElectricCarinfo();
	
	AirCraft a1(989);
	a1.getAirCraftinfo();
	
	FlyingCar f1(101,"abc","flyingcar",2021,"petrol",567);
	f1.getFlyingCarinfo();
	
	SportsCar s1(101,"abc","Sportscar",2025,"petrol",78,50);
	s1.getSportsCarinfo();
	
	Sedan se1(101,"abc","sedan",2022,"petrol");
	se1.getSedaninfo();
	
	SUV suv1(101,"abc","suv",2023,"petrol");
	suv1.getSUVinfo();
	
	
	VehicleRegistry r1;
	r1.addCarInfo(101,"abc","car-arr",2021,"petrol");
	
	r1.displayCarinfo();
	
	return 0;
}