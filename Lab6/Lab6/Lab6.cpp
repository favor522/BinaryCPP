#include <fstream>
#include <iostream>

struct student {
	char fio[100];
	int mark;
};

int main() {
	//Для записи
	struct student ps[] { {"Sergey", 5},
						{"Andrey", 4},
	};
	//Запись файла
	struct student ps_r[10];
	int count = 0;
	std::ofstream File("Da.dat", std::ios::out | std::ios::binary);
	if (File.is_open()) {
		for(auto& p : ps)
			File.write((char *)&p, sizeof(p));
	}
	
	File.close();
	//Чтение файла
	std::ifstream File1("Da.dat", std::ios::in | std::ios::binary);
	if (File1.is_open()) {
		while (File1.read((char*)&ps_r[count], sizeof(student)))
			count++;
	}
	//Вывод значений из файла
	for (int i = 0; i < count; i++) {
		std::cout << ps_r[i].fio << "\n";
		std::cout << ps_r[i].mark << "\n";
	}
	File1.close();
	return 0;
}