




#include <iostream>

using namespace std;


//
//QEYD: Kechdiymiz her shey istifade olunsun
//
//class : Computer
//	fields :
//id(static)
//object_Id
//model(char*)
//vendor(char*)
//videocard(char*)
//monitor(char*)
//cpu_hz
//core
//ram
//disk_size
//isSSD(bool)
//cin, cout overload
//constructors
//destructor
//
//
//class : ComputerStore
//	store_name(char*)
//	store_address(char*)
//	Computer** computers; (array)
//	addComputer();
//deleteComputer(int id);
//cin, cout overload
//constructors
//destructor


class Computer {
	static int id;
	int objectId;
	char* model;
	char* vendor;
	char* videocard;
	char* monitor;
	double cpu_hz;
	int core;
	int ram;
	int disk_size;
	bool isSSD;

public:
#pragma region Constructor and Destructor
	Computer() : objectId(id++) {
		SetModel("N6OLO15");
		SetVendor("GameMax");
		SetVideoCard("NVIDIA GeForce RTX 3060");
		SetMonitor("ASUS VQ259QM");
		SetCpuHz(3.80);
		SetCore(8);
		SetRam(32);
		SetDiskSize(2);
		SetSSD(true);
	}

	Computer(const char* model, const char* vendor, const char* videocard, const char* monitor, double cpu_hz, int core, int ram, int disk_size, bool isSSD) : Computer() {
		SetModel(model);
		SetVendor(vendor);
		SetVideoCard(videocard);
		SetMonitor(monitor);
		SetCpuHz(cpu_hz);
		SetCore(core);
		SetRam(ram);
		SetDiskSize(disk_size);
		SetSSD(isSSD);
	}

	Computer(const Computer& other) {
		objectId = id++;
		SetModel(other.model);
		SetVendor(other.vendor);
		SetVideoCard(other.videocard);
		SetMonitor(other.monitor);
		SetCpuHz(other.cpu_hz);
		SetCore(other.core);
		SetRam(other.ram);
		SetDiskSize(other.disk_size);
		SetSSD(other.isSSD);
	}

	Computer& operator=(const Computer& other) {
		SetModel(other.model);
		SetVendor(other.vendor);
		SetVideoCard(other.videocard);
		SetMonitor(other.monitor);
		SetCpuHz(other.cpu_hz);
		SetCore(other.core);
		SetRam(other.ram);
		SetDiskSize(other.disk_size);
		SetSSD(other.isSSD);
		return *this;
	}
	~Computer() {
		delete[] model;
		delete[] vendor;
		delete[] videocard;
		delete[] monitor;
	}
#pragma endregion

#pragma region Setter and Getter

	int GetObjectId() const { return objectId; }

	const char* GetModel()const { return model; }

	const char* GetVendor()const { return vendor; }

	const char* GetVideoCard()const { return videocard; }

	const char* GetMonitor()const { return monitor; }

	double GetCpuHz()const { return cpu_hz; }

	int GetCore()const { return core; }

	int GetRam()const { return ram; }

	int GetDiskSize()const { return disk_size; }

	bool GetSSD()const { return isSSD; }





	void SetModel(const char* model) {
		delete[] this->model;
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}

	void SetVendor(const char* vendor) {
		delete[] this->vendor;
		this->vendor = new char[strlen(vendor) + 1];
		strcpy_s(this->vendor, strlen(vendor) + 1, vendor);
	}

	void SetVideoCard(const char* videocard) {
		delete[] this->videocard;
		this->videocard = new char[strlen(videocard) + 1];
		strcpy_s(this->videocard, strlen(videocard) + 1, videocard);
	}

	void SetMonitor(const char* monitor) {
		delete[] this->monitor;
		this->monitor = new char[strlen(monitor) + 1];
		strcpy_s(this->monitor, strlen(monitor) + 1, monitor);
	}

	void SetCpuHz(double cpu_hz) {
		this->cpu_hz = cpu_hz;
	}

	void SetCore(int core) {
		this->core = core;
	}

