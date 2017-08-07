#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int compare(int,string);
int year(string);
int month(string, string);
string month_for_year(int,int);
int how_many_days(int, int);
string full_name_of_monthGRE(int);
int shanghaitech(string, string, string);
int shanghaitech_noout(int,int,int);
int Gregorian(string, string, string);
int month_to_numGRE(string);
int month_to_numSTU(string, int);
int sixteen_ten(string);
int plus_a_dayGRE(int, int, int);
int plus_a_daySTU(int, int, int);
int leap_yearGRE(int);
int leap_yearSTU(int);
int day_of_monthSTU(int, int);
int digit_sum(int);
string name_of_monthSTU(int, int);
string name_of_monthGRE(int);
//int year(int);

int main(int argc, char const *argv[]) {
	int simb = compare(argc,argv[1]);
	switch (simb) {
	case 1:
		year(argv[1]);
		break;
	case 2:
		month(argv[1], argv[2]);
		break;
	case 3:
		shanghaitech(argv[1], argv[2], argv[3]);
		break;
	case 4:
		Gregorian(argv[1], argv[2], argv[3]);
		break;
	}
	return 0;
}
string month_for_year(int num_month, int num_year) {
    string line = "";
	int num_date = 1;
	string month_name = full_name_of_monthGRE(num_month);
	while (month_name.size() < 24) {
		month_name += " ";
	}
    line = line + month_name;
	line = line + "┌──┬──┬──┬──┬──┬──┬──┐  " + "│Su│Mo│Tu│We│Th│Fr│Sa│  " + "├──┼──┼──┼──┼──┼──┼──┤  ";
	string elm1 = "│";
	string elm2 = "  ";
	int day_of_month;
	int form_monthLEAP[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int form_monthNOT[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (leap_yearGRE(num_year))
		day_of_month = form_monthLEAP[num_month - 1];
	else
		day_of_month = form_monthNOT[num_month - 1];
	int i = 1;
	int k = 1;
	char num[10];
	char num1[10];
	int code = shanghaitech_noout(num_month,num_date,num_year);
	int num_yearSTU = code % 10000;
	code = (code - num_yearSTU) / 10000;
	int num_dateSTU = code % 100;
	code = (code - num_dateSTU) / 100;
	int num_monthSTU = code ;
	int day_of_month1 ;
	if (leap_yearSTU(num_yearSTU) == 0) 
		day_of_month1 = day_of_monthSTU(num_monthSTU , num_yearSTU);
	else {
		if (leap_yearSTU(num_yearSTU) == 1){
			if (num_monthSTU == 1)
				day_of_month1 = day_of_monthSTU(num_monthSTU, num_yearSTU);
			else
				day_of_month1 = day_of_monthSTU(num_monthSTU - 1, num_yearSTU);
		}
		else {
			if (num_monthSTU < 5)
				day_of_month1 = day_of_monthSTU(num_monthSTU, num_yearSTU);
			else
				day_of_month1 = day_of_monthSTU(num_monthSTU - 1, num_yearSTU);
		}
	}
	int days = how_many_days(num_month,num_year);
	int origin_position = days % 7 + 1;
	while (i < 43){
		if (i < origin_position || i >= origin_position + day_of_month) {
			line = line + "│" + "  ";
		}
		else{
			sprintf(num,"%d",num_date);
			string numb = num;
			if (num_date < 10)
				numb = " " + numb;
			line = line + "│" + numb;
			num_date += 1;
		}
		if (i % 7 == 0){
			line = line + "│" + "  " ;
			while (k < (i + 1 )) {
				if (k < origin_position || k >= origin_position + day_of_month)
					line = line + "│" + "  ";
				else {
					sprintf(num1, "%X", num_dateSTU);
					string number = num1;
					if (num_dateSTU < 16)
						number = " " + number;
					line = line + "│" + number;
					if (num_dateSTU < day_of_month1)
						num_dateSTU += 1;
					else 
						num_dateSTU = 1;
				}
				if (k == i) {
					line = line + "│" + "  " ;
					if (k < 40)
						line = line + "├──┼──┼──┼──┼──┼──┼──┤  ";
				}
				k += 1;

			}
		}
	i += 1;
	}
	line = line + "└──┴──┴──┴──┴──┴──┴──┘" + "  " ;
	return line;
}
int year(string year){
	int num_year = atoi(year.c_str());
	cout << year << endl;
	for (int i = 1; i < 5; i++){
		string line1 = month_for_year(3 * i - 2,num_year);
		string line2 = month_for_year(3 * i - 1,num_year);
		string line3 = month_for_year(3 * i ,num_year);
		string str1 = "";
		string str2 = "";
		string str3 = "";
		for (int k = 0; k < 1088; k++){
			str1 = str1 + line1[k];
			str2 = str2 + line2[k];
			str3 = str3 + line3[k];
			switch (k + 1) {
			case 24:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 92:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 132:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 200:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 240:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 280:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 348:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 388:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 428:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 496:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 536:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 576:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 644:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 684:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 724:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 792:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 832:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 872:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 940:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 980:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 1020:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			case 1088:
				cout << str1 << str2 << str3<< endl;
				str1 = "";
				str2 = "";
				str3 = "";
				break;
			

			}
		}
		cout << endl ;
	}
	return 0;
}

int shanghaitech_noout(int num_month, int num_date, int num_year) {
	int originGRE[3] = { 1,1,1 };
	int originSTU[3] = { 1,1,1 };
	int container;
	while (originGRE[0] != num_month || originGRE[1] != num_date || originGRE[2] != num_year) {
		container = plus_a_dayGRE(originGRE[0], originGRE[1], originGRE[2]);
		originGRE[2] = container % 10000;
		container = (container - originGRE[2]) / 10000;
		originGRE[1] = container % 100;
		container = (container - originGRE[1]) / 100;
		originGRE[0] = container;
		container = plus_a_daySTU(originSTU[0], originSTU[1], originSTU[2]);
		originSTU[2] = container % 10000;
		container = (container - originSTU[2]) / 10000;
		originSTU[1] = container % 100;
		container = (container - originSTU[1]) / 100;
		originSTU[0] = container;
	}
	return  originSTU[2] + originSTU[1] * 10000 + originSTU[0] *1000000  ;
}
int month(string month, string year) {
	int num_month = atoi(month.c_str());
	int num_year = atoi(year.c_str());
	int num_date = 1;
	cout << year << endl;
	string month_name = full_name_of_monthGRE(num_month);
	while (month_name.size() < 24) {
		month_name += " ";
	}
	cout << month_name << endl;
	cout << "┌──┬──┬──┬──┬──┬──┬──┐  " << endl << "│Su│Mo│Tu│We│Th│Fr│Sa│  " << endl << "├──┼──┼──┼──┼──┼──┼──┤  " <<endl;
	//string elm1 = "│";
	//string elm2 = "  ";
	int day_of_month;
	int form_monthLEAP[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int form_monthNOT[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (leap_yearGRE(num_year))
		day_of_month = form_monthLEAP[num_month - 1];
	else
		day_of_month = form_monthNOT[num_month - 1];
	int i = 1;
	int k = 1;
	//string line1 = "";
	//string line2 = "";
	char num[10];
	char num1[10];
	int code = shanghaitech_noout(num_month,num_date,num_year);
	int num_yearSTU = code % 10000;
	code = (code - num_yearSTU) / 10000;
	int num_dateSTU = code % 100;
	code = (code - num_dateSTU) / 100;
	int num_monthSTU = code ;
	int day_of_month1 ;
	if (leap_yearSTU(num_yearSTU) == 0) 
		day_of_month1 = day_of_monthSTU(num_monthSTU , num_yearSTU);
	else {
		if (leap_yearSTU(num_yearSTU) == 1){
			if (num_monthSTU == 1)
				day_of_month1 = day_of_monthSTU(num_monthSTU, num_yearSTU);
			else
				day_of_month1 = day_of_monthSTU(num_monthSTU - 1, num_yearSTU);
		}
		else {
			if (num_monthSTU < 5)
				day_of_month1 = day_of_monthSTU(num_monthSTU, num_yearSTU);
			else
				day_of_month1 = day_of_monthSTU(num_monthSTU - 1, num_yearSTU);
		}
	}
	int days = how_many_days(num_month,num_year);
	int origin_position = days % 7 + 1;
	while (i < 43){
		if (i < origin_position || i >= origin_position + day_of_month) {
			cout << "│" << "  ";
		}
		else{
			sprintf(num,"%d",num_date);
			string numb = num;
			if (num_date < 10)
				numb = " " + numb;
			cout << "│" << numb;
			num_date += 1;
		}
		if (i % 7 == 0){
			cout << "│" << "  " << endl;
			while (k < (i + 1 )) {
				if (k < origin_position || k >= origin_position + day_of_month)
					cout << "│" << "  ";
				else {
					sprintf(num1, "%X", num_dateSTU);
					string number = num1;
					if (num_dateSTU < 16)
						number = " " + number;
					cout << "│" << number;
					if (num_dateSTU < day_of_month1)
						num_dateSTU += 1;
					else 
						num_dateSTU = 1;
				}
				if (k == i) {
					cout << "│" << "  " << endl;
					if (k < 40)
						cout << "├──┼──┼──┼──┼──┼──┼──┤  " << endl;
				}
				k += 1;

			}
		}
	i += 1;
	}
	cout << "└──┴──┴──┴──┴──┴──┴──┘" << "  " << endl << endl;
	return 0;
}
int how_many_days(int month,int year){
	int num_day2 = 0;   
	int num_day = 0;
	int form_monthNOT[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int num_leap_year = 0;
	for (int i = 1; i < year; i++){
		if (leap_yearGRE(i))
			num_leap_year += 1;
	}
	
	int num_day1 = (year - 1) * 365 + num_leap_year;
	if (month == 1){
		num_day = num_day1 + 1;
	}
	else{
		for (int i = 0;i < month - 1;i++){
			num_day2 += form_monthNOT[i];
		}
		if (leap_yearGRE(year) && month != 2)
			num_day = num_day1 + num_day2 + 2;
		else
			num_day = num_day1 + num_day2 + 1;
	}
	return num_day;
}
int Gregorian(string month, string date, string year) {
	int num_year = atoi(year.c_str());
	int num_month = month_to_numSTU(month, leap_yearSTU(num_year));
	int num_date = sixteen_ten(date);
	int originSTU[3] = { 1,1,1 };
	int originGRE[3] = { 1,1,1 };
	int container;
	while (originSTU[0] != num_month || originSTU[1] != num_date || originSTU[2] != num_year) {
		container = plus_a_dayGRE(originGRE[0], originGRE[1], originGRE[2]);
		originGRE[2] = container % 10000;
		container = (container - originGRE[2]) / 10000;
		originGRE[1] = container % 100;
		container = (container - originGRE[1]) / 100;
		originGRE[0] = container;
		container = plus_a_daySTU(originSTU[0], originSTU[1], originSTU[2]);
		originSTU[2] = container % 10000;
		container = (container - originSTU[2]) / 10000;
		originSTU[1] = container % 100;
		container = (container - originSTU[1]) / 100;
		originSTU[0] = container;
	}
	string month_name = name_of_monthGRE(originGRE[0]);
	cout << month_name << " " << originGRE[1] << "," << " "<< originGRE[2] << endl;
	return 0;
}
int shanghaitech(string month, string date, string year) {
	int num_month = month_to_numGRE(month);
	int num_date = atoi(date.c_str());
	int num_year = atoi(year.c_str());
	int originGRE[3] = { 1,1,1 };
	int originSTU[3] = { 1,1,1 };
	int container;
	while (originGRE[0] != num_month || originGRE[1] != num_date || originGRE[2] != num_year) {
		container = plus_a_dayGRE(originGRE[0], originGRE[1], originGRE[2]);
		originGRE[2] = container % 10000;
		container = (container - originGRE[2]) / 10000;
		originGRE[1] = container % 100;
		container = (container - originGRE[1]) / 100;
		originGRE[0] = container;
		container = plus_a_daySTU(originSTU[0], originSTU[1], originSTU[2]);
		originSTU[2] = container % 10000;
		container = (container - originSTU[2]) / 10000;
		originSTU[1] = container % 100;
		container = (container - originSTU[1]) / 100;
		originSTU[0] = container;
	}
	string month_name = name_of_monthSTU(originSTU[0],leap_yearSTU(originSTU[2]));
	cout << month_name << " ";
	printf("%X", originSTU[1]);
	cout << "," << " " << originSTU[2] << endl;
	return 0;
}
int compare(int num,string x) {          //judge whether the form is shanghaitech or gregorian
	if (num == 2)
		return 1;
	else {
		if (num == 3)
			return 2;
		else {
			if (x == "Jan" || x == "Feb" || x == "Mar" || x == "Apr" || x == "May" || x == "Jun" || x == "Jul" || x == "Aug" || x == "Sep" || x == "Oct" || x == "Nov" || x == "Dec")
				return 3;
			else
				return 4;
		}
	}
}
int month_to_numGRE(string x) {
	string mon[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int i = 0;
	while (x != mon[i]) {
		i = i + 1;
	}
	return i + 1;
}
int month_to_numSTU(string month, int kind) {
	int i = 0;
	if (kind == 0) {
		string mon[6] = { "Sist", "Spst", "Slst", "Sem", "Siais", "Ihuman" };
		while (mon[i] != month) {
			i += 1;
		}
		return i + 1;
	}
	else {
		if (kind == 1) {
			string mon[7] = { "Sist","SIST", "Spst", "Slst", "Sem", "Siais", "Ihuman" };
			while (mon[i] != month) {
				i += 1;
			}
			return i + 1;
		}
		else {
			string mon[7] = { "Sist", "Spst", "Slst", "Sem","SEM", "Siais", "Ihuman" };
			while (mon[i] != month) {
				i += 1;
			}
			return i + 1;
		}
	}
}
int plus_a_dayGRE(int month, int date, int year) {
	static int point[3];
	static int symb;
	static int form_monthLEAP[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	static int form_monthNOT[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leap_yearGRE(year))
		symb = form_monthLEAP[month - 1];
	else
		symb = form_monthNOT[month - 1];
	if (date < symb) {
		point[1] = date + 1;
		point[0] = month;
		point[2] = year;
	}
	else {
		point[1] = 1;
		if (month == 12) {
			point[0] = 1;
			point[2] = year + 1;
		}
		else {
			point[0] = month + 1;
			point[2] = year;
		}
	}
	return  point[2] + 10000 * point[1] + 1000000 * point[0];
}
int plus_a_daySTU(int month, int date, int year) {
	static int point[3];
/*	if (leap_yearSTU(year) == 0) {

	}
	for (int i = 0;i < 6;i++)
		form_month[i] = day_of_monthSTU(i + 1, year);
	if (leap_yearSTU(year) == 1) {
		for (int i = 0; i < 6; i++) {
			form_month[6 - i] = form_month[5 - i];
		}
	}
	else {
		if (leap_yearSTU(year) == 2) {
			for (int i = 0; i < 3; i++) {
				form_month[6 - i] = form_month[5 - i];
			}
		}
	}*/
	static int symb;
	if (leap_yearSTU(year) == 0) 
		 symb = day_of_monthSTU(month , year);
	else {
		if (leap_yearSTU(year) == 1){
			if (month == 1)
				symb = day_of_monthSTU(month, year);
			else
				symb = day_of_monthSTU(month - 1, year);
		}
		else {
			if (month < 5)
				symb = day_of_monthSTU(month, year);
			else
				symb = day_of_monthSTU(month - 1, year);
		}
	}
	if (date < symb) {
		point[1] = date + 1;
		point[0] = month;
		point[2] = year;
	}
	else {
		point[1] = 1;
		if (leap_yearSTU(year) == 0) {
			if (month == 6) {
				point[0] = 1;
				point[2] = year + 1;
			}
			else {
				point[0] = month + 1;
				point[2] = year;
			}
		}
		else {
			if (month == 7) {
				point[0] = 1;
				point[2] = year + 1;
			}
			else {
				point[0] = month + 1;
				point[2] = year;
			}
		}
	}
	return point[2] + 10000 * point[1] + 1000000 * point[0];
}
int leap_yearGRE(int year){
	if (year % 100 != 0){
		if (year % 4 == 0)
			return 1;
		else
			return 0;
	}
	else {
		if (year % 400 == 0){
			if (year % 4000 == 0)
				return 0;
			else
				return 1;
		}
		else
			return 0;
	}
}

int leap_yearSTU(int year) {
	if ((year + digit_sum(year)) % 13 != 0)
		return 0;
	else {
		if ((year - digit_sum(year)) % 6 + 1 == 1)
			return 1;
		else
			return 2;
	}
}
int digit_sum(int year) {
	int rest = year;
	int last = 0;
	int sum = 0;
	while (rest != 0) {
		last = rest % 10;
		sum = sum + last;
		rest = (rest - last) / 10;
	}
	return sum;
}
int day_of_monthSTU(int month, int year) {
	int D = 60 + (10 * year - month) % 3;
	return D;
}
string name_of_monthSTU(int month, int kind) {
	if (kind == 0) {
		string mon[6] = { "Sist", "Spst", "Slst", "Sem", "Siais", "Ihuman" };
		return mon[month - 1];
	}
	else {
		if (kind == 1) {
			string mon[7] = { "Sist", "SIST","Spst", "Slst", "Sem", "Siais", "Ihuman" };
			return mon[month - 1];
		}
		else {
			string mon[7] = { "Sist", "Spst", "Slst", "Sem", "SEM","Siais", "Ihuman" };
			return mon[month - 1];
		}
	}
}
string name_of_monthGRE(int month) {
	string mon[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return mon[month - 1];
}
string full_name_of_monthGRE(int month){
	string mon[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return mon[month - 1];
}
int sixteen_ten(string date) {
	char container[2];
	int k = 0;
	for (int i = 0; i < date.size() - 1; i++) {
		container[i] = date[i];
	}
	sscanf(container, "%x", &k);
	return k;
}

