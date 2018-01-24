#include<wiringPi.h>
#include<stdlib.h>
#include<time.h>
int a = 11;
int b = 7;
int c = 4;
int d = 2;
int e = 1;
int f = 10;
int g = 5;
int h = 3;
int dig1 = 12;
int dig2 = 9;
int dig3 = 8;
int dig4 = 6;

void N0()
{
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, HIGH);
	digitalWrite(f, HIGH);
	digitalWrite(g, LOW);
}
void N1()
{
	digitalWrite(a, LOW);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, LOW);
	digitalWrite(e, LOW);
	digitalWrite(f, LOW);
	digitalWrite(g, LOW);
}
void N2()
{
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(c, LOW);
	digitalWrite(d, HIGH);
	digitalWrite(e, HIGH);
	digitalWrite(f, LOW);
	digitalWrite(g, HIGH);
}
void N3()
{
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, LOW);
	digitalWrite(f, LOW);
	digitalWrite(g, HIGH);
}
void N4()
{
	digitalWrite(a, LOW);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, LOW);
	digitalWrite(e, LOW);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}
void N5()
{
	digitalWrite(a, HIGH);
	digitalWrite(b, LOW);
	digitalWrite(c, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, LOW);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}
void N6()
{
	digitalWrite(a, HIGH);
	digitalWrite(b, LOW);
	digitalWrite(c, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, HIGH);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}
void N7()
{
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, LOW);
	digitalWrite(e, LOW);
	digitalWrite(f, LOW);
	digitalWrite(g, LOW);
}
void N8()
{
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, HIGH);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}
void N9()
{
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, LOW);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}
void getNum(int num)
{
	switch (num)
	{
		case 0:
			{
				N0();
				break;
			}
		case 1:
			{
				N1();
				break;
			}
		case 2:
			{
				N2();
				break;
			}
		case 3:
			{
				N3();
				break;
			}
		case 4:
			{
				N4();
				break;
			}
		case 5:
			{
				N5();
				break;
			}
		case 6:
			{
				N6();
				break;
			}
		case 7:
			{
				N7();
				break;
			}
		case 8:
			{
				N8();
				break;
			}
		case 9:
			{
				N9();
				break;
			}
	}
}

void PutPri(int d1, int d2, int d3, int d4, bool dot)
{
	
		getNum(d1);
		digitalWrite(dig1, LOW);
		delayMicroseconds(2500);
		digitalWrite(dig1, HIGH);

		getNum(d2);
		digitalWrite(h, dot);
		digitalWrite(dig2, LOW);
		delayMicroseconds(2500);
		digitalWrite(h, LOW);
		digitalWrite(dig2, HIGH);

		getNum(d3);
		digitalWrite(dig3, LOW);
		delayMicroseconds(2500);
		digitalWrite(dig3, HIGH);

		getNum(d4);
		digitalWrite(dig4, LOW);
		delayMicroseconds(2500);
		digitalWrite(dig4, HIGH);
}

int main()
{
	wiringPiSetup();
	for (int i = 1; i < 13; i++)
	{
		pinMode(i, OUTPUT);
	}
	digitalWrite(dig1, HIGH);
	digitalWrite(dig2, HIGH);
	digitalWrite(dig3, HIGH);
	digitalWrite(dig4, HIGH);
	long tim = 0;
	while(true)
	{
		time_t timep;
		time(&timep);
		tim = (timep / 60) % 1440;
		tim = (tim + 480) % 1440; //480£ºÊ±Çø£¬ 8 * 60 ¡£ Timezone 8 * 60(China).
		PutPri((tim / 60) / 10, (tim / 60) % 10, (tim % 60) / 10, (tim % 60) % 10, timep % 2);
	}
}