	void SetRam(int ram) {
		this->ram = ram;
	}

	void SetDiskSize(int disk_size) {
		this->disk_size = disk_size;
	}

	void SetSSD(bool isSSD) {
		this->isSSD = isSSD;
	}



#pragma endregion

	friend ostream& operator<<(ostream& out, const Computer& obj) {
		out << "==========Computers==========" << endl <<
			"objectId  : " << obj.objectId << endl <<
			"model     : " << obj.model << endl <<
			"vendor    : " << obj.vendor << endl <<
			"videocard : " << obj.videocard << endl <<
			"monitor   : " << obj.monitor << endl <<
			"cpu_hz    : " << obj.cpu_hz << endl <<
			"core      : " << obj.core << endl <<
			"ram       : " << obj.ram << endl <<
			"isSSD     : " << boolalpha << obj.isSSD << noboolalpha << endl << endl;

		return out;
	}

	friend istream& operator>>(istream& in, Computer& obj) {
		char* bf = new char[100];
		int num;
		bool SSD;
		double num_cpu_hz;

		cout << "Model : ";
		in.getline(bf, 20);
		obj.SetModel(bf);

		cout << "Vendor : ";
		in.getline(bf, 20);
		obj.SetVendor(bf);

		cout << "Videocard : ";
		in.getline(bf, 20);
		obj.SetVideoCard(bf);

		cout << "Monitor : ";
		in.getline(bf, 20);
		obj.SetMonitor(bf);

		cout << "Cpu_hz : ";
		cin >> num_cpu_hz;
		obj.SetCpuHz(num_cpu_hz);

		cout << "Core : ";
		cin >> num;
		obj.SetCore(num);

		cout << "Ram : ";
		cin >> num;
		obj.SetRam(num);

		cout << "SSD : ";
		cin >> SSD;
		obj.SetSSD(SSD);

		delete[] bf;
		return in;
	}

};

int Computer::id = 1;


class ComputerStore {
	char* store_name;
	char* store_address;
	int size;
	Computer** computers;


public:


	ComputerStore(const char* name, const char* address) {
		SetName(name);
		SetAddress(address);
		computers = nullptr;
		size = 0;

	}

	~ComputerStore() {
		for (int i = 0; i < size; i++)
		{
			delete computers[i];
		};
		delete[] computers;
	}

	const char* GetAddress() const { return store_address; }

	const char* GetName() const { return store_name; }

	void SetName(const char* name) {
		delete[] store_name;
		store_name = new char[strlen(name) + 1];
		strcpy_s(store_name, strlen(name) + 1, name);
	}

	void SetAddress(const char* address) {
		delete[] store_address;
		store_address = new char[strlen(address) + 1];
		strcpy_s(store_address, strlen(address) + 1, address);
	}


	void addComputer(Computer* comp) {
		Computer** temp = new Computer * [size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = computers[i];
		}
		temp[size] = new Computer;
		*temp[size] = *comp;
		delete[] computers;

		computers = temp;
		size++;
		temp = nullptr;
	}
	void DeleteComputer(int id) {
		int index = -1;
		for (int i = 0; i < size; i++)
		{
			if (computers[i]->GetObjectId() == id) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			Computer** temp = new Computer * [size - 1];
			for (int i = 0; i < index; i++)
			{
				temp[i] = computers[i];
			}

			for (int i = index; i < size; i++)
			{
				temp[i] = computers[i + 1];
			}
			delete[] computers;
			computers = temp;
			size--;
			temp = nullptr;
		}
	}
	friend ostream& operator<<(ostream& out, const ComputerStore& obj) {
		out << obj.store_name << endl << obj.store_address << endl;
		for (int i = 0; i < obj.size; i++)
		{
			cout << *obj.computers[i] << endl;
		}

		return out;
	}

};

int main() {
	ComputerStore t("Comp", "comp");
	t.addComputer(new Computer("N6OLO15", "GameMax", "Rtx 3060", "Asus", 3.2, 8, 32, 2, true));



	cout << t;
}