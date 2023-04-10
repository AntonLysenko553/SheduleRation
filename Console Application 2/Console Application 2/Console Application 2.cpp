#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int Time;
class Event
{
public:
	string EventTimeStart, EventTimeEnd, EventName;
	Event(string t, string d, string n)
	{
		EventTimeStart = t;
		EventTimeEnd = d;
		EventName = n;
	}
	Event()
	{

	}
};
vector <vector <Event>> Week(7);
vector <Event> Day;
int ConvertationTime(string tm)
{
	int hours, minutes, ConvertHours;
	char Mass[4];
	string c = tm.substr(0, 2);
	memset(Mass, 0, sizeof(Mass));
	strncpy_s(Mass, c.c_str(), sizeof(Mass) - 1);
	hours = atoi(Mass);
	string d = tm.substr(3, 2);
	memset(Mass, 0, sizeof(Mass));
	strncpy_s(Mass, d.c_str(), sizeof(Mass) - 1);
	minutes = atoi(Mass);
	ConvertHours = hours * 60;
	Time = minutes + ConvertHours;
	return Time;
}
bool CheckInterval(string strTimeStartNew, string strTimeEndNew, string strTimeStartSaved, string strTimeEndSaved, bool IsDelete)
{
	int intTimeStartNew, intTimeEndNew, intTimeStartSaved, intTimeEndSaved;
	intTimeStartNew = ConvertationTime(strTimeStartNew);
	intTimeStartSaved = ConvertationTime(strTimeStartSaved);
	intTimeEndSaved = ConvertationTime(strTimeEndSaved);
	if (IsDelete)
	{
		if (intTimeStartNew >= intTimeStartSaved && intTimeStartNew <= intTimeEndSaved)
		{
			return true;
		}
	}
	else
	{
		if (intTimeStartNew > intTimeStartSaved && intTimeStartNew < intTimeEndSaved)
		{
			return true;
		}
		intTimeEndNew = ConvertationTime(strTimeEndNew);
		if (intTimeEndNew > intTimeStartSaved && intTimeEndNew < intTimeEndSaved)
		{
			return true;
		}
	}
	return false;
}
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
void OutputTimetable()
{
	int b = 0;
	for(int p = 0; p < Week[b].size(); p++)
	{
		cout << "Monday " << Week[b][p].EventTimeStart << "-" << Week[b][p].EventTimeEnd << " " << Week[b][p].EventName << endl;
	}
	b = 1;
	for (int p = 0; p < Week[b].size(); p++)
	{
		cout << "Tuesday " << Week[b][p].EventTimeStart << "-" << Week[b][p].EventTimeEnd << " " << Week[b][p].EventName << endl;
	}
	b = 2;
	for (int p = 0; p < Week[b].size(); p++)
	{
		cout << "Wednesday " << Week[b][p].EventTimeStart << "-" << Week[b][p].EventTimeEnd << " " << Week[b][p].EventName << endl;
	}
	b = 3;
	for (int p = 0; p < Week[b].size(); p++)
	{
		cout << "Thursday " << Week[b][p].EventTimeStart << "-" << Week[b][p].EventTimeEnd << " " << Week[b][p].EventName << endl;
	}
	b = 4;
	for (int p = 0; p < Week[b].size(); p++)
	{
		cout << "Friday " << Week[b][p].EventTimeStart << "-" << Week[b][p].EventTimeEnd << " " << Week[b][p].EventName << endl;
	}
	b = 5;
	for (int p = 0; p < Week[b].size(); p++)
	{
		cout << "Saturday " << Week[b][p].EventTimeStart << "-" << Week[b][p].EventTimeEnd << " " << Week[b][p].EventName << endl;
	}
	b = 6;
	for (int p = 0; p < Week[b].size(); p++)
	{
		cout << "Sunday " << Week[b][p].EventTimeStart << "-" << Week[b][p].EventTimeEnd << " " << Week[b][p].EventName << endl;
	}
}
int main()
{
	setlocale(0, "");
	for (int j = 0; j < 6; j++)
	{
		Week[j] = Day;
	}
	for (int i = 0;; i++)
	{
		string a;
		int b;
		bool IsSave = true;
		cout << "Для добавления события нажмите 1" << endl;
		cout << "Для удаления события нажмите 2" << endl;
		cout << "Для просмотра события нажмите 3" << endl;
		cout << "Для вывода всех событий за неделю нажмите 4" << endl;
		cout << "Для завершения программы нажмите любую другую клавишу" << endl;
		cin >> a;
		cout << endl;
		if (a == "1")
		{
			string DayOfWeek, TimeStart, TimeEnd, Name;
			cout << "Введите день недели: ";
			cin >> DayOfWeek;
			b = DayNameToNumber(DayOfWeek);
			if (b > 6)
			{
				cout << "Неправильное название дня недели" << endl << endl;
				continue;
			}
			cout << "Введите время начала события: ";
			cin >> TimeStart;
			cout << "Введите время окончания события: ";
			cin >> TimeEnd;
			cout << "Введите название события: ";
			cin >> Name;
			cout << endl;
			//проверка персечения интервалов времени
			if (!Week[b].empty())
			{
				for (int u = 0; u < Week[b].size(); u++)
				{
					if (CheckInterval(TimeStart, TimeEnd, Week[b][u].EventTimeStart, Week[b][u].EventTimeEnd, false))
					{
						cout << "Нельзя добавить событие. На это время уже запланировано событие " << Week[b][u].EventName << endl << endl;
						IsSave = false;
						break;
					}
				}
			}
			if (IsSave)
			{
				Event event1 = Event(TimeStart, TimeEnd, Name);
				Week[b].resize(Week[b].size() + 1);
				Week[b][Week[b].size() - 1] = event1;
			}
		}
		else if (a == "2")
		{
			string DayForDelete, TimeForDelete;
			cout << "Введите день удаляемого события: ";
			cin >> DayForDelete;
			b = DayNameToNumber(DayForDelete);
			if (b > 6)
			{
				cout << "Неправильное название дня недели" << endl << endl;
				continue;
			}
			if (Week[b].empty())
			{
				cout << "В этот день недели не запланировано событий" << endl << endl;
				continue;
			}
			cout << "Введите время удаляемого события: ";
			cin >> TimeForDelete;
			cout << endl;
			bool TF = true;
			for (int u = 0; u < Week[b].size(); u++)
			{
				if (CheckInterval(TimeForDelete, "", Week[b][u].EventTimeStart, Week[b][u].EventTimeEnd, true))
				{
					Week[b].erase(Week[b].begin() + u);
					TF = false;
				}
			}
			if (TF)
			{
				cout << "На это время не запланировано событие" << endl << endl;
			}	
		}
		else if (a == "3")
		{
			string InputDay, InputTime;
			cout << "Введите день недели: ";
			cin >> InputDay;
			if (InputDay == "Today")
			{
				tm Tm;
				time_t t = time(nullptr);
				char d[][25] = {"Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday"};
				errno_t err = localtime_s(&Tm, &t);
				int b = Tm.tm_wday - 1;
				for (int p = 0; p < Week[b].size(); p++)
				{
					cout << d[Tm.tm_wday] << " " << Week[b][p].EventTimeStart << "-" << Week[b][p].EventTimeEnd << " " << Week[b][p].EventName << endl << endl;
				}
			}
			else
			{
				b = DayNameToNumber(InputDay);
				if (b > 6)
				{
					cout << "Неправильное название дня недели" << endl << endl;
					continue;
				}
				if (Week[b].empty())
				{
					cout << "В этот день недели не запланировано событий" << endl << endl;
					continue;
				}
				cout << "Введите время события: ";
				cin >> InputTime;
				for (int u = 0; u < Week[b].size(); u++)
				{
					if (CheckInterval(InputTime, "", Week[b][u].EventTimeStart, Week[b][u].EventTimeEnd, true))
					{
						cout << Week[b][u].EventTimeStart << "-" << Week[b][u].EventTimeEnd << " " << Week[b][u].EventName << endl;
					}
				}
			}
		}
		else if (a == "4")
		{
			OutputTimetable();
		}
		else
		{
			break;
		}
	}
	return 0;
}