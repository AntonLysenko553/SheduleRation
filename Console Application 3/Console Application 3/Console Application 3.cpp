#include <iostream>
#include <vector>
using namespace std;
class WeekRation
{
public:
	string WREating, WRFood, WRPortionSize, WRQuantityCalories;
	WeekRation(string e, string f, string ps, string qc)
	{
		WREating = e;
		WRFood = f;
		WRPortionSize = ps;
		WRQuantityCalories = qc;
	}
	WeekRation()
	{

	}
};
vector <vector <WeekRation>> Week(7);
vector <WeekRation> Day;
int DayNameToNumber(string strDayName)
{
	int n = 7;
	if (strDayName == "Monday")
	{
		n = 0;
	}
	else if (strDayName == "Tuesday")
	{
		n = 1;
	}
	else if (strDayName == "Wednesday")
	{
		n = 2;
	}
	else if (strDayName == "Thursday")
	{
		n = 3;
	}
	else if (strDayName == "Friday")
	{
		n = 4;
	}
	else if (strDayName == "Saturday")
	{
		n = 5;
	}
	else if (strDayName == "Sunday")
	{
		n = 6;
	}
	return n;
}
bool CheckingDEF(int intDayOfWeek, string strEating, string strFood)
{
	for (int i1 = 0; i1 < Week[intDayOfWeek].size(); i1++)
	{
		if (strEating == Week[intDayOfWeek][i1].WREating && strFood == Week[intDayOfWeek][i1].WRFood)
		{
			return false;
			break;
		}
		else
		{
			return true;
		}
	}
}
void OutputWeekRation()
{
	int b = 0;
	int i6;
	bool TF = true;
	for (i6 = 0; i6 < Week[b].size(); i6++)
	{
		cout << "Monday " << Week[b][i6].WREating << " " << Week[b][i6].WRFood << " " << Week[b][i6].WRPortionSize << " " << Week[b][i6].WRQuantityCalories << endl << endl;
	}
	b = 1;
	for (i6 = 0; i6 < Week[b].size(); i6++)
	{
		cout << "Tuesday " << Week[b][i6].WREating << " " << Week[b][i6].WRFood << " " << Week[b][i6].WRPortionSize << " " << Week[b][i6].WRQuantityCalories << endl << endl;
	}
	b = 2;
	for (i6 = 0; i6 < Week[b].size(); i6++)
	{
		cout << "Wednesday " << Week[b][i6].WREating << " " << Week[b][i6].WRFood << " " << Week[b][i6].WRPortionSize << " " << Week[b][i6].WRQuantityCalories << endl << endl;
	}
	b = 3;
	for (i6 = 0; i6 < Week[b].size(); i6++)
	{
		cout << "Thursday " << Week[b][i6].WREating << " " << Week[b][i6].WRFood << " " << Week[b][i6].WRPortionSize << " " << Week[b][i6].WRQuantityCalories << endl << endl;
	}
	b = 4;
	for (i6 = 0; i6 < Week[b].size(); i6++)
	{
		cout << "Friday " << Week[b][i6].WREating << " " << Week[b][i6].WRFood << " " << Week[b][i6].WRPortionSize << " " << Week[b][i6].WRQuantityCalories << endl << endl;
	}
	b = 5;
	for (i6 = 0; i6 < Week[b].size(); i6++)
	{
		cout << "Saturday " << Week[b][i6].WREating << " " << Week[b][i6].WRFood << " " << Week[b][i6].WRPortionSize << " " << Week[b][i6].WRQuantityCalories << endl << endl;
	}
	b = 6;
	for (i6 = 0; i6 < Week[b].size(); i6++)
	{
		cout << "Sunday " << Week[b][i6].WREating << " " << Week[b][i6].WRFood << " " << Week[b][i6].WRPortionSize << " " << Week[b][i6].WRQuantityCalories << endl << endl;
	}
	for (i6 = 0; i6 < Week.size(); i6++)
	{
		if (!Week[i6].empty())
		{
			TF = false;
		}
	}
	if (TF)
	{
		cout << "Ни одного рациона не добавлено" << endl << endl;
	}
}
int main()
{
	setlocale(0, "");
	for (int i2 = 0; i2 < 6; i2++)
	{
		Week[i2] = Day;
	}
    for (;;)
    {
		string a;
		int b;
		bool IsSave = true;
		cout << "Для добавления рациона нажмите 1" << endl;
		cout << "Для удаления рациона нажмите 2" << endl;
		cout << "Для просмотра рациона дня нажмите 3" << endl;
		cout << "Для вывода информации о питании за неделю нажмите 4" << endl;
		cout << "Для завершения программы нажмите любую другую клавишу" << endl;
		cin >> a;
		cout << endl;
		if (a == "1")
		{
			string DayOfWeek, Eating, Food, PortionSize, QuantityCalories;
			cout << "Введите день недели: ";
			cin >> DayOfWeek;
			b = DayNameToNumber(DayOfWeek);
			if (b > 6)
			{
				cout << "Неправильное название дня недели" << endl << endl;
				continue;
			}
			cout << "Введите название приёма пищи: ";
			cin >> Eating;
			cout << "Введите название еды: ";
			cin >> Food;
			if (!Week[b].empty())
			{
				if (!CheckingDEF(b, Eating, Food))
				{
					cout << "Нельзя добавить этот продукт. На этот приём пищи он уже добавлен" << endl << endl;
					continue;
				}
			}
			cout << "Введите размер порции (в граммах): ";
			cin >> PortionSize;
			cout << "Введите количество Ккал в еде: ";
			cin >> QuantityCalories;
			cout << endl;
				//сохранение рациона в вектор
				WeekRation wr1 = WeekRation(Eating, Food, PortionSize, QuantityCalories);
				Week[b].resize(Week[b].size() + 1);
				Week[b][Week[b].size() - 1] = wr1;
		}
		else if (a == "2")
		{
			string DayForDelete;
			cout << "Введите день удаляемого рациона: ";
			cin >> DayForDelete;
			b = DayNameToNumber(DayForDelete);
			if (b > 6)
			{
				cout << "Неправильное название дня недели" << endl << endl;
				continue;
			}
			if (Week[b].empty())
			{
				cout << "На этот день недели не добавлено рационов" << endl << endl;
				continue;
			}
			//удаление рациона присвоением пустого вектора
			Week[b] = Day;
		}
		else if (a == "3")
		{
			string InputDay;
			cout << "Введите день недели: ";
			cin >> InputDay;
			b = DayNameToNumber(InputDay);
			if (b > 6)
			{
				cout << "Неправильное название дня недели" << endl << endl;
				continue;
			}
			if (Week[b].empty())
			{
				cout << "На этот день недели не добавлено рационов. Добавьте рацион, чтобы посмотреть его" << endl << endl;
				continue;
			}
			for (int i5 = 0; i5 < Week[b].size(); i5++)
			{
				cout << Week[b][i5].WREating << " " << Week[b][i5].WRFood << " " << Week[b][i5].WRPortionSize << " " << Week[b][i5].WRQuantityCalories << endl << endl;
			}
		}
		else if (a == "4")
		{
			OutputWeekRation();
		}
		else
		{
			break;
		}
    }
	return 0;
}