struct dates {
	int year;
	int day;
	int month;
};

struct NOTE1
{
	char *name;
	char *phone;
	date *age;
};

struct Tovar
{
	char *name;
	int  qnt;
	int price;
	dates *date;
};

struct MARSHRUT
{
	int num;
	char *startName;
	char *endName;
	int length;
};

struct ABON
{
	char *name;
	char *phone;
	char *dateAbon;
	int bill;
	int sumAbon;
};

void generateDate(dates *t);
void generateName(char *name);
void sortTovar(Tovar* a, int r);
void chooseTovar(Tovar *a, int r);
void generateStart(char *name);
void generateEnd(char *name);
void maxLength(MARSHRUT*a, int r);
void SortBus(MARSHRUT *a, int r);
void chooseBus(MARSHRUT *a, int r);
